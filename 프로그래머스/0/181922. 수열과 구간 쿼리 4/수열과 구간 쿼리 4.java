class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        int[] answer = {};
        
        for(int[] query: queries){
            for(int i = query[0]; i<query[1]+1; i++){
                if(i%query[2] == 0){
                    arr[i]++;
                }
            }
        }
        return arr;
    }
}