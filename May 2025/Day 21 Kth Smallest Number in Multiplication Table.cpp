/*
    Kth Smallest Number in Multiplication Table
    https://www.geeksforgeeks.org/kth-smallest-number-in-multiplication-table/

    
    Problem Explanation
    Kth Smallest Number in Multiplication Table
    Given two integers m and n, you have an m x n multiplication table where the value at cell (i, j) is (i+1)*(j+1).
    You are asked to find the k-th smallest number in this table.

    Approach : Brute Force
    Idea:
    Generate all values in the multiplication table, store them in a list, sort the list, and return the k-th smallest element.
    Implementation:
    Loop through all i from 1 to m and j from 1 to n, compute (i)*(j), and store in a vector.
    Sort the vector.
    Return the element at index k-1.
    Time Complexity:
    Generating all values: O(m * n)
    Sorting: O(m * n * log(m * n))
    Total: O(m * n * log(m * n))
    Space Complexity: O(m * n) (for storing all values)

    But it gives TLE for large inputs.
    So move to the next approach.
*/

class Solution {
  public:
    int kthSmallest(int m, int n, int k) {        
        vector<int> ans; 
        
        // Generate all values in the multiplication table
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans.push_back((i+1)*(j+1)); // (i+1)*(j+1) is the value at cell (i, j)
            }
        }
        // Sort the vector
        sort(ans.begin(), ans.end());
        int value = ans[k-1]; // Return the k-th smallest element
        
        return value;
    }
};

/*
    Optimal Approach : Binary Search
    Idea:
    The multiplication table is sorted in a specific way. 
    The i-th row is sorted, and the j-th column is also sorted.
    We can use binary search to find the k-th smallest element.
    
    Implementation:
    Set low = 1 and high = m*n (the maximum value in the table).
    While low < high:
        Compute mid = (low + high) / 2.
        Count how many numbers are less than or equal to mid in the multiplication table.
        If count < k, set low = mid + 1; otherwise, set high = mid.
    Return low (which will be the k-th smallest number).
    
    Time Complexity:
    Counting numbers: O(m * log(n))
    Binary search: O(log(m * n))
    Total: O(m * log(n) + log(m * n)) ~ O(m * log(n))
    
    Space Complexity: O(1) (no extra storage except variables)
    Note: This approach is more efficient than the brute force method.
    
*/

class Solution {
  public:
    int kthSmallest(int m, int n, int k) {        
        int low = 1;
        int high = m*n;
        
        while(low < high){
            int mid = low + (high - low)/2;
            
            int count = 0;
            for(int i=1; i<=m; i++){
                count += min(mid/i, n);
            }
            
            if(count < k) low = mid+1;
            else high =  mid;
        }
        
        return low;
    }
};



// Happy Coding