class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = startGene.size();

        queue<pair<string , int>>que;
        unordered_set<string> st(bank.begin(), bank.end());
        st.erase(startGene);

        que.push({startGene , 0});

        while(!que.empty()){
            string word = que.front().first;
            int step = que.front().second;

            que.pop();

            if(word == endGene){
                return step;
            }

            for(int i = 0;i<n;i++){
                char ch = word[i];

                for(char alp : {'A', 'C', 'G', 'T'}){
                    word[i] = alp;
                    if(st.find(word)!= st.end()){
                        st.erase(word);
                        que.push({word , step+1});
                    }
                }

                word[i] = ch;
            }
        }

        return -1;
    }
};