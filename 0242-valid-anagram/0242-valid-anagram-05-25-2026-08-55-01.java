class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> charFreq = new HashMap<>();
        
        for (int i=0; i < s.length(); i++) {
            charFreq.put(s.charAt(i), charFreq.getOrDefault(s.charAt(i), 0)+1);
            charFreq.put(t.charAt(i), charFreq.getOrDefault(t.charAt(i), 0)-1);
        }

        for (Character ch: charFreq.keySet()) {
            if (charFreq.get(ch) != 0) {
                return false;
            }
        }

        return true;
    }
}