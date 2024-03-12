class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        int temp;
        for(int[] query:queries){
            temp = arr[query[0]];
            arr[query[0]] = arr[query[1]];
            arr[query[1]] = temp;
        }
        return arr;
    }
}