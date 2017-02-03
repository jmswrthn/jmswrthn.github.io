#include <stdio.h>
#include <string.h>

//defines the character

struct Characters{ 
	
	char name[12];  //Need different code to be able to input two names. i.e.- Chandler Tew
	int attack;
	int defense;
	
};

//Function that prompts user to input info into character struct

struct Characters createCharacter(){
struct Characters aCharacter;

printf("Input character name: ");
scanf("%s",aCharacter.name);

printf("Input desired attack stats: ");
scanf("%d",&aCharacter.attack);

printf("Input desired defense stats: ");
scanf("%d",&aCharacter.defense);

return aCharacter;	
}

// Main function stands alone right now. The above code isn't used yet in main.

int main(){

char choice[12];

printf("Welcome Players! If you're ready, please type an option:\n");
printf("Type 'new' to create your own unique characters or 'load' to use ones already on file: ");
scanf("%s",&choice);

if(strcmp(choice, "new") == 0){
	printf("Cool beans. Let's get started.\n");
	
/* 
   Code to run the struct function goes here.
   Add a FILE* and for loop with the struct.
*/   
   FILE* charactersFile = fopen("characters.data","w");
   for (int i = 0; i < 2; i++){
		struct Characters aCharacter = createCharacter();
		fprintf(charactersFile, "%s %d %d\n", aCharacter.name, aCharacter.attack, aCharacter.defense);
	}
   fclose(charactersFile);
   
	
}

else if(strcmp(choice, "load") == 0){
	printf("Lame sauce, but ok. Here they are.\n");
	
/*
   Code to read from a .data file.
   FILE* and for loop.
*/   
   FILE* charactersFile = fopen("characters.data","r");
	for (int i = 0; i < 2; i++){
		struct Characters aCharacter;
		fscanf(charactersFile, "%s %d %d", aCharacter.name, &aCharacter.attack, &aCharacter.defense);
		
		printf("%s has a %d attack and a %d defense. %s is awesome.\n", aCharacter.name, aCharacter.attack, aCharacter.defense, aCharacter.name);
		
	}
	fclose(charactersFile);

	
}

// This else statement will only run if user doesn't follow input instructions

else{	
printf("Someone doesn't know how to follow instructions.\nCome back later when you're ready.");
}

return 0;	
}