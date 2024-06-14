#include <bits/stdc++.h>
using namespace std;
void hanoi(int start, int end, int n){
    if(n == 1){
        cout << start << ' ' << end << "\n";
        return;
    }
    hanoi(start, 6-start-end, n-1); // n-1 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
    cout << start << ' ' << end << '\n'; // n 원판을 기둥 a에서 b로 옮긴다.
    hanoi(6-start-end, end, n-1); // n-1원판을 기동 6-a-b에서 기동 b로 옮긴다.
}

void countHanoi(int n, int arr[]) // 2의 21승 이상인 경우
{
    arr[0] = 2;
    int carry = 0; // carry가 1이 되면 자리 올림
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
            arr[i] *= 2;
        for (int j = 0; j < i; j++)
        {
            arr[j] *= 2;
            arr[j] += carry;
            if (arr[j] >= 10) {
                carry = 1;
                arr[j] -= 10;
            }
            else
                carry = 0;
        }
    }

    arr[0] -= 1; // 1을 빼줌

    int start = 99;
    for (int i = 99; i > -1; i--)
    {
        if (arr[start] == 0) //시작부분을 구함
        {
            start--;
            continue;
        }

        cout << arr[i];
    }
}
int arr[100];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    if(K < 20){
        cout << (1<<K)-1;
    } else {
        countHanoi(K, arr);
    }
    if(K <= 20){
        cout << "\n";
        hanoi(1, 3, K);
    }
    return 0;
}
