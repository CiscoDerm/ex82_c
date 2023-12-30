#ifndef EXO_H
#define EXO_H

#define MAX_MOTS 100
#define MAX_MOTS_TAILLE 50
#define MAX_TYPE_TAILLE 10
#define MAX_DEFINITION_TAILLE 255

typedef struct {
    char mots[MAX_MOTS_TAILLE];
    char type[MAX_TYPE_TAILLE];
    char definition[MAX_DEFINITION_TAILLE];
} Dictionnaire;

void addMots(Dictionnaire dictionnaire[], int *countMots);
void searchMots(Dictionnaire dictionnaire[], int countMots);
void deleteMots(Dictionnaire dictionnaire[], int *countMots);
void modifyMots(Dictionnaire dictionnaire[], int countMots);
void listMotsByChar(Dictionnaire dictionnaire[], int countMots);
void listMotsByType(Dictionnaire dictionnaire[], int countMots);
void sortDictionnaire(Dictionnaire dictionnaire[], int countMots);
void displayAllMots(Dictionnaire dictionnaire[], int countMots);

#endif // EXO_H
