#include <iostream>  
#include <algorithm> 
#include <queue> 
#include<vector>   

using namespace std;

//Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        if(!root) return res;

        while(!q.empty()){
            int size=q.size();
            vector<int> temp;

            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                temp.push_back(node->val);
                for(int i=0;i<node->children.size();i++){
                    if(node->children[i]){
                        q.push(node->children[i]);
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};