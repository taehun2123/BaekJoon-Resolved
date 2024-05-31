import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        String appendString = "";
        for(int i =0; i<input.length; i++){
            appendString += input[i].charAt(0);
        }
        if(appendString.equals("12345678")){
            System.out.println("ascending");
            return;
        } else if(appendString.equals("87654321")){
            System.out.println("descending");
            return;
        } else {
            System.out.println("mixed");
        }
    }
}
