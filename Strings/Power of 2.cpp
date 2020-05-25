Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1

#Code

string divideBy2(string S)
{
    string ans;
    
    int n=S.length();
    int carry=0;
    int i=0;
    while(i<n)
    {
        int num=S[i]-'0';
        num=num+(carry*10);
        carry=num%2;
        int temp = num/2;
        ans.push_back(temp+'0');
        i++;
    }
    if(carry==1)
    {
        string t;
        t.push_back(carry+'0');
        return t;
    }
    
    while(ans.length()>0 && ans[0]=='0')
    {
        ans.erase(ans.begin());
    }
    
    return ans;
}
int Solution::power(string A) {
    if(A.length()==1 && A[0]=='1')
    {
        return 0;
    }
    
    string temp=A;
    
    while(temp.length()>0)
    {
        if(temp.length()==1 && temp[0]=='1')
        {
            break;
        }
        int n=temp.length();
        int t=temp[n-1]-'0';
        if(t%2!=0)
        {
            return 0;
        }
        
        temp=divideBy2(temp);
    }
    
    return 1;
}
