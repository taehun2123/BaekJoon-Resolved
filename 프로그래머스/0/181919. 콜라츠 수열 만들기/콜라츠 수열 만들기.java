import java.util.*;
class Solution {
    public int[] solution(int n) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();
        while(n > 0){
            list.add(n);
            if(n == 1){
                break;
            }
            if(n%2 == 0){
                n /= 2;
            } else {
                n = 3*n+1;
            }
        }
        answer = list.stream()
                .mapToInt(i->i)
                .toArray();
        return answer;
    }
}