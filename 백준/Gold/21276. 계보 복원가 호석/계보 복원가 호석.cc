#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[1002];;
int deg[1002];
string name[1002];
unordered_map<string, int> id;
vector<int> result[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 1; i<=n; i++) cin >> name[i];
    sort(name + 1, name + n + 1);
    for(int i = 1; i<=n; i++) id[name[i]] = i;

    cin >> m;
    for(int i = 1; i<=m; i++){
        string a, b;
        cin >> a >> b;
        adj[id[b]].push_back(id[a]);
        deg[id[a]]++;
    }
    vector<int> v;
    for(int i = 1; i<=n; i++){
        if(deg[i] == 0){
            v.push_back(i);
        }
    }

    cout << v.size() << "\n";
    for(auto a : v)
        cout << name[a] << " ";
    cout << "\n";


    // indegree가 1 많은 후손(자녀)들의 정보를 배열 result에 저장
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        for(int c : adj[i])
            if(deg[c] - deg[i] == 1) result[i].push_back(c);
    }

    // 해당하는 사람과 자식의 수, 그리고 자식들의 이름을 출력
    for(int i = 1; i <= n; i++) {
        cout << name[i] << ' ' << result[i].size() << ' ';
        for(int c : result[i])
            cout << name[c] << ' ';
        cout << '\n';
    }
    return 0;
}
