class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr,ans;

        for(int i=n-1;i>=0;i--) arr.push_back(nums[i]);
        for(int i=0;i<n;i++)
           if(nums[i]>=0)
           ans.push_back(nums[(i + nums[i]) % n]);

           else
           ans.push_back(arr[((n-i-1)+ abs(nums[i]))% n]);

           return ans;
    }
    
};