import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main{
        public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Integer, Integer> map = new HashMap<>();
        int gob = 1;
        for(int i =0; i<3; i++){
            gob *= Integer.parseInt(br.readLine());
        }
        String strNum = Integer.toString(gob);
        int[] arrNum = new int[strNum.length()];
        for(int i = 0; i<strNum.length(); i++){
            arrNum[i] = strNum.charAt(i) - '0';
        }
        map.put(0, 0);
        map.put(1, 0);
        map.put(2, 0);
        map.put(3, 0);
        map.put(4, 0);
        map.put(5, 0);
        map.put(6, 0);
        map.put(7, 0);
        map.put(8, 0);
        map.put(9, 0);

        for(int num : arrNum){
            if(map.containsKey(num)){
                int value = map.get(num);
                map.replace(num, ++value);
            }
        }
        for(int i = 0; i<10; i++){
            System.out.println(map.get(i));
        }
    }
}