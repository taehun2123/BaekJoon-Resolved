class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        // Calculate the end index for the replacement
        int end = s + overwrite_string.length();

        // Ensure we don't exceed the original string's bounds
        if (end > my_string.length()) {
            end = my_string.length();
        }

        // Create the new string
        String answer = my_string.substring(0, s) + overwrite_string + my_string.substring(end);

        return answer;
    }
}