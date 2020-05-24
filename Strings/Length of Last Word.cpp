Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

#Code

int Solution::lengthOfLastWord(const string A) {
    int length = 0;
    for(int i = A.size()-1 ; i >=0; i--){
        char c = A[i];
        if(isspace(c)){
            if(length != 0){
                return length;
            }
            else{
                length = 0;    
            }
        }
        else{
            length++;    
        }
    }
    
    return length;
}
