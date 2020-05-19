Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003

#Code

#define mod 1000003
int Solution::findRank(string A) {
    int n=A.size();
    int ans=0,count=0;
    long long int fact[n];
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i]=((fact[i-1])%mod*(i % mod))%mod;
    }
    for(int i=0;i<A.size();i++){
        count=0;
        for(int j=i+1;j<A.size();j++){
            if(A[j]<A[i]){
                count++;
            }
        }
        ans= (ans + count *fact[A.size()-i-1]%mod)%mod;
    }
    return (ans+1)%mod;
}
