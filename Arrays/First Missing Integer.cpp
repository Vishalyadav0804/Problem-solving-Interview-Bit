Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

#Code

int Solution::firstMissingPositive(vector<int> &nums) {
    int n=nums.size();
        bool one=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one=true;
            }
        }
        if(!one){
            return 1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            int idx=abs(nums[i]);
            if(idx<n){
                nums[idx]=-(abs(nums[idx]));
            }else{
                nums[0]=-(abs(nums[0]));
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]>0)
                return i;
        }
        if(nums[0]>0)
            return n;
        return n+1;
}
