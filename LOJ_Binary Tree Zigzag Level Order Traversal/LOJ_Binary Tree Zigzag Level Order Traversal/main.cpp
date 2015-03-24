//
//  main.cpp
//  LOJ_Binary Tree Level Order Traversal II
//
//  Created by 丛远东 on 15/3/24.
//  Copyright (c) 2015年 丛远东. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<int> > result;
    
    void treeToVector(TreeNode *root,int level){
        if(root == NULL)
            return;
        if(result.size() == level){
            vector<int> k;
            result.push_back(k);
        }
        
        result[level].push_back(root->val);
        treeToVector(root->left,level+1);
        treeToVector(root->right,level+1);
        
    }
    
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        int level = 0;
        treeToVector(root, level);
        for(int i=0;i<result.size();i++){
            if(i%2==1)
                reverse(result[i].begin(), result[i].end());
        }
        //reverse(result.begin(),result.end());
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *tree = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    tree->left = node1;
    tree->right = node2;
    node1->left = node3;
    node2->right = node4;
    Solution s;
    vector<vector<int> > result = s.zigzagLevelOrder(tree);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}
