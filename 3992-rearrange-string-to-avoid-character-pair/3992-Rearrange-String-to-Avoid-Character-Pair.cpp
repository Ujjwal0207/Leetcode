class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        // Add all characters except x and y
        for (char c = 'a'; c <= 'z'; c++) {
            if (c == x || c == y) continue;

            while (freq[c - 'a']--) {
                ans += c;
            }
        }

        // Add all y
        while (freq[y - 'a']--) {
            ans += y;
        }

        // Add all x
        while (freq[x - 'a']--) {
            ans += x;
        }

        return ans;
    }
};