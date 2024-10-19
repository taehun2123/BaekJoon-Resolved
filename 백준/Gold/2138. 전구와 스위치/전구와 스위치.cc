#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
string arr, ansArr, temp;
int ans = MAX;
int n;


void switching(int index){
    if(index>0) temp[index-1] = temp[index-1] == '0' ? '1' : '0';
    temp[index] = temp[index] == '0' ? '1' : '0';
    if(index<n-1) temp[index+1] = temp[index+1] == '0' ? '1' : '0';
}

void switchBtn(int isZero){
    int cnt = 0;
    temp = arr;
    if(isZero == 1){
        temp[0] = temp[0] == '0' ? '1' : '0';
        temp[1] = temp[1] == '0' ? '1' : '0';
        cnt++;
    }
    for(int i = 1; i<n; i++){
        if(temp[i-1] != ansArr[i-1]){
            switching(i);
            cnt++;
        }
    }

    if(temp == ansArr) ans = min(ans, cnt);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> arr;
    cin >> ansArr;

    switchBtn(0);
    switchBtn(1);

    if(ans != MAX) cout << ans;
    else cout << -1;

    return 0;
}




