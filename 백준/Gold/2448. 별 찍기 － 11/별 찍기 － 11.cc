#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pb push_back
#define pii pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define elif else if
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;
int n;
char board[3100][6200];

/*
 *    *
 *   * *
 *  *****
 */
void fill_star(const int& x, const int& y) {
    board[x][y] = '*';
    board[x + 1][y - 1] = '*', board[x + 1][y + 1] = '*';

    for (int i = y - 2; i <= y + 2; ++i) {
        board[x + 2][i] = '*';
    }
}

void func(const int& s, const int& x, const int& y) {
    if (s == 3) { // n은 항상 3 * 2^k 수 == 3이 최소값
        fill_star(x, y);
        return;
    }

    int ns = s / 2; //3
    func(ns, x, y); //3, 0, 5 - 위쪽 작은 삼각형
    func(ns, x + ns, y - ns); //3, 3, 2 //왼쪽 아래 작은 삼각형
    func(ns, x + ns, y + ns); //3, 3, 8 //오른쪽 아래 작은 삼각형
    /*
                 * - 여기 하나
                * *
               *****
    여기 하나 - *     * - 여기 하나
             * *   * *
            ***** *****
     */
}

int main() {
    io;

    cin >> n; //만약 n이 6이라고 가정 - 재귀는 항상 가장 작은 형태에서 부터 생각 한다.
    func(n, 0, n - 1); //6 0 5
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            if (board[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << "\n";
    }
}