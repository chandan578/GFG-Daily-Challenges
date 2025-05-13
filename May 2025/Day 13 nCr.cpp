
/*  
Problem Approach
The typical formula for nCr is:

However, directly computing factorials can cause integer overflow and is inefficient. Your code uses an iterative approach to compute nCr more efficiently:

It initializes a result variable (res) to 1.
Then, for each i from 0 to r-1, it multiplies res by (n - i) and divides by (i + 1).
This avoids computing large factorials and keeps intermediate results smaller.
This approach is mathematically equivalent to the formula above, but much more efficient and less prone to overflow for reasonable values of n and r.
*/
class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        
        if(r>n) return 0;
        if(r == 0 || n == r) return 1;
        
        if(r > n-r) r = n-r;
        
        long long res = 1;
        for(int i=0; i<r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        
        return (int)res;
    }
};

/*
Time Complexity
The loop runs r times.
Each iteration does a constant amount of work (multiplication and division).
So, the time complexity is O(r).
*/