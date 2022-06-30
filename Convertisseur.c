#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void convertir(int, int, char*);
int trouverValeur(char);

int main(int argc, char *argv[]) {
    int previousBase, newBase;
    
    printf("Base originale : ");
    scanf("%d", &previousBase);
    
    printf("Base visée : ");
    scanf("%d", &newBase);
    
    for( int i = 1; i < argc; i++ )
        convertir(previousBase, newBase, argv[i]);
    
    return 0;
}

void convertir(int previousBase, int newBase, char* num) {
    int decVal = 0;
    
    // Calcul de la valeur en décimal
    for( int i = 0; i < strlen(num); i++ ) {
        // On lit de droite à gauche
        char c = num[strlen(num) - i - 1];
        
        decVal += trouverValeur(c) * pow(previousBase, i);
    }
    
    // Détermination de la puissance du premier caractère du nouveau nombre
    int puissanceMax = 0;
    
    while( (int)(decVal/pow(newBase, puissanceMax + 1)) > 0 )
        puissanceMax++;
        
    int puissance = puissanceMax;
    
    // Construction de le nouvelle chaîne de caractère
    char newStr[puissance + 1];
    
    char newChar;
    
    while( puissance >= 0 ) {
        // Détermination du nouveau caractère
        newChar = (int)(decVal / pow(newBase, puissance)) + ( (int)(decVal / pow(newBase, puissance)) < 10 ? 48 : 87 );
        
        // Ajout du caractère à la chaîne
        newStr[puissanceMax - puissance] = newChar;
        
        // Nouvelle valeur
        decVal = decVal - pow(newBase, puissance) * (int)(decVal / pow(newBase, puissance));
        
        // On passe à la puissance inférieure
        puissance--;
    }
    
    // Affichage final
    for( int i = 0; i <= puissanceMax; i++ )
        printf("%c", newStr[i]);
    
    printf(" ");
}

int trouverValeur(char c) {
    if( isdigit(c) ) return (int)c - 48;
    else             return (int)c - 87;
}
