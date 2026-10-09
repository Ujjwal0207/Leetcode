class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                if (count % 2 == 1) {
                    count--;
                    ans++;
                }
                count += 2;
            }
            else {
                count--;

                if (count < 0) {
                    ans++;
                    count = 1;
                }
            }
        }

        return ans + count;
    }
};