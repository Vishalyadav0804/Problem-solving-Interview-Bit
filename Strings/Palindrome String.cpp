Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

#Code

bool isAlphaNumeric(char c){
    if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
     return true;
    return false;
}
int Solution::isPalindrome(string A) {
    int i=0;
    int j=A.size();
    while(i<=j){
        if(!isAlphaNumeric(A[i])){
         i++;
         continue;
        }
        if(!isAlphaNumeric(A[j])){
         j--;
         continue;
        }
        if(A[i]!=A[j] && abs(A[i]-A[j])!=32)
         return 0;
        
        i++;j--;
    }
    return 1;
}
