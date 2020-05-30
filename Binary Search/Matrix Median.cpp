Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 ``` Matrix=
    
    
#Code

int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    int min=A[0][0],max=A[0][m-1];
    for(int i=0;i<n;i++){
        if(A[i][0]<min){
            min=A[i][0];
        }
        if(A[i][m-1]>max){
            max=A[i][m-1];
        }
    }
    int desired_element=(1+n*m)/2;
    while(min<max){
        int mid=(min+max)/2;
        int count=0;
        for(int i=0;i<n;i++){
            count+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        if(count<desired_element){
            min=mid+1;
        }else{
            max=mid;
        }
    }
    return min;
}
