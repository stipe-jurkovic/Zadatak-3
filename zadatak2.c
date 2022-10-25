// zadatak2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROGRAM_SUCCESS 0
#define MAX_NAME 50
#define MAX_LASTNAME 50

typedef struct _Osoba {

    char name[MAX_NAME];
    char lastname[MAX_LASTNAME];
    int yearOfBirth;

} Osoba;

typedef struct Cvor* Position;

typedef struct Cvor {

    Osoba Osoba;
    Position Next;

} Cvor;

int NewElBeg(Position P, Osoba O) {

    Position Q = malloc(sizeof(struct Cvor));
    Q->Next = P->Next;
    P->Next = Q;

    strcpy(Q->Osoba.name, O.name);
    strcpy(Q->Osoba.lastname, O.lastname);
    Q->Osoba.yearOfBirth = O.yearOfBirth;

    return PROGRAM_SUCCESS;
}

int NewElEnd(Position P, Osoba O) {

    Position Q = malloc(sizeof(Cvor));

    while (P->Next != NULL) {
        P = P->Next;
    }
    P->Next = Q;
    Q->Next = NULL;
    strcpy(Q->Osoba.name, O.name);
    strcpy(Q->Osoba.lastname, O.lastname);
    Q->Osoba.yearOfBirth = O.yearOfBirth;

    return PROGRAM_SUCCESS;
}

int PrintList(Position P) {

    P = P->Next;
    while (P != NULL) {

        printf("%s\n", P->Osoba.name);
        printf("%s\n", P->Osoba.lastname);
        printf("%i\n", P->Osoba.yearOfBirth);
        P = P->Next;
        printf("\n");
    }
    return PROGRAM_SUCCESS;
}
int findLastname(Position P, char lastname[MAX_LASTNAME]) {
    P = P->Next;

    while (P != NULL) {
        if (strcmp(P->Osoba.lastname, lastname) != 1) {
            printf("%s\n", P->Osoba.name);
            printf("%s\n", P->Osoba.lastname);
            printf("%i\n", P->Osoba.yearOfBirth);
            printf("\n");
        }
        P = P->Next;

    }
    return PROGRAM_SUCCESS;
}

int main()
{
    Osoba Osoba;
    Position headPoz = NULL;
    headPoz = malloc(sizeof(Cvor));
    headPoz->Next = NULL;
    strcpy(Osoba.name, "petar");
    strcpy(Osoba.lastname, "petric");
    Osoba.yearOfBirth = 1999;
    //printf("%s", Osoba.name);

    NewElBeg(headPoz, Osoba);
    NewElBeg(headPoz, Osoba);
    NewElBeg(headPoz, Osoba);
    NewElBeg(headPoz, Osoba);
    Osoba.yearOfBirth = 2001;
    strcpy(Osoba.lastname, "Lukacevic");
    NewElEnd(headPoz, Osoba);
    PrintList(headPoz);

    findLastname(headPoz, "Lukacevic");





    return PROGRAM_SUCCESS;
}

