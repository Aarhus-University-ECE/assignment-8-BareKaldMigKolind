#include "insertion_sort.h"

#include "linked_list.h"

void sort(linked_list* llPtr) {
    // Add your sort function here

    // Min algoritme kommer til at sørge for at venstre siden altid er sorteret
    // korrekt, mens den bevæger sig mod højre. Derfor antager jeg, at den
    // første node er sorteret korrekt, hvilket logisk også giver mening. Jeg
    // sætter derfor min currentNode til at være element nummer to i listen.
    node_t* currentNode = llPtr->head->next;
    // Prev er ved starten af hvert gennemløb den forgående node. Derfor er den
    // var starten af sat til llPtr->head.
    node_t* prev = llPtr->head;
    // Jeg skal bruge en temp pointer senere. Den oprettes derfor bare, så jeg
    // kan bruge den senere.
    node_t* temp;

    // Jeg skal lave et gennemløb af listen. Derfor skal mit while loop køre
    // indtil currentNode er NULL, det vil sige slutelementet.
    while (currentNode != NULL) {
        // Hvis currentNode->data er større end prev->data, så er listen
        // sorteret korrekt indtil CurrentNode. Derfor er det kun hvis
        // currentNode->data < prev->data, at jeg skal foretage mig noget.
        if (currentNode->data < prev->data) {
            // Hvis de første to elementer skal bytte plads, er det lidt et
            // særtilfælde. Derfor er min håndtering af dette også en smule
            // anderledes. Derfor tjekker jeg for det som det første.
            if (prev == llPtr->head) {
                // Her bytter vi rundt på det første og andet element.
                prev->next = currentNode->next;
                currentNode->next = prev;
                // Da vi får en ny headNode skal den pointer også opdateres.
                llPtr->head = currentNode;

                // Det her er den generelle håndtering af sorteringsproblemet.
            } else {
                // Nu skal jeg forsøge at finde elementet før og efter
                // currentNodes sorterede plads.
                //  Derfor sætter jeg temp til at være det forreste element.
                temp = llPtr->head;
                // Her er et lille edgecase eksempel igen. Hvis currentNode skal
                // være forrest, skal vi igen have opdateret head elementet.
                // Derfor laver jeg denne if-sætning.
                if (currentNode->data < temp->data) {
                    prev->next = currentNode->next;
                    currentNode->next = temp;
                    llPtr->head = currentNode;

                    // igen er det her min generelle håndtering af
                    // sorteringsproblemet.
                } else {
                    // Her gennemløber jeg den venstre del af listen indtil
                    // currentNode.
                    while (temp->next->data <= currentNode->data) {
                        temp = temp->next;
                    }
                    // Efter while løkken må følgende gælde:
                    // temp->data < CurrentNode->data < temp-next-data

                    // Her deler jeg den sidste sorteringshåndtering op.
                    // Hvis listen hedder temp->prev->currentNode bliver
                    // if-sætningen kørt.
                    if (temp->next->next == currentNode) {
                        // Her er temp->next == prev. Da prev->data >
                        // currentNode->data skal prev altså pege på
                        // currentNode->next
                        temp->next->next = currentNode->next;

                        // CurrentNode skal pege på prev. Og da prev ==
                        // temp->next er det altså:
                        currentNode->next = temp->next;

                        // Og Temp skal pege på currentNode.
                        temp->next = currentNode;

                        // Hvis ikke if sætningen er kørt er det fordi
                        // currentNode->next == NULL. Vi kan derfor komme ud
                        // for, at der tabes en node. I det tilfælde skal else
                        // sætningen køres.
                    } else {
                        // Her er prev altså det største element i listen.
                        // Derfor skal den stå længst til højre og derfor skal
                        // den pege på CurrentNode->next, som altså er NULL
                        prev->next = currentNode->next;
                        // Der gælder stadig at temp->data < CurrentNode->data <
                        // temp-next-data Derfor skal currentNode pege på
                        // temp->next.
                        currentNode->next = temp->next;
                        // Og temp skal pege på currentNode.
                        temp->next = currentNode;
                    }
                }
            }
        }

        // Skubber prev og currentNode en tak. Ellers ender vi i noget bøvl.
        prev = currentNode;
        currentNode = currentNode->next;
    }

    return;
}