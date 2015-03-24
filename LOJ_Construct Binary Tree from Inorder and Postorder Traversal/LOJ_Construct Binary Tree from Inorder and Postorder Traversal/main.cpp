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
    
    TreeNode *constructTree(vector<int> &inorder,int istart,int iend,vector<int> &postorder,int pstart,int pend){
        
        if(istart>iend)
            return NULL;
        
        TreeNode *tree = new TreeNode(postorder[pend]);

        int step = 0;
        for(int i=istart;i<=iend;i++){
            if(postorder[pend] == inorder[i]){
                break;
            }else{
                step++;
            }
        }
        
        TreeNode *ltree = constructTree(inorder,istart,istart+step-1,postorder,pstart,pstart+step-1);
        TreeNode *rtree = constructTree(inorder,istart+step+1,iend,postorder,pstart+step,pend-1);
        tree->left = ltree;
        tree->right = rtree;
        
        return tree;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0 || inorder.size() != postorder.size())
            return NULL;
        return constructTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> postorder;
    vector<int> inorder;
    
    postorder.push_back(4);
    postorder.push_back(5);
    postorder.push_back(2);
    postorder.push_back(6);
    postorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(1);
    
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);
    
    Solution s;
    TreeNode *tree = s.buildTree(inorder,postorder);
    
    preOrderTraverse(tree);
    
    
    return 0;
}
