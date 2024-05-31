import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < t; i++) {
            String[] hwn = br.readLine().split(" ");
            int h = Integer.parseInt(hwn[0]);
            int w = Integer.parseInt(hwn[1]);
            int n = Integer.parseInt(hwn[2]);

            int floor = (n - 1) % h + 1;
            int room = (n - 1) / h + 1;

            System.out.printf("%d%02d\n", floor, room);
        }
    }
}
