// Malheuresement j'ai completement oublié de faire un OUTPUT des données sur un fichier .json ou .txt
// Et surtout ATTENTION ATTENTION : Ne pas mettre d'espace dans le mots que l'on veut ajouter.
// Maxim Dufosse

// En vous soihaitant de bonnes vacances et surtout de bonnes fêtes ;) 



#include "exo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ajouter un mot au dictionnaire
void addMots(Dictionnaire dictionnaire[], int *countMots) {
    if (*countMots >= MAX_MOTS) {
        printf("Dictionnaire plein!\n");
        return;
    }

    printf("Entrez un mot : ");
    scanf("%s", dictionnaire[*countMots].mots);
    printf("Entrez le type (N.F, N.M, ADJ, ...): ");
    scanf("%s", dictionnaire[*countMots].type);
    getchar(); // Nettoyer le buffer d'entrée
    printf("Entrez une définition : ");
    fgets(dictionnaire[*countMots].definition, MAX_DEFINITION_TAILLE, stdin);
    dictionnaire[*countMots].definition[strcspn(dictionnaire[*countMots].definition, "\n")] = 0;

    (*countMots)++;
    sortDictionnaire(dictionnaire, *countMots);
}

// Recherche d'un mot dans le dictionnaire
void searchMots(Dictionnaire dictionnaire[], int countMots) {
    char Trv[MAX_MOTS_TAILLE];
    printf("Mot à rechercher : ");
    scanf("%s", Trv);

    for (int i = 0; i < countMots; i++) {
        if (strcmp(dictionnaire[i].mots, Trv) == 0) {
            printf("Mot: %s\nType: %s\nDéfinition: %s\n", dictionnaire[i].mots, dictionnaire[i].type, dictionnaire[i].definition);
            return;
        }
    }
    printf("Mot non trouvé.\n");
}

// Supprimer un mot du dictionnaire
void deleteMots(Dictionnaire dictionnaire[], int *countMots) {
    char MotsSup[MAX_MOTS_TAILLE];
    printf("Mot à supprimer : ");
    scanf("%s", MotsSup);

    for (int i = 0; i < *countMots; i++) {
        if (strcmp(dictionnaire[i].mots, MotsSup) == 0) {
            for (int j = i; j < (*countMots) - 1; j++) {
                dictionnaire[j] = dictionnaire[j + 1];
            }
            (*countMots)--;
            printf("Mot supprimé.\n");
            return;
        }
    }
    printf("Mot non trouvé.\n");
}

// Modifier un mot ou sa définition
void modifyMots(Dictionnaire dictionnaire[], int countMots) {
    char MotsModifier[MAX_MOTS_TAILLE];
    printf("Mot à modifier : ");
    scanf("%s", MotsModifier);

    for (int i = 0; i < countMots; i++) {
        if (strcmp(dictionnaire[i].mots, MotsModifier) == 0) {
            printf("Nouveau mot (laissez vide pour ne pas modifier) : ");
            getchar(); // Nettoyer le buffer d'entrée
            char newMots[MAX_MOTS_TAILLE];
            fgets(newMots, MAX_MOTS_TAILLE, stdin);
            newMots[strcspn(newMots, "\n")] = 0;

            if (strlen(newMots) > 0) {
                strcpy(dictionnaire[i].mots, newMots);
            }

            printf("Nouvelle définition (laissez vide pour ne pas modifier) : ");
            char newDefinition[MAX_DEFINITION_TAILLE];
            fgets(newDefinition, MAX_DEFINITION_TAILLE, stdin);
            newDefinition[strcspn(newDefinition, "\n")] = 0;

            if (strlen(newDefinition) > 0) {
                strcpy(dictionnaire[i].definition, newDefinition);
            }

            printf("Mot modifié.\n");
            sortDictionnaire(dictionnaire, countMots);
            return;
        }
    }
    printf("Mot non trouvé.\n");
}

// Lister des mots commençant par un caractère donné
void listMotsByChar(Dictionnaire dictionnaire[], int countMots) {
    char startChar;
    printf("Lister des mots commençant par le caractère : ");
    scanf(" %c", &startChar); // Notez l'espace avant %c pour consommer les espaces blancs

    int found = 0;
    for (int i = 0; i < countMots; i++) {
        if (dictionnaire[i].mots[0] == startChar) {
            printf("%s - %s\n", dictionnaire[i].mots, dictionnaire[i].definition);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun mot trouvé commençant par '%c'.\n", startChar);
    }
}

// Lister des mots et leur nombre pour un type donné
void listMotsByType(Dictionnaire dictionnaire[], int countMots) {
    char type[MAX_TYPE_TAILLE];
    printf("Lister des mots pour le type : ");
    scanf("%s", type);

    int incr = 0;
    for (int i = 0; i < countMots; i++) {
        if (strcmp(dictionnaire[i].type, type) == 0) {
            printf("%s - %s\n", dictionnaire[i].mots, dictionnaire[i].definition);
            incr++;
        }
    }

    printf("Nombre de mots de type '%s': %d\n", type, incr);
}

// Trier le dictionnaire dans l'ordre alphabétique
void sortDictionnaire(Dictionnaire dictionnaire[], int countMots) {
    Dictionnaire temp;
    for (int i = 0; i < countMots - 1; i++) {
        for (int j = i + 1; j < countMots; j++) {
            if (strcmp(dictionnaire[i].mots, dictionnaire[j].mots) > 0) {
                temp = dictionnaire[i];
                dictionnaire[i] = dictionnaire[j];
                dictionnaire[j] = temp;
            }
        }
    }
}

void displayAllMots(Dictionnaire dictionnaire[], int countMots) {
    if (countMots == 0) {
        printf("Le dictionnaire est vide.\n");
        return;
    }

    printf("Affichage de tous les mots:\n\n");
    for (int i = 0; i < countMots; i++) {
        printf("Mot: %s\nType: %s\nDéfinition: %s\n\n", dictionnaire[i].mots, dictionnaire[i].type, dictionnaire[i].definition);
    }
}
