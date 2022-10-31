extern "C" {
// Add the header files required to run your main
#include "insertion_sort.h"
#include "linked_list.h"
#include "list_queue.h"
}

void testFunction() {
    queue q;
    int x = 5;
    int x0 = 10;
    int x1 = 20;
    int y;
    int y0;
    int y1;

    // Test A
    printf("Test A: \n");
    init_queue(&q);
    if (empty(&q) == 1) {
        printf("Test A == Succes\n\n");
    } else {
        printf("Something went wrong with Test A\n\n");
        abort;
    }

    // Test B
    printf("\nTest B:\n");
    enqueue(&q, x);
    y = dequeue(&q);
    if (x == y && empty(&q) == 1) {
        printf("Test B == Success \n\n");
    } else {
        printf("Something went wrong with Test B\n\n");
        abort;
    }

    // Test C
    printf("\nTest C:\n");
    enqueue(&q, x0);
    enqueue(&q, x1);
    y0 = dequeue(&q);
    y1 = dequeue(&q);
    if (x0 == y0 && x1 == y1 && empty(&q)) {
        printf("Test C == Success \n\n");
    } else {
        printf("Something went wrong with Test C\n\n");
        abort;
    }
}

// File for sandboxing and trying out code
int main(int argc, char **argv) {
    testFunction();

    return 0;
}