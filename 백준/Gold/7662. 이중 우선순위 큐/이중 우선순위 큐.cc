#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        priority_queue<int, vector<int>, greater<>> low_PQ;
        priority_queue<int> PQ;
        map<int, int> cnt;
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            char command;
            int num;
            cin >> command >> num ;
            if(command == 'I'){
                PQ.push(num);
                low_PQ.push(num);
                cnt[num]++;
            }
            else if(command == 'D'){
                if(!low_PQ.empty() && num == -1){
                    cnt[low_PQ.top()]--;
                    low_PQ.pop();
                }
                else if(!PQ.empty() && num == 1){
                    cnt[PQ.top()]--;
                    PQ.pop();
                }
                while(!PQ.empty() && cnt[PQ.top()] == 0) PQ.pop();
                while(!low_PQ.empty() && cnt[low_PQ.top()] == 0) low_PQ.pop();
            }
        }
        while(!PQ.empty() && cnt[PQ.top()] == 0) PQ.pop();
        while(!low_PQ.empty() && cnt[low_PQ.top()] == 0) low_PQ.pop();
        if(PQ.empty() || low_PQ.empty()) cout << "EMPTY" << "\n";
        else cout << PQ.top() << " " << low_PQ.top() << "\n";
    }
    return 0;
}
