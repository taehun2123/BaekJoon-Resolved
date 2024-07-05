#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, mn = INT_MAX;
int board[51][51];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickenStores;

int distanceTable[100][13]; // 최대 100개의 집과 13개의 치킨집

void precomputeDistances() {
    for (int i = 0; i < houses.size(); ++i) {
        for (int j = 0; j < chickenStores.size(); ++j) {
            distanceTable[i][j] = abs(houses[i].X - chickenStores[j].X) + abs(houses[i].Y - chickenStores[j].Y);
        }
    }
}

int calculateDistance(vector<int>& selected) {
    int totalDistance = 0;
    for (int i = 0; i < houses.size(); ++i) {
        int minDistance = INT_MAX;
        for (int idx : selected) {
            minDistance = min(minDistance, distanceTable[i][idx]);
        }
        totalDistance += minDistance;
    }
    return totalDistance;
}

void selectChicken(int start, vector<int>& selected) {
    if (selected.size() == m) {
        mn = min(mn, calculateDistance(selected));
        return;
    }
    for (int i = start; i < chickenStores.size(); ++i) {
        selected.push_back(i);
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

    precomputeDistances();

    vector<int> selected;
    selectChicken(0, selected);
    
    cout << mn;
    return 0;
}
