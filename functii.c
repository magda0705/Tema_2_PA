#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functii.h"

/*player data_player(FILE *file) {
    player player;
    player.nume = (char *)malloc(50);
    fscanf(file, "%s", player.nume);
    player.prenume = (char *)malloc(50);
    fscanf(file, "%s", player.prenume);
    fscanf(file, "%d", &player.puncte);
    return player;
}
*/
team data_team(FILE *file,int i) {
    team team;

    fscanf(file, "%f ", &team.scor);
    team.numele_echipei = (char *)malloc(50);
    fgets(team.numele_echipei, 50, file);
    team.numele_echipei[strlen(team.numele_echipei)-1]='\0';
    // if (team.numele_echipei[strlen(team.numele_echipei) - 3] == ' ')
    //     team.numele_echipei[strlen(team.numele_echipei) - 3] = '\0';
    // else
    //     team.numele_echipei[strlen(team.numele_echipei) - 2] = '\0';
    team.pozitie_meci=i;
    team.nr_victorii=0;
    //team.jucatori = (player *)malloc(team.nr_jucatori * sizeof(player));
    return team;
}

void enQueue(Queue *q, team echipa) {
    Node *newNode = malloc(sizeof(Node));
    newNode->val = echipa;
    newNode->next = NULL;

    if (q->rear == NULL)
        q->rear = newNode;
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    if (q->front == NULL) q->front = q->rear;
}

void deQueue(Queue *queue) {
    if (queue->front == NULL) return;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(temp);
}

void push(Stack **top, team team) {
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    newNode->val = team;
    newNode->next = *top;
    *top = newNode;
}

//functii pentru eliberarea memoriei
/*
void freePlayer(player player) {
    free(player.nume);
    free(player.prenume);
}
*/
void freeTeam(team t) {
    // for (int i = 0; i < t.nr_jucatori; i++) {
    //     freePlayer(t.jucatori[i]);
    // }
    // free(t.jucatori);
    free(t.numele_echipei);
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        freeTeam(temp->val);
        free(temp);
    }
}

void freeQueue(Queue *q) {
    while (q->front != NULL) {
        Node *temp = q->front;
        q->front = q->front->next;
        freeTeam(temp->val);
        free(temp);
    }
    free(q);
}

// void freeStack(Stack *top) {
//     Stack *temp;
//     while (top != NULL) {
//         temp = top;
//         top = top->next;
//         freeTeam(temp->val);
//         free(temp);
//     }
// }

// functie care contine toate functiile de eliberare a memoriei
// void freeAllMemory(Node *listHead, Queue *queue, Stack *stack) {
//     freeList(listHead);
//     freeQueue(queue);
//     freeStack(stack);
// }

double powp(double a, int b)
{
    double p=1;
    while(b>0)
    {
        p=p*a;
        b--;
    }
    return p;
}

double calculeaza_scor(int runda, int etape) {
    double a=2.00-0.15;
    double num=0.15*powp(a,runda);
    double numi=powp(2,etape)+powp(a,etape)*(Q-1);
    return num/numi;
}

bool compara_echipe(team echipa1, team echipa2) {
    float scorEchipa1 = 0, scorEchipa2 = 0;
    scorEchipa1=echipa1.scor;
    scorEchipa2=echipa2.scor;
    if (scorEchipa1 != scorEchipa2) {
        return scorEchipa1 > scorEchipa2;
    } else {
        return strcmp(echipa1.numele_echipei, echipa2.numele_echipei) > 0;
    }
}

