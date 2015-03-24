//
//  main.cpp
//  LOJ_Construct Binary Tree from Preorder and Inorder Traversal
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

void preOrderTraverse(TreeNode* &T){
    if(T){
        cout<<T->val<<" ";
        preOrderTraverse(T->left);
        preOrderTraverse(T->right);
    }
}

class Solution {
public:
    
    TreeNode *constructTree(vector<int> &preorder,int pstart,int pend,vector<int> &inorder,int istart,int iend){
        
        if(pstart>pend)
            return NULL;
        
        TreeNode *tree = new TreeNode(preorder[pstart]);
        
        int step = 0;
        for(int i=istart;i<=iend;i++){
            if(preorder[pstart] == inorder[i]){
                break;
            }else{
                step++;
            }
        }
        
        TreeNode *ltree = constructTree(preorder,pstart+1,pstart+step,inorder,istart,istart+step-1);
        TreeNode *rtree = constructTree(preorder,pstart+step+1,pend,inorder,istart+step+1,iend);
        tree->left = ltree;
        tree->right = rtree;
        
        return tree;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0 || preorder.size() != inorder.size())
            return NULL;
        
        return constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> preorder;
    vector<int> inorder;
    
    for(int i=1;i<=6;i++){
        preorder.push_back(i);
    }
    inorder.push_back(3);
    inorder.push_back(2);
    inorder.push_back(1);
    inorder.push_back(5);
    inorder.push_back(4);
    inorder.push_back(6);
    
    Solution s;
    TreeNode *tree = s.buildTree(preorder,inorder);
    
    preOrderTraverse(tree);
    
    
    return 0;
}
