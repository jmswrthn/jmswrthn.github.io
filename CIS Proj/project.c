#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Characters{ 
	
	char name[12]; //Need different code to be able to input two names. i.e.- Chandler Tew
	char race[12]; 
	int attack;
	int defense;
	
};
int roll(){
	srand(time(NULL));
    int dieVal= (rand() %6)+1;
    //printf("%d %d \n", dieVal );
	//printf("\n");
	return dieVal;
}
int attackInterf(){
	struct Characters Playerchar;
	struct Characters Player2char;
	Playerchar.attack = 5;
	Playerchar.defense = 5;
	Player2char.attack = 5;
	Player2char.defense = 5;
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
		printf("\nPlayer 1 do you wish to \n(1) Attack (2)Defend: ");
		scanf("%d",&firstmenuchoice);
		while((firstmenuchoice != 1) && (firstmenuchoice != 2)){
			printf("\nPlayer 1 you entered:%d please enter a (1 or 2) to \n(1) Attack or (2)Defend: ",firstmenuchoice);
			scanf("%d",&firstmenuchoice);
		}
		dieRoll=roll();
		if(firstmenuchoice == 1){
			attackOne = (dieRoll + player1Atk);
			printf("\nPlayer 1 attack of %d plus a roll of %d as a total attack of %d\n",player1Atk,dieRoll,attackOne);
		}
		else{
			defOne = (dieRoll + player1Def);
			printf("\nPlayer 1 Defence of %d plus a roll of %d as a total Defence of %d\n",player1Def,dieRoll,defOne);
		}
		
		//Player two roll Attack and Defence Calc
		printf("\nPlayer 2 do you wish to \n(1) Attack (2)Defend: ");
		scanf("%d",&secondmenuchoice);
		while((secondmenuchoice != 1) && (secondmenuchoice != 2)){
			printf("\nPlayer 2 you entered:%d please enter a (1 or 2) to \n(1) Attack or (2)Defend: ",secondmenuchoice);
			scanf("%d",&secondmenuchoice);
		}
		dieRoll=roll();
		if(secondmenuchoice == 1){
			attackTwo = (dieRoll + player2Atk);
			printf("\nPlayer 2 attack of %d plus a roll of %d as a total attack of %d\n",player2Atk,dieRoll,attackTwo);
		}
		else{
			defTwo = (dieRoll + player2Def);
			printf("\nPlayer 2 Defence of %d plus a roll of %d as a total Defence of %d\n",player2Def,dieRoll,defTwo);
		}
		//both attack
		if(firstmenuchoice == 1 && secondmenuchoice == 1){
			printf("\nPlayer 1 had an Attack of %d and a defence of %d while Player 2 had an Attack of %d and a defence of %d\n",attackOne,player1Def,attackTwo,player2Def);
			if((attackOne+player1Def)>(attackTwo+player2Def)){
				firstPWins++;
				printf("\nFirst player wins with a total of %d of 3 won\n",firstPWins);
			}
			else if((attackOne+player1Def)<(attackTwo+player2Def)){
				secondPwins++;
				printf("\nSecond player wins with a total of %d of 3 won\n",secondPwins);
			}
			else{
				printf("\nBoth players are equaly powerful this round play again\n");
			}
		}
		//p1 attack and p2 defend
		else if((firstmenuchoice == 1 && secondmenuchoice == 2)){
			printf("\nPlayer 1 had an Attack of %d and a defence of %d while Player 2 had an Attack of %d and a defence of %d\n",attackOne,player1Def,player2Atk,defTwo);
			if((attackOne+player1Def)>(player2Atk+defTwo)){
				firstPWins++;
				printf("\nFirst player wins with a total of %d of 3 won\n",firstPWins);
			}
			else if((attackOne+player1Def)<(player2Atk+defTwo)){
				secondPwins++;
				printf("\nSecond player wins with a total of %d of 3 won\n",secondPwins);
			}
			else{
				printf("\nBoth players are equaly powerful this round play again\n");
			}
		}
		//p1 defend and p2 attack
		else if((firstmenuchoice == 2 && secondmenuchoice == 1)){
			printf("\nPlayer 1 had an Attack of %d and a defence of %d while Player 2 had an Attack of %d and a defence of %d\n",player1Atk,defOne,attackTwo,player2Def);	
			if((player1Atk+defOne)>(attackTwo+player2Def)){
				firstPWins++;
				printf("\nFirst player wins with a total of %d of 3 won\n",firstPWins);
			}
			else if((player1Atk+defOne)>(attackTwo+player2Def)){
				secondPwins++;
				printf("\nSecond player wins with a total of %d of 3 won\n",secondPwins);
			}
			else{
				printf("\nBoth players are equaly powerful this round play again\n");
			}
		}
		//p1 and p2 both defend
		else{
			printf("\nBoth players went the Buddha's path attackig none in order achieve nirvana. A tie this round there goes the game.\n");
		}
		//resets for begening of loop
		firstmenuchoice = 0;
		secondmenuchoice = 0;
	}		
}
int main() {
	attackInterf();
    return 0;
}
