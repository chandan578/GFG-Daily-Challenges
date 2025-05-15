
/// brute force using 2 loops in O(n^2) time and O(1) space
class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        
        int n = s.length();
        
        int count = n; // count the single character substrings
        for(int i=0; i<n-1; i++){ // for each character
            // for each character, check the number of substrings that start and end with that character
            char ch = s[i];
            for(int j=i+1; j<n; j++){ // for each character
                // check if the character at the end of the substring is same as the character at the start
                if(ch == s[j]) count++;
            }
        }
        
        return count;
    }
};



// optimized using frequency map in O(n) time and O(n) space
class Solution {
  public:
  int countSubstring(string &s) {
        
        int n = s.length();
        unordered_map<char, int> freq; // frequency map to store the frequency of each character
        
        int count = 0;
        for(char& ch : s) freq[ch]++;  // count the frequency of each character
        
        for(auto& it : freq){  // for each character in the frequency map
            // for each character, the number of substrings that start and end with that character
            int currFreq = it.second;
            count += (currFreq*(currFreq+1))/2; //  n*(n+1)/2
        }
        
        return count;
    }
};