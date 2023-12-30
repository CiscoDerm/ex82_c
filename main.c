#include "exo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Dictionnaire dictionnaire[MAX_MOTS];
    int countMots = 0;
    int choix;

    do {
        printf("\nDictionnaire de Mots\n");
        printf("1. Ajouter un mot\n");
        printf("2. Recherche d'un mot\n");
        printf("3. Supprimer un mot\n");
        printf("4. Modifier un mot\n");
        printf("5. Lister des mots par caractère\n");
        printf("6. Lister des mots par type\n");
        printf("7. Afficher votre dictionnaire\n");
        printf("8. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: system("clear"); addMots(dictionnaire, &countMots); break;
            case 2: system("clear"); searchMots(dictionnaire, countMots); break;
            case 3: system("clear"); deleteMots(dictionnaire, &countMots); break;
            case 4: system("clear"); modifyMots(dictionnaire, countMots); break;
            case 5: system("clear"); listMotsByChar(dictionnaire, countMots); break;
            case 6: system("clear"); listMotsByType(dictionnaire, countMots); break;
            case 7: system("clear"); displayAllMots(dictionnaire, countMots); break;
            case 8: printf("Au revoir!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 8);

    return 0;
}
