class Solution {
public:

    int f(vector<int>& nums, int target){
        int n=nums.size();
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        if(nums[0]==0) prev[0]=2;
        else prev[0]=1;
        if(nums[0]!=0&&target>=nums[0]) prev[nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=target;tar++){
                int notake=prev[tar];
                int take=0;
                if(tar>=nums[i]){
                    take=prev[tar-nums[i]];
                }
                curr[tar]=take+notake;
            }
            prev=curr;
        }
        return prev[target];
    }

    int partition(int n,int d,vector<int>& nums){
        int totalsum=0;
        for(auto it:nums){totalsum+=it;}
        if(totalsum-d<0||(totalsum-d)%2) return false;
        return f(nums,(totalsum-d)/2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return partition(n,target,nums);
    }
};