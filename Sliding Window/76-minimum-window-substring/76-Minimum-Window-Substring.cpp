class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int k = t.size();

        if (k > n) {
            return "";
        }

        int count = k;
        int mini = n + 1;
        int start = 0;

        unordered_map<char, int> mp;

        for (auto it : t) {
            mp[it]++;
        }

        int i = 0;
        int j = 0;

        while (j < n) {
            if (mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;

            while (count == 0) {
                int current_size = j - i + 1;

                if (mini > current_size) {
                    mini = current_size;
                    start = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count++;
                }

                i++;
            }

            j++;
        }

        if (mini == n + 1) return "";

        return s.substr(start, mini);
    }
};