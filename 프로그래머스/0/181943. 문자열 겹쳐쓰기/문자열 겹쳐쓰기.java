class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        String start = my_string.substring(0, s);
        String end = my_string.substring(s + overwrite_string.length());
        return start + overwrite_string + end;
    }
}