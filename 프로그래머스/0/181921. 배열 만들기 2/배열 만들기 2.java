import java.util.*;
class Solution {
    public int[] solution(int l, int r) {
        int[] answer = {-1};
        ArrayList<Integer> list = new ArrayList<>();
        int count = 0;
        for(int i = l; i<=r; i++){
            String strNum = String.valueOf(i);
            int checkPoint = 0;
            for(int j = 0; j<strNum.length(); j++){
                if(strNum.charAt(j) == '0' || strNum.charAt(j) == '5'){
                    checkPoint++;
                }
            }
            if(checkPoint == strNum.length()){
                list.add(i);
                count++;
            }
        }
        if(count == 0){
            return answer;
        }
        answer = list.stream()
                .mapToInt(i -> i)
                .toArray();
        
        return answer;
    }
}