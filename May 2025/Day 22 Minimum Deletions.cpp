/*
    Minimum Deletions to make a string palindrome
    https://practice.geeksforgeeks.org/problems/minimum-deletions-1587115620/1

    Problem Statement:
    Given a string s, the task is to find the minimum number of characters you need to delete from s so that the resulting string is a palindrome.
    A palindrome is a string that reads the same backward as forward. For example, "racecar" and "madam" are palindromes, while "hello" and "world" are not.
   
    Task: Given a string s, find the minimum number of characters you need to delete from s so that the resulting string is a palindrome.

    Approach:
    Top Down DP:
    1. Create a 2D array t of size n x n, where n is the length of the string s.
    2. Initialize all elements of t to -1.
    
    3. Define a recursive function solve(s, i, j) that takes the string s and two indices i and j as input.
    4. If i >= j, return 0, as no deletions are needed.
    5. If t[i][j] is not -1, return t[i][j], as the result has already been computed.
    6. If s[i] == s[j], call solve(s, i+1, j-1) and store the result in t[i][j].
    7. If s[i] != s[j], call solve(s, i+1, j) and solve(s, i, j-1), and take the minimum of the two results, adding 1 to account for the deletion.
    8. Store the result in t[i][j] and return it.
    9. In the main function, call solve(s, 0, n-1) to get the minimum number of deletions needed to make the string a palindrome.
    10. Return the result.

    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
    where n is the length of the string s.
*/


class Solution {
  public:
    int t[1001][1001];
    int solve(string& s, int i, int j){
        if(i >= j) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        if(s[i] == s[j]) return t[i][j] = solve(s, i+1, j-1);
        
        return t[i][j] = 1 + min(solve(s, i+1, j), solve(s, i, j-1));
    }
    int minDeletions(string s) {
        // code here
        
        int n = s.length();
        
        memset(t, -1, sizeof(t));
        
        vector<vector<int>> dp(n+1, )
        
        return solve(s, 0, n-1);
        
    }
};


?/*
    Bottom Up DP:
    1. Create a 2D array dp of size n x n, where n is the length of the string s.
    2. Initialize all elements of dp to 0.
    3. Iterate through the string s in reverse order, starting from the last character.
    4. For each character s[i], iterate through the string from i to n-1.
    5. If s[i] == s[j], set dp[i][j] = dp[i+1][j-1].
    6. If s[i] != s[j], set dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]).
    7. The final result will be stored in dp[0][n-1], which represents the minimum number of deletions needed to make the string a palindrome.
    8. Return dp[0][n-1] as the final result.

    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
    where n is the length of the string s.
*/

class Solution {
  public:
    
    int minDeletions(string s) {
        
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=2; i<=n; i++){
            for(int j=0; j<= n-i; j++){
                int k = j + i - 1;
                if(s[j] == s[k]) dp[j][k] = dp[j+1][k-1];
                else dp[j][k] = 1 + min(dp[j+1][k], dp[j][k-1]);
            }
        }
        
        return dp[0][n-1];
        
    }

};