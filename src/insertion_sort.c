#include "insertion_sort.h"

#include "linked_list.h"

void sort(linked_list* llPtr) {
    // Add your sort function here

    linked_list* sortedList = createLinkedList();

    node_t* currentUnsorted = llPtr->head;
    node_t* currentSorted;

    while (currentUnsorted != NULL) {
        currentSorted = createNode(currentUnsorted->data);
        insertFront(currentSorted, sortedList);

        while (currentSorted->data > currentSorted->next->data &&
               currentSorted->next != NULL) {
            int tempVal = currentSorted->data;
            currentSorted->data = currentSorted->next->data;
            currentSorted->next->data = tempVal;

            currentSorted = currentSorted->next;
        }

        currentUnsorted = currentUnsorted->next;
    }

    llPtr = sortedList;

    return;
}
