#include <stdio.h>

/* Parts we need
        Create Character
        Load/Write New Character
        Random Dice
        How much damage is dealt
        Write damage to character
        */

struct CharacterSet{
    char name[12];
    char race[12];
    int attack;
    int defense;
}

void CreateCharacter(){
    struct CharacterSet aCharacter;
    int quotient = dividend/divisor;
    
    printf("Enter character's name: ");
        scanf("%s", aCharacter.name);
    
    printf("Enter charactere's race: ");
        scanf("%s", aCharacter.race);
    
    printf("Enter attack: ");
        scanf("%lf", aCharacter.attack);
        
    printf("Enter defense: ");
        scanf("%lf", aCharacter.defense);
    
    printf("%s is %s and has a strength of %d and health of %d o\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense);
}

int main(){
    CreateCharacter();
    return 0;
}
