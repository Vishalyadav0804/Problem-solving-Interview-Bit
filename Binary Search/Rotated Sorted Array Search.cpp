Given an array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return index of B in array A, otherwise return -1
Constraints

1 <= N <= 1000000
1 <= A[i] <= 10^9
all elements in A are disitinct.
For Example

Input 1:
    A = [4, 5, 6, 7, 0, 1, 2, 3]
    B = 4
Output 1:
    0
Explanation 1:
 Target 4 is found at index 0 in A.


Input 2:
    A = [5, 17, 100, 3]
    B = 6
Output 2:
    -1
    
    
#Code


int binarysearch(vector<int> nums,int l,int r,int target){
    if(l>r)
        return -1;
    int mid=(l+r)/2;
    if(nums[mid]==target)
        return mid;
    if(nums[l]<=nums[mid]){
        if(target>=nums[l] && target<=nums[mid]){
            return binarysearch(nums,l,mid-1,target);
        }
        else
            return binarysearch(nums,mid+1,r,target);
    }
    if(target>=nums[mid] && target<=nums[r])
        return binarysearch(nums,mid+1,r,target);
    return binarysearch(nums,l,mid-1,target);
}
int Solution::search(const vector<int> &A, int B) {
    int n=A.size();
    int res=binarysearch(A,0,n-1,B);
    return res;
}
