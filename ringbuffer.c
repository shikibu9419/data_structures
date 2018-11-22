#include<stdio.h>
#include<stdlib.h>
#define QUEUE_MAX_SIZE 5

void start_queue();
void enqueue(int);
void dequeue();
void print();
int next_queue(int);
int queue[QUEUE_MAX_SIZE + 1];
int head = 0;
int tail = 0;

int main() {
    start_queue();
    return 0;
}

void start_queue() {
    int item;
    char command;

    printf("Start queue console.\n");

    while(1) {
        printf("> ");
        scanf("%c%*c", &command);

        switch(command) {
            case 'i':
                scanf("%d%*c", &item);
                enqueue(item);
                break;
            case 'd':
                dequeue();
                break;
            case 'p':
                print();
                break;
            case 'q':
                printf("Quit running queue.\n");
                return;
            default:
                printf("Please input 'i integer', 'd', 'p', or 'q'.\n\n");
        }
    }
}

int next_queue(int now) {
    return (now + 1) % (QUEUE_MAX_SIZE + 1);
}

void enqueue(int item) {
    int next = next_queue(tail);
    if(next == head) {
        printf("Can't enqueue: Queue is full!\n");
        return;
    }

    queue[tail] = item;
    tail = next;
}

void dequeue() {
    if(head == tail) {
        printf("Can't dequeue: Queue is null!\n");
        return;
    }

    int value = queue[head];
    head = next_queue(head);
    printf("Dequeued: %d.\n", value);
}

void print() {
    int now = head;
    while(now != tail) {
        printf("%d\n", queue[now]);
        now = next_queue(now);
    }
    putchar('\n');
}
