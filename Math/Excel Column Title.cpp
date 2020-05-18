Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    
#Code

string Solution::convertToTitle(int A) {
    string map="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans;
    while(A>0){
        A=A-1;
        int rem=A%26;
        ans=map[rem]+ans;
        A=A/26;
    }
    return ans;
}
