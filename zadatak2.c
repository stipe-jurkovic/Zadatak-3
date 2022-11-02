#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROGRAM_SUCCESS 0
#define PROGRAM_FAILED 1
#define MAX_NAME 500
#define MAX_LASTNAME 500

typedef struct _Osoba {

    char name[MAX_NAME];
    char lastname[MAX_LASTNAME];
    int yearOfBirth;

} Osoba;

struct Cvor;

typedef struct Cvor* Position;

typedef struct Cvor {

    Osoba Osoba;
    Position Next;

} Cvor;



int Menu();
int NewEl(Position P, Osoba O);
int DelElByName(Position P, Osoba O);
int PrintEl(Position P);
Position PrevEl(Position P, Osoba O);
Position EndOfList(Position P);
int DelAll(Position P);
int NewElBeg(Position P, Osoba O);
int NewElEnd(Position P, Osoba O);
int NewElAfter(Position P, Osoba OA, Osoba O);
int NewElBefore(Position P, Osoba OB, Osoba O);
int PrintList(Position P);
int findLastname(Position P, char lastname[MAX_LASTNAME]);


int main()
{
    Osoba Osoba, Osoba2;
    Position headPoz;
    int p, od;
    
    p = 0;
    od = 1;

    headPoz = malloc(sizeof(Cvor));
    headPoz->Next = NULL;

    strcpy(Osoba.name, "");
    strcpy(Osoba.lastname, "");
    Osoba.yearOfBirth = 0;

    strcpy(Osoba2.name, "");
    strcpy(Osoba2.lastname, "");
    Osoba2.yearOfBirth = 0;


    while (od!=0) {

        Menu();
        scanf("%d", &od);

        switch (od)
        {
        case 1:
            printf("\n\nUnesite ime: "); scanf("%s", Osoba.name);
            printf("\n\nUnesite prezime: "); scanf("%s", Osoba.lastname);
            printf("\n\nUnesite godinu rodenja: "); scanf("%d", &Osoba.yearOfBirth);
            NewElBeg(headPoz, Osoba);
            break;
        case 2:
            printf("\n\nUnesite ime: "); scanf("%s", Osoba.name);
            printf("\n\nUnesite prezime: "); scanf("%s", Osoba.lastname);
            printf("\n\nUnesite godinu rodenja: "); scanf("%d", &Osoba.yearOfBirth);
            NewElEnd(headPoz, Osoba);
            break;
        case 3:
            printf("\n\nIza koje osobe? (Unesite podatke te osobe)\n\n");
            printf("\n\nUnesite ime: "); scanf("%s", Osoba.name);
            printf("\n\nUnesite prezime: "); scanf("%s", Osoba.lastname);
            printf("\n\nUnesite godinu rodenja: "); scanf("%d", &Osoba.yearOfBirth);
            printf("\n\nUnesite podatke osobe ciji se podatci trebaju unijeti.\n\n");
            printf("\n\nUnesite ime: "); scanf("%s", Osoba2.name);
            printf("\n\nUnesite prezime: "); scanf("%s", Osoba2.lastname);
            printf("\n\nUnesite godinu rodenja: "); scanf("%d", &Osoba2.yearOfBirth);
            NewElAfter(headPoz, Osoba, Osoba2);
            break;
        case 4:
            printf("\n\nIspred koje osobe? (Unesite podatke te osobe)\n\n");
            printf("\n\nUnesite ime: "); scanf("%s", Osoba.name);
            printf("\n\nUnesite prezime: "); scanf("%s", Osoba.lastname);
            printf("\n\nUnesite godinu rodenja: "); scanf("%d", &Osoba.yearOfBirth);
            printf("\n\nUnesite podatke osobe ciji se podatci trebaju unijeti.\n\n");
            printf("\n\nUnesite ime: "); scanf("%s", Osoba2.name);
            printf("\n\nUnesite prezime: "); scanf("%s", Osoba2.lastname);
            printf("\n\nUnesite godinu rodenja: "); scanf("%d", &Osoba2.yearOfBirth);
            NewElBefore(headPoz, Osoba, Osoba2);
            break;
        case 5:
            PrintList(headPoz);
            break;
        case 6:
            printf("\n\nUnesite prezime: "); scanf("%s", Osoba.lastname);
            findLastname(headPoz, Osoba.lastname);
            break;
        case 7:
            printf("\n\nUnesite ime: "); scanf("%s", Osoba.name);
            printf("\n\nUnesite prezime: "); scanf("%s", Osoba.lastname);
            printf("\n\nUnesite godinu rodenja: "); scanf("%d", &Osoba.yearOfBirth);
            DelElByName(headPoz, Osoba);
            break;
        case 8:
            //Ovdje ubaciti poziv na funkciju za sortiranje
            break;
        case 9:
            //Ovdje ubaciti poziv na funkciju za upis u datoteku
            break;
        case 10:
            //Ovdje ubaciti poziv na funkciju za ispis iz datoteke ispisuje se na ekran te se pise u listu
            break;
        case 11:
            DelAll(headPoz);
            break;
        default:
            printf("default");
            break;
        }
        memset(Osoba.name, 0, strlen(Osoba.name));
        memset(Osoba.lastname, 0, strlen(Osoba.lastname));
        Osoba.yearOfBirth = 0;
        memset(Osoba2.name, 0, strlen(Osoba2.name));
        memset(Osoba2.lastname, 0, strlen(Osoba2.lastname));
        Osoba2.yearOfBirth = 0;
    }
    
    DelAll(headPoz);
    free(headPoz);
    return PROGRAM_SUCCESS;
}

int Menu() {

    printf("#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("Unesite broj one opcije koju zelite odabrati.\n");
    printf("(0)  Prekinuti program.\n");
    printf("(1)  Dinamicki dodati novi element na pocetak liste.\n");
    printf("(2)  Dinamicki dodati novi element na kraj liste.\n");
    printf("(3)  Dinamicki dodati novi element iza odredenog elementa.\n");
    printf("(4)  Dinamicki dodati novi element ispred odredenog elementa.\n");
    printf("(5)  Ispisati listu.\n");
    printf("(6)  Pronaci element u listi (po prezimenu).\n");
    printf("(7)  Obrisati element iz liste.\n");
    printf("(8)  Sortirati listu po prezimenu osoba.\n");
    printf("(9)  Upisati listu u datoteku.\n");
    printf("(10) Ucitati listu iz datoteke.\n");
    printf("(11) Izbrisati listu.\n");
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n\n");
    printf("   Unos:    ");
    return PROGRAM_SUCCESS;
}

Position EndOfList(Position P) {

    while (P->Next != NULL) {
        P = P->Next;
    }
    return P;
}
Position PrevEl(Position P, Osoba O) {

   
    while (P->Next!= NULL && P->Next->Osoba.yearOfBirth != O.yearOfBirth 
        && strcmp(P->Next->Osoba.name, O.name)!=0 
        && strcmp(P->Next->Osoba.lastname, O.lastname) != 0) 
    {
        P = P->Next;
    }

    return P;
}
int PrintEl(Position P) {
    //P = P->Next;
    printf("\nName:       %s\n", P->Osoba.name);
    printf("Lastname:   %s\n", P->Osoba.lastname);
    printf("Birthyear:  %i\n", P->Osoba.yearOfBirth);
    printf("Age:        %i   (calculated from birthyear)\n", 2022 - P->Osoba.yearOfBirth);
    printf("\n");
    return PROGRAM_SUCCESS;
}
int DelElByName(Position P, Osoba O) {
    
    Position temp = NULL;

    P = PrevEl(P,O);
    if (P->Next==NULL)
    {
        printf("\n\nElement was not found!\n\n\n");
        return PROGRAM_FAILED;
    }
    temp = P->Next;
    P->Next = P->Next->Next;

    free(temp);
    printf("\n\nDeleted 1 element!\n\n\n");
    return PROGRAM_SUCCESS;
}
int DelAll(Position P) {

    int i = 0;
    if (P->Next == NULL)
    {
        printf("\n\nLista je prazna!! Success?\n\n\n");
        return PROGRAM_SUCCESS;
    }
    while (P->Next != NULL) {
    DelElByName(P, P->Next->Osoba);
    i++;
    }
    printf("\n\nDeleted list! Deleted %i entries.\n\n\n", i);
    return PROGRAM_SUCCESS;
}
int NewEl(Position P, Osoba O) {

    Position Q = malloc(sizeof(struct Cvor));

    if (Q == NULL)
    {
        printf("\n\nNedovoljno memorije.\n\n\n");
        return PROGRAM_FAILED;
    }

    strcpy(Q->Osoba.name, O.name);
    strcpy(Q->Osoba.lastname, O.lastname);
    Q->Osoba.yearOfBirth = O.yearOfBirth;

    Q->Next = P->Next;
    P->Next = Q;

    return PROGRAM_SUCCESS;
}
int NewElBeg(Position P, Osoba O) {

    NewEl(P, O);
    printf("\n\nNew element created at the begining of the list!\n\n\n");
    return PROGRAM_SUCCESS;
}
int NewElEnd(Position P, Osoba O) {

    P = EndOfList(P);
    NewEl(P, O);
    printf("\n\nNew element created at the end of the list!\n\n\n");
    return PROGRAM_SUCCESS;
}
int NewElAfter(Position P, Osoba OB, Osoba O) {

    P = PrevEl(P, OB);
    NewEl(P->Next,O);
    printf("\n\nNew element created!\n\n\n");
    return PROGRAM_SUCCESS;
}
int NewElBefore(Position P, Osoba OA, Osoba O) {

    P = PrevEl(P, OA);
    NewEl(P, O);
    printf("\n\nNew element created!\n\n\n");
    return PROGRAM_SUCCESS;
}
int PrintList(Position P) {

    P = P->Next;
    if (P == NULL)
    {
        printf("\n\nLista je prazna!!\n\n\n");
        return PROGRAM_SUCCESS;
    }
    while (P != NULL) {

        printf("\nName:       %s\n", P->Osoba.name);
        printf("Lastname:   %s\n", P->Osoba.lastname);
        printf("Birthyear:  %i\n", P->Osoba.yearOfBirth);
        printf("Age:        %i   (calculated from birthyear)\n", 2022 - P->Osoba.yearOfBirth);
        P = P->Next;
        printf("\n");
    }
    return PROGRAM_SUCCESS;
}
int findLastname(Position P, char lastname[MAX_LASTNAME]) {
    P = P->Next;

    while (P != NULL) {
        if (strcmp(P->Osoba.lastname, lastname) == 0) {
            PrintEl(P);
            return PROGRAM_SUCCESS;
        }
        P = P->Next;
    }
    printf("\nLastname not found!!\n\n");

    return PROGRAM_FAILED;
}
