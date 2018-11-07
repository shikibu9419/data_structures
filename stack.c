#include<stdio.h>
#include<stdlib.h>

typedef struct cell {
    int item;
    struct cell *next;
} cell_t;

void stack();
void print(cell_t *);
cell_t *lalloc();
cell_t *push(int, cell_t *);
cell_t *pop(cell_t *);

int main(void) {
    stack();
    return 0;
}

void stack() {
    cell_t *top = NULL;
    char command;
    int item, k;
    int i;

    printf("Start stack console.\n");

    while(1) {
        printf("> ");
        scanf("%c%*c", &command);

        switch(command) {
            case 'i':
                scanf("%d%*c", &item);
                top = push(item, top);
                break;
            case 'd':
                top = pop(top);
                break;
            case 'm':
                scanf("%d%*c", &k);
                while(top != NULL && k--)
                    top = pop(top);
                if(k > 0)
                    pop(top);
                break;
            case 'p':
                print(top);
                break;
            case 'q':
                printf("Quit running stack.\n");
                return;
            default:
                printf("Please input 'i integer', 'd', 'm integer', 'p', or 'q'.\n\n");
        }
    }
}

void print(cell_t *top) {
    cell_t *now = top;
    while(now != NULL) {
        printf("%d\n", now -> item);
        now = now -> next;
    }
    putchar('\n');
}

cell_t *lalloc() {
    return (cell_t *) malloc(sizeof(cell_t));
}

cell_t *push(int x, cell_t *top) {
    cell_t *p;
    p = lalloc();
    p -> item = x;
    p -> next = top;
    return p;
}

cell_t *pop(cell_t *top) {
    int x;
    if(top != NULL) {
        x = top -> item;
        top = top -> next;
    } else
        printf("Stack is empty.\n\n");
    return top;
}
