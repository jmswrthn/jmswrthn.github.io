  #include <stdio.h>
 struct PlayerName{
	char name[16];
	};
	
	void numSave(){
char name[16];
struct PlayerName aplayer;
printf("enter 16 characters save name: ");
scanf("%s",aplayer.name);
	FILE* userCharFile = fopen("name.data","w");
	fprintf(userCharFile,"%s",aplayer.name);
	fclose(userCharFile);
	}
	
void createscoreboardname(){
struct PlayerName aplayer;
printf("enter character name: ");
scanf("%s",aplayer.name);
}	



int main(){
numSave();
createscoreboardname();
return 0;
}