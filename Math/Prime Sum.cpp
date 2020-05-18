
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

#Code

bool isPrime(int x){
    if(x<=1){
        return false;
    }
    if(x==2){
        return true;
    }
    if(x%2==0){
        return false;
    }
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> v;
    v.reserve(2);
    
    for(int i=2;i<=A;i++){
        if(isPrime(i) && isPrime(A-i)){
            v.push_back(i);
            v.push_back(A-i);
            return v;
        }
    }
    return v;
}
