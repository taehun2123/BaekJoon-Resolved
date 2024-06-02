import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int repeat = sc.nextInt();
        sc.nextLine();                          //입력 버퍼

        for(int i=0; i<repeat; i++){
            String arr1= sc.nextLine();
            String[] arr2 = arr1.split("");     //문자열 길이 안정해졌을때 사용하는 방법
            int sum=0;
            int score=0;

            if(arr2[0].equals("O")) {          //반복문 예외상황
                score++;
                sum+=score;
            }
            for(int j=1; j<arr2.length; j++){
                if(arr2[j].equals("O")){           //O일때
                    if(arr2[j-1].equals(arr2[j])) {//O 연속
                    score++;
                    sum += score;
                    }
                    else{                          //O 불연속
                        score=1;
                        sum+=score;
                    }
                }
                else score=0;                      //X일때
            }
            System.out.println(sum);
        }
    }
}