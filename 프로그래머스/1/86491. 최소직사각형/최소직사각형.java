import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int widthMax = 0;
        int heightMax = 0;
        for(int[] item: sizes){
            int maxValue = Math.max(item[0], item[1]);
            int minValue = Math.min(item[0], item[1]);
            
            widthMax = Math.max(widthMax, maxValue);
            heightMax = Math.max(heightMax, minValue);
        }
        

        
        answer = widthMax * heightMax;
        return answer;
    }
}