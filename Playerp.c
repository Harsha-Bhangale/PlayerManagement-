#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int size=5,count=0;
typedef struct Player{
	int jerseyNumber;
	char playerName[20];
	int runs;
	int wickets;
	int matchesPlayed;
}Player;
void addPlayer(Player player[] )
{
	printf("------how many player do you want to add?--------\n");
	int n;
	scanf("%d",&n);
	n+=count;
	 for(int i=count;i<n;i++,count++)
    {
    	printf("\nJersey number:");
    	scanf("%d",&player[i].jerseyNumber);
    	printf("\nPlayer Name:");
    	scanf("%s",player[i].playerName);
    	printf("\nRuns:");
    	scanf("%d",&player[i].runs);
    	printf("\nWickets:");
    	scanf("%d",&player[i].wickets);
    	printf("\nMatches played:");
    	scanf("%d",&player[i].matchesPlayed);
	}
}
int searchPlayerByJerseyNumber(Player player[],int jerseyNumber)
{
    	int index=-1;
    	for(int i=0;i<count;i++)
    	{
    		if(jerseyNumber==player[i].jerseyNumber)
    		{
    			index=i;
    			break;
			}
		}
		return index;
}
int searchPlayerByPlayerName(Player player[],char playerName[])
{   
int index=-1;
	for(int i=0;i<count;i++)
	{
		if(strcasecmp (playerName,player[i].playerName)==0)
		{
			index=1;
			break;
		}
	}
	return index;
}
int removePlayer(Player player[],int jerseyNumber)
{  
	int index=searchPlayerByJerseyNumber(player,jerseyNumber);

	if(index==-1)
	return -1;

		for(int i=index;i<count;i++)
		{
			player[i]=player[i+1];
		}
		count--;
	return 0;
}
void displayPlayer(Player* player)
{
	printf("\n\nJersey number :%d \nPlayer Name :%s\nRuns:%d\nWikets:%d\nmatches played:%d\n",
	player->jerseyNumber,player->playerName,player->runs,player->wickets,player->matchesPlayed);
}
void displayPlayerForUpdate(Player*player)//display update player
{
	printf("\n\nJersey number :%d \nPlayer Name :%s\nRuns:%d\nWikets:%d\nmatches played:%d\n",
	player->jerseyNumber,player->playerName,player->runs,player->wickets,player->matchesPlayed);
}
int updatePlayer(Player player[],int jerseyNumber)
{
	int index=searchPlayerByJerseyNumber(player,jerseyNumber);
    displayPlayerForUpdate(&player[index]);
    int choice;
    printf("\nPress 1 to continue update:");
    scanf("%d",&choice);
    if (choice==1)
  {
	printf("\nRuns:");
	scanf("%d",&player->runs);
	printf("\nWickets:");
	scanf("%d",&player->wickets);
	printf("\nMatches played:");
	scanf("%d",&player->matchesPlayed);
  }  
return index;

}
void sortbyRuns(Player player[])
{
	 for(int i=0;i< count;i++)
	 {
	 	for(int j=0;j<count-i;j++)
	 	{
	 		if(player[j].runs>player[j+1].runs){
	 			Player temp=player[i];
	 			player[j]=player[j+1];
	 			player[j+1]=temp;
			 }
		 }
	 }
	 printf("\n players sorted by runs:");
}
void sortbyWickets(Player player[])
{
	for(int i=0;i< count;i++)
	 {
	 	for(int j=0;j<count-i;j++)
	 	{
	 		if(player[j].runs>player[j+1].runs){
	 			Player temp=player[i];
	 			player[j]=player[j+1];
	 			player[j+1]=temp;
			 }
		 }
	 }
	 printf("\n players sorted by wickets:");
}

void displayAllPlayer(Player player[])
{
		for(int i=0;i<count;i++)
  {
  	  printf("\nJersey number:%d\nPlayer name:%s\nRuns:%d\nWikets:%d\nmatches played:%d\n",
	  player[i].jerseyNumber,player[i].playerName,player[i].runs,player[i].wickets,player[i].matchesPlayed);
  }
}
void displayAllPlayerReverse(Player player[])
{
		for(int i=count-1;i>=0;i--)
  {
  	  printf("\nJersey number:%d\nPlayer name:%s\nRuns:%d\nWikets:%d\nmatches played:%d\n",
	  player[i].jerseyNumber,player[i].playerName,player[i].runs,player[i].wickets,player[i].matchesPlayed);
  }
}
int main()
{
	Player* player=(Player* )malloc(sizeof(Player)*size);
	int choice;
	do{
	printf("+-------------------------+\n");
    printf("|          Menu           |\n");
    printf("+-------------------------+\n");
    printf("|  1. Add player          |\n");
    printf("|  2. Remove player       |\n");
    printf("|  3. Search player       |\n");
    printf("|  4. Update player       |\n");
    printf("|  5. Display sorted      |\n");
    printf("|  6. Display all         |\n");
    printf("|  7. Exit                |\n");
    printf("+-------------------------+\n");
    printf("Enter your option:");

		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 	//add player
			            addPlayer(player);
			            break;
			case 2:     //remove player
			           {
			            int jerseyNumber;
			            printf("\nEnter the jersey number of player you want to remove:");
						scanf("%d",&jerseyNumber);
						removePlayer(player,jerseyNumber);
			        	break;
		            	}
						
		    case 3:     //Search player
			            {
				            printf("-----------------------------\n");
	                        printf("|  1. Search by jersey number |\n");
	                        printf("|  2. Search by player name   |\n");
	    					printf("-----------------------------\n");
			                int ch;
			                scanf("%d",&ch);
		                if(ch==1)
						{
		                	int jerseyNumber;
		                	printf("\nEnter the jersey number of the player you want:");
		                	scanf("%d",&jerseyNumber);
		                	int index=searchPlayerByJerseyNumber(player,jerseyNumber);
		                	displayPlayer(&player[index]);
						}
						else if(ch==2)
			            {   char playerName[20];
			                printf("\nEnter the player name of the player you want:");
			                scanf("%s",playerName);
							int index=searchPlayerByPlayerName(player,playerName);
							displayPlayer(&player[index]);
							  
						}	
						break;							
			case 4:      //update player
			            {
			             	int jerseyNumber;
			                printf("enter the player jersey number  you want to update:");
			                scanf("%d",&jerseyNumber);
			                int index=searchPlayerByJerseyNumber(player,jerseyNumber);
			                updatePlayer(player,jerseyNumber);
			                break;
						}
			case 5:     //display sorted
			            {
			           	printf("---------------------------\n");
					    printf("|  1. Sorted by runs       |\n");
					    printf("|  2. Sorted by wickets    |\n");
					    printf("---------------------------\n");
		                int ch;
		                scanf("%d",&ch);
		                 if(ch==1)
						{ 
					     	sortbyRuns(player);
					     	printf("\n1.Ascending order:");
					     	printf("\n2.descending order:");
					     	int order;
					     	scanf("%d",&order);
					     	if(order==1)
					     	{
					     		printf("\nPlayer runs by asceding runs:");
					     		displayAllPlayer(player);
							 }
		                   else if(order==2)
		                   {
		                   	 printf("\nPlayer runs by desecding runs:");
					     		displayAllPlayerReverse(player);
						   }
						}
						else if(ch==2)
			            {   
						sortbyWickets(player);
					     	printf("\n1.Ascending order:");
					     	printf("\n2.descending order:");
					     	int order;
					     	scanf("%d",&order);
					     	if(order==1)
					     	{
					     		printf("\nPlayer Wickets by asceding runs:");
					     		displayAllPlayer(player);
							 }
		                   else if(order==2)
		                   {
		                   	 printf("\nPlayer Wickets by desecding runs:");
					     		displayAllPlayerReverse(player);
						   }	  
						}	
						}
		            	break;			
			             
		    case 6:      //displayAllplayer
			         	displayAllPlayer(player);	             
			            break;
			case 7:      //exit
			            choice=0;
						break;
						
			default :	break;		            
			
			}	
	}

}    while(choice);
    return 0;
}