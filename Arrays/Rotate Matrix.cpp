You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]

#Code

void Solution::rotate(vector<vector<int> > &nums) {
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            swap(nums[i][j],nums[j][i]);
        }
    }
    for(auto &row:nums){
        reverse(row.begin(),row.end());
    }
}
