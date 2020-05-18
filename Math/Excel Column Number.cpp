Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
    
    #Code
    
    
    int Solution::titleToNumber(string A) {
    int sum=0,j=0;
    for(int i=A.size()-1;i>=0;i--){
        sum=sum+(A[i]-'A'+1)*pow(26,j);
        j++;
    }
    return sum;
}
