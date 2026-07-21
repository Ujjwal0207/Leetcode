class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right, int& count) {
        int j = mid + 1;

        // Count reverse pairs
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step (standard merge sort)
        vector<int> temp(right - left + 1);
        int i = left;
        j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while (i <= mid)
            temp[k++] = nums[i++];

        while (j <= right)
            temp[k++] = nums[j++];

        for (int t = 0; t < temp.size(); t++) {
            nums[left + t] = temp[t];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right, int& count) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid, count);
            mergeSort(nums, mid + 1, right, count);
            merge(nums, left, mid, right, count);
        }
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);
        return count;
    }
};
