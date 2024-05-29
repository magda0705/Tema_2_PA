#ifndef FUNCTII_H
#define FUNCTII_H

#include <stdbool.h> // include stdbool.h pentru tipul bool

#define DECIMALS 4
#define TEAMS 32
#define Q 0.15

/*typedef struct {
    char *nume;
    char *prenume;
    int puncte;
} player;
*/
typedef struct {
    //int nr_jucatori;
    float scor;
    int pozitie_meci;
    int nr_victorii;
    char *numele_echipei;
} team;

typedef struct Node {
    team val;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

typedef struct Stack {
    team val;
    struct Stack *next;
} Stack;

team data_team(FILE *file,int i);
//player data_player(FILE *file);
void enQueue(Queue *q, team echipa);
void deQueue(Queue *queue);
void push(Stack **top, team team);
//void freePlayer(player player);
void freeTeam(team t);
void freeList(Node *head);
void freeQueue(Queue *q);
void freeStack(Stack *top);
void freeAllMemory(Node *listHead, Queue *queue, Stack *stack);
double calculeaza_scor(int runda, int etape);
bool compara_echipe(team echipa1, team echipa2);
double powp(double a, int b);
#endif // FUNCTII_H


