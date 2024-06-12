#include <bits/stdc++.h>

using namespace std;
int v[1000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    deque<int>dq;

    //입력이 1일 때: 맨 뒤에 원소를 넣어준다
    //입력이 2일 때: 원소를 맨 뒤에서 두번째에 넣어준다
    //입력이 3일 때: 원소를 맨 앞에 넣어준다
    int card = 1;
    for (int i = n - 1; i >= 0; i--) {

        if (v[i] == 1) {
            dq.push_back(card);
        }else if (v[i] == 2) {
            int tmp = dq.back();
            dq.pop_back();
            dq.push_back(card);
            dq.push_back(tmp);
        }else if (v[i] == 3) {
            dq.push_front(card);
        }

        card++;
    }
    reverse(dq.begin(), dq.end());
    for (auto i : dq) cout << i << ' ';
}