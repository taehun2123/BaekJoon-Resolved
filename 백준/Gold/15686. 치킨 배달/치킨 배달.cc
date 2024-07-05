#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, mn = INT_MAX;
int board[51][51];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickenStores;

int calculateDistance(vector<pair<int, int>>& selected) {
    int totalDistance = 0;
    
    for (auto house : houses) {
        int minDistance = INT_MAX;
        for (auto store : selected) {
            int distance = abs(house.X - store.X) + abs(house.Y - store.Y);
            minDistance = min(minDistance, distance);
        }
        totalDistance += minDistance;
    }
    return totalDistance;
}

void selectChicken(int start, vector<pair<int, int>>& selected) {
    if (selected.size() == m) {
        mn = min(mn, calculateDistance(selected));
        return;
    }
    for (int i = start; i < chickenStores.size(); ++i) {
        selected.push_back(chickenStores[i]);
        selectChicken(i + 1, selected);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                houses.push_back({i, j});
            } else if (board[i][j] == 2) {
                chickenStores.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> selected;
    selectChicken(0, selected);
    
    cout << mn;
    return 0;
}
