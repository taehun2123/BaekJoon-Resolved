import java.util.*;
class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();
        for(int num: num_list){
            list.add(num);
        }
        if(list.get(list.size()-1) > list.get(list.size()-2)){
            int last = list.get(list.size()-1) - list.get(list.size()-2);
            list.add(last);
        } else {
            int last = list.get(list.size()-1) * 2;
            list.add(last);
        }
        answer = list.stream()
                .mapToInt(i -> i)
                .toArray();        
        return answer;
    }
}