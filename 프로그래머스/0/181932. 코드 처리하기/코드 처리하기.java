import java.util.*;
class Solution {
    public String solution(String code) {
        String answer = "";
        int mode = 0;
        ArrayList<Character> list = new ArrayList<>();
        for (int i = 0; i < code.length(); i++) {
            if (code.charAt(i) == '1') {
                mode = (mode == 0) ? 1 : 0;
            } else {
                if ((mode == 0 && i % 2 == 0) || (mode == 1 && i % 2 == 1)) {
                    list.add(code.charAt(i));
                }
            }
        }
        for (char c : list) {
            answer += c + "";
        }
                    
        answer = list.isEmpty() ? "EMPTY" : answer;
        return answer;
    }
}