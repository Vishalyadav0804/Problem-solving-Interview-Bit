Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

#Code

vector<vector<int> > Solution::diagonal(vector<vector<int> > &vect) {
    vector<vector<int>> res;
    int x=vect.size();
    vector<int> v[2*x-1];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            v[i+j].push_back(vect[i][j]);
        }
    }
    for(auto x:v){
        res.push_back(x);
    }
    
    return res;
}
