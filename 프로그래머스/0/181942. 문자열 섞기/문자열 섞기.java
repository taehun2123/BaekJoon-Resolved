import java.util.ArrayList;

class Solution {
    public String solution(String str1, String str2) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<str1.length()+str2.length(); i++){
            if(i < str1.length()){
                sb.append(str1.charAt(i));
            }
            if(i < str2.length()){
                sb.append(str2.charAt(i));
            }
        }
        answer = sb.toString();
        return answer;
    }
}