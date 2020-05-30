Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.


#Code

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    long long int base =x ,ans=1;
     while(n>0) 
    {
        if(n%2==1)
        {
            ans=(ans*base)%d;
            n--;
        } 
        else
        {
            base = (base * base) % d;
            n/=2;
        }
    }
   if (ans < 0) 
        ans = (ans + d) % d;
  return ans ;
}
