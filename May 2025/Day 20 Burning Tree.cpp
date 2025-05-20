
/*
 Burning Tree
 https://practice.geeksforgeeks.org/problems/burning-tree/1


Problem Explanation
Given a binary tree and a target node, the task is to find the minimum time required to burn the entire tree if the fire starts from the target node.

The fire spreads to all adjacent nodes (parent, left child, right child) in one second.
Burning the target node itself takes 1 second.
Approach
Find Parent Mapping and Target Node:

Traverse the tree using BFS to create a mapping from each node to its parent.
Also, locate the actual node corresponding to the target value.
Simulate the Burning Process (BFS):

Use a queue to perform BFS starting from the target node.
Use a visited map to avoid revisiting nodes.
For each node, in every second, the fire spreads to its left child, right child, and parent (if they exist and are not visited).
Use a flag to check if any new node is burned in the current second; if yes, increment the time.
Return the Time:

The total time taken to burn the entire tree is the answer.

Time Complexity: O(n), where n is the number of nodes in the tree.
Space Complexity: O(n), for storing the parent mapping and visited nodes.

*/

class Solution {
  public:
    void findParent(Node* root, unordered_map<Node*, Node*>& parentNode, Node*& targetNode, int target){
        
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()){
            Node* currNode = que.front();
            que.pop();
            
            if(currNode->data == target) targetNode = currNode;
            
            if(currNode->left){
                parentNode[currNode->left] = currNode;
                que.push(currNode->left);
            }
            
            if(currNode->right){
                parentNode[currNode->right] = currNode;
                que.push(currNode->right);
            }
        }
        
    }
    int minTime(Node* root, int target) {
        // code here
        
        unordered_map<Node*, Node*> parentNode;
        Node* targetNode = NULL;
        findParent(root, parentNode, targetNode, target);
        
        unordered_map<Node*, bool> visited;
        int time = 0;
        visited[targetNode] = true;
        queue<Node*> que;
        que.push(targetNode);
        while(!que.empty()){
            int size = que.size();
            
            bool flag = false;
            while(size--){
                Node* curr = que.front();
                que.pop();
                
                // for left
                if(curr->left && !visited[curr->left]){
                    visited[curr->left] = true;
                    flag = true;
                    que.push(curr->left);
                }
                
                // for right
                if(curr->right && !visited[curr->right]){
                    visited[curr->right] = true;
                    flag = true;
                    que.push(curr->right);
                }
                
                // for parent
                if(parentNode[curr] && !visited[parentNode[curr]]){
                    Node* parent = parentNode[curr];
                    visited[parent] = true;
                    flag = true;
                    que.push(parent);
                }
            }
            if(flag) time++;
        }
        
        return time;
    }

};