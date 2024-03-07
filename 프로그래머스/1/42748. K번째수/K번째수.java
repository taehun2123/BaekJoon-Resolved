import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];

        for(int a = 0; a < commands.length; a++){
            ArrayList<Integer> list = new ArrayList<>();
            for(int i = commands[a][0]-1; i<commands[a][1]; i++){
                list.add(array[i]);
            }
            Collections.sort(list);
            answer[a] = list.get(commands[a][2]-1);
        }
        
        
        
        return answer;
    }
}