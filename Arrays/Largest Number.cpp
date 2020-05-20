Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

#Code

bool compare(string X,string Y){
        string XY=X.append(Y);
        string YX=Y.append(X);
        if(XY>YX){
            return 1;
        }
        return 0;
}
string Solution::largestNumber(const vector<int> &nums) {
        vector<string> v;
        string ans="";
        if(nums.size()==0){
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));    
        }
        sort(v.begin(),v.end(),[this] (string X, string Y) {
    return compare(X, Y); });
        for(int i=0;i<v.size();i++){
            ans+=v[i];
        }
        while(ans[0]=='0'){
            ans.erase(ans.begin());
        }
        if(ans.size()==0){
            return "0";
        }
        return ans;
}
