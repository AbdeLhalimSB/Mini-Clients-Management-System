#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

				//Structers
typedef struct Client{
	int ID;
	char Name[20];
	char LName[20];
}clt;


				//Functions Declaration
void Menu();
void loading(char Text[],int counter,char lasttext[]);
void cpyright();
void add(clt *T,int c);
void delay(char text[],char delay,int repeat);
void Display(clt *T,int c);
void search(clt *T,int c);
void Update(clt *T,int c);
void save(clt *T,int c);
void wipe();

				//Main Program
FILE *db;
int main(){
	clt clts[250];
	int choice,c=0;
	loading("Loading",5,"Loading Successful");
	cpyright();
	menu:
	Menu();
	scanf("%d",&choice);
	switch(choice){
		case 1:
			add(clts,c);
			c++;
			system("cls");
		break;
		case 2:
			Display(clts,c);
		break;
		case 3:
			search(clts,c);
		break;
		case 4:
			Update(clts,c);
		break;
		case 5:
			save(clts,c);
		break;
		case 6:
			system("cls");
			delay("\n\n\t\t\t\t\t\tOpening",'.',10);
			db=fopen("database.txt","r");
			while(!feof(db)){
				fscanf(db,"%d %s %s",&clts[c].ID,&clts[c].Name,&clts[c].LName);
				c++;
			}
			c=c-1;
			fclose(db);
		break;
		case 7:
			wipe();
		break;
		case 8:
			system("cls");
			delay("\n\n\t\t\t\t\t\tExiting",'.',10);
			exit(1);
		break;
		default :
			system("cls");
			printf("\n\n\n\n\n\n\t\t\t\t\tPleas choose number from the list !!");
			sleep(2);
			system("cls");
		break;
	}
	goto menu;
	return 0;
}
				//Display & Design functions
void loading(char Text[],int counter,char lasttext[]){
	system("color 3");
	int i;
	for(i=0;i<=100;i+=counter){
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s %d%%",Text,i);
		Sleep(150);
		system("cls");
	}
	system("cls");
	system("color B");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s",lasttext);
	sleep(5);
}
void cpyright(){
	char text[]="THIS PROGRAM MADE BY NOURA & ABDELHALIM";
	int i;
	printf("\n\n\n\n\n\n\n\t\t\t");
	for(i=0;i<=strlen(text);i++){
		printf("%c ",text[i]);
		Sleep(100);
	}
	printf("\n\t\t\t");
	for(i=0;i<=strlen(text)*2-2;i++){
		printf("\xcd");
		Sleep(20);
	}
	sleep(3);
}
void delay(char text[],char delay,int repeat){
	int i;
	printf("\n\n\t\t\t\t%s",text);
	for(i=0;i<repeat;i++){
		printf("%c",delay);
		Sleep(150);
	}
}
void Menu(){
	system("cls");
	system("color 4");
	printf("\n\t\t\t\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\t\t\t\t\xcd\xcd\xcd\xcd|CLIENT MANAGMENT SYSTEM|\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t            \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\n\t\t\t\t\t1.Add new client");
	printf("\n\n\t\t\t\t\t2.Display clients");
	printf("\n\n\t\t\t\t\t3.Search client");
	printf("\n\n\t\t\t\t\t4.Update client");
	printf("\n\n\t\t\t\t\t5.Save all");
	printf("\n\n\t\t\t\t\t6.Open clients");
	printf("\n\n\t\t\t\t\t7.Clean database");
	printf("\n\n\t\t\t\t\t8.Exit");
	printf("\n\n\t\t\t\t\xcd\xcd>Your choice :");
}
				//Main functions
void add(clt *T,int c){
	system("cls");
	system("color A");
	printf("\n\t\t\t\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\t\t\t\t\xcd\xcd\xcd\xcd|     ADD CLIENT      |\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t            \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\n\t\tID : ");
	scanf("%d",&T[c].ID);
	printf("\n\n\t\tFirst Name : ");
	scanf("%s",&T[c].Name);
	printf("\n\n\t\tLast Name : ");
	scanf("%s",&T[c].LName);
	delay("Creating Account",'.',15);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tCreating Account Successful");
	sleep(2);
}
void Display(clt *T,int c){
	system("cls");
	system("color 6");
	printf("\n\t\t\t\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\t\t\t\t\xcd\xcd\xcd\xcd|   DISPLAY CLIENTS   |\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t            \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	int i;
	for(i=0;i<c;i++){
		printf("\n\t\t__________________________________________________________________________________");
		printf("\n\t\t| ID : %d    | Name :   %20s | Last Name :   %20s |",T[i].ID,T[i].Name,T[i].LName);
		Sleep(20);
	}
	printf("\n\t\t__________________________________________________________________________________");
	printf("\n\n");
	system("pause");
}
void search(clt *T,int c){
	int so,i,t=0;
	system("cls");
	system("color D");
	printf("\n\t\t\t\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\t\t\t\t\xcd\xcd\xcd\xcd|    SEARCH CLIENT    |\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t            \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\n\n\t\t\tEnter The ID you are looking for \xcd\xcd> ");
	scanf("%d",&so);
	delay("\tSearching",'.',10);
	for(i=0;i<c;i++){
		if(so==T[i].ID){
			system("cls");
			system("color 2");
			printf("\n\n\n\n\t\t\t\tThe ID is found");
			sleep(2);
			system("cls");
			printf("\n\n\n\t\t\t\t\t\tInformations\n\n");
			printf("\n\t\t__________________________________________________________________________________");
			printf("\n\t\t| ID : %d    | Name :   %20s | Last Name :   %20s |",T[i].ID,T[i].Name,T[i].LName);
			printf("\n\n\n");
			system("pause");
			t++;
		}
	}
	if(t==0){
		system("cls");
		system("color 4");
		printf("\n\n\n\n\t\t\t\t\tThe ID is not found");
		sleep(2);
	}
}
void Update(clt *T,int c){
	int se,i,t=0;
	system("cls");
	system("color 6");
	printf("\n\t\t\t\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\t\t\t\t\xcd\xcd\xcd\xcd|    UPDATE CLIENT    |\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t            \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n\n\n\t\t\tEnter The ID you are looking for \xcd\xcd> ");
	scanf("%d",&se);
	for(i=0;i<c;i++){
		if(se==T[i].ID){
			system("cls");
			system("color 2");
			printf("\n\n\n\n\t\t\t\tThe ID is found");
			sleep(2);
			system("cls");
			printf("\n\n\n\t\t\t\t\t\tOld Informations\n\n");
			printf("\n\t\t__________________________________________________________________________________");
			printf("\n\t\t| ID : %d    | Name :   %20s | Last Name :   %20s |",T[i].ID,T[i].Name,T[i].LName);
			printf("\n\n\n");
			printf("\n\n\n\t\t\t\t\t\tNew Informations\n\n");
			printf("\n\n\t\tID : ");
			scanf("%d",&T[i].ID);
			printf("\n\n\t\tFirst Name : ");
			scanf("%s",&T[i].Name);
			printf("\n\n\t\tLast Name : ");
			scanf("%s",&T[i].LName);
			delay("\t   Updating ",'.',10);
			system("cls");
			system("color 2");
			printf("\n\n\n\n\t\t\t\t\tUpdating Completed");
			sleep(1);
			t++;
			}
	}
	if(t==0){
		system("cls");
		system("color 4");
		printf("\n\n\n\n\t\t\t\t\tThe ID is not found");
		sleep(2);
	}
}
void save(clt *T,int c){
	int i;
	loading("Saving",5,"Data Saved");
	db=fopen("database.txt","w");
	for(i=0;i<c;i++){
		fprintf(db,"%d %s %s\n",T[i].ID,T[i].Name,T[i].LName);
	}
	fclose(db);
}
void wipe(){
	loading("Clearing Data",5,"Data Deleted");
	remove("database.txt");
}
