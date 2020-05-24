Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
        
        
#Code

vector<vector<int> > Solution::generateMatrix(int n) {
    int t=0,l=0,r=n-1,b=n-1;
    int d=0,count=1;
    vector<vector<int> >a(n,vector<int>(n));
    while(t<=b&&l<=r){
        if(d==0){
            for(int i=l;i<=r;i++){
                a[t][i]=count;
                count++;
            }
            d=1;
            t++;
        }
        else if(d==1){
            for(int i=t;i<=b;i++){
                a[i][r]=count;
                count++;
            }
            d=2;
            r--;
        }
        else if(d==2){
            for(int i=r;i>=l;i--){
                a[b][i]=count;
                count++;
            }
            d=3;
            b--;
        }
        else if(d==3){
            for(int i=b;i>=t;i--){
                a[i][l]=count;
                count++;
            }
            d=0;
            l++;
        }
    }
    return a;
}
