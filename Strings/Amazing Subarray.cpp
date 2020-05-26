You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

Input

Only argument given is string S.
Output

Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
Constraints

1 <= length(S) <= 1e6
S can have special characters
Example

Input
    ABEC

Output
    6

Explanation
	Amazing substrings of given string are :
	1. A
	2. AB
	3. ABE
	4. ABEC
	5. E
	6. EC
	here number of substrings are 6 and 6 % 10003 = 6.


#Code

int Solution::solve(string A) {
    int count = 0;
    int N = A.length();
    for (size_t i = 0; i < N; ++i) {
        if (A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u' || A[i]=='A' 
        || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U') {
            count += N - i;
        }
    }
    return count%10003;
}
