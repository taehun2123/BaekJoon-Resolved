import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] sp = br.readLine().split(" ");
        int sum = 0;
        for(int i = 0; i<sp.length; i++){
            sum += Integer.parseInt(sp[i]) * Integer.parseInt(sp[i]);
        }
        System.out.println(sum % 10);
    }
}