#include <stdio.h>

/* what is in the function */
struct CharacterSet{
    char name[12];
    char race[12];
    int attack;
    int defense;
};

struct CharacterSet createCharacter(){
    struct CharacterSet aCharacter; /* make me a new one */
    
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
    
    /* Checking the variables before the function */
    int sum = aCharacter.attack + aCharacter.defense;
    while(sum > 10){

        printf("Oops. There’s a problem. The sum of your attack and defense points is greater than 10. Please try again.\n");
        
        printf("Enter attack: ");
            scanf("%d", &aCharacter.attack);
        
        printf("Enter defense: ");
            scanf("%d", &aCharacter.defense); 
    
        printf("%s is %s and has an attack of %d and a defense of %d.\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense);
        
        sum = aCharacter.attack + aCharacter.defense;
    }

    return aCharacter;
}

int main(){
    struct CharacterSet aCharacter = createCharacter();
    
    return 0;
}
