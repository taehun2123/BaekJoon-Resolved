import java.util.*;
class Solution {
    public String solution(int[] numLog) {
        String answer = "";
        ArrayList<Character> list = new ArrayList<>();
        for(int i = 0; i<numLog.length-1; i++){
            if(numLog[i]+1 == numLog[i+1]){
                list.add('w');
            } else if(numLog[i]-1 == numLog[i+1]){
                list.add('s');
            } else if(numLog[i]+10 == numLog[i+1]){
                list.add('d');
            } else {
                list.add('a');
            }
        }
        StringBuilder builder = new StringBuilder(list.size());
        for(Character ch: list)
        {
            builder.append(ch);
        }
        return builder.toString();
    }
}