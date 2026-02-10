class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int j=0,n=nums.size();

        if(n<k) k = k % n;
        for(int i= n-k ;j<n;j++)
        {
            ans.push_back(nums[i % n]);
            i++;
        }

        for(int i=0;i<n;i++) nums[i] = ans[i];
    }
};