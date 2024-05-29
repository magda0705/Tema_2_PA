#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"
int Adiacenta[TEAMS][TEAMS];

int main(int argc, char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    FILE *grafic = fopen(argv[2], "w");
    FILE *scor = fopen(argv[3], "w");

    if (in == NULL || grafic == NULL || scor == NULL) {
        fprintf(stderr, "Eroare la deschiderea fisierelor!\n");
        return 1;
    }

    Queue *meciuri = (Queue *)malloc(sizeof(Queue));
    meciuri->front = meciuri->rear = NULL;
    Queue *infranti = (Queue *)malloc(sizeof(Queue));
    infranti->front = infranti->rear = NULL;

    team echipa_curenta;
    team prima_echipa, a_doua_echipa;

    for (int i = 0; i < TEAMS; i++) {
        echipa_curenta = data_team(in,i);
        enQueue(meciuri, echipa_curenta);
    }
return 0;
}
