#include <bits/stdc++.h>
using namespace std;

int arr[10];        // 현재 순열을 저장할 배열
int init[10];       // 초기 입력 요소를 저장할 배열
bool isUsed[10];    // 순열에서 사용된 요소를 추적하기 위한 배열
int n, m;

void solved(int k) {
    if(k == m) {  // 기저 조건: k가 m과 같아지면 현재까지 만든 순열을 출력
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) { // 0부터 n-1까지 반복
        // 중복되지 않도록 처리:
        // 1. isUsed[i]가 false여야 함
        // 2. i가 0이거나 (즉, 첫 번째 요소)
        // 3. 또는 init[i]가 init[i-1]과 다르거나
        // 4. 또는 init[i]가 init[i-1]과 같은 경우 isUsed[i-1]가 true여야 함
        if(!isUsed[i] && i == 0 || init[i] != init[i - 1]) {
            arr[k] = init[i];  // 현재 요소를 순열에 추가
            isUsed[i] = true;  // 현재 요소를 사용함으로 표시
            solved(k + 1);     // 다음 위치에 대해 재귀 호출
            isUsed[i] = false; // 재귀 호출이 끝나면 현재 요소를 사용하지 않음으로 표시
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> init[i];
    }

    sort(init, init + n);

    solved(0);
    return 0;
}
