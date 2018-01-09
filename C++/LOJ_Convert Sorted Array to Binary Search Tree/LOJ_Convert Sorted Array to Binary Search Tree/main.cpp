//
//  main.cpp
//  LOJ_Convert Sorted Array to Binary Search Tree
//
//  Created by 丛远东 on 15/3/23.
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
    
    TreeNode *createBST(vector<int> &num,int left,int right){
        if(left > right)
            return NULL;
        int mid = (left + right)/2;
        
        TreeNode *leftnode = createBST(num, left, mid -1);
        TreeNode *rightnode = createBST(num, mid + 1, right);
        
        TreeNode *node = new TreeNode(num[mid]);
        node->left = leftnode;
        node->right = rightnode;
        
        return node;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return createBST(num,0,num.size()-1);
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    TreeNode *tree = s.sortedArrayToBST(num);
    
    preOrderTraverse(tree);
}


/*
Vector 基本操作
 
 (1)头文件#include<vector>.
 
 (2)创建vector对象，vector<int> vec;
 
 (3)尾部插入数字：vec.push_back(a);
 
 (4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。
 
 (5)使用迭代器访问元素.
 
 vector<int>::iterator it;
 for(it=vec.begin();it!=vec.end();it++)
 cout<<*it<<endl;
 (6)插入元素：    vec.insert(vec.begin()+i,a);在第i+1个元素前面插入a;
 
 (7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素
 
 vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始
 
 (8)向量大小:vec.size();
 
 (9)清空:vec.clear();
 
 */
