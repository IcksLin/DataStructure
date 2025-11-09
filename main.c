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

//栈实现=====================================
#define STACK_SIZE 100
typedef struct MyStack MyStack;
struct MyStack {
    int top;
    int my_stack[STACK_SIZE];
};
void stack_init(MyStack** stack);
bool stack_push(MyStack* stack, int data);
bool stack_pop(MyStack* stack , int *pData);
bool stack_empty(MyStack* stack);
//==========================================

//队列实现===================================
#define QUEUE_SIZE 100
typedef struct Queue Queue;
struct Queue {
    int data[QUEUE_SIZE];
    int front;
    int rear;
};
//
void queue_init(Queue* queue);
bool queue_is_empty(Queue* queue);
bool queue_is_full(Queue* queue);
void enqueue(Queue* queue, int data);
bool dequeue(Queue* queue,int* data) ;
void print_queue(Queue* queue);
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
bool BST_delete_tree(BST_node** root, int data);
void BST_print_list(BST_node* root);

//===========================================

int main() {
    //链表测试=================================
    // MyNode* root = NULL;
    // node_init(&root);
    // for (int i = 0; i < 10; i++) {
    //     add_node(&root, i);
    // }
    // print_list(root);
    // delete_node(&root, 20);
    // delete_node(&root, 2);
    // print_list(root);
    //队列测试=================================
    Queue queue;
    printf("%d\n",queue_is_full(&queue));

    printf("%d\n",queue_is_empty(&queue));
    queue_init(&queue);
    for (int i = 0;i<101;i++) {
        enqueue(&queue,i);
    }
    print_queue(&queue);
    printf("\n===========================\n");
    for (int i = 0;i<101;i++) {
        int data;
        if (dequeue(&queue,&data)) {
            printf("%d ",data);
        }
    }
    printf("\n");
    print_queue(&queue);
    //循环队列默认会牺牲最后一个储存位用于判断是否空队或者满队，故有效容积为99，即打印到98为止

    //BST测试=================================
    // printf("\n===============================\n");
    // BST_node* BST_root = NULL;
    // BST_insert(&BST_root, 20);
    // for (int i = 0; i<100;i++) {
    //     BST_insert(&BST_root, i);
    // }
    // BST_print_list(BST_root);
    // printf("\n%d\n",BST_delete_tree(&BST_root,30));
    //
    // BST_print_list(BST_root);
    // BST_node *find_test = BST_find(BST_root, 70);
    // if (find_test != NULL) {
    //     printf("\n Test Successful! \n");
    //     printf(" Test Data : ");
    //     printf("%d", find_test->data);
    // }
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

//链表打印
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

//栈初始化
void stack_init(MyStack** stack) {
    if (stack == NULL|| *stack == NULL) {
        printf("Struct is invalid\n");
        return;
    }
    for (int i = 0;i<STACK_SIZE;i++) {
        (*stack)->my_stack[i] = 0;

    }
    (*stack)->top = -1;
}

//入栈
bool stack_push(MyStack* stack, int data) {
    if (stack == NULL ) {
        printf("Stack is invalid\n");
        return false;
    }
    if (stack->top == STACK_SIZE - 1) {
        printf("Stack Full\n");
        return false;
    }
    stack->my_stack[++stack->top] = data;
    return true;
}

//出栈
bool stack_pop(MyStack* stack, int *pData) {
    if (stack==NULL) {
        printf("Stack is invalid\n");
        return false;
    }
    if (stack->top == -1) {
        printf("Stack Empty\n");
        return false;
    }
    return stack->my_stack[stack->top--];
}

//队列初始化
void queue_init(Queue* queue) {
    if (queue == NULL) {
        printf("Queue is invalid\n");
        return;
    }
    for (int i = 0;i<QUEUE_SIZE;i++) {
        queue->data[i] = 0;
    }

    queue->front = 0;
    queue->rear = 0;

}

bool queue_is_empty(Queue* queue) {
    if (queue == NULL) {
        printf("Queue is invalid\n");
        return false;
    }
    if (queue->rear == queue->front) {
        return true;
    }
    return false;
}

//
bool queue_is_full(Queue* queue) {
    if (queue == NULL) {
        printf("Queue is invalid\n");
        return false;
    }
    return (queue->rear+1) % QUEUE_SIZE == queue->front;
}

//入队，循环
void enqueue(Queue* queue, int data) {
    if (queue == NULL) {
        printf("Queue is invalid\n");
        return;
    }
    if (queue_is_full(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
}

//出队
bool dequeue(Queue* queue,int* data) {
    if (queue == NULL) {
        printf("Queue is invalid\n");
        return false;
    }
    if (queue_is_empty(queue)) {
        printf("Queue is empty\n");
        return false;
    }
    *data = queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    return true;

}

//打印队列
void print_queue(Queue* queue) {
    if (queue == NULL) {
        printf("Empty Queue\n");
        return;
    }
    //注意循环跳出条件为!=，可实现循环队列的跨零点打印
    for (int i = queue->front; i != queue->rear; i = (i + 1) % QUEUE_SIZE) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");

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

//使用栈代替递归进行打印操作
//栈定义
#define MAX_BST_STACK_SIZE 4500
typedef struct BST_stack BST_stack;
struct BST_stack {
    int top;
    BST_node* my_stack[MAX_BST_STACK_SIZE];
};
//栈初始化函数
void BST_stack_init(BST_stack** stack) {
    if (stack == NULL) {
        printf("Init failed\n");
        return;
    }
    if ((*stack) == NULL) {
       if((*stack = (BST_stack*)malloc(sizeof(BST_stack)))) {
           (*stack)->top = -1;
       }else {
           printf("Malloc Failed\n");
       }
    }
}
//压栈函数
bool BST_STack_push(BST_stack** stack, BST_node* node) {
    if (stack == NULL || (*stack) == NULL) {
        return false;
    }
    //传入指针检查
    if (node==NULL) {
        return false;
    }
    //满栈检查
    if ((*stack)->top == MAX_BST_STACK_SIZE - 1) {
        return false;
    }
    (*stack)->my_stack[++(*stack)->top] = node;
    return true;

}
//出栈函数
bool BST_Stack_pop(BST_stack** stack,BST_node** node) {
    //例行检查
    if (stack == NULL || (*stack) == NULL) {
        return false;
    }
    if ((*stack)->top == -1) {
        return false;
    }
    *node = (*stack)->my_stack[(*stack)->top--];
    return true;
}
//打印函数
void BST_print_list_by_stack(BST_node* root) {
    if (root == NULL) {
        printf("Empty List\n");
        return;
    }
    //定义变量
    BST_stack* stack = NULL;
    BST_stack_init(&stack);
    BST_node* cur = root;
    //将根节点压入栈内
    BST_STack_push(&stack,root);
    while (stack->top != -1) {
        if (cur->left != NULL) {
            //移动
            cur = cur->left;
            //压栈
            BST_STack_push(&stack,cur);
        }
        if (cur->right != NULL) {
            cur = cur->right;
            BST_STack_push(&stack,cur);
        }

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

//删除操作
bool BST_delete_tree(BST_node** root, int data) {
    if (root == NULL || *root == NULL) {
        printf("BST is invalid\n");
        return false;
    }

    BST_node* cur = *root;
    BST_node* prev = NULL;

    // 查找要删除的节点
    while (cur != NULL && cur->data != data) {
        prev = cur;
        if (cur->data > data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    // 没找到
    if (cur == NULL) {
        return false;
    }

    // 情况1：要删除的节点有两个子节点
    if (cur->left != NULL && cur->right != NULL) {
        // 找到右子树的最小节点
        BST_node* min_parent = cur;
        BST_node* min_node = cur->right;

        while (min_node->left != NULL) {
            min_parent = min_node;
            min_node = min_node->left;
        }

        // 用min_node的值替换cur的值
        cur->data = min_node->data;

        // 现在删除min_node（它最多有一个右子节点）
        if (min_parent->left == min_node) {
            min_parent->left = min_node->right;
        } else {
            min_parent->right = min_node->right;
        }

        free(min_node);
    }
    // 情况2：要删除的节点有0或1个子节点
    else {
        BST_node* child = (cur->left != NULL) ? cur->left : cur->right;

        if (prev == NULL) {
            // 删除的是根节点
            *root = child;
        } else if (prev->left == cur) {
            prev->left = child;
        } else {
            prev->right = child;
        }

        free(cur);
    }

    return true;
}