class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size(),total=0,c,sum;
        for(int i=0;i<n;i++)
        {
            c=2;
            sum= nums[i] +1;
            for(int j=2;j<=(nums[i]/2);j++)
             {
                if(c==5)  break;
                if(nums[i] % j ==0) 
                {
                    sum+= j;
                    c++;
                }
             }
            if(c==4) total+=sum;
         }
        return total;
    }
};