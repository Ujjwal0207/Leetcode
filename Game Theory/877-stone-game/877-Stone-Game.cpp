class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int l = 0;
        int r = n-1;

        int sum_a =0;
        int sum_b =0;

        int flag = 1;

        while(l <= r){
            if(flag == 1){
                if(piles[l] >= piles[r]){
                    sum_a += piles[l];
                    l++;
                }

                else{
                    sum_a += piles[r];
                    r--;
                }
            }

            else{
                if(piles[l] >= piles[r]){
                    sum_b += piles[l];
                    l++;
                }

                else{
                    sum_b += piles[r];
                    r--;
                }
            }
        }

        if(sum_a > sum_b){
            return true;
        }

        return false;
    }
};