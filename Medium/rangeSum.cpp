class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;
        int sum = 0, ans = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++)
        {
            sum = nums[i];
            temp.push_back(sum);   // push single element sum

            for(int j = i + 1; j < n; j++)
            {
                sum += nums[j];   // FIX: use nums[j], not nums[i]
                temp.push_back(sum);
            }
        }

        sort(temp.begin(), temp.end());   // REQUIRED step

        for(int i = left - 1; i <= right - 1; i++)   // FIX: 0-based index
            ans = (ans + temp[i]) % MOD;

        return ans;
    }
};