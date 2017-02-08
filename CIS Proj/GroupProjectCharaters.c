#include <stdio.h>

struct Character{

char name[12];
int strength;
int defense;
char race[12];
};

void createAndPrintCharacter(){
    struct Character aCharacter;
    
    printf("Enter character name: ");
    scanf("%s",aCharacter.name);
    
    printf("strength: ");
    scanf("%d",&aCharacter.strength);
    
    printf("defense: ");
    scanf("%d",&aCharacter.defense);
    
    printf("race: ");
    scanf("%s",aCharacter.race);
    
    printf("%s is the character name and %d is the strength and %d is the defense and %s is the race\n", aCharacter.name, aCharacter.strength, aCharacter.defense, aCharacter.race);
}
    
int main(){ 
    
    createAndPrintCharacter();
    return 0;
} 