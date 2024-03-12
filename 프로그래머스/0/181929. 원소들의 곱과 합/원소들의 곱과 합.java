class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        int sum = 0;
        int gob = 1;
        for(int num: num_list){
            sum += num;
            gob *= num;
        }
        if(gob < Math.pow(sum,2)){
            answer = 1;
        } else {
            answer = 0;
        }
        return answer;
    }
}