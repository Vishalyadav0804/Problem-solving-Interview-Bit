Please Note:
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise.

#Code

bool isnum(char ch){
    return (ch>='0' && ch<='9')?true:false;
}
int Solution::atoi(const string A) {
    int i=0,sign=1,res=0;
    while(A[i]==' '){
        i++;
    }
    if(A[0] == '-' || A[0] == '+')
    {
        if(A[i++] == '-') 
            sign = -1;
        else 
            sign = 1;
    }
    while(isnum(A[i])){
        if(res>INT_MAX/10 || (res == INT_MAX/10 && A[i]-'0' > 7)){
            if(sign==1){
                return INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }
        res=res*10+(A[i]-'0');
        i++;
    }
    return sign*res;
}
