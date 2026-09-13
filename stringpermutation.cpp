class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) {
            return false;
        }

        int count1[26] = {0};
        int count2[26] = {0};

        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        bool match = true;
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                match = false;
                break;
            }
        }
        if (match) return true;

        for (int i = n1; i < n2; i++) {
            count2[s2[i] - 'a']++;
            count2[s2[i - n1] - 'a']--;

            bool same = true;
            for (int j = 0; j < 26; j++) {
                if (count1[j] != count2[j]) {
                    same = false;
                    break;
                }
            }
            if (same) return true;
        }

        return false;
    }
};