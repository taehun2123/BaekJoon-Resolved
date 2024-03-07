import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> list = new ArrayList<>();
        
        int last = arr[0];
        list.add(last);
        
        for(int i = 0; i < arr.length; i++){
            if(arr[i] != last){
                list.add(arr[i]);
                last = arr[i];
            }
        }
        
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        

        return answer;
    }
}