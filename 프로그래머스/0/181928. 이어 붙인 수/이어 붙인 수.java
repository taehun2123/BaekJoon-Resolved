class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        String even = "";
        String one = "";
        for(int num:num_list){
            if(num%2 == 0){
                even += (num+"");
            } else {
                one += (num+"");
            }
        }
        answer = Integer.parseInt(even) + Integer.parseInt(one);
        return answer;
    }
}