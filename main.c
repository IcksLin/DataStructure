#include <stdio.h>
#include <stdlib.h>

// 前向声明
typedef struct MyNode MyNode;
// 结构体定义
struct MyNode {
    int data;
    MyNode* next;
};

typedef struct MyTreeNode {
    int data;
    struct MyNode* left;
    struct MyNode* right;
}MyTreeNode;

void node_init(MyNode** root);
void add_node(MyNode** root , int data);
void delete_node(MyNode** root, int data);
void print_list(MyNode* root);


int main() {
    MyNode* root = NULL;
    // 直接初始化，不要先指向栈变量
    node_init(&root);
    for (int i = 0; i < 10; i++) {
        add_node(&root, i);
    }
    print_list(root);
    delete_node(&root, 20);
    delete_node(&root, 2);
    print_list(root);
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