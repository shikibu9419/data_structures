#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *left;
    struct node *right;
} node_t;

node_t *talloc();
node_t *insert(int, node_t *);
node_t *delete_node(node_t *);
node_t *delete(int, node_t *);
char children_type(node_t *);
void print_tree(node_t *);

int main() {
    int item;
    char command;
    node_t *root = NULL;

    printf("Start bstree console.\n");

    while(1) {
        printf("> ");
        scanf("%c%*c", &command);

        switch(command) {
            case 'i':
                scanf("%d%*c", &item);
                root = insert(item, root);
                break;
            case 'd':
                scanf("%d%*c", &item);
                root = delete(item, root);
                break;
            case 'p':
                print_tree(root);
                putchar('\n');
                break;
            case 'q':
                printf("Quit running bstree.\n");
                return 0;
            default:
                printf("Please input 'i integer', 'd integer', 'p', or 'q'.\n\n");
        }
    }

    return 0;
}

node_t *talloc() {
    return ((node_t *) malloc(sizeof(node_t)));
}

node_t *insert(int num, node_t *root) {
    if(root == NULL) {
        root        = talloc();
        root->num   = num;
        root->left  = NULL;
        root->right = NULL;
    } else if(num == root->num)
        printf("%d is already inserted.\n\n", num);
    else if(num < root->num)
        root->left  = insert(num, root->left);
    else
        root->right = insert(num, root->right);

    return root;
}

char children_type(node_t *ptr) {
    if(ptr->left == NULL)
        return (ptr->right == NULL) ? 'n' : 'r';
    else
        return (ptr->right == NULL) ? 'l' : 'b';
}

node_t *delete_node(node_t *ptr) {
    node_t *p, *parent;

    char c = children_type(ptr);
    if(c == 'n')
        ptr = NULL;
    else if(c == 'l')
        ptr = ptr->left;
    else if(c == 'r')
        ptr = ptr->right;
    else if(c == 'b') {
        p = ptr->right;
        if(children_type(p) == 'r' || children_type(p) == 'n')
            p->left = ptr->left;
        else {
            while(p->left != NULL) {
                parent = p;
                p = p->left;
            }
            parent->left = p->right;
            p->left      = ptr->left;
            p->right     = ptr->right;
        }
        ptr = p;
    }

    return ptr;
}

node_t *delete(int num, node_t *root) {
    if(root == NULL)
        printf("%d is not in bstree.\n\n", num);
    else if(num == root->num)
        root = delete_node(root);
    else if(num < root->num)
        root->left  = delete(num, root->left);
    else if(num > root->num)
        root->right = delete(num, root->right);
    return root;
}

void print_tree(node_t *root) {
    if(root == NULL)
        return;
    print_tree(root->left);
    printf("%d\n", root->num);
    print_tree(root->right);
}
