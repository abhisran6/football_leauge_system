#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1000
int team()
{
	char team_name[50];
	int i,n;
	int  game_played;
	int game_won;
	int game_lost;
	int game_draw;
	int game_points;
		printf("------------------------------------------------------");
		printf("\n");
		printf("Enter number of Teams you want to enter data for: ");
		scanf("%d",&n);
		FILE *fptr;
		fptr=(fopen("D:\\Team_Details.txt", "a"));
		for (i=1;i<=n;++i)
		{		
			printf("\nEnter %dst Team Name :- ",i);
			scanf("%s",team_name);
			printf("Enter Game Played :- ");
    		scanf("%d",&game_played);
			printf("Enter Game Won :- ");
			scanf("%d",&game_won);
			printf("Enter Game Lost :- ");
			scanf("%d",&game_lost);
			game_draw=game_played-(game_won+game_lost);
			game_points=(game_won*3)+(game_draw*1);		
			fprintf(fptr,"Team Name: %s  Total Played =%d   Total Win =%d  Total Lost =%d  Total Draw =%d  Team Points=%d\n",team_name,game_played,game_won,game_lost,game_draw,game_points);
		}
		printf("\nAll Teams Data Added Succesfully\n");
		fclose(fptr);
		return 0;
}
int append()
{
	char team_name[50];
	int  game_played;
	int game_won;
	int game_lost;
	int game_draw;
	int game_points;
	FILE *fptr;
	fptr=(fopen("D:\\Team_Details.txt", "a"));
		printf("Enter New Team Name :- ");
		scanf("%s",team_name);
		printf("Enter Game Played :- ");
    	scanf("%d",&game_played);
		printf("Enter Game Won :- ");
		scanf("%d",&game_won);
		printf("Enter Game Lost :- ");
		scanf("%d",&game_lost);
		game_draw=game_played-(game_won+game_lost);
		game_points=(game_won*3)+(game_draw*1);		
		fprintf(fptr,"Team Name: %s  Total Played =%d   Total Win =%d  Total Lost =%d  Total Draw =%d  Team Points=%d\n",team_name,game_played,game_won,game_lost,game_draw,game_points);
		printf("Team Data Added Succesfully");
		fclose(fptr);
		return 0;
}
int display()
{
    FILE *fPtr;
    fPtr = fopen("D:\\Team_Details.txt", "r"); 
	char ch[50];  
	printf("\n");
    while((fgets(ch,50,fPtr))!=NULL)
	{  
    	printf("%s ", ch);
	}
	fclose(fPtr);
	return 0;
}
int main()
{	
    printf("\n\n\t\t                           Football League System   \n\n");
    int choice, num, i;
    while(1)
    {	
		printf("\n");
        printf("                       *Press  1 to Enter the Details of the Team \n");
        printf("                       *Press  2 to Add New Record in the End of the File \n");
        printf("                       *Press  3 to Display Team Details \n");
        printf("                       *Press  4 For Exit \n\n\n");
        printf("*********************************************************************************");
        printf("\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                team();
                break;
            case 2:
               append();
               break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\n\t\t\tThank You\n\n\n");
                exit(0);
                break;
            default:
            	printf("\n\n\t\t  Invalid Input   \n\n\n");
        }
    }
    	    return 0;
}