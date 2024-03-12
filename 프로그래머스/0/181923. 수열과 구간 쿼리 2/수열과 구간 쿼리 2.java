import java.util.*;
class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        int[] answer = {};
        ArrayList<Integer> result = new ArrayList<>();
        for(int[] query:queries){
            ArrayList<Integer> list = new ArrayList<>();
            for(int i = query[0]; i<=query[1]; i++){
                if(arr[i] > query[2])
                    list.add(arr[i]);
            }
            Collections.sort(list);
            if(list.isEmpty()){
                result.add(-1);
            } else {
                result.add(list.get(0));
            }
        }
        answer = result.stream()
            .mapToInt(i -> i)
            .toArray();
        return answer;
    }
}