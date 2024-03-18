import java.util.*;
class Solution {
    public String solution(String my_string, int[][] queries) {
        for(int[] query: queries){
            String back = "";
            for(int i = query[1]; i>=query[0]; i--){
                back += my_string.charAt(i);
            }
            String start = my_string.substring(0, query[0]);
            String end = my_string.substring(query[1]+1);
            my_string = start + back + end;
        }
        return my_string;
    }
}