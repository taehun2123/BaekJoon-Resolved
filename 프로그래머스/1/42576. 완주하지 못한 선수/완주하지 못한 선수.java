import java.util.HashMap;
import java.util.Map;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> map = new HashMap<>();
        
        // 각 참가자의 등장 횟수를 카운트합니다.
        for(String p : participant) {
            map.put(p, map.getOrDefault(p, 0) + 1);
        }
        
        // 완주한 참가자의 등장 횟수를 감소시킵니다.
        for(String c : completion) {
            map.put(c, map.get(c) - 1);
        }
        
        // 등장 횟수가 0보다 큰 참가자를 찾습니다.
        for(String key : map.keySet()) {
            if(map.get(key) > 0) {
                answer = key;
                break;
            }
        }
        
        return answer;
    }
}