Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.


int Solution::diffPossible(vector<int> &A, int B) {
    if(A.size() == 0 || A.size() == 1){
        return 0;
    }
    int l=0,r=A.size()-1;
    while(l<r){
        if(A[r]-A[l]==B){
            return 1;
        }
        else if(A[r]-A[l]>B){
            r--;
        }else{
            l++;
        }
    }
    return 0;
}
