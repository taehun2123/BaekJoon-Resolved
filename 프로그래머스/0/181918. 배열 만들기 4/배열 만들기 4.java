import java.util.*;
class Solution {
    public int[] solution(int[] arr) {
        int[] stk = {};
        int num = 0;
        ArrayList<Integer> list = new ArrayList<>();
        while(arr.length > num){
            if(list.isEmpty()){
                list.add(arr[num]);
                num++;
            } 
            else if(list.get(list.size()-1) < arr[num]){
                list.add(arr[num]);
                num++;
            }
            else if(list.get(list.size()-1) >= arr[num]){
                list.remove(list.size()-1);
            }
        }
        stk = list.stream()
            .mapToInt(i->i)
            .toArray();
        return stk;
    }
}