#include "my_binarytree.h"


TreeNode *btree_create_node(int value)
{
    TreeNode *n = malloc(sizeof(TreeNode));
    if(!n) return NULL;
    n->data = value;
    n->left = n->right = NULL;
    return n;
}
void btree_free(TreeNode *root)
{
    if(!root) return;
    btree_free(root->left);
    btree_free(root->right);
    free(root);
}

TreeNode *btree_insert(TreeNode *root, int value)
{
    if(value<root->data)
    {
        root->left = btree_insert(root->left,value);
    }else if (value>root->data)
    {
        root->right = btree_insert(root->right,value);
    }
    return root;
    
}

TreeNode *btree_find(TreeNode *root, int value)
{
    if(!root) return NULL;
    if(value == root->data) return root;
    if(value < root->data) return btree_find(root->left,value);
    return btree_find(root->right,value);
}

void btree_preorder(TreeNode *root)
{
    if(!root) return;
    printf("%d ",root->data);
    btree_preorder(root->left);
    btree_preorder(root->right);

} 
void btree_inorder(TreeNode *root)
{
    if(!root) return;
    btree_inorder(root->left);
    printf("%d ",root->data);
    btree_inorder(root->right);
}  
void btree_postorder(TreeNode *root)
{
    if(!root) return;
    btree_inorder(root->left);
    btree_inorder(root->right);
    printf("%d ",root->data);
}
void btree_levelorder(TreeNode *root)
{
    if(!root) return;
    TreeNode *queue[1024];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front<rear)
    {
        TreeNode *cur = queue[front++];
        printf("%d",cur->data);
        if(cur->left) queue[rear++] = cur->left;
        if(cur->right) queue[rear++] = cur->right;
    }
    
}

int btree_size(TreeNode *root)
{
    if(!root) return 0;
    return 1 + btree_size(root->left)+btree_size(root->right);
}     
int btree_height(TreeNode *root)
{
    if(!root) return 0;
    int l = btree_height(root->left);
    int r = btree_height(root->right);
    return 1 + (l>r?l:r);
}
int btree_leaf_count(TreeNode *root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return btree_leaf_count(root->left) + btree_leaf_count(root->right);
}