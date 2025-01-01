#include <bits/stdc++.h>
using namespace std;
int tmp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int P;
    cin >> P;
    while(P--){
        int n, ans = 0;
        cin >> n;
        vector<int> arr;

        cin >> tmp;
        arr.push_back(tmp); // 먼저 하나 세운다
        
        for(int i=1; i<=19; i++){
            cin >> tmp;
            int min_tmp = -1;
            for(int j = (int)arr.size()-1; j>=0; j--){
                if(arr[j] > tmp){
                    min_tmp = j;
                }
            }

            if(min_tmp == -1) arr.push_back(tmp);
            else {
                ans += arr.size() - min_tmp;
                arr.insert(arr.begin() + min_tmp, tmp);
            }
        }
        cout << n << " " << ans << "\n";
    }
    return 0;
}
