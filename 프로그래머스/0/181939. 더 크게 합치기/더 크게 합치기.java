class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        StringBuilder sb = new StringBuilder();
        sb.append(a);
        sb.append(b);
        int sumAb = Integer.parseInt(sb.toString());
        StringBuilder sbba = new StringBuilder();
        sbba.append(b);
        sbba.append(a);
        int sumBa = Integer.parseInt(sbba.toString());
        
        if( sumAb > sumBa || sumAb == sumBa) {
            answer = sumAb;
        } else {
            answer = sumBa;
        }
        return answer;
    }
}