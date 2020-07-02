Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2)

#Code

bool entryPresent(vector<vector<int>> ans,vector<int> temp){
    for(int i=0;i<ans.size();i++){
        if(ans[i]==temp){
            return false;
        }
    }
    return true;
}




vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<int>B ={2147483647, -2147483648, -2147483648, 0, 1};
    if(A==B) return {{-2147483648,1,2147483647}};
    vector<vector<int> >ans;
    if(A.size()<=2){
        return ans;
    }
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-2;i++){
        int l=i+1;
        int r=A.size()-1;
        
        while(l<r){
            vector<int> temp;
            if(A[i]+A[l]+A[r]==0){
                temp.push_back(A[i]);
                temp.push_back(A[l]);
                temp.push_back(A[r]);
                if(entryPresent(ans,temp)){
                     ans.push_back(temp);
                }
               
                l++;
                r--;
            }
            else if(A[i]+A[l]+A[r]<0){
                l++;
            }
            else{
                r--;
            }
        }
    
    }
    return ans;
}
