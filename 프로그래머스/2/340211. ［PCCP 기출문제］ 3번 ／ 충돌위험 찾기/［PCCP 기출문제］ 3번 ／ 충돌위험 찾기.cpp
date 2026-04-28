#include <string>
#include <vector>
#include <map>
using namespace std;

vector<pair<int,int>> getPath(pair<int,int> from, pair<int,int> to){
    vector<pair<int,int>> result;
    int r = from.first, c = from.second;
    int tr = to.first,  tc = to.second;
    // 행 먼저
    while(r != tr){
        r += (tr > r) ? 1 : -1;
        result.push_back({r, c});
    }
    // 열 나중
    while(c != tc){
        c += (tc > c) ? 1 : -1;
        result.push_back({r, c});
    }
    return result;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int cnt = 0;
    vector<vector<pair<int,int>>> timeline(routes.size());

    for(int i = 0; i < (int)routes.size(); i++){
        timeline[i].push_back({points[routes[i][0]-1][0], points[routes[i][0]-1][1]});
        for(int j = 0; j+1 < (int)routes[i].size(); j++){
            pair<int,int> from = {points[routes[i][j]-1][0],   points[routes[i][j]-1][1]};
            pair<int,int> to   = {points[routes[i][j+1]-1][0], points[routes[i][j+1]-1][1]};
            auto seg = getPath(from, to);
            for(auto& pos : seg) timeline[i].push_back(pos);
        }
    }

    int maxTime = 0;
    for(auto& t : timeline) maxTime = max(maxTime, (int)t.size());

    for(int t = 0; t < maxTime; t++){
        map<pair<int,int>, int> posCount;
        for(int i = 0; i < (int)routes.size(); i++){
            if(t >= (int)timeline[i].size()) continue;
            posCount[timeline[i][t]]++;
        }
        for(auto& [pos, n] : posCount){
            if(n >= 2) cnt++;
        }
    }
    return cnt;
}