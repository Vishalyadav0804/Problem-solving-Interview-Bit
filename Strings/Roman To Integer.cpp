Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more
details about roman numerals at Roman Numeric System



Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
    
#Code

int Solution::romanToInt(string s) {
    int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                if(s[i+1]=='V' || s[i+1]=='X'){
                    res--;
                }else{
                    res++;
                }
            }
            if(s[i]=='V'){
                res+=5;
            }
            if(s[i]=='X'){
                if(s[i+1]=='L' || s[i+1]=='C'){
                    res-=10;
                }else{
                    res+=10;
                }
            }
            if(s[i]=='L'){
                res+=50;
            }
            if(s[i]=='C'){
                if(s[i+1]=='D' ||s[i+1]=='M'){
                    res-=100;
                }else{
                    res+=100;
                }
            }
            if(s[i]=='D'){
                res+=500;
            }
            if(s[i]=='M'){
                res+=1000;
            }
        }
        return res;
}
