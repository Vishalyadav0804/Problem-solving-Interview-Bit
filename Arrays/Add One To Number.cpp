Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

#Code

vector<int> Solution::plusOne(vector<int> &A) {
    int add=1;
    for(int i=A.size()-1;i>=0;i--){
        int x=A[i]+add;
        if(x/10==1){
            add=1;
        }else{
            add=0;
        }
        A[i]=x%10;
    }
    if(add==1){
        A.insert(A.begin(),add);
    }
    while(A[0]==0){
        A.erase(A.begin());
    }
    return A;
}
