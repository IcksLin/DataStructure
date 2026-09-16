#ifndef MY_BINARYTREE_H
#define MY_BINARYTREE_H
#include<stdio.h>
#include<stdlib.h>


typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *btree_create_node(int value);
void btree_free(TreeNode *root);

TreeNode *btree_insert(TreeNode *root, int value);

TreeNode *btree_find(TreeNode *root, int value);

void btree_preorder(TreeNode *root);    
void btree_inorder(TreeNode *root);     
void btree_postorder(TreeNode *root);   
void btree_levelorder(TreeNode *root);  

int btree_size(TreeNode *root);         
int btree_height(TreeNode *root);       
int btree_leaf_count(TreeNode *root);   



#endif
