#include <string>
#include <vector>

using namespace std;

//현재 퍼즐의 난이도 : diffs
//현재 퍼즐의 소요 시간 : time_cur
//이전 퍼즐의 소요 시간 : time_prev
//숙련도 : level <- 최솟값 = answer
//diffs[i]는 i번째 퍼즐의 난이도, times[i]는 i번째 퍼즐의 소요 시간입니다.
//diffs[0] = 1
// diff <= level == answer = time_cur
// diff > level == answer = (time_cur + time_prev)*(diff-level) + (time_cur)

long long calc_time(vector<int>& diffs, vector<int>& times, int level){
        long long used_time = 0;
        for(int j = 0; j< diffs.size(); j++){
            if(diffs[j] <= level) used_time += times[j];
            else {
                used_time += ((times[j]+times[j-1])*(diffs[j] - level) + times[j]);
            }
        }
        return used_time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int start = 1;
    int end = 100000;
    int answer = 100000;
    while(start <= end){
        int mid = (start + end) / 2;
        
        if (calc_time(diffs, times, mid) <= limit) {
            answer = mid;
            end = mid - 1; 
        } else {
            start = mid + 1; 
        }
    }
    
    return answer; // level
}