#include <stdio.h>

struct CharacterSet{
    char name[12];
    char race[12];
    int attack;
    int defense;
};

/* return character set */
struct CharacterSet createCharacter(){
    struct CharacterSet aCharacter;
    
    printf("Enter character's name: ");
        scanf("%s", aCharacter.name);
    
    printf("Enter charactere's race: ");
        scanf("%s", aCharacter.race);
    
    printf("Now choose the strength of our character. Your attack and defense score cannot be greater than 10.\n");
    
    printf("Enter attack: ");
        scanf("%d", &aCharacter.attack);
        
    printf("Enter defense: ");
        scanf("%d", &aCharacter.defense); 
    
    printf("%s is %s and has an attack of %d and a defense of %d.\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense);

    return aCharacter;
}

int main(){
    struct CharacterSet aCharacter = createCharacter();

    int sum = -5;
    while(sum <= 10){
        sum = aCharacter.attack + aCharacter.defense;

        printf("Oops. There’s a problem. The sum of your attack and defense points is greater than 10. Please try again.\n");
        
        printf("Enter attack: ");
            scanf("%d", &aCharacter.attack);
        
        printf("Enter defense: ");
            scanf("%d", &aCharacter.defense); 
    
        printf("%s is %s and has an attack of %d and a defense of %d.\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense);
    }
    return 0;
}
