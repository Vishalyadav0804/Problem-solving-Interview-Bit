Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

#Code

int Solution::reverse(int A) {
    int reverse=0;
    while(A!=0){
        int lastdigit=A%10;
        int temp=lastdigit+reverse*10;
        if(temp/10!=reverse){
            return 0;
        }
        reverse=temp;
        A=A/10;
    }
    return reverse;
}
