class Solution {
public:
    int characterReplacement(string s, int k) {
        int c[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            c[s[right] - 'A']++;
            if (c[s[right] - 'A'] > maxFreq) {
                maxFreq = c[s[right] - 'A'];
            }

            while ((right - left + 1) - maxFreq > k) {
                c[s[left] - 'A']--;
                left++;
            }

            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }

        return maxLen;
    }
};