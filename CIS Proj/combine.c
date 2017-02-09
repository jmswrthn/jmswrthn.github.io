#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int roll(){
	srand(time(NULL));
    int dieVal= (rand() %6)+1;
    //printf("%d %d \n", dieVal );
	//printf("\n");
	return dieVal;
}
int attackInterf(){
	struct CharacterSet Playerchar = createCharacter();
	struct CharacterSet Player2char = createCharacter();
	//Playerchar.attack = 5;
	//Playerchar.defense = 5;
	//Player2char.attack = 5;
	//Player2char.defense = 5;
	int player1Atk = Playerchar.attack;
	int attackOne;
	int player2Atk  = Player2char.attack;
	int attackTwo;
	int player1Def  = Playerchar.defense;
	int defOne;
	int player2Def  = Player2char.defense;
	int defTwo;
	int firstmenuchoice;
	int secondmenuchoice;
	int dieRoll;
	int firstPWins = 0;
	int secondPwins = 0;
	
	while(firstPWins != 3 && secondPwins != 3){
		//Player one roll Attack and Defence Calc
		printf("\n%s do you wish to \n(1) Attack (2)Defend: ", Playerchar.name);
		scanf("%d",&firstmenuchoice);
		while((firstmenuchoice != 1) && (firstmenuchoice != 2)){
			printf("\n%s you entered:%d please enter a (1 or 2) to \n(1) Attack or (2)Defend: ",Playerchar.name,firstmenuchoice);
			scanf("%d",&firstmenuchoice);
		}
		dieRoll=roll();
		if(firstmenuchoice == 1){
			attackOne = (dieRoll + player1Atk);
			printf("\n%s attack of %d plus a roll of %d as a total attack of %d\n", Playerchar.name,player1Atk,dieRoll,attackOne);
		}
		else{
			defOne = (dieRoll + player1Def);
			printf("\n%s defense of %d plus a roll of %d as a total defence of %d\n",Playerchar.name,player1Def,dieRoll,defOne);
		}
		
		//Player two roll Attack and Defence Calc
		printf("\n%s do you wish to \n(1) Attack (2)Defend: ", Player2char.name);
		scanf("%d",&secondmenuchoice);
		while((secondmenuchoice != 1) && (secondmenuchoice != 2)){
			printf("\n%s you entered:%d please enter a (1 or 2) to \n(1) Attack or (2)Defend: ",Player2char.name,secondmenuchoice);
			scanf("%d",&secondmenuchoice);
		}
		dieRoll=roll();
		if(secondmenuchoice == 1){
			attackTwo = (dieRoll + player2Atk);
			printf("\n%s attack of %d plus a roll of %d as a total attack of %d\n",Player2char.name,player2Atk,dieRoll,attackTwo);
		}
		else{
			defTwo = (dieRoll + player2Def);
			printf("\n%s defence of %d plus a roll of %d as a total defence of %d\n",Player2char.name,player2Def,dieRoll,defTwo);
		}
		//both attack
		if(firstmenuchoice == 1 && secondmenuchoice == 1){
			printf("\n%s had an attack of %d and a defence of %d while %s had an attack of %d and a defence of %d\n",Playerchar.name,attackOne,player1Def,Player2char.name,attackTwo,player2Def);
			if((attackOne+player1Def)>(attackTwo+player2Def)){
				firstPWins++;
				printf("\n%s wins with a total of %d of 3 won\n",Playerchar.name,firstPWins);
			}
			else if((attackOne+player1Def)<(attackTwo+player2Def)){
				secondPwins++;
				printf("\n%s wins with a total of %d of 3 won\n",Player2char.name,secondPwins);
			}
			else{
				printf("\nBoth players, %s and %s, are equaly powerful this round play again\n",Playerchar.name,Player2char.name);
			}
		}
		//p1 attack and p2 defend
		else if((firstmenuchoice == 1 && secondmenuchoice == 2)){
			printf("\n%s had an attack of %d and a defence of %d while %s had an attack of %d and a defence of %d\n",Playerchar.name,attackOne,player1Def,Playerchar.name,player2Atk,defTwo);
			if((attackOne+player1Def)>(player2Atk+defTwo)){
				firstPWins++;
				printf("\n%s wins with a total of %d of 3 won\n",Playerchar.name,firstPWins);
			}
			else if((attackOne+player1Def)<(player2Atk+defTwo)){
				secondPwins++;
				printf("\n%s wins with a total of %d of 3 won\n",Player2char.name,secondPwins);
			}
			else{
				printf("\nBoth players, %s and %s, are equaly powerful this round play again\n",Playerchar.name,Player2char.name);
			}
		}
		//p1 defend and p2 attack
		else if((firstmenuchoice == 2 && secondmenuchoice == 1)){
			printf("\n%s had an Attack of %d and a defence of %d while %s had an Attack of %d and a defence of %d\n",Playerchar.name,player1Atk,defOne,Player2char.name,attackTwo,player2Def);	
			if((player1Atk+defOne)>(attackTwo+player2Def)){
				firstPWins++;
				printf("\n%s wins with a total of %d of 3 won\n",Playerchar.name,firstPWins);
			}
			else if((player1Atk+defOne)>(attackTwo+player2Def)){
				secondPwins++;
				printf("\n%s wins with a total of %d of 3 won\n",Player2char.name,secondPwins);
			}
			else{
				printf("\nBoth players, %s and %s, are equaly powerful this round play again\n",Playerchar.name,Player2char.name);
			}
		}
		//p1 and p2 both defend
		else{
			printf("\nBoth players, %s and %s, went the Buddha's path attacking none in order achieve nirvana. A tie this round there goes the game.\n",Playerchar.name,Player2char.name);
		}
		//resets for begening of loop
		firstmenuchoice = 0;
		secondmenuchoice = 0;
	}		
    return 0;
}


int main() {
	attackInterf();
    return 0;
}
