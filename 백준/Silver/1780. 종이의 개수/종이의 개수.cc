#include <bits/stdc++.h>
using namespace std;
long long arr[2500][2500];
int cnt[3];
int n;
//해당 종이 내부에 같은 숫자로만 채워졌는지 확인하는 함수
bool check(int x, int y, int n) {
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (arr[x][y] != arr[i][j])
                return false;
    return true;
}

void func(int x, int y, int n){
    if (check(x, y, n)) {
        cnt[arr[x][y] + 1] += 1;
        return;
    }
    int a = n/3;
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            func(x+i*a, y+j*a, a);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    func(0, 0, n);
    for(int i = 0; i<3; i++) cout << cnt[i] << "\n";
    return 0;
}
