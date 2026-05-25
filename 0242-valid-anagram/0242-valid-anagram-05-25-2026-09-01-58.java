class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        int[] charFreq = new int[26];
        
        for (int i=0; i < s.length(); i++) {
            charFreq[s.charAt(i)-'a'] = charFreq[s.charAt(i)-'a'] + 1;
            charFreq[t.charAt(i)-'a'] = charFreq[t.charAt(i)-'a'] - 1;
        }

        for (int i=0; i < 26; i++) {
            if (charFreq[i] != 0) {
                return false;
            }
        }

        return true;
    }
}