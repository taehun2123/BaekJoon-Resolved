import java.util.*;
class Solution {
    public int[] solution(int[] num_list, int n) {
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i<num_list.length; i+=n){
            list.add(num_list[i]);
        }
        int[] arr = list.stream()
        .mapToInt(Integer::intValue)
    	.toArray();        
        return arr;
    }
}