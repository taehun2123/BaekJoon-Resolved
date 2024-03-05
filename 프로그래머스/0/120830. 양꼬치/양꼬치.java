class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        int cal = n * 12000 + k * 2000 ;
        if(n/10 >= 1){
            cal -= ((n/10) * 2000);
        }
        answer = cal;
        return answer;
    }
}