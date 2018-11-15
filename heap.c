#include<stdio.h>
#include<stdlib.h>
#define HEAP_MAX_SIZE 10

void start_heap();
void putheap(int);
void upheap(int);
void getheap();
void downheap(int);
void print();
int heap[HEAP_MAX_SIZE + 1] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0};  // 0: No number setted
int size = 7;

int main() {
    start_heap();
    return 0;
}

void start_heap() {
    int i;
    int item;
    char command;

    // Initialize heap
    for(i = 7; i >= 1; i--)
        downheap(i);

    printf("Now data in heap:\n");
    print();

    printf("Start heap console.\n");

    while(1) {
        printf("> ");
        scanf("%c%*c", &command);

        switch(command) {
            case 'i':
                scanf("%d%*c", &item);
                putheap(item);
                break;
            case 'd':
                getheap();
                break;
            case 'p':
                print();
                break;
            case 'q':
                printf("Quit running heap.\n");
                return;
            default:
                printf("Please input 'i integer', 'd', 'p', or 'q'.\n\n");
        }
    }
}

void putheap(int item) {
    if(size == HEAP_MAX_SIZE) {
        printf("Can't insert: Heap is full!\n");
        return;
    }

    size++;
    heap[size] = item;
    upheap(size);
}

void upheap(int child) {
    int value = heap[child];
    int parent = child / 2;
    while(parent >= 1 && heap[parent] < value) {
        heap[child] = heap[parent];
        child = parent;
        parent = child / 2;
    }
    heap[child] = value;
}

void getheap() {
    if(size == 0) {
        printf("Can't delete: Heap is null!\n");
        return;
    }

    int value = heap[1];
    heap[1] = heap[size];
    size--;
    downheap(1);
    printf("Deleted: %d\n", value);
}

void downheap(int parent) {
    int value = heap[parent];
    int child = parent * 2;
    while(child <= size) {
        if(child < size && heap[child] < heap[child + 1])
            child++;
        if(heap[child] < value)
            break;
        heap[parent] = heap[child];
        parent = child;
        child = parent * 2;
    }
    heap[parent] = value;
}

void print() {
    int i;
    for(i = 1; i <= size; i++)
        printf("%d\n", heap[i]);
    putchar('\n');
}
