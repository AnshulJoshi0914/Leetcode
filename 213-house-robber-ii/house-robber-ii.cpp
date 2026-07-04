class Solution {
public:

    int hr1(vector<int>& NUMS){
        int prev2=0;
        int prev=NUMS[0];
        int n=NUMS.size();

        for(int i=1;i<n;i++){
            int take=NUMS[i];
            take+=prev2;
            int notake=0+prev;
            int curi=max(take,notake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1(n);
        vector<int> temp2(n);
        
        if(n==1)  return nums[0];
        for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(hr1(temp1),hr1(temp2));
    }
};