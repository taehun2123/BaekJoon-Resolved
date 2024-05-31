import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Character, Integer> map = new HashMap<>();
        int cnt = 0;
        char maxKey = ' ';
        char[] chArr = br.readLine().toUpperCase().toCharArray();
        Arrays.sort(chArr);
        for(char alpa : chArr){
            if(map.containsKey(alpa)){
                int value = map.get(alpa);
                map.replace(alpa, ++value);
            } else {
                map.put(alpa, 0);
            }
        }
        int maxValue = Collections.max(map.values());
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {  // Itrate through hashma
            if (entry.getValue() == maxValue) {
                maxKey = entry.getKey();
                cnt++;
            }
        }
        if(cnt == 1){
            System.out.println(maxKey);
        } else {
            maxKey = '?';
            System.out.println(maxKey);
        }
    }
    }