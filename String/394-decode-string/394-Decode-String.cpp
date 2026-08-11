class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr = "";
        int num = 0;

        for(char ch : s) {

            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if(ch == '[') {
                nums.push(num);
                strs.push(curr);

                num = 0;
                curr = "";
            }

            else if(ch == ']') {
                int k = nums.top();
                nums.pop();

                string prev = strs.top();
                strs.pop();

                string temp = "";

                while(k--) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            else {
                curr += ch;
            }
        }

        return curr;
    }
};