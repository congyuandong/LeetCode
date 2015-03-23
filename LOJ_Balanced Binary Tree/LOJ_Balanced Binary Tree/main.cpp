//
//  main.cpp
//  LOJ_Balanced Binary Tree
//
//  Created by 丛远东 on 15/3/23.
//  Copyright (c) 2015年 丛远东. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrderTraverse(TreeNode* &T){
    if(T){
        cout<<T->val<<" ";
        preOrderTraverse(T->left);
        preOrderTraverse(T->right);
    }
}

int depthOfTree(TreeNode* &T){
    int ldepth,rdepth;
    if(T==NULL)
        return 0;
    ldepth = depthOfTree(T->left);
    rdepth = depthOfTree(T->right);
    
    return (ldepth>rdepth)?(ldepth+1):(rdepth+1);
}

class Solution {
private:
    bool balanced = true;
    
    int depthOfTree(TreeNode *root) {
        if(!balanced)
            return -1;
        if(root == NULL)
            return 0;
        int ldepth,rdepth;
        ldepth = depthOfTree(root->left);
        rdepth = depthOfTree(root->right);
        
        if(abs(ldepth-rdepth)>1)
            balanced = false;
        
        return (ldepth>rdepth)?(ldepth+1):(rdepth+1);
    }
    
    
public:
    bool isBalanced(TreeNode *root) {
        balanced = true;
        depthOfTree(root);
        return balanced;
    }
};


int main(int argc, const char * argv[]) {
    TreeNode *tree = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    tree->left = node1;
    tree->right = node2;
    //node1->left = node3;
    //node3->left = node4;
    
    //preOrderTraverse(tree);
    //cout<<endl<<depthOfTree(tree)<<endl;
    Solution s;
    cout<<s.isBalanced(tree)<<endl;
    return 0;
}

