You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].


#Code

vector<int> Solution::flip(string A) {
    int i,left=0,diff=0,max_diff=0;
    vector<int> v;
    for(i=0;i<A.size();i++){
        if(A[i]=='1'){
            diff--;
        }
        if(A[i]=='0'){
            diff++;
        }
        if(diff<0){
            diff=0;
            left=i+1;
        }
        if(diff>max_diff){
            v.clear();
            max_diff=diff;
            v.push_back(left+1);
            v.push_back(i+1);
        }
    }
    return v;
}
