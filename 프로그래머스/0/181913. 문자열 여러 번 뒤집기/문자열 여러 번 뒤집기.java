import java.util.*;
class Solution {
    public String solution(String my_string, int[][] queries) {
        for(int[] query: queries){
            String back = "";
            for(int i = query[1]; i>=query[0]; i--){ //역순으로 String 변수에 삽입
                back += my_string.charAt(i);
            }
            String start = my_string.substring(0, query[0]); //0 ~ query[0]까지 문자열
            String end = my_string.substring(query[1]+1); // query[1] ~ 끝까지 문자열
            my_string = start + back + end; // 결합
        }
        return my_string;
    }
}