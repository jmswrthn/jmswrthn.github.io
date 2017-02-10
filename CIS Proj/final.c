#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
    
    printf("Now choose the strength of our character. Your attack and defense score cannot be greater than 10.\n\n");
    
    printf("Enter attack: ");
        scanf("%d", &aCharacter.attack);
        
    printf("Enter defense: ");
        scanf("%d", &aCharacter.defense); 
    
    printf("%s is %s and has an attack of %d and a defense of %d.\n\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense);
    
    /* Checking the variables before the function */
    int sum = aCharacter.attack + aCharacter.defense;
    while(sum > 10){

        printf("Oops. There’s a problem. The sum of your attack and defense points is greater than 10. Please try again.\n\n");
        
        printf("Enter attack: ");
            scanf("%d", &aCharacter.attack);
        
        printf("Enter defense: ");
            scanf("%d", &aCharacter.defense); 
    
        printf("%s is %s and has an attack of %d and a defense of %d.\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense);
        
        sum = aCharacter.attack + aCharacter.defense;
    }

    return aCharacter;
}
int roll(){
	srand(time(NULL));
    int dieVal= (rand() %6)+1;
    //printf("%d %d \n", dieVal );
	//printf("\n");
	return dieVal;
}
int attackInterf(){
	
	struct CharacterSet playerChar;
	struct CharacterSet player2Char;
	
	FILE* charactersFile = fopen("characters.data","r");
	for (int i = 0; i < 2; i++){
		if(i == 0)
    	fscanf(charactersFile, "%s %s %d %d", playerChar.name, &playerChar.race, &playerChar.attack, &playerChar.defense);
		else if(i == 1)
		{
		fscanf(charactersFile, "%s %s %d %d", player2Char.name, &player2Char.race, &player2Char.attack, &player2Char.defense);	
		}
		// printf("%s is a %s and has a %d attack and a %d defense. %s is awesome.\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense, aCharacter.name);
		
	}
	fclose(charactersFile);

	/*struct CharacterSet Playerchar = createCharacter();
	struct CharacterSet Player2char = createCharacter();*/
	
	//Playerchar.attack = 5;
	//Playerchar.defense = 5;
	//Player2char.attack = 5;
	//Player2char.defense = 5;
	int player1Atk = playerChar.attack;
	int attackOne;
	int player2Atk  = player2Char.attack;
	int attackTwo;
	int player1Def  = playerChar.defense;
	int defOne;
	int player2Def  = player2Char.defense;
	int defTwo;
	int firstmenuchoice;
	int secondmenuchoice;
	int dieRoll;
	int firstPWins = 0;
	int secondPwins = 0;
	
	while(firstPWins != 3 && secondPwins != 3){
		//Player one roll Attack and Defence Calc
		printf("\n%s do you wish to \n(1) Attack (2)Defend: ", playerChar.name);
		scanf("%d",&firstmenuchoice);
		while((firstmenuchoice != 1) && (firstmenuchoice != 2)){
			printf("\n%s you entered:%d please enter a (1 or 2) to \n(1) Attack or (2)Defend: ",playerChar.name,firstmenuchoice);
			scanf("%d",&firstmenuchoice);
		}
		dieRoll=roll();
		if(firstmenuchoice == 1){
			attackOne = (dieRoll + player1Atk);
			printf("\n%s attack of %d plus a roll of %d as a total attack of %d\n", playerChar.name,player1Atk,dieRoll,attackOne);
		}
		else{
			defOne = (dieRoll + player1Def);
			printf("\n%s defense of %d plus a roll of %d as a total defence of %d\n",playerChar.name,player1Def,dieRoll,defOne);
		}
		
		//Player two roll Attack and Defence Calc
		printf("\n%s do you wish to \n(1) Attack (2)Defend: ", player2Char.name);
		scanf("%d",&secondmenuchoice);
		while((secondmenuchoice != 1) && (secondmenuchoice != 2)){
			printf("\n%s you entered:%d please enter a (1 or 2) to \n(1) Attack or (2)Defend: ",player2Char.name,secondmenuchoice);
			scanf("%d",&secondmenuchoice);
		}
		dieRoll=roll();
		if(secondmenuchoice == 1){
			attackTwo = (dieRoll + player2Atk);
			printf("\n%s attack of %d plus a roll of %d as a total attack of %d\n",player2Char.name,player2Atk,dieRoll,attackTwo);
		}
		else{
			defTwo = (dieRoll + player2Def);
			printf("\n%s defence of %d plus a roll of %d as a total defence of %d\n",player2Char.name,player2Def,dieRoll,defTwo);
		}
		//both attack
		if(firstmenuchoice == 1 && secondmenuchoice == 1){
			printf("\n%s had an attack of %d and a defence of %d while %s had an attack of %d and a defence of %d\n",playerChar.name,attackOne,player1Def,player2Char.name,attackTwo,player2Def);
			if((attackOne+player1Def)>(attackTwo+player2Def)){
				firstPWins++;
				printf("\n%s wins with a total of %d of 3 won\n",playerChar.name,firstPWins);
			}
			else if((attackOne+player1Def)<(attackTwo+player2Def)){
				secondPwins++;
				printf("\n%s wins with a total of %d of 3 won\n",player2Char.name,secondPwins);
			}
			else{
				printf("\nBoth players, %s and %s, are equaly powerful this round play again\n",playerChar.name,player2Char.name);
			}
		}
		//p1 attack and p2 defend
		else if((firstmenuchoice == 1 && secondmenuchoice == 2)){
			printf("\n%s had an attack of %d and a defence of %d while %s had an attack of %d and a defence of %d\n",playerChar.name,attackOne,player1Def,player2Char.name,player2Atk,defTwo);
			if((attackOne+player1Def)>(player2Atk+defTwo)){
				firstPWins++;
				printf("\n%s wins with a total of %d of 3 won\n",playerChar.name,firstPWins);
			}
			else if((attackOne+player1Def)<(player2Atk+defTwo)){
				secondPwins++;
				printf("\n%s wins with a total of %d of 3 won\n",player2Char.name,secondPwins);
			}
			else{
				printf("\nBoth players, %s and %s, are equaly powerful this round play again\n",playerChar.name,player2Char.name);
			}
		}
		//p1 defend and p2 attack
		else if((firstmenuchoice == 2 && secondmenuchoice == 1)){
			printf("\n%s had an Attack of %d and a defence of %d while %s had an Attack of %d and a defence of %d\n",playerChar.name,player1Atk,defOne,player2Char.name,attackTwo,player2Def);	
			if((player1Atk+defOne)>(attackTwo+player2Def)){
				firstPWins++;
				printf("\n%s wins with a total of %d of 3 won\n",playerChar.name,firstPWins);
			}
			else if((player1Atk+defOne)>(attackTwo+player2Def)){
				secondPwins++;
				printf("\n%s wins with a total of %d of 3 won\n",player2Char.name,secondPwins);
			}
			else{
				printf("\nBoth players, %s and %s, are equaly powerful this round play again\n",playerChar.name,player2Char.name);
			}
		}
		//p1 and p2 both defend
		else{
			printf("\nBoth players, %s and %s, went the Buddha's path attacking none in order achieve nirvana. A tie this round there goes the game.\n",playerChar.name,player2Char.name);
		}
		//resets for begening of loop
		firstmenuchoice = 0;
		secondmenuchoice = 0;
	}		
    return 0;
}
/************************************
*************************************/

int main(){
	
	char choice[12];

printf("Welcome Players! If you're ready, please type an option:\n");
printf("Type 'new' to create your own unique characters or 'load' to use ones already on file: ");
scanf("%s",&choice);

if(strcmp(choice, "new") == 0){
	printf("Cool beans. Let's get started.\n\n");
	
/* 
   Code to run the struct function goes here.
   Add a FILE* and for loop with the struct.
*/   
   FILE* charactersFile = fopen("characters.data","w");
   for (int i = 0; i < 2; i++){
		struct CharacterSet aCharacter = createCharacter();
		fprintf(charactersFile, "%s %s %d %d", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense);
	}
   fclose(charactersFile);
   
   printf("Let's get ready to rumble!!!\n");
   attackInterf();
   
}

else if(strcmp(choice, "load") == 0){
	printf("Lame sauce, but ok. Here they are.\n\n");
	
/*
   Code to read from a .data file.
   FILE* and for loop.
*/   
   FILE* charactersFile = fopen("characters.data","r");
	for (int i = 0; i < 2; i++){
		struct CharacterSet aCharacter;
		fscanf(charactersFile, "%s %s %d %d", aCharacter.name, &aCharacter.race, &aCharacter.attack, &aCharacter.defense);
		
		printf("%s is a %s and has a %d attack and a %d defense. %s is ready for battle.\n", aCharacter.name, aCharacter.race, aCharacter.attack, aCharacter.defense, aCharacter.name);
		
	}
	fclose(charactersFile);
	
	attackInterf();
}

// This else statement will only run if user doesn't follow input instructions

else{	
printf("Someone doesn't know how to follow instructions.\nCome back later when you're ready.");
}
	
	/*
	attackInterf();
	*/
	
    return 0;
}