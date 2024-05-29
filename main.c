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

    int etape = 6;
    while (meciuri->front != NULL && meciuri->front->next != NULL) {
        // etape++;
        prima_echipa = meciuri->front->val;
        deQueue(meciuri);
        a_doua_echipa = meciuri->front->val;
        deQueue(meciuri);

        if (compara_echipe(prima_echipa, a_doua_echipa)) {
            prima_echipa.nr_victorii++;
            enQueue(meciuri, prima_echipa);
            enQueue(infranti, a_doua_echipa);
            
            Adiacenta[a_doua_echipa.pozitie_meci][prima_echipa.pozitie_meci] = 1;
        } else {
            a_doua_echipa.nr_victorii++;
            enQueue(meciuri, a_doua_echipa);
            enQueue(infranti, prima_echipa);
            
            Adiacenta[prima_echipa.pozitie_meci][a_doua_echipa.pozitie_meci] = 1;
        }
    }
    enQueue(infranti, meciuri->front->val);

    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < TEAMS; j++) {
            fprintf(grafic, "%d ", Adiacenta[i][j]);
        }
        fprintf(grafic, "\n");
    }
    while (infranti->front != NULL) {
        echipa_curenta = infranti->front->val;
        //printf("%s\n",echipa_curenta.numele_echipei);
        fprintf(scor, "%.4f %s\n", calculeaza_scor(echipa_curenta.nr_victorii, etape), echipa_curenta.numele_echipei);
        deQueue(infranti);
    }
    //freeAllMemory are ca parametru 3 o var de tip Stack, iar infranti este de tip Queue
    //freeAllMemory(NULL, meciuri, infranti);
    freeQueue(meciuri);
    freeQueue(infranti);
    fclose(in);
    fclose(grafic);
    fclose(scor);

    return 0;
}


