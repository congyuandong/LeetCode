//
//  main.cpp
//  LOJ_Maximum Depth of Binary Tree
//
//  Created by 丛远东 on 15/3/24.
//  Copyright (c) 2015年 丛远东. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        int ldepth,rdepth;
        if(root == NULL)
            return 0;
        ldepth = maxDepth(root->left);
        rdepth = maxDepth(root->right);
        return ldepth>rdepth?ldepth+1:rdepth+1;
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
    node1->left = node3;
    node3->left = node4;
    Solution s;
    cout<<s.maxDepth(tree)<<endl;
    return 0;
}
