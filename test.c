#include<stdio.h>
#include<stdlib.h>
// #include "queue.h"

/*struct data{
    int a;
    float b;
    double c;
    struct data *d;
};

int main() {
    struct data d;
    
    printf("\n%d\n",sizeof(float));
    printf("\n%d\n",sizeof(int));
    printf("\n%d\n",sizeof(long));
    printf("\n%d\n",sizeof(char));
    printf("\n%d\n",sizeof(double));
    printf("\n%d\n",sizeof(d));
    printf("\n%d\n",sizeof(struct data *));
    printf("\n%d\n",sizeof(char *));
    return 0;
}*/

// gcc -c queue.c -> gives us queue.o for library impls
// gcc test.c queue.o -> a.exe

/* typedef struct _test {
    int a;
    int b;
}test;

int main() {
    queue *q = createQueue(sizeof(test));
    test t1 = {10,20};
    test t2 = {30,40};
    test t3 = {50,60};
    enqueue(q, &t1);
    enqueue(q, &t2);
    enqueue(q, &t3);
    test t4;
    peek(q, &t4);
    printf("%d, %d\n", t4.a, t4.b);
    dequeue(q);
    peek(q, &t4);
    printf("%d, %d\n", t4.a, t4.b);
    dequeue(q);
    peek(q, &t4);
    printf("%d, %d\n", t4.a, t4.b);
    dequeue(q);
    peek(q, &t4);
    printf("%d, %d\n", t4.a, t4.b);
    return 0;
}*/

/*int util(char *p) {
    int length = 0;
    while(*p != '\0') {
        p++;
        length++;
    }
    return length;
}

int main() {
    char *p = "hello";
    int length = util(p);
    printf("%d", length);
    printf("%s", p);
    return 0;
}*/

typedef struct _node{
    int data;
    struct _node *next;    
}node;

void func(node** ptr);

int main() {
    node *ptr = (node*)malloc(sizeof(node));

    ptr->data = 10;
    ptr->next = (node*)malloc(sizeof(node));
    ptr->next->data = 20;
    ptr->next->next = NULL;

    func(&ptr);

    while(ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0; 
}

void func(node** ptr) {
    node* p = *ptr;
    p = p->next;
    *ptr = p;
}