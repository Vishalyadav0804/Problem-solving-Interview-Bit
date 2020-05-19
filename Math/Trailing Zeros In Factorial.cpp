Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1

#Code

int Solution::trailingZeroes(int A) {
    int sum=0;
    while(A!=0){
        sum=sum+(A/5);
        A=A/5;
    }
    return sum;
}
