Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.



Input Format

The only argument given is string A.
Output Format

Return the string A after reversing the string word by word.
For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"
    
#Code

string Solution::solve(string A) {
    if(A.size()<=1){
        return A;
    }
    stack <string> tokens; 
    stringstream check1(A); 
      
    string intermediate; 
    while(getline(check1, intermediate, ' ')) 
    { 
        tokens.push(intermediate); 
    } 
    A.clear();
    while(!tokens.empty()){
        A+=tokens.top();
        A+=" ";
        tokens.pop();
    }
    int n=A.size()-1;
    A.erase(A.begin()+n);
    return A;
}
