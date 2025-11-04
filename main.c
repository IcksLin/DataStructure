#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//链表======================================
// 前向声明，节点
typedef struct MyNode MyNode;
// 结构体定义
struct MyNode {
    int data;
    MyNode* next;
};
void node_init(MyNode** root);
void add_node(MyNode** root , int data);
void delete_node(MyNode** root, int data);
void print_list(MyNode* root);
//==========================================

//BST（查找二叉树）============================
//前向声明，二叉树（查找二叉树实现）
typedef struct BST_node BST_node;
//结构体定义
struct BST_node {
    int data;
    BST_node* left;
    BST_node* right;
};

void BST_insert(BST_node** root,int data);
BST_node* BST_find(BST_node* root,int data);
void BST_delete_tree(BST_node** root, int data);
void BST_print_list(BST_node* root);
//===========================================

int main() {
    //链表测试=================================
    MyNode* root = NULL;
    node_init(&root);
    for (int i = 0; i < 10; i++) {
        add_node(&root, i);
    }
    print_list(root);
    delete_node(&root, 20);
    delete_node(&root, 2);
    print_list(root);
    //BST测试=================================
    printf("\n===============================\n");
    BST_node* BST_root = NULL;
    BST_insert(&BST_root, 20);
    for (int i = 0; i<100;i++) {
        BST_insert(&BST_root, i);
    }
    BST_print_list(BST_root);
    BST_node *find_test = BST_find(BST_root, 70);
    if (find_test != NULL) {
        printf("\n Test Successful! \n");
        printf(" Test Data : ");
        printf("%d", find_test->data);
    }
    return 0;
}

//初始化节点
void node_init(MyNode** root) {
    if (root == NULL) {
        printf("NULL can`t be inited\n");
        return;
    }
    if (!(*root = (MyNode*)malloc(sizeof(MyNode)))) {
        printf("Malloc Failed\n");
        return;
    };
    (*root)->next = NULL;
    (*root)->data = 0;

}

//添加节点
void add_node(MyNode** root , int data) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    MyNode* temp = *root;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = (MyNode*)malloc(sizeof(MyNode));
    temp->next->data = data;
    temp->next->next = NULL;
}

void delete_node(MyNode** root, int data) {
    if (root == NULL || *root == NULL) {
        printf("NULL or empty list\n");
        return;
    }

    MyNode* current = *root;
    MyNode* prev = NULL;

    if (current != NULL && current->data == data) {
        *root = current->next;
        free(current);
        printf("Head node deleted successfully\n");
        return;
    }

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node not found\n");
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Node deleted successfully\n");
}

void print_list(MyNode* root) {
    if (root == NULL) {
        printf("Empty List\n");
        return;
    }
    printf("%d\n", root->data);
    while (root->next != NULL) {
        root = root->next;
        printf("%d ", root->data);

    }
}

//BST树的递归插入
void BST_insert(BST_node** root,int data){
    if (root == NULL) {
        return; // 无效的根指针
    }

    if (*root == NULL) {
        // 创建新节点
        *root = (BST_node*)malloc(sizeof(BST_node));
        if (*root == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        // 初始化新节点
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        printf("New node inserted with data: %d\n", data);
        return;
    }

    if ((*root)->data > data) {
        BST_insert(&(*root)->left, data);
    }else if ((*root)->data < data) {
        BST_insert(&(*root)->right, data);
    }
}

//递归打印
void BST_print_list(BST_node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    if (root->left != NULL) {
        BST_print_list(root->left);
    }
    if (root->right != NULL) {
        BST_print_list(root->right);
    }
}

//查找
BST_node* BST_find(BST_node* root,int data) {
    BST_node* temp = root;
    if (temp==NULL) {
        printf("Node not found\n");
        return NULL;
    }
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        if (temp->data > data) {
            temp = temp->left;
        }else if (temp->data < data) {
            temp = temp->right;
        }
    }
    printf("Node not found\n");
    return NULL;
}