#include <stdio.h>

struct CharacterSet{
    char name[12];
    char race[12];
    int attack;
    int defense;
};

void CreateCharacter(){
    struct CharacterSet aCharacter;
    
    printf("Enter character's name: ");
        scanf("%s", aCharacter.name);
    
    printf("Enter charactere's race: ");
        scanf("%s", aCharacter.race);
    
    printf("Enter attack: ");
        scanf("%d", &aCharacter.attack);
        
    printf("Enter defense: ");
        scanf("%d", &aCharacter.defense);
    
    printf("%s is %s and has an attack of %d and a defense of %d.\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense);
}

int main(){
    CreateCharacter();
    return 0;
}
