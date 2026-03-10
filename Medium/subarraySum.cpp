class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;

        map<int,int>mp;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int rem =sum - k;
            if(mp.find(rem) != mp.end() )  cnt += mp[rem];
            mp[sum]++;
        }

        return cnt;
    }
};