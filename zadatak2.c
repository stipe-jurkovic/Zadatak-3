#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROGRAM_SUCCESS 0
#define PROGRAM_FAILED 1
#define MAX_NAME 500
#define MAX_LASTNAME 500
#define MAX_FILE_NAME 50

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
int PrintToFile(Position P, char nameOfFile[MAX_FILE_NAME]);
int ReadFromFile(char nameOfFile[MAX_FILE_NAME]);
int SortByLastname(Position P);
int cmp(char str1[MAX_LASTNAME], char str2[MAX_LASTNAME]);

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
            SortByLastname(headPoz);
            break;
        case 9:;
            printf("Unesite ime datoteke (pr. ime.txt):\n");
            char fileName[MAX_FILE_NAME] = "";
            scanf(" %s", fileName);
            PrintToFile(headPoz, fileName);
            break;
        case 10:;
            printf("Unesite ime datoteke (pr. ime.txt):\n");
            char nameOfFile[MAX_FILE_NAME] = "";
            scanf(" %s", nameOfFile);
            ReadFromFile(nameOfFile);
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

int PrintToFile(Position P, char nameOfFile[MAX_FILE_NAME]) {
    FILE *file = NULL;
    char fileName[MAX_FILE_NAME] = "";
   
    strcpy(fileName, nameOfFile);
    file = fopen(fileName, "w");
   
    if (file == NULL)
    {
        printf("\n\nNedovoljno prostora.\n\n");
        return PROGRAM_FAILED;
    }
   
    P = P->Next;
    if (P == NULL)
    {
        printf("\n\nLista je prazna!!\n\n\n");
        return PROGRAM_FAILED;
    }
    while (P != NULL) {

        fprintf(file, "\nName:       %s\n", P->Osoba.name);
        fprintf(file, "Lastname:   %s\n", P->Osoba.lastname);
        fprintf(file, "Birthyear:  %i\n", P->Osoba.yearOfBirth);
        P = P->Next;
        fprintf(file, "\n");
    }
   
    printf("\n\nSuccessfully added the list to list.txt\n\n");
    fclose(file);
   
    return PROGRAM_SUCCESS;
}

int ReadFromFile(char nameOfFile[MAX_FILE_NAME])
{
    char fileName[MAX_FILE_NAME] = "";
    FILE *file = NULL;
    char c = "\0";
    strcpy(fileName, nameOfFile);
    strcpy(fileName, nameOfFile);
    file = fopen(fileName, "r");
   
    if (file == NULL)
    {
        printf("\n\nNemoguce otvoriti datoteku.\n\n");
        return PROGRAM_FAILED;
    }
   
    c = fgetc(file);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(file);
    }
   
    printf("\n\nKraj liste.\n\n");
    fclose(file);
    return PROGRAM_SUCCESS;
}

int cmp(char str1[MAX_LASTNAME], char str2[MAX_LASTNAME])
{
    if (strcmp(str1, str2) == 0)
        return 1; // jednaki stringovi
        
    return 0;
}

int SortByLastname(Position P)
{
    Position curr = NULL;
    Position prev = NULL;
    Position temp = NULL;
    Position end = NULL;
   
    while (P-> Next != end)
    {
        prev = P;
        curr = P -> Next;

        while (curr -> Next != end)
        {
            if (strcmp(curr -> Osoba.lastname, curr -> Next -> Osoba.lastname) > 0)
            {
                temp = curr -> Next;
                prev -> Next = temp;
                curr -> Next = temp -> Next;
                temp -> Next = curr;
                curr = temp;
            }
            
            else if (cmp(curr -> Osoba.lastname, curr -> Next -> Osoba.lastname)
                    && strcmp(curr -> Osoba.name, curr -> Next -> Osoba.name) > 0)
            {
                temp = curr -> Next;
                prev -> Next = temp;
                curr -> Next = temp -> Next;
                temp -> Next = curr;
                curr = temp;
            }
            
            else if (cmp(curr -> Osoba.lastname, curr -> Next -> Osoba.lastname)
                    && strcmp(curr -> Osoba.name, curr -> Next -> Osoba.name) == 0
                    && curr -> Osoba.yearOfBirth > curr -> Next -> Osoba.yearOfBirth)
            {
                temp = curr -> Next;
                prev -> Next = temp;
                curr -> Next = temp -> Next;
                temp -> Next = curr;
                curr = temp;
            }

            prev = curr;
            curr = curr -> Next;
        }

        end = curr;
    }
    
    printf("\n\nList sorted.\n\n");

    return PROGRAM_SUCCESS;
}
