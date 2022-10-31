#include "list_queue.h"

#include <stdio.h>

#include "assert.h"

void init_queue(queue *q) {
    // Add your init_queue
    // Laver en tom queue. Derfor skal front og rear være NULL.
    q->front = NULL;
    q->rear = NULL;

    // Størrelsen er naturligvis 0.
    q->size = 0;
}

int empty(queue *q) {
    // Add your empty function
    // I empty kigger jeg bare på størrelsen af queuen. Altså om size == 0.
    // Jeg returner 1 hvis size == 0, fordi empty == true.
    if (q->size == 0) {
        return 1;
    }
    // Ellers er empty == false og derfor returner jeg 0.
    return 0;
}

void enqueue(queue *q, int x) {
    // Add your enqueue function
    // Først skal der gøres plads til en ny qnode. Derfor bruger jeg malloc. Jeg
    // kalder den nye qnode for RearNew.
    qnode *rearNew = (qnode *)malloc(sizeof(qnode));

    // Nu skal data og pointer opdateres. Da det er et rear element, skal
    // rearNew pege på NULL.

    rearNew->data = x;
    rearNew->next = NULL;

    // Nu skal rearNew indsættes i queuen q. Der er to scenarier, enten er q tom
    // eller også er den ikke. Derfor tjekker jeg om q er tom:
    if (empty(q) == 1) {
        // Hvis q er tom, så er rearNew både forreste og bagerste element.
        // Derfor skal den både hver front og rear.
        q->front = rearNew;
    } else {
        // Hvis q ikke er tom, så skal q->rear ikke længere pege på NULL, men på
        // rearNew.
        q->rear->next = rearNew;
    }
    // Da vi har ændret q->rear og fået et nyt element bagerst, så skal q-rear
    // opdateres.
    q->rear = rearNew;

    // Desuden er størrelsen af q nu vokset med en.
    q->size = q->size + 1;
}

int dequeue(queue *q) {
    // Add your dequeue function

    // Først tjekker jeg lige at queue q ikke er tom. Det giver nemlig ikke
    // mening at dequeue på en tom queue.
    assert(empty(q) == 0);

    // Dequeue skal returne data fra den node, som slettes. Derfor skal vi gemme
    // dataen. Det bruger jeg temp til.
    int temp = q->front->data;

    // Før jeg opdaterer queuens front, gemmer jeg den først i en pointer kaldet
    // formerFront
    qnode *formerFront = q->front;

    // Så opdaterer jeg fronten på queuen til at være det næste elementen i
    // queuen.
    q->front = q->front->next;

    // Og jeg husker at free formerFront, så vi undergår memory leak.
    free(formerFront);

    // Nu er q->size blevet en mindre, derfor skal size opdateres.
    q->size = q->size - 1;

    // Jeg returner temp.
    return temp;
}
