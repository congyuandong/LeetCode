//
//  main.cpp
//  LOJ_Convert Sorted List to Binary Search Tree
//
//  Created by 丛远东 on 15/3/23.
//  Copyright (c) 2015年 丛远东. All rights reserved.
//

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    
    vector<int> createVector(ListNode *head){
        vector<int> num;
        while(head != NULL){
            num.push_back(head->val);
            head = head->next;
        }
        return num;
    }
    
    /*
     *解法1，和使用vector构建BST一样，先构建vector
     */
    //TreeNode *sortedListToBST(ListNode *head) {
    //    vector<int> num = createVector(head);
    //    return createBST(num,0,num.size()-1);
    //}
    
    
    TreeNode *buildBST(ListNode *&head,int left,int right){
        if(left>right)
            return NULL;
        int mid = (left + right)/2;
        TreeNode *leftnode = buildBST(head,left,mid-1);
        TreeNode *parent = new TreeNode(head->val);
        parent->left = leftnode;
        head = head->next;
        parent->right = buildBST(head,mid+1,right);
        return parent;
    }
    
    /*
     *解法2，链表结构其实是中序遍历的结果，所以
     */
    TreeNode *sortedListToBST(ListNode *head) {
        int count = 0;
        ListNode *nodelist = head;
        while(nodelist != NULL){
            count++;
            nodelist = nodelist->next;
        }
        return buildBST(head,0,count-1);
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    ListNode *link = new ListNode(1);
    ListNode *p = link;
    ListNode *node = new ListNode(2);
    link->next = node;
    link=link->next;
    node = new ListNode(3);
    link->next = node;
    link=link->next;
    node = new ListNode(4);
    link->next = node;
    link=link->next;
    node = new ListNode(5);
    link->next = node;
    link=link->next;
    node = new ListNode(6);
    link->next = node;
    link=link->next;
    node = new ListNode(7);
    link->next = node;
    link=link->next;

    
    TreeNode *tree = s.sortedListToBST(p);
    
    preOrderTraverse(tree);
}