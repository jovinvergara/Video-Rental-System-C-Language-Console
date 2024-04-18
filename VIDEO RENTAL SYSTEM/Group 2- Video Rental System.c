#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX 256

void Login(); // MENU FOR LOGIN 
void AdminAccountTab(); // MENU FOR ADMIN ACCOUNT 
void ViewMovieList(); // MOVIE LIST VIEW FOR ADMIN ACCOUNT
void AddMovie(); // ADD MOVIE 
void RentTab(); // RENT TAB MENU FOR CASHIER ACCOUNT
void Receipt(); // Receipting void for text file and printf in renting tab | Individual, Multiple and Intial Receipt Transaction
void ReturnTab(); //RETURNING

int RID; //CUSTOM ORDER For movies that is recently added
char Mname[100][100], Mgenre[100][100], Myear[100][100]; // CUSTOM ORDER
int Mprice[100], ms1, ms2, ms3, ms4, ms5; // CUSTOM ORDER
int m1, m2, m3, m4; // ARRAY FOR CUSTOM ORDER (FOR DEFAULT CASE TO THE MOVIES THAT IS OUTSIDE THE RANGE OF 20)

char CusName1[100][100]; // CUSTOMER NAME TO TEXT FILE FOR INDIVIDUAL RECEIPT
int rentID[100] = {0}, duration[50] = {0}; // INDEXING FOR RENTING MOVIE ID AND DURATION OF THE RENT
char y_n, confirm, ChoicesAB, genre; // FOR CHOICES YES AND NO.
int i, j, b = 0, a = 0, x = 0, d, d1, e, f, g1, g2, h, k, p = 0, orderCount, fprice, price, orderPrice[100][50] = {0}, rday, rmonth, ryear; // ARRAY VARIABLES FOR MOVIE INFORMATION AND RECEIPTING
float totalPrice[100] = {0}, totalAmount[100] = {0}; // CALCULATING TOTAL OF THE ORDER

int codenum = 0;
int as1 = 5, as2 = 5, as3 = 5, as4 = 5, as5 = 5, asMstock[100]; //STOCKS of MOVIES
int hs1 = 5, hs2 = 5, hs3 = 5, hs4 = 5, hs5 = 5, hsMstock[100];
int ds1 = 5, ds2 = 5, ds3 = 5, ds4 = 5, ds5 = 5, dsMstock[100];
int sfs1 = 5, sfs2 = 5, sfs3 = 5, sfs4 = 5, sfs5 = 5, sfsMstock[100];
int ads1 = 5, ads2 = 5, ads3 = 5, ads4 = 5, ads5 = 5, adsMstock[100];

char CusName[100], CusNameh[100], CusContact[50][30], CustomerStatus[50][30], CusID[50][30];  // CUSTOMER INFORMATION CONTAINER OF INPUTTED VALUE 

int gen1=6,gen2=6,gen3=6,gen4=6,gen5=6; // ADDING NEW MOVIES
int rID[100];


void gotoxy(int x, int y)
{
    COORD pos= {x,y}; //sets co-ordinates in(x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void Login() // FOR DETERMENING ADMIN AND CASHIER ACC
{
	char Username[10]; 
	char Password[10]; 
	
	do 
	{
	system("cls");  //for do while to enter another username and password if not correct then system clear the recent added value
	
	gotoxy(40, 3);printf(" _________________________________________");
    gotoxy(40, 4);printf("|                                         |");
    gotoxy(40, 5);printf("|                L O G I N                |");
    gotoxy(40, 6);printf("|_________________________________________|\n\n\n\n");
	
	gotoxy(40, 9);printf("  \tUSERNAME: "); 
	gotoxy(40, 11);printf("  \tPASSWORD: "); 
	//left design
	gotoxy(40, 7);printf("|");
	gotoxy(40, 8);printf("|");
	gotoxy(40, 9);printf("|");
	gotoxy(40, 10);printf("|");
	gotoxy(40, 11);printf("|"); 
	gotoxy(40, 12);printf("|"); 
	//right design
	gotoxy(82, 7);printf("|");
	gotoxy(82, 8);printf("|");
	gotoxy(82, 9);printf("|");
	gotoxy(82, 10);printf("|");
	gotoxy(82, 11);printf("|"); 
	gotoxy(82, 12);printf("|"); 
	//bottom design
	gotoxy(40, 13);printf("|_________________________________________|");
	
	gotoxy(62, 15);printf("Enter [2] to go back"); 
	gotoxy(58, 9);scanf(" %s", &Username);
   
    if ((strcmp (Username, "2")== 0)) 
    {
	
		system("cls");
		main();// then show Admin Tab
		break;
    }
    
	gotoxy(58, 11);scanf(" %s", &Password);
	
	

	
	if ((strcmp (Username, "admin")== 0 && strcmp(Password, "admin")==0)) // If true admin
	{
		system("cls");
		AdminAccountTab(); // then show Admin Tab
		break;
	}
	else if ((strcmp (Username, "2")== 0)) 
	{
		system("cls");
		main();// then show Admin Tab
		break;
	}

	
    }while ((strcmp (Username, "admin")!= 0 || strcmp(Password, "admin")!=0));
    
    
}

void AddMovie() // ADDING MOVIE in the LIST on Admin Menu
{
	system("cls");
	char c ;
	int limiter;
				
				gotoxy(40, 3); printf("============================================");
                gotoxy(40, 4); printf("||                                        ||");
                gotoxy(40, 5); printf("||              ADDING MOVIES             ||");
                gotoxy(40, 6); printf("||                                        ||");
                gotoxy(40, 7); printf("============================================");
                gotoxy(40, 8); printf("||                                        ||");
                gotoxy(40, 9); printf("||       [A] Add Action Movie             ||");
                gotoxy(40, 10);printf("||       [B] Add Horror Movie             ||");
			    gotoxy(40, 11);printf("||       [C] Add Drama  Movie             ||");
                gotoxy(40, 12);printf("||       [D] Add Sci-Fi Movie             ||");
                gotoxy(40, 13);printf("||       [E] Add Adventure Movie          ||"); 
				gotoxy(40, 14);printf("||                                        ||");    
			    gotoxy(40, 15);printf("============================================");              
				gotoxy(71, 16); printf("[G] Go Back");
				
				gotoxy(41, 19); printf(" Enter your choice: ");
	            genre = getch();
	            
				while ( genre != 'A' && genre != 'a' && genre != 'B' && genre != 'b' && genre != 'C' && genre != 'c' && genre != 'D' && genre != 'd' && genre != 'E' && genre != 'e' && genre != 'G' && genre != 'g')
	            {
                genre = getch();
                }
                
                //FILE pointer for every genres
				FILE * action; 
				FILE * horror;
				FILE * drama;
				FILE * scifi;
				FILE * adventure;
				
				switch(genre)
				{
					case 'A' : case 'a' : //ACTION
						system("cls");
						limiter = 0; 
						
						do
						{   
						    action = fopen("Action.txt", "r");
		
		                	if(action != NULL) 
				                {
				                gotoxy(40, 3); printf("============================================");
		                        gotoxy(40, 4); printf("||                                        ||");
		                        gotoxy(40, 5); printf("||              ACTION MOVIES             ||");
		                        gotoxy(40, 6); printf("||                                        ||");
		                        gotoxy(40, 7); printf("============================================");
									
				                printf("\n\n\n");	
			
					            while ( (c = fgetc(action)) != EOF)
					            putchar(c); //showing the list
					
				                printf("               ***************************************************************************************************\n"); // spacing design
				            }
				            
				            action = fopen("Action.txt", "a+"); // Opening file name MovieList.txt to open in append mode
	
	                        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tADDING NEW ACTION MOVIE");
	                        
	                        	//Entering the MovieList basic information table and scanning.
	                            printf("\n\n");
                             	printf("\t\t\t\t\t\tRent ID      : %d \n", gen1);
	                            printf("\t\t\t\t\t\tMovie name   : ");
	                            scanf("\n%[^\n]s", Mname);
	                            printf("\t\t\t\t\t\tMovie year   : ");
                             	scanf("%s", Myear);
                               	printf("\t\t\t\t\t\tPrice        : ");
                                scanf("%d", &fprice);
                                printf("\t\t\t\t\t\tStock/s      : ");
                                scanf("%d", &ms1);
	
	                            //Catching entered value in printf and scanf from the preceding code and aligning it accordingly with its c identifiers
	                           	fprintf(action, "               | %-11d|  %-23s| Action            | %-11s| P%d.00       | %d       |\n", gen1, Mname, Myear, fprice, ms1); 
	                            fclose(action); // File f closing (IMPORTANT!)
	                            system("cls");
	
	                            gotoxy(40, 5);printf(" _________________________________________");
                                gotoxy(40, 6);printf("|                                         |");
                                gotoxy(40, 7);printf("|               MOVIE ADDED!              |");
                                gotoxy(40, 8);printf("|_________________________________________|\n\n\n\n");
								gen1++;	
									
	                            printf("\n\n\n\n");
	                            printf("\t\t\t\t\t  Press [ENTER] key to go back in the menu.");
                                getch(); // Waiting for any key to be entered
                                
                                AdminAccountTab();
                                
                                
                                limiter++;
						} while (limiter < 1);
						
						break;
						
				    case 'B' : case 'b' : //HORROR
				    	system("cls");
				    	limiter = 0;
				    	
				    	do
						{
							horror = fopen("Horror.txt", "r");
		
		                	if(horror != NULL) 
				                {
				                gotoxy(40, 3); printf("============================================");
		                        gotoxy(40, 4); printf("||                                        ||");
		                        gotoxy(40, 5); printf("||              HORROR MOVIES             ||");
		                        gotoxy(40, 6); printf("||                                        ||");
		                        gotoxy(40, 7); printf("============================================");
									
				                printf("\n\n\n");	
			
					            while ( (c = fgetc(horror)) != EOF)
					            putchar(c); //showing the list
					
				                printf("               ***************************************************************************************************\n"); // spacing design
				            }
							
				    	 	horror = fopen("Horror.txt", "a+"); // Opening file name MovieList.txt to open in append mode
	                        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tADDING NEW HORROR MOVIE");
	                        
	                        	//Entering the MovieList basic information table and scanning.
	                            printf("\n\n");
                             	printf("\t\t\t\t\t\tRent ID      : %d \n", gen2);
	                            printf("\t\t\t\t\t\tMovie name   : ");
	                            scanf("\n%[^\n]s", Mname);
	                            printf("\t\t\t\t\t\tMovie year   : ");
                             	scanf("%s", Myear);
                               	printf("\t\t\t\t\t\tPrice        : ");
                                scanf("%d", &fprice);
                                printf("\t\t\t\t\t\tStock/s      : ");
                                scanf("%d", &ms2);
	
	                            //Catching entered value in printf and scanf from the preceding code and aligning it accordingly with its c identifiers
	                           	fprintf(horror, "               | %-11d|  %-23s| Horror            | %-11s| P%d.00       | %d       |\n", gen2, Mname, Myear, fprice, ms2); 
	                            fclose(horror); // File f closing (IMPORTANT!)
	                            system("cls");
	
	                            gotoxy(40, 5);printf(" _________________________________________");
                                gotoxy(40, 6);printf("|                                         |");
                                gotoxy(40, 7);printf("|               MOVIE ADDED!              |");
                                gotoxy(40, 8);printf("|_________________________________________|\n\n\n\n");
								gen2++;
									
	                            printf("\n\n\n\n");
	                            printf("\t\t\t\t\t  Press [ENTER] key to go back in the menu.");
                                getch(); // Waiting for any key to be entered
                                
                                AdminAccountTab();
                                
                                
                                limiter++;
						} while (limiter < 1);
						break;
					case 'C' : case 'c' : //DRAMA
						system("cls");
						limiter = 0;
						
						do
						{
							
							drama = fopen("Drama.txt", "r");
		
		                	if(drama != NULL) 
				                {
				                gotoxy(40, 3); printf("============================================");
		                        gotoxy(40, 4); printf("||                                        ||");
		                        gotoxy(40, 5); printf("||              DRAMA MOVIES              ||");
		                        gotoxy(40, 6); printf("||                                        ||");
		                        gotoxy(40, 7); printf("============================================");
									
				                printf("\n\n\n");	
			
					            while ( (c = fgetc(drama)) != EOF)
					            putchar(c); //showing the list
					
				                printf("               ***************************************************************************************************\n"); // spacing design
				            }
							
							drama = fopen("Drama.txt", "a+"); // Opening file name MovieList.txt to open in append mode
	
	                        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tADDING NEW DRAMA MOVIE");
	                        
	                        	//Entering the MovieList basic information table and scanning.
	                            printf("\n\n");
                             	printf("\t\t\t\t\t\tRent ID      : %d \n", gen3);
	                            printf("\t\t\t\t\t\tMovie name   : ");
	                            scanf("\n%[^\n]s", Mname);
	                            printf("\t\t\t\t\t\tMovie year   : ");
                             	scanf("%s", Myear);
                               	printf("\t\t\t\t\t\tPrice        : ");
                                scanf("%d", &fprice);
                                printf("\t\t\t\t\t\tStock/s      : ");
                                scanf("%d", &ms3);
	
	                            //Catching entered value in printf and scanf from the preceding code and aligning it accordingly with its c identifiers
	                           	fprintf(drama, "               | %-11d|  %-23s| Drama             | %-11s| P%d.00       | %d       |\n", gen3, Mname, Myear, fprice, ms3); 
	                            fclose(drama); // File f closing (IMPORTANT!)
	                            system("cls");
	
	                            gotoxy(40, 5);printf(" _________________________________________");
                                gotoxy(40, 6);printf("|                                         |");
                                gotoxy(40, 7);printf("|               MOVIE ADDED!              |");
                                gotoxy(40, 8);printf("|_________________________________________|\n\n\n\n");
								gen3++;
								
	                            printf("\n\n\n\n");
	                            printf("\t\t\t\t\t  Press [ENTER] key to go back in the menu.");
                                getch(); // Waiting for any key to be entered
                                
                                AdminAccountTab();
                                
                                
                                limiter++;
						} while (limiter < 1);
						break;
					case 'D' : case 'd' : //SCI-FI
						system("cls");
						limiter = 0;
						
						do
						{
							
							scifi = fopen("Sci-Fi.txt", "r");
		
		                	if(scifi != NULL) 
				                {
				                gotoxy(40, 3); printf("============================================");
		                        gotoxy(40, 4); printf("||                                        ||");
		                        gotoxy(40, 5); printf("||              SCI-FI MOVIES             ||");
		                        gotoxy(40, 6); printf("||                                        ||");
		                        gotoxy(40, 7); printf("============================================");
									
				                printf("\n\n\n");	
			
					            while ( (c = fgetc(scifi)) != EOF)
					            putchar(c); //showing the list
					
				                printf("               ***************************************************************************************************\n"); // spacing design
				            }
							
							scifi = fopen("Sci-Fi.txt", "a+"); // Opening file name MovieList.txt to open in append mode
	
	                        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tADDING NEW SCI-FI MOVIE");
	                        
	                        	//Entering the MovieList basic information table and scanning.
	                            printf("\n\n");
                             	printf("\t\t\t\t\t\tRent ID      : %d \n", gen4);
	                            printf("\t\t\t\t\t\tMovie name   : ");
	                            scanf("\n%[^\n]s", Mname);
	                            printf("\t\t\t\t\t\tMovie year   : ");
                             	scanf("%s", Myear);
                               	printf("\t\t\t\t\t\tPrice        : ");
                                scanf("%d", &fprice);
                                printf("\t\t\t\t\t\tStock/s      : ");
                                scanf("%d", &ms4);
	
	                            //Catching entered value in printf and scanf from the preceding code and aligning it accordingly with its c identifiers
	                           	fprintf(scifi, "               | %-11d|  %-23s| Sci-Fi            | %-11s| P%d.00       | %d       |\n", gen4, Mname, Myear, fprice, ms4); 
	                            fclose(scifi); // File f closing (IMPORTANT!)
	                            system("cls");
	
	                            gotoxy(40, 5);printf(" _________________________________________");
                                gotoxy(40, 6);printf("|                                         |");
                                gotoxy(40, 7);printf("|               MOVIE ADDED!              |");
                                gotoxy(40, 8);printf("|_________________________________________|\n\n\n\n");
								gen4++;
								
	                            printf("\n\n\n\n");
	                            printf("\t\t\t\t\t  Press [ENTER] key to go back in the menu.");
                                getch(); // Waiting for any key to be entered
                                
                                AdminAccountTab();
                                
                                
                                limiter++;
						} while (limiter < 1);
						break;
					case 'E' : case 'e' : //ADVENTURE
						system("cls");
						limiter = 0;
						
						do
						{
							
							adventure = fopen("Adventure.txt", "r");
		
		                	if(adventure != NULL) 
				                {
				                gotoxy(40, 3); printf("============================================");
								gotoxy(40, 4); printf("||                                        ||");
                       		 	gotoxy(40, 5); printf("||           ADVENTURE MOVIES             ||");
								gotoxy(40, 6); printf("||                                        ||");
                       			gotoxy(40, 7); printf("============================================");
									
				                printf("\n\n\n");	
			
					            while ( (c = fgetc(adventure)) != EOF)
					            putchar(c); //showing the list
					
				                printf("               ***************************************************************************************************\n"); // spacing design
				            }
							
							adventure = fopen("Adventure.txt", "a+"); // Opening file name MovieList.txt to open in append mode
	
	                        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tADDING NEW ADVENTURE MOVIE");
	                        
	                        	//Entering the MovieList basic information table and scanning.
	                            printf("\n\n");
                             	printf("\t\t\t\t\t\tRent ID      : %d \n", gen5);
	                            printf("\t\t\t\t\t\tMovie name   : ");
	                            scanf("\n%[^\n]s", Mname);
	                            printf("\t\t\t\t\t\tMovie year   : ");
                             	scanf("%s", Myear);
                               	printf("\t\t\t\t\t\tPrice        : ");
                                scanf("%d", &fprice);
                                printf("\t\t\t\t\t\tStock/s      : ");
                                scanf("%d", &ms5);
	
	                            //Catching entered value in printf and scanf from the preceding code and aligning it accordingly with its c identifiers
	                           	fprintf(adventure, "               | %-11d|  %-23s| Adventure         | %-11s| P%d.00       | %d       |\n", gen5, Mname, Myear, fprice, ms5); 
	                            fclose(adventure); // File f closing (IMPORTANT!)
	                            system("cls");
	
	                            gotoxy(40, 5);printf(" _________________________________________");
                                gotoxy(40, 6);printf("|                                         |");
                                gotoxy(40, 7);printf("|               MOVIE ADDED!              |");
                                gotoxy(40, 8);printf("|_________________________________________|\n\n\n\n");
								
								gen5++;	
	                            printf("\n\n\n\n");
	                            printf("\t\t\t\t\t  Press [ENTER] key to go back in the menu.");
                                getch(); // Waiting for any key to be entered
                                
                                AdminAccountTab();
                                
                                
                                limiter++;
						} while (limiter < 1);
						break;		
					case 'G' : case 'g' : //GO BACK TO RENT TAB
						system("cls");
						AdminAccountTab();
						break;	
				}
}

void RentTab() // RENT AND RETURNING TAB
{
	
	FILE * action; 
	FILE * horror;
	FILE * drama;
	FILE * scifi;
	FILE * adventure;
	FILE * fID;
	
	char c;
	int d = 0;
	
	gotoxy(40, 3);printf(" _________________________________________");
    gotoxy(40, 4);printf("|                                         |");
    gotoxy(40, 5);printf("|           Y.M.W.S Video Rental          |");
    gotoxy(40, 6);printf("|_________________________________________|\n\n\n\n");
	
	gotoxy(48, 9); printf("[A] RENT");
	gotoxy(65, 9); printf("[B] RETURN");
	//Left and right design
	gotoxy(40, 7);printf("|");gotoxy(82, 7);printf("|");
	gotoxy(40, 8);printf("|");gotoxy(82, 8);printf("|");
	gotoxy(40, 9);printf("|");gotoxy(82, 9);printf("|");
	gotoxy(40, 10);printf("|");gotoxy(82,10);printf("|");
	gotoxy(40, 11);printf("|_________________________________________|");
	gotoxy(69, 13); printf("[G] Go Back");
	
	gotoxy(47, 17); printf(" Enter your choice : ");
	ChoicesAB = getch();
	
	while ( ChoicesAB != 'A' && ChoicesAB != 'B' && ChoicesAB != 'a' && ChoicesAB != 'b'  && ChoicesAB != 'G' && ChoicesAB != 'g'  )
	{

	ChoicesAB = getch();
    }
	
	
	switch(ChoicesAB)
	{
			case 'A': case 'a' : // CHOOSING GENRE'S
				system("cls");
				
				gotoxy(40, 3); printf("============================================");
                gotoxy(40, 4); printf("||                                        ||");
                gotoxy(40, 5); printf("||           SELECT MOVIE GENRE'S         ||");
                gotoxy(40, 6); printf("||                                        ||");
                gotoxy(40, 7); printf("============================================");
                gotoxy(40, 8); printf("||                                        ||");
                gotoxy(40, 9); printf("||       [A] Action                       ||");
                gotoxy(40, 10);printf("||       [B] Horror                       ||");
			    gotoxy(40, 11);printf("||       [C] Drama                        ||");
                gotoxy(40, 12);printf("||       [D] Sci-Fi                       ||");
                gotoxy(40, 13);printf("||       [E] Adventure                    ||"); 
				gotoxy(40, 14);printf("||                                        ||");    
			    gotoxy(40, 15);printf("============================================");              
				gotoxy(71, 16); printf("[G] Go Back");
				
				gotoxy(47, 19); printf(" Enter your choice : ");
	            genre = getch();
	            
				while ( genre != 'A' && genre != 'a' && genre != 'B' && genre != 'b' && genre != 'C' && genre != 'c' && genre != 'D' && genre != 'd' && genre != 'E' && genre != 'e' && genre != 'G' && genre != 'g')
	            {
                genre = getch();
                }
				
				switch(genre)
				{
					case 'A' : case 'a' : //ACTION
						system("cls");
						
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tEnter customer name: ");
						scanf("\n%[^\n]s", CusName);
						
						system("cls");
						
						i = 0;
						j = 0;
						orderCount = 0;
											
						do{
							system("cls");
							
							action = fopen("Action.txt", "r");
			
			                if(action != NULL) 
			                {
				                gotoxy(40, 3); printf("============================================");
		                        gotoxy(40, 4); printf("||                                        ||");
		                        gotoxy(40, 5); printf("||              ACTION MOVIES             ||");
		                        gotoxy(40, 6); printf("||                                        ||");
		                        gotoxy(40, 7); printf("============================================");
									
				                printf("\n\n\n");	
			
					            while ( (c = fgetc(action)) != EOF)
					            putchar(c); //showing the list
					
				                printf("               ***************************************************************************************************\n"); // spacing design
					            fclose(action); // file closing
			                }
							printf("\n\n\n");				
							printf("\t\t\t\t\tEnter rent ID: ");
							scanf("%d", &rentID[i]);
							printf("\t\t\t\t\tEnter duration: ");
							scanf("%d", &duration[j]);
							printf("\t\t\t\t\tAdd more movies? [Y or N]"); // asking yes or no if ever you want to add movies or not
							y_n = getch();
							
							while (y_n != 'y' && y_n != 'Y' && y_n != 'n' && y_n != 'N') // condition for if ever not y and n is not entered, the keypress do not register
							{
								y_n = getch();
							}
							
							i++; // incrementation of movie id entered 
							j++; // incremantation of days to be rented or duration
							orderCount++;
											
						}while(y_n == 'y' || y_n == 'Y');
						
						if(y_n == 'n' || y_n == 'N'){
						}
						
						i = 0;
						m1 = 0; 
						m2 = 0;
						m3 = 0;
						m4 = 0;
						
					do{
						switch(rentID[i])
						{
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								break;
							case 5:
								break;
							default:
								
								system("cls");
								
								action = fopen("Action.txt", "r"); // opening movie file to dislay and to guide the cashier to enter movie information outside the 20 selected movies from switch case.
						
								if(action != NULL) // if there's MovieList.txt
								{
					
								while ( (c = fgetc(action)) != EOF) // then show list
								putchar(c);
								}
								
								printf("                     ******************************************************************************************\n");
								fclose(action); // file closing
								
								//Enter the Movie information of the custom order outside the 20 selected movies in switch case
								printf("\n\n");
								printf("\t\t\t\t\t\tMovie name   : ");
								scanf("\n%[^\n]s", Mname[m1]);
								printf("\t\t\t\t\t\tGenre        : ");
								scanf("\n%[^\n]s", Mgenre[m2]);
								printf("\t\t\t\t\t\tMovie year   : ");
								scanf("%s", Myear[m3]);
								printf("\t\t\t\t\t\tPrice        : ");
								scanf("%d", &Mprice[m4]);
								break;		
						}
						
						//for adding the value of inputted value in custom order outside 20 selected movies in switch case from the previous printf, scanf
						m1++; 
						m2++;
						m3++;
						m4++;
						i++;
					}while(i < orderCount); // while it is inside do order count or how many times you enter a custom movie number from the renting tab
					
					system("cls");
					
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\tConfirm Order? [Y/N]");
					confirm = getch();
	
					while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') // Condition if the user press key accidentaly for not to register unless it is y= yes and n=no
					{
						confirm = getch();
					}
					
					if (confirm == 'y' || confirm == 'Y') // if yes confirm order condition
					{
						system("cls");
						Receipt();
					}
					else if (confirm == 'n' || confirm == 'N') // if yes confirm order condition
					{
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tPress any keys to go to menu...");
						getch();
						AdminAccountTab();
					}
					
						break;
				    case 'B' : case 'b' : //HORROR
				    	system("cls");
				    	
				    	printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tEnter customer name: ");
						scanf("\n%[^\n]s", CusName);
				    	
				    	system("cls");
						
						i = 0;
						j = 0;
						orderCount = 0;
				    	
				    	do{
				    	system("cls");
							
				    	horror = fopen("Horror.txt", "r");
		
		                if(horror != NULL) 
		                {
			                gotoxy(40, 3); printf("============================================");
	                        gotoxy(40, 4); printf("||                                        ||");
	                        gotoxy(40, 5); printf("||              HORROR MOVIES             ||");
	                        gotoxy(40, 6); printf("||                                        ||");
	                        gotoxy(40, 7); printf("============================================");
								
			                printf("\n\n\n");
		
				            while ( (c = fgetc(horror)) != EOF)
				            putchar(c); //showing the list
				
			                printf("               ***************************************************************************************************\n"); // spacing design
				            fclose(horror); // file closing
		                }
		                
							printf("\n\n\n");				
							printf("\t\t\t\t\tEnter rent ID: ");
							scanf("%d", &rentID[i]);
							printf("\t\t\t\t\tEnter duration: ");
							scanf("%d", &duration[j]);
							printf("\t\t\t\t\tAdd more movies? [Y or N]"); // asking yes or no if ever you want to add movies or not
							y_n = getch();
							
							while (y_n != 'y' && y_n != 'Y' && y_n != 'n' && y_n != 'N') // condition for if ever not y and n is not entered, the keypress do not register
							{
								y_n = getch();
							}
							
							i++; // incrementation of movie id entered 
							j++; // incremantation of days to be rented or duration
							orderCount++;
											
						}while(y_n == 'y' || y_n == 'Y');
						
						if(y_n == 'n' || y_n == 'N'){
						}
							
						i = 0;
						m1 = 0; 
						m2 = 0;
						m3 = 0;
						m4 = 0;
						
					do{
						switch(rentID[i])
						{
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								break;
							case 5:
								break;
							default:
								
								system("cls");
								
								horror = fopen("Horror.txt", "r"); // opening movie file to dislay and to guide the cashier to enter movie information outside the 20 selected movies from switch case.
						
								if(action != NULL) // if there's MovieList.txt
								{
					
								while ( (c = fgetc(horror)) != EOF) // then show list
								putchar(c);
								}
								
								printf("                     ******************************************************************************************\n");
								fclose(horror); // file closing
								
								//Enter the Movie information of the custom order outside the 20 selected movies in switch case
								printf("\n\n");
								printf("\t\t\t\t\t\tMovie name   : ");
								scanf("\n%[^\n]s", Mname[m1]);
								printf("\t\t\t\t\t\tGenre        : ");
								scanf("\n%[^\n]s", Mgenre[m2]);
								printf("\t\t\t\t\t\tMovie year   : ");
								scanf("%s", Myear[m3]);
								printf("\t\t\t\t\t\tPrice        : ");
								scanf("%d", &Mprice[m4]);
								break;						
						}
						
						//for adding the value of inputted value in custom order outside 20 selected movies in switch case from the previous printf, scanf
						m1++; 
						m2++;
						m3++;
						m4++;
						i++;
					}while(i < orderCount); // while it is inside do order count or how many times you enter a custom movie number from the renting tab
					
					system("cls");
					
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\tConfirm Order? [Y/N]");
					confirm = getch();
	
					while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') // Condition if the user press key accidentaly for not to register unless it is y= yes and n=no
					{
						confirm = getch();
					}
					
					if (confirm == 'y' || confirm == 'Y') // if yes confirm order condition
					{
						system("cls");
						Receipt();
					}
					else if (confirm == 'n' || confirm == 'N') // if yes confirm order condition
					{
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tPress any keys to go to menu...");
						getch();
						AdminAccountTab();
					}
					
						break;
					case 'C' : case 'c' : //DRAMA
						system("cls");
					
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tEnter customer name: ");
						scanf("\n%[^\n]s", CusName);
						
						system("cls");
						
						i = 0;
						j = 0;
						orderCount = 0;
						
						do{
						system("cls");	
							
						drama = fopen("Drama.txt", "r");
		
		                if(drama != NULL) 
		                {
		                gotoxy(40, 3); printf("============================================");
                        gotoxy(40, 4); printf("||                                        ||");
                        gotoxy(40, 5); printf("||              DRAMA MOVIES              ||");
                        gotoxy(40, 6); printf("||                                        ||");
                        gotoxy(40, 7); printf("============================================");
							
		                printf("\n\n\n");
	
			            while ( (c = fgetc(drama)) != EOF)
			            putchar(c); //showing the list
			
						printf("               ***************************************************************************************************\n"); // spacing design			            
						fclose(drama); // file closing
		                }
		                
							printf("\n\n\n");				
							printf("\t\t\t\t\tEnter rent ID: ");
							scanf("%d", &rentID[i]);
							printf("\t\t\t\t\tEnter duration: ");
							scanf("%d", &duration[j]);
							printf("\t\t\t\t\tAdd more movies? [Y or N]"); // asking yes or no if ever you want to add movies or not
							y_n = getch();
							
							while (y_n != 'y' && y_n != 'Y' && y_n != 'n' && y_n != 'N') // condition for if ever not y and n is not entered, the keypress do not register
							{
								y_n = getch();
							}
							
							i++; // incrementation of movie id entered 
							j++; // incremantation of days to be rented or duration
							orderCount++;
											
						}while(y_n == 'y' || y_n == 'Y');
						
						if(y_n == 'n' || y_n == 'N'){
						}
						
						i = 0;
						m1 = 0; 
						m2 = 0;
						m3 = 0;
						m4 = 0;
						
					do{
						switch(rentID[i])
						{
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								break;
							case 5:
								break;	
							default:
								
								system("cls");
								
								drama = fopen("Drama.txt", "r"); // opening movie file to dislay and to guide the cashier to enter movie information outside the 20 selected movies from switch case.
						
								if(drama != NULL) // if there's MovieList.txt
								{
					
								while ( (c = fgetc(drama)) != EOF) // then show list
								putchar(c);
								}
								
								printf("                     ******************************************************************************************\n");
								fclose(drama); // file closing
								
								//Enter the Movie information of the custom order outside the 20 selected movies in switch case
								printf("\n\n");
								printf("\t\t\t\t\t\tMovie name   : ");
								scanf("\n%[^\n]s", Mname[m1]);
								printf("\t\t\t\t\t\tGenre        : ");
								scanf("\n%[^\n]s", Mgenre[m2]);
								printf("\t\t\t\t\t\tMovie year   : ");
								scanf("%s", Myear[m3]);
								printf("\t\t\t\t\t\tPrice        : ");
								scanf("%d", &Mprice[m4]);
								break;					
						}
						
						//for adding the value of inputted value in custom order outside 20 selected movies in switch case from the previous printf, scanf
						m1++; 
						m2++;
						m3++;
						m4++;
						i++;
					}while(i < orderCount); // while it is inside do order count or how many times you enter a custom movie number from the renting tab
					
					system("cls");
					
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\tConfirm Order? [Y/N]");
					confirm = getch();
	
					while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') // Condition if the user press key accidentaly for not to register unless it is y= yes and n=no
					{
						confirm = getch();
					}
					
					if (confirm == 'y' || confirm == 'Y') // if yes confirm order condition
					{
						system("cls");
						Receipt();
					}
					else if (confirm == 'n' || confirm == 'N') // if yes confirm order condition
					{
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tPress any keys to go to menu...");
						getch();
						AdminAccountTab();
					}
						
						break;
					case 'D' : case 'd' : //SCI-FI
						system("cls");
					
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tEnter customer name: ");
						scanf("\n%[^\n]s", CusName);
						
						system("cls");
						
						i = 0;
						j = 0;
						orderCount = 0;
						
						do{
						system("cls");	
							
						scifi = fopen("Sci-Fi.txt", "r");
		
		                if(scifi != NULL) 
		                {
		                gotoxy(40, 3); printf("============================================");
                        gotoxy(40, 4); printf("||                                        ||");
                        gotoxy(40, 5); printf("||              SCI-FI MOVIES             ||");
                        gotoxy(40, 6); printf("||                                        ||");
                        gotoxy(40, 7); printf("============================================");
							
		                printf("\n\n\n");
	
			            while ( (c = fgetc(scifi)) != EOF)
			            putchar(c); //showing the list
			
						printf("               ***************************************************************************************************\n"); // spacing design							            
						fclose(scifi); // file closing
		                }
		                
							printf("\n\n\n");				
							printf("\t\t\t\t\tEnter rent ID: ");
							scanf("%d", &rentID[i]);
							printf("\t\t\t\t\tEnter duration: ");
							scanf("%d", &duration[j]);
							printf("\t\t\t\t\tAdd more movies? [Y or N]"); // asking yes or no if ever you want to add movies or not
							y_n = getch();
							
							while (y_n != 'y' && y_n != 'Y' && y_n != 'n' && y_n != 'N') // condition for if ever not y and n is not entered, the keypress do not register
							{
								y_n = getch();
							}
							
							i++; // incrementation of movie id entered 
							j++; // incremantation of days to be rented or duration
							orderCount++;
											
						}while(y_n == 'y' || y_n == 'Y');
						
						if(y_n == 'n' || y_n == 'N'){
						}
						
						i = 0;
						m1 = 0; 
						m2 = 0;
						m3 = 0;
						m4 = 0;
						
					do{
						switch(rentID[i])
						{
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								break;
							case 5:
								break;		
							default:
								
								system("cls");
								
								scifi = fopen("Sci-Fi.txt", "r"); // opening movie file to dislay and to guide the cashier to enter movie information outside the 20 selected movies from switch case.
						
								if(scifi != NULL) // if there's MovieList.txt
								{
					
								while ( (c = fgetc(scifi)) != EOF) // then show list
								putchar(c);
								}
								
								printf("                      ******************************************************************************************\n");
								fclose(scifi); // file closing
								
								//Enter the Movie information of the custom order outside the 20 selected movies in switch case
								printf("\n\n");
								printf("\t\t\t\t\t\tMovie name   : ");
								scanf("\n%[^\n]s", Mname[m1]);
								printf("\t\t\t\t\t\tGenre        : ");
								scanf("\n%[^\n]s", Mgenre[m2]);
								printf("\t\t\t\t\t\tMovie year   : ");
								scanf("%s", Myear[m3]);
								printf("\t\t\t\t\t\tPrice        : ");
								scanf("%d", &Mprice[m4]);
								break;			
						}
						
						//for adding the value of inputted value in custom order outside 20 selected movies in switch case from the previous printf, scanf
						m1++; 
						m2++;
						m3++;
						m4++;
						i++;
					}while(i < orderCount); // while it is inside do order count or how many times you enter a custom movie number from the renting tab
					
					system("cls");
					
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\tConfirm Order? [Y/N]");
					confirm = getch();
	
					while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') // Condition if the user press key accidentaly for not to register unless it is y= yes and n=no
					{
						confirm = getch();
					}
					
					if (confirm == 'y' || confirm == 'Y') // if yes confirm order condition
					{
						system("cls");
						Receipt();
					}
					else if (confirm == 'n' || confirm == 'N') // if yes confirm order condition
					{
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tPress any keys to go to menu...");
						getch();
						AdminAccountTab();
					}
						
						break;
					case 'E' : case 'e' : //ADVENTURE
						system("cls");
					
					    printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tEnter customer name: ");
						scanf("\n%[^\n]s", CusName);
						
						system("cls");
						
						i = 0;
						j = 0;
						orderCount = 0;
						
						do{
						system("cls");
							
						adventure = fopen("Adventure.txt", "r");
		
		                if(adventure != NULL) 
		                {
		                gotoxy(40, 3); printf("============================================");
                        gotoxy(40, 4); printf("||                                        ||");
                        gotoxy(40, 5); printf("||           ADVENTURE MOVIES             ||");
                        gotoxy(40, 6); printf("||                                        ||");
                        gotoxy(40, 7); printf("============================================");
							
		                printf("\n\n\n");
	
			            while ( (c = fgetc(adventure)) != EOF)
			            putchar(c); //showing the list
			
						printf("               ***************************************************************************************************\n"); // spacing design			    
						fclose(adventure); // file closing
		                }
		                
						    printf("\n\n\n");				
							printf("\t\t\t\t\tEnter rent ID: ");
							scanf("%d", &rentID[i]);
							printf("\t\t\t\t\tEnter duration: ");
							scanf("%d", &duration[j]);
							printf("\t\t\t\t\tAdd more movies? [Y or N]"); // asking yes or no if ever you want to add movies or not
							y_n = getch();
							
							while (y_n != 'y' && y_n != 'Y' && y_n != 'n' && y_n != 'N') // condition for if ever not y and n is not entered, the keypress do not register
							{
								y_n = getch();
							}
							
							i++; // incrementation of movie id entered 
							j++; // incremantation of days to be rented or duration
							orderCount++;
											
						}while(y_n == 'y' || y_n == 'Y');
						
						if(y_n == 'n' || y_n == 'N'){
						}
						
						i = 0;
						m1 = 0; 
						m2 = 0;
						m3 = 0;
						m4 = 0;
						
					do{
						switch(rentID[i])
						{
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								break;
							case 5:
								break;
							default:
								
								system("cls");
								
								adventure = fopen("Adventure.txt", "r"); // opening movie file to dislay and to guide the cashier to enter movie information outside the 20 selected movies from switch case.
						
								if(adventure != NULL) // if there's MovieList.txt
								{
					
								while ( (c = fgetc(adventure)) != EOF) // then show list
								putchar(c);
								}
								
								printf("                     ******************************************************************************************\n");
								fclose(adventure); // file closing
								
								//Enter the Movie information of the custom order outside the 20 selected movies in switch case
								printf("\n\n");
								printf("\t\t\t\t\t\tMovie name   : ");
								scanf("\n%[^\n]s", Mname[m1]);
								printf("\t\t\t\t\t\tGenre        : ");
								scanf("\n%[^\n]s", Mgenre[m2]);
								printf("\t\t\t\t\t\tMovie year   : ");
								scanf("%s", Myear[m3]);
								printf("\t\t\t\t\t\tPrice        : ");
								scanf("%d", &Mprice[m4]);
								break;						
						}
						
						//for adding the value of inputted value in custom order outside 20 selected movies in switch case from the previous printf, scanf
						m1++; 
						m2++;
						m3++;
						m4++;
						i++;
					}while(i < orderCount); // while it is inside do order count or how many times you enter a custom movie number from the renting tab
					
					system("cls");
					
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\tConfirm Order? [Y/N]");
					confirm = getch();
	
					while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') // Condition if the user press key accidentaly for not to register unless it is y= yes and n=no
					{
						confirm = getch();
					}
					
					if (confirm == 'y' || confirm == 'Y') // if yes confirm order condition
					{
						system("cls");
						Receipt();
					}
					else if (confirm == 'n' || confirm == 'N') // if yes confirm order condition
					{
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t\t\tPress any keys to go to menu...");
						getch();
						AdminAccountTab();
					}
						
						break;		
					case 'G' : case 'g' : //GO BACK TO RENT TAB
						system("cls");
						RentTab();
						break;	
				}
				break;
			case 'B': case 'b' : //RETURNING
			    system("cls");
                ReturnTab();
                printf("Click any keys to go back to menu...");
                getch();
                system("cls");
                AdminAccountTab();
				break;
			case 'G': case 'g' : //GOING BACK TO ADMIN ACCOUNT TAB OR HOME
				system("cls");
				AdminAccountTab();
				break;
   }
   
   d++;
}

void Receipt() // Receipt filing for mutiple receipts and idividual receipt and initial receipts and was responsible for counting transaction times and total
// Printing to textfile for receipts
{
	char c, z; 
	char cusConfirm;
	int customer = 1;
	time_t t;
	t = time(NULL);
	struct tm tm = *localtime(&t);
	char str[MAX], fname[MAX]; 
	char newln[MAX];       
	int lno, linectr = 0;
	
	FILE * fr; // file pointer to fr Multiple receipt
	FILE * fID; // file pointer to Single receipt
	FILE * fhl;// basta sa history log hehe
	FILE * action; 
	FILE * horror;
	FILE * drama;
	FILE * scifi;
	FILE * adventure;
	FILE * temp;
	
	strcat(CusName, ".txt");
				
	switch(genre)
	{
		case 'A' : case 'a' : //ACTION
			system("cls");
			
			z = 0; // 0 starting point for customer information
			d1 = 0;
			d = 0;
			e = 0;
			g1 = 0;
			g2 = 0;
			h = 0;
					
			do{
						
				//filling out customer information inside the loop
				printf("\n\n\n\n\n");
				printf("\t\t\t\tPLEASE INPUT CUSTOMER INFORMATION\n\n\n");
				printf("\t\t\t\tEnter [CUSTOMER FULL NAME]       : ");
				scanf("\n%[^\n]s", CusName1[d]);
				printf("\t\t\t\tEnter [CUSTOMERS CONTACT NUMBER] : ");
				scanf("%s", CusContact[e]);
				printf("\t\t\t\tStatus [STUDENT|PWD|SENIOR|NONE] : ");
				scanf("%s", CustomerStatus[h]);
				printf("\t\t\t\tEnter [PRESENTED VALID ID]       : ");
				scanf("\n%[^\n]s", CusID[d1]);
						
				d++;
				d1++;
				e++;
				g1++;
				g2++;
				h++;
				z++;
			} while(z > 1);	
					
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\tConfirm customer information? [Y or N] "); // confirmation for y and n if you want to continue
			cusConfirm = getch();
					
			while(cusConfirm != 'y' && cusConfirm != 'Y' && cusConfirm != 'n' && cusConfirm != 'N') //while y Y n N is not entered there will be no keys to be accepted in program
			{
				cusConfirm = getch();
			}
						
			if (cusConfirm == 'y' || cusConfirm == 'Y') //if Y=yes the movie entered earlier + the customer information will go in the multiple receipt list and individual receipt |fr| |fID|.
			{
						
				fr = fopen("HistoryList.txt", "a+"); // Opening file fr= multiple receipt list in append mode.
				fID = fopen(CusName, "w+"); // Opening file fID= single receipt list in w+ read and write mode.
						
				//index starting for movie total,discounted total and customer information 
				d = 0;
				d1 = 0;
				e = 0;
				g1 = 0;
				g2 = 0; 
				h = 0;
				d = 0;
				m4 = 0;
				j = 0;
						
				i = 0; // entered movie id selected in renting tab
						
				fprintf(fr, "Movie Information: \n\n");
						
				do
				{
					system("cls");
					do
					{
						switch(rentID[i]) // switch cases for receipting in multiple receipts/ individual receipts and Initial Receipt after making a transaction
						{
							case 1:
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Skyfall"); //fr Multiple receipt, adding to the preceding one. Going to collection of Receipt. 
								printf("Movie name: Skyfall"); // Initial Receipt para ma display after
								fprintf(fID, "Movie name: Skyfall"); // fID Individual Receipt by CusName
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Action");
								printf("Genre: Action");
								fprintf(fID, "Genre: Action");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2014");
								printf("Year: 2014");
								fprintf(fID, "Year: 2014");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								as1--;
								
								action = fopen("Action.txt", "r");
						        if (!action) 
						        {
						                printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 3;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(action))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, action);
						            if  (!feof(action)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 1          |  Skyfall                | Action            | 2014       | P120.00       | %d       |\n", as1);
						                }
						            }
						        }
						        fclose(action);
						        fclose(temp);
						        remove("Action.txt");
						        rename("temp.txt", "Action.txt");
								fclose(action);
						        fclose(temp);			
								break;
							case 2: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: John Wick");
								printf("Movie name: John Wick");
								fprintf(fID, "Movie name: John Wick");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Action");
								printf("Genre: Action");
								fprintf(fID, "Genre: Action");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2014");
								printf("Year: 2014");
								fprintf(fID, "Year: 2014");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								as2--;
								
								action = fopen("Action.txt", "r");
						        if (!action) 
						        {
						                printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 4;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(action))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, action);
						            if  (!feof(action)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 2          |  John Wick              | Action            | 2014       | P120.00       | %d       |\n", as2);
						                }
						            }
						        }
						        fclose(action);
						        fclose(temp);
						        remove("Action.txt");
						        rename("temp.txt", "Action.txt");
								fclose(action);
						        fclose(temp);	
								break;		
							case 3: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Battlefield Earth");
								printf("Movie name: Battlefield Earth");
								fprintf(fID, "Movie name: Battlefield Earth");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Action");
								printf("Genre: Action");
								fprintf(fID, "Genre: Action");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2020");
								printf("Year: 2020");
								fprintf(fID, "Year: 2020");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								as3--;
								
								action = fopen("Action.txt", "r");
						        if (!action) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 5;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(action))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, action);
						            if  (!feof(action)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 3          |  Battlefield Earth      | Action            | 2020       | P120.00       | %d       |\n", as3);
						                }
						            }
						        }
						        fclose(action);
						        fclose(temp);
						        remove("Action.txt");
						        rename("temp.txt", "Action.txt");
						        fclose(action);
						        fclose(temp);
								break;
							case 4: 
								fprice = 108;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Spider-Man");
								printf("Movie name: Spider-Man");
								fprintf(fID, "Movie name: Spider-Man");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Action");
								printf("Genre: Action");
								fprintf(fID, "Genre: Action");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2002");
								printf("Year: 2002");
								fprintf(fID, "Year: 2002");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fr, "\n");		
								
								as4--;
								
								action = fopen("Action.txt", "r");
						        if (!action) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 6;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(action))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, action);
						            if  (!feof(action)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 4          |  Spider-Man             | Action            | 2002       | P108.00       | %d       |\n", as4);
						                }
						            }
						        }
						        fclose(action);
						        fclose(temp);
						        remove("Action.txt");
						        rename("temp.txt", "Action.txt");
								fclose(action);
						        fclose(temp);
								break;		
							case 5:
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n"); 
								fprice = 108;
								fprintf(fr, "Movie name: Die Hard");
								printf("Movie name: Die Hard");
								fprintf(fID, "Movie name: Die Hard");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Action");
								printf("Genre: Action");
								fprintf(fID, "Genre: Action");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2016");
								printf("Year: 2016");
								fprintf(fID, "Year: 2016");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								as5--;
								
								action = fopen("Action.txt", "r");
						        if (!action) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 7;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(action))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, action);
						            if  (!feof(action)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 5          |  Die Hard               | Action            | 1988       | P108.00       | %d       |\n", as5);
						                }
						            }
						        }
						        fclose(action);
						        fclose(temp);
						        remove("Action.txt");
						        rename("temp.txt", "Action.txt");
								fclose(action);
						        fclose(temp);
								break;		
							default:
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprice = Mprice[m4];
								fprintf(fr, "Movie name: %s", Mname[i]);
								printf("Movie name: %s", Mname[i]);
								fprintf(fID, "Movie name: %s", Mname[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: %s", Mgenre[i]);
								printf("Genre: %s", Mgenre[i]);
								fprintf(fID, "Genre: %s", Mgenre[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: %s", Myear[i]);
								printf("Year: %s", Myear[i]);
								fprintf(fID, "Year: %s", Myear[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								break;		
						}
								
						totalPrice[p] += orderPrice[a][x]; // total price without discount
								
						//adding incremantation inputted
						m4++;
						j++;
						x++;
					
						i++;
								
					} while( i < orderCount);
							
						//applying the discounting
					if ((strcmp(CustomerStatus[h], "PWD") == 0) || (strcmp(CustomerStatus[h], "STUDENT") == 0) || (strcmp(CustomerStatus[h], "SENIOR") == 0))
					{
						totalAmount[b] = totalPrice[p] * 0.80;
					}
					else // outside PWD STUDENT AND SENIOR no discount
					{
						totalAmount[b] = totalPrice[p];
					}
							
					//receipts continue to printing for individual and multiple and initial receipt
					fprintf(fr, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					printf("\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fID, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fr, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					printf("\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fID, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
						
					fprintf(fr, "Customer Information: \n\n");
					printf("Customer Information: \n\n");
					fprintf(fID, "Customer Information: \n\n");
					
					fprintf(fr, "Name: %s (%s)", CusName1[d], CustomerStatus);
					printf("Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fID, "Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Contact Num: %s", CusContact[e]);
					printf("Contact Num: %s", CusContact[e]);
					fprintf(fID, "Contact Num: %s", CusContact[e]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					fprintf(fID, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900		);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Presented ID: %s", CusID[d1]);
					printf("Presented ID: %s", CusID[d1]);
					fprintf(fID, "Presented ID: %s", CusID[d1]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "====================================================================================="); // lining or seperator for multiple list
					fprintf(fr, "\n");
					fprintf(fr, "\n");
	
					codenum++;
					
					fhl = fopen("HistoryLog.txt", "a");
					
					fprintf(fhl, "     |    %d    | %-26s|              %-18d| %d/%d/%d-           |        On-Going         |\n", codenum, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900);
							
					g1++;
					g2++;
					d++;
					d1++;
							
					i++;
				}while (i < customer); //limiter
			}
					
			fclose(fr);
			fclose(fID);	
			fclose(fhl);
			break;
		case 'B' : case 'b' : //HORROR
			system("cls");
					
			z = 0; // 0 starting point for customer information
			d1 = 0;
			d = 0;
			e = 0;
			g1 = 0;
			g2 = 0;
			h = 0;
					
			do{
						
				//filling out customer information inside the loop
				printf("\n\n\n\n\n");
				printf("\t\t\t\tPLEASE INPUT CUSTOMER INFORMATION\n\n\n");
				printf("\t\t\t\tEnter [CUSTOMER FULL NAME]       : ");
				scanf("\n%[^\n]s", CusName1[d]);
				printf("\t\t\t\tEnter [CUSTOMERS CONTACT NUMBER] : ");
				scanf("%s", CusContact[e]);
				printf("\t\t\t\tStatus [STUDENT|PWD|SENIOR|NONE] : ");
				scanf("%s", CustomerStatus[h]);
				printf("\t\t\t\tEnter [PRESENTED VALID ID]       : ");
				scanf("\n%[^\n]s", CusID[d1]);
						
				d++;
				d1++;
				e++;
				g1++;
				g2++;
				h++;
				z++;
			} while(z > 1);	
					
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\tConfirm customer information? [Y or N] "); // confirmation for y and n if you want to continue
			cusConfirm = getch();
					
			while(cusConfirm != 'y' && cusConfirm != 'Y' && cusConfirm != 'n' && cusConfirm != 'N') //while y Y n N is not entered there will be no keys to be accepted in program
			{
				cusConfirm = getch();
			}
						
			if (cusConfirm == 'y' || cusConfirm == 'Y') //if Y=yes the movie entered earlier + the customer information will go in the multiple receipt list and individual receipt |fr| |fID|.
			{
						
				fr = fopen("HistoryList.txt", "a+"); // Opening file fr= multiple receipt list in append mode.
				fID = fopen(CusName, "w+"); // Opening file fID= single receipt list in w+ read and write mode.
						
				//index starting for movie total,discounted total and customer information 
				d = 0;
				d1 = 0;
				e = 0;
				g1 = 0;
				g2 = 0; 
				h = 0;
				d = 0;
				m4 = 0;
				j = 0;
						
				i = 0; // entered movie id selected in renting tab
						
				fprintf(fr, "Movie Information: \n\n");
						
				do
				{		
					system("cls");
					do
					{
						switch(rentID[i]) // switch cases for receipting in multiple receipts/ individual receipts and Initial Receipt after making a transaction
						{
							case 1:
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Insidious 1"); //fr Multiple receipt, adding to the preceding one. Going to collection of Receipt. 
								printf("Movie name: Insidious 1"); // Initial Receipt para ma display after
								fprintf(fID, "Movie name: Insidious 1"); // fID Individual Receipt by CusName
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Horror");
								printf("Genre: Horror");
								fprintf(fID, "Genre: Horror");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2017");
								printf("Year: 2017");
								fprintf(fID, "Year: 2017");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								hs1--;
								
								horror = fopen("Horror.txt", "r");
						        if (!horror) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 3;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(horror))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, horror);
						            if  (!feof(horror)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 1          |  Insidious 1            | Horror            | 2017       | P120.00       | %d       |\n", hs1);
						                }
						            }
						        }
						        fclose(horror);
						        fclose(temp);
						        remove("Horror.txt");
						        rename("temp.txt", "Horror.txt");
								fclose(horror);
						        fclose(temp);
								break;
							case 2: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Sinsister");
								printf("Movie name: Sinsister");
								fprintf(fID, "Movie name: Sinsister");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Horror");
								printf("Genre: Horror");
								fprintf(fID, "Genre: Horror");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2012");
								printf("Year: 2012");
								fprintf(fID, "Year: 2012");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								hs2--;
								
								horror = fopen("Horror.txt", "r");
						        if (!horror) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 4;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(horror))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, horror);
						            if  (!feof(horror)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 2          |  Sinsister              | Horror            | 2012       | P120.00       | %d       |\n", hs2);
						                }
						            }
						        }
						        fclose(horror);
						        fclose(temp);
						        remove("Horror.txt");
						        rename("temp.txt", "Horror.txt");
								fclose(horror);
						        fclose(temp);
								break;
							case 3: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: The Conjuring");
								printf("Movie name: The Conjuring");
								fprintf(fID, "Movie name: The Conjuring");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Horror");
								printf("Genre: Horror");
								fprintf(fID, "Genre: Horror");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2013");
								printf("Year: 2013");
								fprintf(fID, "Year: 2013");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								hs3--;	
								
								horror = fopen("Horror.txt", "r");
						        if (!horror) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 5;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(horror))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, horror);
						            if  (!feof(horror)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 3          |  The Conjuring          | Horror            | 2013       | P120.00       | %d       |\n", hs3);
						                }
						            }
						        }
						        fclose(horror);
						        fclose(temp);
						        remove("Horror.txt");
						        rename("temp.txt", "Horror.txt");
								fclose(horror);
						        fclose(temp);
								break;
							case 4: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Hereditary");
								printf("Movie name: Hereditary");
								fprintf(fID, "Movie name: Hereditary");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Horror");
								printf("Genre: Horror");
								fprintf(fID, "Genre: Horror");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2018");
								printf("Year: 2018");
								fprintf(fID, "Year: 2018");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fr, "\n");		
								
								hs4--;	
								
								horror = fopen("Horror.txt", "r");
						        if (!horror) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 6;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(horror))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, horror);
						            if  (!feof(horror)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 4          |  Hereditary             | Horror            | 2018       | P120.00       | %d       |\n", hs4);
						                }
						            }
						        }
						        fclose(horror);
						        fclose(temp);
						        remove("Horror.txt");
						        rename("temp.txt", "Horror.txt");
								fclose(horror);
						        fclose(temp);
								break;		
							case 5: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Orphan:First Kill");
								printf("Movie name: Orphan:First Kill");
								fprintf(fID, "Movie name: Orphan:First Kill");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Horror");
								printf("Genre: Horror");
								fprintf(fID, "Genre: Horror");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2022");
								printf("Year: 2022");
								fprintf(fID, "Year: 2022");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								hs5--;
								
								horror = fopen("Horror.txt", "r");
						        if (!horror) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 7;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(horror))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, horror);
						            if  (!feof(horror)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 5          |  Orphan:First Kill      | Horror            | 2022       | P120.00       | %d       |\n", hs5);
						                }
						            }
						        }
						        fclose(horror);
						        fclose(temp);
						        remove("Horror.txt");
						        rename("temp.txt", "Horror.txt");
								fclose(horror);
						        fclose(temp);
								break;		
							default:
								fprice = Mprice[m4];
								fprintf(fr, "Movie name: %s", Mname[i]);
								printf("Movie name: %s", Mname[i]);
								fprintf(fID, "Movie name: %s", Mname[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: %s", Mgenre[i]);
								printf("Genre: %s", Mgenre[i]);
								fprintf(fID, "Genre: %s", Mgenre[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: %s", Myear[i]);
								printf("Year: %s", Myear[i]);
								fprintf(fID, "Year: %s", Myear[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								break;		
						}
								
						totalPrice[p] += orderPrice[a][x]; // total price without discount
								
						//adding incremantation inputted
						m4++;
						j++;
						x++;
					
						i++;
								
					} while( i < orderCount);
							
						//applying the discounting
					if ((strcmp(CustomerStatus[h], "PWD") == 0) || (strcmp(CustomerStatus[h], "STUDENT") == 0) || (strcmp(CustomerStatus[h], "SENIOR") == 0))
					{
						totalAmount[b] = totalPrice[p] * 0.80;
					}
					else // outside PWD STUDENT AND SENIOR no discount
					{
						totalAmount[b] = totalPrice[p];
					}
							
					//receipts continue to printing for individual and multiple and initial receipt
					fprintf(fr, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					printf("\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fID, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fr, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					printf("\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fID, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
						
					fprintf(fr, "Customer Information: \n\n");
					printf("Customer Information: \n\n");
					fprintf(fID, "Customer Information: \n\n");
					
					fprintf(fr, "Name: %s (%s)", CusName1[d], CustomerStatus);
					printf("Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fID, "Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Contact Num: %s", CusContact[e]);
					printf("Contact Num: %s", CusContact[e]);
					fprintf(fID, "Contact Num: %s", CusContact[e]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					fprintf(fID, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900		);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Presented ID: %s", CusID[d1]);
					printf("Presented ID: %s", CusID[d1]);
					fprintf(fID, "Presented ID: %s", CusID[d1]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "====================================================================================="); // lining or seperator for multiple list
					fprintf(fr, "\n");
					fprintf(fr, "\n");
					
					codenum++;
					
					fhl = fopen("HistoryLog.txt", "a");
					
					fprintf(fhl, "     |    %d    | %-26s|              %-18d| %d/%d/%d-           |        On-Going         |\n", codenum, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900);
							
					g1++;
					g2++;
					d++;
					d1++;
							
					i++;
							
					i++;
				}while (i < customer); //limiter
			}
					
			fclose(fr);
			fclose(fID);
			fclose(fhl);
					
			break;	
		case 'C' : case 'c' : //DRAMA
			system("cls");
					
			z = 0; // 0 starting point for customer information
			d1 = 0;
			d = 0;
			e = 0;
			g1 = 0;
			g2 = 0;
			h = 0;
					
			do{
						
				//filling out customer information inside the loop
				printf("\n\n\n\n\n");
				printf("\t\t\t\tPLEASE INPUT CUSTOMER INFORMATION\n\n\n");
				printf("\t\t\t\tEnter [CUSTOMER FULL NAME]       : ");
				scanf("\n%[^\n]s", CusName1[d]);
				printf("\t\t\t\tEnter [CUSTOMERS CONTACT NUMBER] : ");
				scanf("%s", CusContact[e]);
				printf("\t\t\t\tStatus [STUDENT|PWD|SENIOR|NONE] : ");
				scanf("%s", CustomerStatus[h]);
				printf("\t\t\t\tEnter [PRESENTED VALID ID]       : ");
				scanf("\n%[^\n]s", CusID[d1]);
						
				d++;
				d1++;
				e++;
				g1++;
				g2++;
				h++;
				z++;
			} while(z > 1);	
					
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\tConfirm customer information? [Y or N] "); // confirmation for y and n if you want to continue
			cusConfirm = getch();
					
			while(cusConfirm != 'y' && cusConfirm != 'Y' && cusConfirm != 'n' && cusConfirm != 'N') //while y Y n N is not entered there will be no keys to be accepted in program
			{
				cusConfirm = getch();
			}
						
			if (cusConfirm == 'y' || cusConfirm == 'Y') //if Y=yes the movie entered earlier + the customer information will go in the multiple receipt list and individual receipt |fr| |fID|.
			{
						
				fr = fopen("HistoryList.txt", "a+"); // Opening file fr= multiple receipt list in append mode.
				fID = fopen(CusName, "w+"); // Opening file fID= single receipt list in w+ read and write mode.
						
				//index starting for movie total,discounted total and customer information 
				d = 0;
				d1 = 0;
				e = 0;
				g1 = 0;
				g2 = 0; 
				h = 0;
				d = 0;
				m4 = 0;
				j = 0;
						
				i = 0; // entered movie id selected in renting tab
						
				fprintf(fr, "Movie Information: \n\n");
						
				do
				{
					system("cls");
					do
					{
						switch(rentID[i]) // switch cases for receipting in multiple receipts/ individual receipts and Initial Receipt after making a transaction
						{
							case 1:
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Moonlight 1"); //fr Multiple receipt, adding to the preceding one. Going to collection of Receipt. 
								printf("Movie name: Moonlight 1"); // Initial Receipt para ma display after
								fprintf(fID, "Movie name: Moonlight 1"); // fID Individual Receipt by CusName
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Drama");
								printf("Genre: Drama");
								fprintf(fID, "Genre: Drama");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2016");
								printf("Year: 2016");
								fprintf(fID, "Year: 2016");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								ds1--;	
								
								drama = fopen("Drama.txt", "r");
						        if (!drama) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 3;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(drama))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, drama);
						            if  (!feof(drama)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 1          |  Moonlight 1            | Drama             | 2016       | P120.00       | %d       |\n", ds1);
						                }
						            }
						        }
						        fclose(drama);
						        fclose(temp);
						        remove("Drama.txt");
						        rename("temp.txt", "Drama.txt");
								fclose(drama);
						        fclose(temp);
									
								break;
							case 2: 
								fprice = 108;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Shattered Glass");
								printf("Movie name: Shattered Glass");
								fprintf(fID, "Movie name: Shattered Glass");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Drama");
								printf("Genre: Drama");
								fprintf(fID, "Genre: Drama");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2003");
								printf("Year: 2003");
								fprintf(fID, "Year: 2003");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								ds2--;		
								
								drama = fopen("Drama.txt", "r");
						        if (!drama) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 4;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(drama))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, drama);
						            if  (!feof(drama)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 2          |  Shattered Glass        | Drama             | 2003       | P108.00       | %d       |\n", ds2);
						                }
						            }
						        }
						        fclose(drama);
						        fclose(temp);
						        remove("Drama.txt");
						        rename("temp.txt", "Drama.txt");
								fclose(drama);
						        fclose(temp);
								
								break;
							case 3: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: 365 Days");
								printf("Movie name: 365 Days");
								fprintf(fID, "Movie name: 365 Days");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Drama");
								printf("Genre: Drama");
								fprintf(fID, "Genre: Drama");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2020");
								printf("Year: 2020");
								fprintf(fID, "Year: 2020");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								ds3--;	
								
								drama = fopen("Drama.txt", "r");
						        if (!drama) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 5;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(drama))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, drama);
						            if  (!feof(drama)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 3          |  365 Days               | Drama             | 2020       | P120.00       | %d       |\n", ds3);
						                }
						            }
						        }
						        fclose(drama);
						        fclose(temp);
						        remove("Drama.txt");
						        rename("temp.txt", "Drama.txt");
								fclose(drama);
						        fclose(temp);
									
								break;
							case 4: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Chemical Hearts");
								printf("Movie name: Chemical Hearts");
								fprintf(fID, "Movie name: Chemical Hearts");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Drama");
								printf("Genre: Drama");
								fprintf(fID, "Genre: Drama");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2020");
								printf("Year: 2020");
								fprintf(fID, "Year: 2020");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fr, "\n");	
								
								ds4--;		
								
								drama = fopen("Drama.txt", "r");
						        if (!drama) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 6;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(drama))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, drama);
						            if  (!feof(drama)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 4          |  Chemical Hearts        | Drama             | 2020       | P120.00       | %d       |\n", ds4);
						                }
						            }
						        }
						        fclose(drama);
						        fclose(temp);
						        remove("Drama.txt");
						        rename("temp.txt", "Drama.txt");
								fclose(drama);
						        fclose(temp);
								
								break;		
							case 5: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Spotlight");
								printf("Movie name: Spotlight");
								fprintf(fID, "Movie name: Spotlight");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Drama");
								printf("Genre: Drama");
								fprintf(fID, "Genre: Drama");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2015");
								printf("Year: 2015");
								fprintf(fID, "Year: 2015");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								ds5--;		
								
								drama = fopen("Drama.txt", "r");
						        if (!drama) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 7;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(drama))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, drama);
						            if  (!feof(drama)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 5          |  Spotlight              | Drama             | 2015       | P120.00       | %d       |\n", ds5);
						                }
						            }
						        }
						        fclose(drama);
						        fclose(temp);
						        remove("Drama.txt");
						        rename("temp.txt", "Drama.txt");
								fclose(drama);
						        fclose(temp);
								
								break;		
							default:
								fprice = Mprice[m4];
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: %s", Mname[i]);
								printf("Movie name: %s", Mname[i]);
								fprintf(fID, "Movie name: %s", Mname[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: %s", Mgenre[i]);
								printf("Genre: %s", Mgenre[i]);
								fprintf(fID, "Genre: %s", Mgenre[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: %s", Myear[i]);
								printf("Year: %s", Myear[i]);
								fprintf(fID, "Year: %s", Myear[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								break;		
						}
								
						totalPrice[p] += orderPrice[a][x]; // total price without discount
								
						//adding incremantation inputted
						m4++;
						j++;
						x++;
					
						i++;
								
					} while( i < orderCount);
							
						//applying the discounting
					if ((strcmp(CustomerStatus[h], "PWD") == 0) || (strcmp(CustomerStatus[h], "STUDENT") == 0) || (strcmp(CustomerStatus[h], "SENIOR") == 0))
					{
					    totalAmount[b] = totalPrice[p] * 0.80;
					}
					else // outside PWD STUDENT AND SENIOR no discount
					{
						totalAmount[b] = totalPrice[p];
					}
							
					//receipts continue to printing for individual and multiple and initial receipt
					fprintf(fr, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					printf("\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fID, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fr, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					printf("\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fID, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
						
					fprintf(fr, "Customer Information: \n\n");
					printf("Customer Information: \n\n");
					fprintf(fID, "Customer Information: \n\n");
					
					fprintf(fr, "Name: %s (%s)", CusName1[d], CustomerStatus);
					printf("Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fID, "Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Contact Num: %s", CusContact[e]);
					printf("Contact Num: %s", CusContact[e]);
					fprintf(fID, "Contact Num: %s", CusContact[e]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					fprintf(fID, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900		);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Presented ID: %s", CusID[d1]);
					printf("Presented ID: %s", CusID[d1]);
					fprintf(fID, "Presented ID: %s", CusID[d1]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "====================================================================================="); // lining or seperator for multiple list
					fprintf(fr, "\n");
					fprintf(fr, "\n");
					
					codenum++;
					
					fhl = fopen("HistoryLog.txt", "a");
					
					fprintf(fhl, "     |    %d    | %-26s|              %-18d| %d/%d/%d-           |        On-Going         |\n", codenum, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900);
					
					g1++;
					g2++;
					d++;
					d1++;
							
					i++;
				}while (i < customer); //limiter
			}
					
			fclose(fr);
			fclose(fID);
			fclose(fhl);
					
			break;
		case 'D' : case 'd' : //SCI-FI
			system("cls");
					
			z = 0; // 0 starting point for customer information
			d1 = 0;
			d = 0;
			e = 0;
			g1 = 0;
			g2 = 0;
			h = 0;
					
			do{
						
				//filling out customer information inside the loop
				printf("\n\n\n\n\n");
				printf("\t\t\t\tPLEASE INPUT CUSTOMER INFORMATION\n\n\n");
				printf("\t\t\t\tEnter [CUSTOMER FULL NAME]       : ");
				scanf("\n%[^\n]s", CusName1[d]);
				printf("\t\t\t\tEnter [CUSTOMERS CONTACT NUMBER] : ");
				scanf("%s", CusContact[e]);
				printf("\t\t\t\tStatus [STUDENT|PWD|SENIOR|NONE] : ");
				scanf("%s", CustomerStatus[h]);
				printf("\t\t\t\tEnter [PRESENTED VALID ID]       : ");
				scanf("\n%[^\n]s", CusID[d1]);
						
				d++;
				d1++;
				e++;
				g1++;
				g2++;
				h++;
				z++;
			} while(z > 1);	
					
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\tConfirm customer information? [Y or N] "); // confirmation for y and n if you want to continue
			cusConfirm = getch();
					
			while(cusConfirm != 'y' && cusConfirm != 'Y' && cusConfirm != 'n' && cusConfirm != 'N') //while y Y n N is not entered there will be no keys to be accepted in program
			{
					cusConfirm = getch();
			}
						
			if (cusConfirm == 'y' || cusConfirm == 'Y') //if Y=yes the movie entered earlier + the customer information will go in the multiple receipt list and individual receipt |fr| |fID|.
			{
						
				fr = fopen("HistoryList.txt", "a+"); // Opening file fr= multiple receipt list in append mode.
				fID = fopen(CusName, "w+"); // Opening file fID= single receipt list in w+ read and write mode.
						
				//index starting for movie total,discounted total and customer information 
				d = 0;
				d1 = 0;
				e = 0;
				g1 = 0;
				g2 = 0; 
				h = 0;
				d = 0;
				m4 = 0;
				j = 0;
						
				i = 0; // entered movie id selected in renting tab
						
				fprintf(fr, "Movie Information: \n\n");
						
				do
				{
					system("cls");
					do
					{
						switch(rentID[i]) // switch cases for receipting in multiple receipts/ individual receipts and Initial Receipt after making a transaction
						{
							case 1:
								fprice = 108;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Star Wars"); //fr Multiple receipt, adding to the preceding one. Going to collection of Receipt. 
								printf("Movie name: Star Wars"); // Initial Receipt para ma display after
								fprintf(fID, "Movie name: Star Wars"); // fID Individual Receipt by CusName
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Sci-Fi");
								printf("Genre: Sci-Fi");
								fprintf(fID, "Genre: Sci-Fi");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 1977");
								printf("Year: 1977");
								fprintf(fID, "Year: 1977");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								sfs1--;		
								
								scifi = fopen("Sci-Fi.txt", "r");
						        if (!scifi) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 3;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(scifi))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, scifi);
						            if  (!feof(scifi)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 1          |  Star Wars              | Sci-Fi            | 1977       | P108.00       | %d       |\n", sfs1);
						                }
						            }
						        }
						        fclose(scifi);
						        fclose(temp);
						        remove("Sci-Fi.txt");
						        rename("temp.txt", "Sci-Fi.txt");
								fclose(scifi);
						        fclose(temp);
								
								break;
							case 2: 
								fprice = 108;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Jurassic Park");
								printf("Movie name: Jurassic Park");
								fprintf(fID, "Movie name: Jurassic Park");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Sci-Fi");
								printf("Genre: Sci-Fi");
								fprintf(fID, "Genre: Sci-Fi");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 1993");
								printf("Year: 1993");
								fprintf(fID, "Year: 1993");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								sfs2--;	
								
								scifi = fopen("Sci-Fi.txt", "r");
						        if (!scifi) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 4;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(scifi))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, scifi);
						            if  (!feof(scifi)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 2          |  Jurassic Park          | Sci-Fi            | 1993       | P108.00       | %d       |\n", sfs2);
						                }
						            }
						        }
						        fclose(scifi);
						        fclose(temp);
						        remove("Sci-Fi.txt");
						        rename("temp.txt", "Sci-Fi.txt");
								fclose(scifi);
						        fclose(temp);
									
								break;
							case 3: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: The Hunger Games");
								printf("Movie name: The Hunger Games");
								fprintf(fID, "Movie name: The Hunger Games");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Sci-Fi");
								printf("Genre: Sci-Fi");
								fprintf(fID, "Genre: Sci-Fi");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2012");
								printf("Year: 2012");
								fprintf(fID, "Year: 2012");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								sfs3--;	
								
								scifi = fopen("Sci-Fi.txt", "r");
						        if (!scifi) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 5;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(scifi))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, scifi);
						            if  (!feof(scifi)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 3          |  The Hunger Games       | Sci-Fi            | 2012       | P120.00       | %d       |\n", sfs3);
						                }
						            }
						        }
						        fclose(scifi);
						        fclose(temp);
						        remove("Sci-Fi.txt");
						        rename("temp.txt", "Sci-Fi.txt");
								fclose(scifi);
						        fclose(temp);
									
								break;
							case 4: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Black Adam");
								printf("Movie name: Black Adam");
								fprintf(fID, "Movie name: Black Adam");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Sci-Fi");
								printf("Genre: Sci-Fi");
								fprintf(fID, "Genre: Sci-Fi");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2022");
								printf("Year: 2022");
								fprintf(fID, "Year: 2022");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fr, "\n");	
								
								sfs4--;		
								
								scifi = fopen("Sci-Fi.txt", "r");
						        if (!scifi) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 6;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(scifi))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, scifi);
						            if  (!feof(scifi)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 4          |  Black Adam             | Sci-Fi            | 2022       | P120.00       | %d       |\n", sfs4);
						                }
						            }
						        }
						        fclose(scifi);
						        fclose(temp);
						        remove("Sci-Fi.txt");
						        rename("temp.txt", "Sci-Fi.txt");
								fclose(scifi);
						        fclose(temp);
								
								break;		
							case 5: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Stowaway");
								printf("Movie name: Stowaway");
								fprintf(fID, "Movie name: Stowaway");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Sci-Fi");
								printf("Genre: Sci-Fi");
								fprintf(fID, "Genre: Sci-Fi");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2020");
								printf("Year: 2020");
								fprintf(fID, "Year: 2020");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								sfs5--;		
								
								scifi = fopen("Sci-Fi.txt", "r");
						        if (!scifi) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 7;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(scifi))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, scifi);
						            if  (!feof(scifi)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 5          |  Stowaway               | Sci-Fi            | 2020       | P120.00       | %d       |\n", sfs5);
						                }
						            }
						        }
						        fclose(scifi);
						        fclose(temp);
						        remove("Sci-Fi.txt");
						        rename("temp.txt", "Sci-Fi.txt");
								fclose(scifi);
						        fclose(temp);
								
								break;		
							default:
								fprice = Mprice[m4];
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: %s", Mname[i]);
								printf("Movie name: %s", Mname[i]);
								fprintf(fID, "Movie name: %s", Mname[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: %s", Mgenre[i]);
								printf("Genre: %s", Mgenre[i]);
								fprintf(fID, "Genre: %s", Mgenre[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: %s", Myear[i]);
								printf("Year: %s", Myear[i]);
								fprintf(fID, "Year: %s", Myear[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								break;		
						}
								
						totalPrice[p] += orderPrice[a][x]; // total price without discount
								
						//adding incremantation inputted
						m4++;
						j++;
						x++;
					
						i++;
								
					} while( i < orderCount);
							
						//applying the discounting
					if ((strcmp(CustomerStatus[h], "PWD") == 0) || (strcmp(CustomerStatus[h], "STUDENT") == 0) || (strcmp(CustomerStatus[h], "SENIOR") == 0))
					{
					    totalAmount[b] = totalPrice[p] * 0.80;
					}
					else // outside PWD STUDENT AND SENIOR no discount
					{
						totalAmount[b] = totalPrice[p];
					}
							
					//receipts continue to printing for individual and multiple and initial receipt
					fprintf(fr, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					printf("\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fID, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fr, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					printf("\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fID, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
						
					fprintf(fr, "Customer Information: \n\n");
					printf("Customer Information: \n\n");
					fprintf(fID, "Customer Information: \n\n");
					
					fprintf(fr, "Name: %s (%s)", CusName1[d], CustomerStatus);
					printf("Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fID, "Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Contact Num: %s", CusContact[e]);
					printf("Contact Num: %s", CusContact[e]);
					fprintf(fID, "Contact Num: %s", CusContact[e]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					fprintf(fID, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900		);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Presented ID: %s", CusID[d1]);
					printf("Presented ID: %s", CusID[d1]);
					fprintf(fID, "Presented ID: %s", CusID[d1]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "====================================================================================="); // lining or seperator for multiple list
					fprintf(fr, "\n");
					fprintf(fr, "\n");
					
					codenum++;
					
					fhl = fopen("HistoryLog.txt", "a");
					
					fprintf(fhl, "     |    %d    | %-26s|              %-18d| %d/%d/%d-           |        On-Going         |\n", codenum, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900);
					
					g1++;
					g2++;
					d++;
					d1++;
							
					i++;
				}while (i < customer); //limiter
			}
					
			fclose(fr);
			fclose(fID);
			fclose(fhl);
				
			break;
		case 'E' : case 'e' : //ADVENTURE
			system("cls");
					
			z = 0; // 0 starting point for customer information
			d1 = 0;
			d = 0;
			e = 0;
			g1 = 0;
			g2 = 0;
			h = 0;
					
			do{
						
				//filling out customer information inside the loop
				printf("\n\n\n\n\n");
				printf("\t\t\t\tPLEASE INPUT CUSTOMER INFORMATION\n\n\n");
				printf("\t\t\t\tEnter [CUSTOMER FULL NAME]       : ");
				scanf("\n%[^\n]s", CusName1[d]);
				printf("\t\t\t\tEnter [CUSTOMERS CONTACT NUMBER] : ");
				scanf("%s", CusContact[e]);
				printf("\t\t\t\tStatus [STUDENT|PWD|SENIOR|NONE] : ");
				scanf("%s", CustomerStatus[h]);
				printf("\t\t\t\tEnter [PRESENTED VALID ID]       : ");
				scanf("\n%[^\n]s", CusID[d1]);
						
				d++;
				d1++;
				e++;
				g1++;
				g2++;
				h++;
				z++;
			} while(z > 1);	
					
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\tConfirm customer information? [Y or N] "); // confirmation for y and n if you want to continue
			cusConfirm = getch();
					
			while(cusConfirm != 'y' && cusConfirm != 'Y' && cusConfirm != 'n' && cusConfirm != 'N') //while y Y n N is not entered there will be no keys to be accepted in program
			{
				cusConfirm = getch();
			}
						
			if (cusConfirm == 'y' || cusConfirm == 'Y') //if Y=yes the movie entered earlier + the customer information will go in the multiple receipt list and individual receipt |fr| |fID|.
			{
						
				fr = fopen("HistoryList.txt", "a+"); // Opening file fr= multiple receipt list in append mode.
				fID = fopen(CusName, "w+"); // Opening file fID= single receipt list in w+ read and write mode.
						
				//index starting for movie total,discounted total and customer information 
				d = 0;
				d1 = 0;
				e = 0;
				g1 = 0;
				g2 = 0; 
				h = 0;
				d = 0;
				m4 = 0;
				j = 0;
						
				i = 0; // entered movie id selected in renting tab
						
				fprintf(fr, "Movie Information: \n\n");
						
				do
				{	
					system("cls");
					do
					{
						switch(rentID[i]) // switch cases for receipting in multiple receipts/ individual receipts and Initial Receipt after making a transaction
						{
							case 1:
								fprice = 108;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Lord of the Rings"); //fr Multiple receipt, adding to the preceding one. Going to collection of Receipt. 
								printf("Movie name: Lord of the Rings"); // Initial Receipt para ma display after
								fprintf(fID, "Movie name: Lord of the Rings"); // fID Individual Receipt by CusName
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Adventure");
								printf("Genre: Adventure");
								fprintf(fID, "Genre: Adventure");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2001");
								printf("Year: 2001");
								fprintf(fID, "Year: 2001");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");		
								
								ads1--;	
								
								adventure = fopen("Adventure.txt", "r");
						        if (!adventure) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 3;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(adventure))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, adventure);
						            if  (!feof(adventure)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 1          |  Lord of the Rings      | Adventure         | 2001       | P108.00       | %d       |\n", ads1);
						                }
						            }
						        }
						        fclose(adventure);
						        fclose(temp);
						        remove("Adventure.txt");
						        rename("temp.txt", "Adventure.txt");
								fclose(adventure);
						        fclose(temp);
								
								break;
							case 2: 
								fprice = 108;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: The Santa Clause");
								printf("Movie name: The Santa Clause");
								fprintf(fID, "Movie name: The Santa Clause");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Adventure");
								printf("Genre: Adventure");
								fprintf(fID, "Genre: Adventure");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 1993");
								printf("Year: 1993");
								fprintf(fID, "Year: 1993");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");			
								printf("\n");			
								fprintf(fID, "\n");	
								
								ads2--;	
								
								adventure = fopen("Adventure.txt", "r");
						        if (!adventure) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 4;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(adventure))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, adventure);
						            if  (!feof(adventure)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 2          |  The Santa Clause       | Adventure         | 2020       | P120.00       | %d       |\n", ads2);
						                }
						            }
						        }
						        fclose(adventure);
						        fclose(temp);
						        remove("Adventure.txt");
						        rename("temp.txt", "Adventure.txt");
								fclose(adventure);
						        fclose(temp);
									
								break;
							case 3: 
								fprice = 108;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Avatar");
								printf("Movie name: Avatar");
								fprintf(fID, "Movie name: Avatar");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Adventure");
								printf("Genre: Adventure");
								fprintf(fID, "Genre: Adventure");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2009");
								printf("Year: 2009");
								fprintf(fID, "Year: 2009");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								ads3--;	
								
								adventure = fopen("Adventure.txt", "r");
						        if (!adventure) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 5;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(adventure))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, adventure);
						            if  (!feof(adventure)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 3          |  Avatar                 | Adventure         | 2009       | P108.00       | %d       |\n", ads3);
						                }
						            }
						        }
						        fclose(adventure);
						        fclose(temp);
						        remove("Adventure.txt");
						        rename("temp.txt", "Adventure.txt");
								fclose(adventure);
						        fclose(temp);
									
								break;
							case 4: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Brave");
								printf("Movie name: Brave");
								fprintf(fID, "Movie name: Brave");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Adventure");
								printf("Genre: Adventure");
								fprintf(fID, "Genre: Adventure");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2011");
								printf("Year: 2011");
								fprintf(fID, "Year: 2011");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fr, "\n");	
								
								ads4--;	
								
								adventure = fopen("Adventure.txt", "r");
						        if (!adventure) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 6;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(adventure))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, adventure);
						            if  (!feof(adventure)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 4          |  Brave                  | Adventure         | 2011       | P120.00       | %d       |\n", ads4);
						                }
						            }
						        }
						        fclose(adventure);
						        fclose(temp);
						        remove("Adventure.txt");
						        rename("temp.txt", "Adventure.txt");
								fclose(adventure);
						        fclose(temp);
									
								break;		
							case 5: 
								fprice = 120;
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: Greyhound");
								printf("Movie name: Greyhound");
								fprintf(fID, "Movie name: Greyhound");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: Adventure");
								printf("Genre: Adventure");
								fprintf(fID, "Genre: Adventure");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: 2020");
								printf("Year: 2020");
								fprintf(fID, "Year: 2020");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");	
								
								ads5--;	
								
								adventure = fopen("Adventure.txt", "r");
						        if (!adventure) 
						        {
						            printf("Unable to open the input file!!\n");
						        }
						        temp = fopen("temp.txt", "w+");
						        /* get the new line from the user *
						        /* get the line number to delete the specific line */
						        lno = 7;
						        lno++;
						         // copy all contents to the temporary file other except specific line
						        while (!feof(adventure))
						        {
						            strcpy(str, "\0");
						            fgets(str, MAX, adventure);
						            if  (!feof(adventure)) 
						            {
						                linectr++;
						                if (linectr != lno) 
						                {
						                    fprintf(temp, "%s", str);
						                } 
						                else
						                {
						                    fprintf(temp, "               | 5          |  Greyhound              | Adventure         | 2020       | P120.00       | %d       |\n", ads5);
						                }
						            }
						        }
						        fclose(adventure);
						        fclose(temp);
						        remove("Adventure.txt");
						        rename("temp.txt", "Adventure.txt");
								fclose(adventure);
						        fclose(temp);
									
								break;		
							default:
								fprice = Mprice[m4];
								fprintf(fr, "Rent ID: %d", rentID[i]);
								printf("Rent ID: %d", rentID[i]);
								fprintf(fID, "Rent ID: %d", rentID[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Movie name: %s", Mname[i]);
								printf("Movie name: %s", Mname[i]);
								fprintf(fID, "Movie name: %s", Mname[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Genre: %s", Mgenre[i]);
								printf("Genre: %s", Mgenre[i]);
								fprintf(fID, "Genre: %s", Mgenre[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Year: %s", Myear[i]);
								printf("Year: %s", Myear[i]);
								fprintf(fID, "Year: %s", Myear[i]);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Price: P%d.00/day", fprice);
								printf("Price: P%d.00/day", fprice);
								fprintf(fID, "Price: P%d.00/day", fprice);
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "Days to be rented: %d", duration[j]);
								printf("Days to be rented: %d", duration[j]);
								fprintf(fID, "Days to be rented: %d", duration[j]);
								orderPrice[a][x] = duration[j] * fprice;
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								fprintf(fr, "\n");
								printf("\n");
								fprintf(fID, "\n");
								break;		
						}
								
						totalPrice[p] += orderPrice[a][x]; // total price without discount
								
						//adding incremantation inputted
						m4++;
						j++;
						x++;
					
						i++;
								
					} while( i < orderCount);
							
						//applying the discounting
					if ((strcmp(CustomerStatus[h], "PWD") == 0) || (strcmp(CustomerStatus[h], "STUDENT") == 0) || (strcmp(CustomerStatus[h], "SENIOR") == 0))
					{
					    totalAmount[b] = totalPrice[p] * 0.80;
					}
					else // outside PWD STUDENT AND SENIOR no discount
					{
						totalAmount[b] = totalPrice[p];
					}
							
					//receipts continue to printing for individual and multiple and initial receipt
					fprintf(fr, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					printf("\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fID, "\t\t\t\t\t\t\tTotal Amount: P%.2lf\n", totalPrice[p]);
					fprintf(fr, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					printf("\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fID, "\t\t\t\t\t\t\tDiscounted Price: P%.2lf", totalAmount[b]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
						
					fprintf(fr, "Customer Information: \n\n");
					printf("Customer Information: \n\n");
					fprintf(fID, "Customer Information: \n\n");
					
					fprintf(fr, "Name: %s (%s)", CusName1[d], CustomerStatus);
					printf("Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fID, "Name: %s (%s)", CusName1[d], CustomerStatus);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Contact Num: %s", CusContact[e]);
					printf("Contact Num: %s", CusContact[e]);
					fprintf(fID, "Contact Num: %s", CusContact[e]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
					fprintf(fID, "Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900		);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "Presented ID: %s", CusID[d1]);
					printf("Presented ID: %s", CusID[d1]);
					fprintf(fID, "Presented ID: %s", CusID[d1]);
					fprintf(fr, "\n");
					printf("\n");
					fprintf(fID, "\n");
					fprintf(fr, "====================================================================================="); // lining or seperator for multiple list
					fprintf(fr, "\n");
					fprintf(fr, "\n");
					
					codenum++;
					
					fhl = fopen("HistoryLog.txt", "a");
					
					fprintf(fhl, "     |    %d    | %-26s|              %-18d| %d/%d/%d-           |        On-Going         |\n", codenum, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900);
					
					g1++;
					g2++;
					d++;
					d1++;
							
					i++;
				}while (i < customer); //limiter
			}
					
			fclose(fr);
			fclose(fID);
			fclose(fhl);
					
			break;
	}
			
	printf("Press any key to go back to menu...");
	getch();
	AdminAccountTab();

} 

void ReturnTab()
{
	
	FILE * fID; // file pointer to Single receipt
	FILE * fhl;// basta sa history log hehe
	FILE * action; 
	FILE * horror;
	FILE * drama;
	FILE * scifi;
	FILE * adventure;
	FILE * temp;
	FILE * Temp;
	
	time_t t;
	t = time(NULL);
	struct tm tm = *localtime(&t);
	char c, retConfirm;
	char str[MAX]; 
	char newln[MAX];       
	int lno, hlline = 2 , linectr;
	int codenum1;
	
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\tSearch for customer transaction: ");
	scanf("\n%[^\n]s", CusName);
	strcat(CusName, ".txt");
	
	fID = fopen(CusName, "r");
	
	system("cls");
	
	if(fID != NULL) 
	{
		            
		while ( (c = fgetc(fID)) != EOF)
		putchar(c); //showing the list
		
		fclose(fID); // file closing
	}
	
	getch();
	
	system("cls");
				
	gotoxy(40, 3); printf("============================================");
    gotoxy(40, 4); printf("||                                        ||");
    gotoxy(40, 5); printf("||           SELECT MOVIE GENRE'S         ||");
    gotoxy(40, 6); printf("||               (TO RETURN ON)           ||");
    gotoxy(40, 7); printf("============================================");
    gotoxy(40, 8); printf("||                                        ||");
    gotoxy(40, 9); printf("||       [A] Action                       ||");
    gotoxy(40, 10);printf("||       [B] Horror                       ||");
	gotoxy(40, 11);printf("||       [C] Drama                        ||");
    gotoxy(40, 12);printf("||       [D] Sci-Fi                       ||");
    gotoxy(40, 13);printf("||       [E] Adventure                    ||"); 
	gotoxy(40, 14);printf("||                                        ||");    
	gotoxy(40, 15);printf("============================================");              
	gotoxy(71, 16); printf("[G] Go Back");
				
	gotoxy(47, 19); printf(" Enter your choice : ");
	genre = getch();
	            
	while ( genre != 'A' && genre != 'a' && genre != 'B' && genre != 'b' && genre != 'C' && genre != 'c' && genre != 'D' && genre != 'd' && genre != 'E' && genre != 'e' && genre != 'G' && genre != 'g')
	{
    	genre = getch();
    }
	
	i = 0;
	d = 0;
	switch(genre)
		{
			case 'A' : case 'a' : //ACTION
				system("cls");
				
				do{
					printf("\n\n\n");
					printf("\t\t\t\t\tRETURNING ACTION MOVIE");
					printf("\n\n");
					printf("\t\t\t\t\tEnter rent ID(To Return): ");
					scanf("%d", &i);
						
						switch(i){
							case 1:
								linectr = 0;
								as1 ++;
				
								action = fopen("Action.txt", "r");
								if (!action) 
								{
								    printf("Unable to open the input file!!\n");
								}
								temp = fopen("temp.txt", "w+");
								
								lno = 3;
								lno++;
												        
								while (!feof(action))
								{
									strcpy(str, "\0");
									fgets(str, MAX, action);
									if  (!feof(action)) 
									{
										linectr++;
										if (linectr != lno) 
									 	{
											fprintf(temp, "%s", str);
										} 
										else
										{
											fprintf(temp, "               | 1          |  Skyfall                | Action            | 2014       | P120.00       | %d       |\n", as1);
										}
									}
								}								
								fclose(action);
								fclose(temp);
								remove("Action.txt");
								rename("temp.txt", "Action.txt");
								fclose(action);
								fclose(temp);
								
								break;
							case 2:	
								linectr = 0;
								as2 ++;
								
								action = fopen("Action.txt", "r");
								if (!action) 
								{
								        printf("Unable to open the input file!!\n");
								}
								temp = fopen("temp.txt", "w+");
								/* get the new line from the user *
								/* get the line number to delete the specific line */
								lno = 4;
								lno++;
								// copy all contents to the temporary file other except specific line
								while (!feof(action))
								{
								    strcpy(str, "\0");
								    fgets(str, MAX, action);
								    if  (!feof(action)) 
								    {
								        linectr++;
								        if (linectr != lno) 
								        {
								            fprintf(temp, "%s", str);
								        } 
								        else
								        {
								            fprintf(temp, "               | 2          |  John Wick              | Action            | 2014       | P120.00       | %d       |\n", as2);
								        }
								    }
								}
						
								fclose(action);
								fclose(temp);
								remove("Action.txt");
								rename("temp.txt", "Action.txt");
								fclose(action);
								fclose(temp);
												
								break;
							case 3:	
								linectr = 0;
								as3 ++;					
							
								action = fopen("Action.txt", "r");
								if (!action) 
								{
								    printf("Unable to open the input file!!\n");
								}
								temp = fopen("temp.txt", "w+");
								/* get the new line from the user *
								/* get the line number to delete the specific line */
								lno = 5;
								lno++;
								// copy all contents to the temporary file other except specific line
								while (!feof(action))
								{
								    strcpy(str, "\0");
								    fgets(str, MAX, action);
								    if  (!feof(action)) 
								    {
								        linectr++;
								        if (linectr != lno) 
								        {
								            fprintf(temp, "%s", str);
								        } 
								        else
								        {
								            fprintf(temp, "               | 3          |  Battlefield Earth      | Action            | 2020       | P120.00       | %d       |\n", as3);
								        }
								    }
								}
								
								fclose(action);
								fclose(temp);
								remove("Action.txt");
								rename("temp.txt", "Action.txt");
								fclose(action);
								fclose(temp);
			
								break;
							case 4:
								linectr = 0;
								as4 ++;
								
								action = fopen("Action.txt", "r");
								if (!action) 
								{
								    printf("Unable to open the input file!!\n");
								}
								temp = fopen("temp.txt", "w+");
								/* get the new line from the user *
								/* get the line number to delete the specific line */
								lno = 6;
								lno++;
								// copy all contents to the temporary file other except specific line
								while (!feof(action))
								{
								    strcpy(str, "\0");
								    fgets(str, MAX, action);
								    if  (!feof(action)) 
								    {
								        linectr++;
								        if (linectr != lno) 
								        {
								            fprintf(temp, "%s", str);
								        } 
								        else
								        {
								            fprintf(temp, "               | 4          |  Spider-Man             | Action            | 2002       | P108.00       | %d       |\n", as4);
								        }
								    }
								}	
								
								fclose(action);
								fclose(temp);
								remove("Action.txt");
								rename("temp.txt", "Action.txt");
								fclose(action);
								fclose(temp);
								
								break;
							case 5:
								linectr = 0;
								as5 ++;
								
								action = fopen("Action.txt", "r");
								if (!action) 
								{
								    printf("Unable to open the input file!!\n");
								}
								temp = fopen("temp.txt", "w+");
								/* get the new line from the user *
								/* get the line number to delete the specific line */
								lno = 7;
								lno++;
								// copy all contents to the temporary file other except specific line
								while (!feof(action))
								{
								    strcpy(str, "\0");
								    fgets(str, MAX, action);
								    if  (!feof(action)) 
								    {
								        linectr++;
								        if (linectr != lno) 
								        {
								            fprintf(temp, "%s", str);
								        } 
								        else
								        {
								            fprintf(temp, "               | 5          |  Die Hard               | Action            | 1988       | P108.00       | %d       |\n", as5);
								        }
								    }
								}
												
								fclose(action);
								fclose(temp);
								remove("Action.txt");
								rename("temp.txt", "Action.txt");
								fclose(action);
								fclose(temp);
								
								break;
						}
						
						printf("\n\n\n\t\t\t\t\tIs there other more to return [Y/N]?");
						retConfirm = getch();
						
						while(retConfirm != 'y' && retConfirm != 'Y' && retConfirm != 'n' && retConfirm != 'N'){
							retConfirm = getch();
						}
						
						i++;
				}while(retConfirm == 'y' || retConfirm == 'Y');
				
				linectr = 0;
				
				system("cls");
				
				char hlog, c;
    
	            FILE* fhl;
    	    	fhl = fopen("HistoryLog.txt", "r");
    	    	
    	    	if(fhl != NULL) 
		        {							
		        	printf("\n\n\n");	
	
			        while ( (c = fgetc(fhl)) != EOF)
			        putchar(c); //showing the list
			
		            printf("     **************************************************************************************************************************\n"); // spacing design
		        }
		        fclose(fhl); // file closing
				
				
				printf("\n\n\n\n\t\t\t\t\tEnter code number [Code#]: ");
				scanf("%d", &codenum1);
				
				hlline = hlline + codenum1;
				
				hlline++;
				
				printf("\n");
				printf("\t\t\t\t\tPlease input date [mm dd yyyy]: ");
				scanf("%d %d %d", &rmonth, &rday, &ryear);
				
				fhl = fopen("HistoryLog.txt", "r");
				Temp = fopen("Temp.txt", "w+");
				
				while (!feof(fhl))
				{
					strcpy(str, "\0");
					fgets(str, MAX, fhl);
					if  (!feof(fhl)) 
					{
						linectr++;
						if (linectr != hlline) 
						{
							fprintf(Temp, "%s", str);
						} 
						else
						{
							fprintf(Temp, "     |    %d    | %-26s|              %-18d| %d/%d/%d-%d/%d/%d |        Returned         |\n", codenum1, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900, rmonth, rday, ryear);
						}
					}
				}
													
				fclose(fhl);
				fclose(Temp);
				remove("HistoryLog.txt");
				rename("Temp.txt", "HistoryLog.txt");
				fclose(fhl);
				fclose(Temp);
							
				break;
						
			case 'B' : case 'b' : //HORROR
				system("cls");
				
				do{
					printf("\n\n\n");
					printf("\t\t\t\t\tRETURNING HORROR MOVIE");
					printf("\n\n");
					printf("\t\t\t\t\tEnter rent ID(To Return): ");
					scanf("%d", &i);
						
					switch(i){
					case 1:
						linectr = 0;
						hs1 ++;
		
						horror = fopen("Horror.txt", "r");
						if (!horror) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 3;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(horror))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, horror);
						    if  (!feof(horror)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 1          |  Insidious 1            | Horror            | 2017       | P120.00       | %d       |\n", hs1);
						        }
						    }
						}
						
						fclose(horror);
						fclose(temp);
						remove("Horror.txt");
						rename("temp.txt", "Horror.txt");
						fclose(horror);
						fclose(temp);
						
						break;
					case 2:
						linectr = 0;
						hs2++;					
					
						horror = fopen("Horror.txt", "r");
						if (!horror) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 4;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(horror))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, horror);
						    if  (!feof(horror)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 2          |  Sinsister              | Horror            | 2012       | P120.00       | %d       |\n", hs2);
						        }
						    }
						}
							
						fclose(horror);
						fclose(temp);
						remove("Horror.txt");
						rename("temp.txt", "Horror.txt");
						fclose(horror);
						fclose(temp);
						
						break;
					case 3:	
						linectr = 0;
						hs3++;	
								
						horror = fopen("Horror.txt", "r");
						if (!horror) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 5;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(horror))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, horror);
						    if  (!feof(horror)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 3          |  The Conjuring          | Horror            | 2013       | P120.00       | %d       |\n", hs3);
						        }
						    }
						}
						
						fclose(horror);
						fclose(temp);
						remove("Horror.txt");
						rename("temp.txt", "Horror.txt");
						fclose(horror);
						fclose(temp);
				
						break;
					case 4:
						linectr = 0;
						hs4++;	
								
						horror = fopen("Horror.txt", "r");
						if (!horror) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 6;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(horror))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, horror);
						    if  (!feof(horror)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 4          |  Hereditary             | Horror            | 2018       | P120.00       | %d       |\n", hs4);
						        }
						    }
						}
						
						fclose(horror);
						fclose(temp);
						remove("Horror.txt");
						rename("temp.txt", "Horror.txt");
						fclose(horror);
						fclose(temp);
							
						break;
					case 5:
						linectr = 0;
						hs5++;
								
						horror = fopen("Horror.txt", "r");
						if (!horror) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 7;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(horror))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, horror);
							if  (!feof(horror)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 5          |  Orphan:First Kill      | Horror            | 2022       | P120.00       | %d       |\n", hs5);
						        }
						    }
						}
						
						fclose(horror);
						fclose(temp);
						remove("Horror.txt");
						rename("temp.txt", "Horror.txt");
						fclose(horror);
						fclose(temp);
						
					}
						break;
					
					    printf("\n\n\n\t\t\t\t\tIs there other more to return [Y/N]?");
						retConfirm = getch();
						
						while(retConfirm != 'y' && retConfirm != 'Y' && retConfirm != 'n' && retConfirm != 'N'){
							retConfirm = getch();
						}
						
						i++;
				}while(retConfirm == 'y' || retConfirm == 'Y');
				
				linectr = 0;
				
				system("cls");
				

    

    	    	fhl = fopen("HistoryLog.txt", "r");
    	    	
    	    	if(fhl != NULL) //displaying hlog while returning for guide enter code number
		        {							
		        	printf("\n\n\n");	
	
			        while ( (c = fgetc(fhl)) != EOF)
			        putchar(c); //showing the list
			
		            printf("     **************************************************************************************************************************\n"); // spacing design
		        }
		        fclose(fhl); // file closing
				
				printf("\n\n\n\n\t\t\t\t\tEnter code number [Code#]: ");
				scanf("%d", &codenum1);
				
				hlline = hlline + codenum1;
				
				hlline++;
				
				printf("\n");
				printf("\t\t\t\t\tPlease input date [mm dd yyyy]: ");
				scanf("%d %d %d", &rmonth, &rday, &ryear);
			
				fhl = fopen("HistoryLog.txt", "r");
				Temp = fopen("Temp.txt", "w+");
				
				while (!feof(action))
				{
					strcpy(str, "\0");
					fgets(str, MAX, fhl);
					if  (!feof(fhl)) 
					{
						linectr++;
						if (linectr != hlline) 
						{
							fprintf(Temp, "%s", str);
						} 
						else
						{
							fprintf(Temp, "     |    %d    | %-26s|              %-18d| %d/%d/%d-%d/%d/%d |        Returned         |\n", codenum1, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900, rmonth, rday, ryear);
						}
					}
				}
													
				fclose(fhl);
				fclose(Temp);
				remove("HistoryLog.txt");
				rename("Temp.txt", "HistoryLog.txt");
				fclose(fhl);
				fclose(Temp);
				
				break;		
				
			case 'C' : case 'c' : //DRAMA
				system("cls");
				
				do{
					printf("\n\n\n");
					printf("\t\t\t\t\tRETURNING DRAMA MOVIE");
					printf("\n\n");
					printf("\t\t\t\t\tEnter rent ID(To Return): ");
					scanf("%d", &i);
					
					switch(i){
					case 1:
						linectr = 0;
						ds1++;	
								
						drama = fopen("Drama.txt", "r");
						if (!drama) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 3;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(drama))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, drama);
						    if  (!feof(drama)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 1          |  Moonlight 1            | Drama             | 2016       | P120.00       | %d       |\n", ds1);
						        }
						    }
						}
							
						fclose(drama);
						fclose(temp);
						remove("Drama.txt");
						rename("temp.txt", "Drama.txt");
						fclose(drama);
						fclose(temp);
					
						break;
					case 2:	
						linectr = 0;
						ds2++;		
								
						drama = fopen("Drama.txt", "r");
						if (!drama) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 4;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(drama))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, drama);
						    if  (!feof(drama)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 2          |  Shattered Glass        | Drama             | 2003       | P108.00       | %d       |\n", ds2);
						        }
						    }
						}
						
						fclose(drama);
						fclose(temp);
						remove("Drama.txt");
						rename("temp.txt", "Drama.txt");
						fclose(drama);
						fclose(temp);
						
						break;
					case 3:
						linectr = 0;	
						ds3++;	
								
						drama = fopen("Drama.txt", "r");
						if (!drama) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 5;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(drama))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, drama);
						    if  (!feof(drama)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 3          |  365 Days               | Drama             | 2020       | P120.00       | %d       |\n", ds3);
						        }
						    }
						}
						
						fclose(drama);
						fclose(temp);
						remove("Drama.txt");
						rename("temp.txt", "Drama.txt");
						fclose(drama);
						fclose(temp);
						
						break;
					case 4:
						linectr = 0;
						ds4++;		
								
						drama = fopen("Drama.txt", "r");
						if (!drama) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 6;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(drama))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, drama);
						    if  (!feof(drama)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 4          |  Chemical Hearts        | Drama             | 2020       | P120.00       | %d       |\n", ds4);
						        }
						    }
						}
						
						fclose(drama);
						fclose(temp);
						remove("Drama.txt");
						rename("temp.txt", "Drama.txt");
						fclose(drama);
						fclose(temp);
						
						break;
					case 5:
						linectr = 0;
						ds5++;		
								
						drama = fopen("Drama.txt", "r");
						if (!drama) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 7;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(drama))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, drama);
						    if  (!feof(drama)) 
							{
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 5          |  Spotlight              | Drama             | 2015       | P120.00       | %d       |\n", ds5);
						        }
						    }
						}
						
						fclose(drama);
						fclose(temp);
						remove("Drama.txt");
						rename("temp.txt", "Drama.txt");
						fclose(drama);
						fclose(temp);
		
						break;	
				}		
					    printf("\n\n\n\t\t\t\t\tIs there other more to return [Y/N]?");
						retConfirm = getch();
						
						while(retConfirm != 'y' && retConfirm != 'Y' && retConfirm != 'n' && retConfirm != 'N'){
							retConfirm = getch();
						}
						
						i++;
				}while(retConfirm == 'y' || retConfirm == 'Y');		
				
				linectr = 0;			
				
				system("cls");
				

    

    	    	fhl = fopen("HistoryLog.txt", "r");
    	    	
    	    	if(fhl != NULL) 
		        {							
		        	printf("\n\n\n");	
	
			        while ( (c = fgetc(fhl)) != EOF)
			        putchar(c); //showing the list
			
		            printf("     **************************************************************************************************************************\n"); // spacing design
		        }
		        fclose(fhl); // file closing

				
				printf("\n\n\n\n\t\t\t\t\tEnter code number [Code#]: ");
				scanf("%d", &codenum1);
				
				hlline = hlline + codenum1;
				
				hlline++;
				
				printf("\n");
				printf("\t\t\t\t\tPlease input date [mm dd yyyy]: ");
				scanf("%d %d %d", &rmonth, &rday, &ryear);
			
				fhl = fopen("HistoryLog.txt", "r");
				Temp = fopen("Temp.txt", "w+");
				
				while (!feof(action))
				{
					strcpy(str, "\0");
					fgets(str, MAX, fhl);
					if  (!feof(fhl)) 
					{
						linectr++;
						if (linectr != hlline) 
						{
							fprintf(Temp, "%s", str);
						} 
						else
						{
							fprintf(Temp, "     |    %d    | %-26s|              %-18d| %d/%d/%d-%d/%d/%d |        Returned         |\n", codenum1, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900, rmonth, rday, ryear);
						}
					}
				}
													
				fclose(fhl);
				fclose(Temp);
				remove("HistoryLog.txt");
				rename("Temp.txt", "HistoryLog.txt");
				fclose(fhl);
				fclose(Temp);
				
				break;
						
			case 'D' : case 'd' : //SCI-FI
				do{
					printf("\n\n\n");
					printf("\t\t\t\t\tRETURNING SCI-FI MOVIE");
					printf("\n\n");
					printf("\t\t\t\t\tEnter rent ID(To Return): ");
					scanf("%d", &i);
					
					switch(i){
					case 1:
						
						linectr = 0;
						
						sfs1++;		
								
						scifi = fopen("Sci-Fi.txt", "r");
						if (!scifi) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 3;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(scifi))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, scifi);
						    if  (!feof(scifi)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 1          |  Star Wars              | Sci-Fi            | 1977       | P108.00       | %d       |\n", sfs1);
						        }
						    }
						}
							
						fclose(scifi);
						fclose(temp);
						remove("Sci-Fi.txt");
						rename("temp.txt", "Sci-Fi.txt");
						fclose(scifi);
						fclose(temp);
						
						break;
					case 2:
						linectr = 0;
						sfs2++;	
								
						scifi = fopen("Sci-Fi.txt", "r");
						if (!scifi) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 4;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(scifi))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, scifi);
						    if  (!feof(scifi)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 2          |  Jurassic Park          | Sci-Fi            | 1993       | P108.00       | %d       |\n", sfs2);
						        }
						    }
						}
						
						fclose(scifi);
						fclose(temp);
						remove("Sci-Fi.txt");
						rename("temp.txt", "Sci-Fi.txt");
						fclose(scifi);
						fclose(temp);
						
						break;
					case 3:	
						linectr = 0;
						sfs3++;	
								
						scifi = fopen("Sci-Fi.txt", "r");
						if (!scifi) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 5;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(scifi))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, scifi);
						    if  (!feof(scifi)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 3          |  The Hunger Games       | Sci-Fi            | 2012       | P120.00       | %d       |\n", sfs3);
						        }
						    }
						}
						
						fclose(scifi);
						fclose(temp);
						remove("Sci-Fi.txt");
						rename("temp.txt", "Sci-Fi.txt");
						fclose(scifi);
						fclose(temp);
						
						break;
					case 4:
						linectr = 0;
						sfs4++;		
								
						scifi = fopen("Sci-Fi.txt", "r");
						if (!scifi) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 6;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(scifi))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, scifi);
						    if  (!feof(scifi)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 4          |  Black Adam             | Sci-Fi            | 2022       | P120.00       | %d       |\n", sfs4);
						        }
						    }
						}
						
						fclose(scifi);
						fclose(temp);
						remove("Sci-Fi.txt");
						rename("temp.txt", "Sci-Fi.txt");
						fclose(scifi);
						fclose(temp);
						
						break;
					case 5:
						linectr = 0;
						sfs5++;		
								
						scifi = fopen("Sci-Fi.txt", "r");
						if (!scifi) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 7;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(scifi))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, scifi);
						    if  (!feof(scifi)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 5          |  Stowaway               | Sci-Fi            | 2020       | P120.00       | %d       |\n", sfs5);
						        }
						    }
						}
						
						fclose(scifi);
						fclose(temp);
						remove("Sci-Fi.txt");
						rename("temp.txt", "Sci-Fi.txt");
						fclose(scifi);
						fclose(temp);
						
						break;	
				}
					    printf("\n\n\n\t\t\t\t\tIs there other more to return [Y/N]?");
						retConfirm = getch();
						
						while(retConfirm != 'y' && retConfirm != 'Y' && retConfirm != 'n' && retConfirm != 'N'){
							retConfirm = getch();
						}
						
						i++;
				}while(retConfirm == 'y' || retConfirm == 'Y');	
				
				linectr = 0;
				
				system("cls");

    

    	    	fhl = fopen("HistoryLog.txt", "r");
    	    	
    	    	if(fhl != NULL) 
		        {							
		        	printf("\n\n\n");	
	
			        while ( (c = fgetc(fhl)) != EOF)
			        putchar(c); //showing the list
			
		            printf("     **************************************************************************************************************************\n"); // spacing design
		        }
		        fclose(fhl); // file closing
				
				printf("\n\n\n\n\t\t\t\t\tEnter code number [Code#]: ");
				scanf("%d", &codenum1);
				
				hlline = hlline + codenum1;
				
				hlline++;
				
				printf("\n");
				printf("\t\t\t\t\tPlease input date [mm dd yyyy]: ");
				scanf("%d %d %d", &rmonth, &rday, &ryear);
				
				fhl = fopen("HistoryLog.txt", "r");
				Temp = fopen("Temp.txt", "w+");
				
				while (!feof(action))
				{
					strcpy(str, "\0");
					fgets(str, MAX, fhl);
					if  (!feof(fhl)) 
					{
						linectr++;
						if (linectr != hlline) 
						{
							fprintf(Temp, "%s", str);
						} 
						else
						{
							fprintf(Temp, "     |    %d    | %-26s|              %-18d| %d/%d/%d-%d/%d/%d |        Returned         |\n", codenum1, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900, rmonth, rday, ryear);
						}
					}
				}
													
				fclose(fhl);
				fclose(Temp);
				remove("HistoryLog.txt");
				rename("Temp.txt", "HistoryLog.txt");
				fclose(fhl);
				fclose(Temp);
						
				break;
						
			case 'E' : case 'e' : //ADVENTURE
				system("cls");
						
				do{
					printf("\n\n\n");
					printf("\t\t\t\t\tRETURNING ADVENTURE MOVIE");
					printf("\n\n");
					printf("\t\t\t\t\tEnter rent ID(To Return): ");
					scanf("%d", &i);
					
					switch(i){
					case 1:
						linectr = 0;
						ads1++;	
								
						adventure = fopen("Adventure.txt", "r");
						if (!adventure) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 3;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(adventure))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, adventure);
						    if  (!feof(adventure)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 1          |  Lord of the Rings      | Adventure         | 2001       | P108.00       | %d       |\n", ads1);
						        }
						    }
						}
						
						fclose(adventure);
						fclose(temp);
						remove("Adventure.txt");
						rename("temp.txt", "Adventure.txt");
						fclose(adventure);
						fclose(temp);
						
						break;
					case 2:	
						linectr = 0;
						ads2++;	
								
						adventure = fopen("Adventure.txt", "r");
						if (!adventure) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 4;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(adventure))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, adventure);
						    if  (!feof(adventure)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 2          |  The Santa Clause       | Adventure         | 2020       | P120.00       | %d       |\n", ads2);
						        }
						    }
						}
						
						fclose(adventure);
						fclose(temp);
						remove("Adventure.txt");
						rename("temp.txt", "Adventure.txt");
						fclose(adventure);
						fclose(temp);
						
						break;
					case 3:	
						linectr = 0;
						ads3++;	
								
						adventure = fopen("Adventure.txt", "r");
						if (!adventure) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 5;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(adventure))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, adventure);
						    if  (!feof(adventure)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 3          |  Avatar                 | Adventure         | 2009       | P108.00       | %d       |\n", ads3);
						        }
						    }
						}
						
						fclose(adventure);
						fclose(temp);
						remove("Adventure.txt");
						rename("temp.txt", "Adventure.txt");
						fclose(adventure);
						fclose(temp);
						
						break;
					case 4:
						linectr = 0;
						ads4++;	
								
						adventure = fopen("Adventure.txt", "r");
						if (!adventure) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 6;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(adventure))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, adventure);
						    if  (!feof(adventure)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 4          |  Brave                  | Adventure         | 2011       | P120.00       | %d       |\n", ads4);
						        }
						    }
						}
						
						fclose(adventure);
						fclose(temp);
						remove("Adventure.txt");
						rename("temp.txt", "Adventure.txt");
						fclose(adventure);
						fclose(temp);
						
						break;
					case 5:
						linectr = 0;
						ads5++;	
								
						adventure = fopen("Adventure.txt", "r");
						if (!adventure) 
						{
						    printf("Unable to open the input file!!\n");
						}
						temp = fopen("temp.txt", "w+");
						/* get the new line from the user *
						/* get the line number to delete the specific line */
						lno = 7;
						lno++;
						// copy all contents to the temporary file other except specific line
						while (!feof(adventure))
						{
						    strcpy(str, "\0");
						    fgets(str, MAX, adventure);
						    if  (!feof(adventure)) 
						    {
						        linectr++;
						        if (linectr != lno) 
						        {
						            fprintf(temp, "%s", str);
						        } 
						        else
						        {
						            fprintf(temp, "               | 5          |  Greyhound              | Adventure         | 2020       | P120.00       | %d       |\n", ads5);
						        }
						    }
						}
						
						fclose(adventure);
						fclose(temp);
						remove("Adventure.txt");
						rename("temp.txt", "Adventure.txt");
						fclose(adventure);
						fclose(temp);
						
						break;	
				}		
				        printf("\n\n\n\t\t\t\t\tIs there other more to return [Y/N]?");
						retConfirm = getch();
						
						while(retConfirm != 'y' && retConfirm != 'Y' && retConfirm != 'n' && retConfirm != 'N'){
							retConfirm = getch();
						}
					
					i++;	
				}while(retConfirm == 'y' || retConfirm == 'Y');	
				
				linectr = 0;
				
				system("cls");
				

    

    	    	fhl = fopen("HistoryLog.txt", "r");
    	    	
    	    	if(fhl != NULL) 
		        {							
		        	printf("\n\n\n");	
	
			        while ( (c = fgetc(fhl)) != EOF)
			        putchar(c); //showing the list
			
		            printf("     **************************************************************************************************************************\n"); // spacing design
		        }
		        fclose(fhl); // file closing
				
				printf("\n\n\n\n\t\t\t\t\tEnter code number [Code#]: ");
				scanf("%d", &codenum1);
				
				hlline = hlline + codenum1;
				
				hlline++;
				
				printf("\n");
				printf("\t\t\t\t\tPlease input date [mm dd yyyy]: ");
				scanf("%d %d %d", &rmonth, &rday, &ryear);
				
				fhl = fopen("HistoryLog.txt", "r");
				Temp = fopen("Temp.txt", "w+");
				
				while (!feof(action))
				{
					strcpy(str, "\0");
					fgets(str, MAX, fhl);
					if  (!feof(fhl)) 
					{
						linectr++;
						if (linectr != hlline) 
						{
							fprintf(Temp, "%s", str);
						} 
						else
						{
							fprintf(Temp, "     |    %d    | %-26s|              %-18d| %d/%d/%d-%d/%d/%d |        Returned         |\n", codenum1, CusName1[d], orderCount, tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900, rmonth, rday, ryear);
						}
					}
				}
													
				fclose(fhl);
				fclose(Temp);
				remove("HistoryLog.txt");
				rename("Temp.txt", "HistoryLog.txt");
				fclose(fhl);
				fclose(Temp);
				
				break;	
					
			case 'G' : case 'g' : //GO BACK TO RENT TAB
				system("cls");
				RentTab();
				break;	
		}
	}
	

void HistoryLog()
{
    char hlog, c;
    
	FILE* fhl;
	

    	    	system("cls");
    	    	gotoxy(40, 3);printf(" _________________________________________");
			    gotoxy(40, 4);printf("|                                         |");
			    gotoxy(40, 5);printf("|               HISTORY LOG               |");
			    gotoxy(40, 6);printf("|_________________________________________|");
    	    	
    	    	fhl = fopen("HistoryLog.txt", "r");
    	    	
    	    	if(fhl != NULL) 
		        {							
		        	printf("\n\n\n");	
	
			        while ( (c = fgetc(fhl)) != EOF)
			        putchar(c); //showing the list
			
		            printf("     **************************************************************************************************************************\n"); // spacing design
		        }
		        fclose(fhl); // file closing
		        
		        printf("\n\t\t\t\t\t\tPress [ENTER] to go back to menu.");
			
		        getch();
			    system("cls");
				AdminAccountTab(); 	

    
}

void AdminAccountTab() // admin menu
{
	
	FILE * action; 
    FILE * horror;
	FILE * drama;
	FILE * scifi;
	FILE * adventure; // opening single receipt fID
	
	system("cls");	
	char MenuChoices, c; // For Navigation of choices
	char sGenre[100];
	
    gotoxy(40, 3);printf(" _________________________________________");
    gotoxy(40, 4);printf("|                                         |");
    gotoxy(40, 5);printf("|           Y.M.W.S Video Rental          |");
    gotoxy(40, 6);printf("|_________________________________________|\n\n\n\n");
    
    gotoxy(46, 9);printf("1. Rent a Movie");
    gotoxy(46, 11);printf("2. View Movie");
    gotoxy(46, 13);printf("3. Add Movie");
	gotoxy(46, 15);printf("4. Search Movie");
	gotoxy(46, 17);printf("5. History Log");
	gotoxy(46, 19);printf("6. Log Out");
    gotoxy(46, 21);printf("7. Exit");
	
	
	gotoxy(40, 24); printf(" Enter your choice : ");
	MenuChoices = getch();
	
	while (MenuChoices != '1' && MenuChoices != '2' && MenuChoices != '3' && MenuChoices != '4' && MenuChoices != '5' && MenuChoices != '6' && MenuChoices != '7' )  // 1,2, 3, 4,5 and 6 keys will only be accepted
	{
	MenuChoices = getch();
    }
	
	switch (MenuChoices)
	{
			case '1':
				system("cls");
				RentTab();
				break;
			case '2': 
			    system("cls");
                ViewMovieList();
				break;
			case '3' : 
                system("cls");
        		AddMovie();
				break;	
		    case '4' : 
		       	system("cls");
		       	
		       	gotoxy(40, 3); printf("============================================");
                gotoxy(40, 4); printf("||                                        ||");
                gotoxy(40, 5); printf("||               MOVIE GENRE'S            ||");
                gotoxy(40, 6); printf("||                                        ||");
                gotoxy(40, 7); printf("============================================");
                gotoxy(40, 8); printf("||                                        ||");
                gotoxy(40, 9); printf("||       Action                           ||");
                gotoxy(40, 10);printf("||       Horror                           ||");
			    gotoxy(40, 11);printf("||       Drama                            ||");
                gotoxy(40, 12);printf("||       Sci-Fi                           ||");
                gotoxy(40, 13);printf("||       Adventure                        ||"); 
				gotoxy(40, 14);printf("||                                        ||");    
			    gotoxy(40, 15);printf("============================================");  
		       	
		       
		        printf("\n\n\n\n\n\n\n\t\t\t\tEnter [MOVIE GENRE] to check availability: "); // Searching for movie
				scanf("%s", sGenre); //scanning
				
				system("cls");
				
				while ((strcmp(sGenre, "Action") != 0) && (strcmp(sGenre, "Horror") != 0) && (strcmp(sGenre, "Drama") != 0) && (strcmp(sGenre, "Sci-Fi") != 0) && (strcmp(sGenre, "Adventure") != 0)){
					system("cls");
					printf("\n\n\n\n\n\n\n\t\t\t\t\t\tError!!! ");
					getch();
					
					system("cls");
					AdminAccountTab();
				}
			
				if (strcmp(sGenre, "Action") == 0){
					
					strcat(sGenre, ".txt"); // converting name entered to text file
					
					action = fopen(sGenre, "r"); // read mode
					
					if(action != NULL) 
		            {
		            gotoxy(40, 3); printf("============================================");
                    gotoxy(40, 4); printf("||                                        ||");
                    gotoxy(40, 5); printf("||              ACTION MOVIES             ||");
                    gotoxy(40, 6); printf("||                                        ||");
                    gotoxy(40, 7); printf("============================================");
							
		            printf("\n\n\n");	
	
			        while ( (c = fgetc(action)) != EOF)
			        putchar(c); //showing the list
			
		            printf("               ***************************************************************************************************\n"); // spacing design
			        fclose(action); // file closing
		            }
		            
		            getch();
				
					printf("\n\n\n");
					printf("\t\t\t\t\tPress any key to go back to Menu...");
		
					getch();
					
					
				} else if(strcmp(sGenre, "Horror") == 0){
					
					strcat(sGenre, ".txt"); // converting name entered to text file
					
					horror = fopen("Horror.txt", "r");
		
		            if(horror != NULL) 
		            {
		            gotoxy(40, 3); printf("============================================");
                    gotoxy(40, 4); printf("||                                        ||");
                    gotoxy(40, 5); printf("||              HORROR MOVIES             ||");
                    gotoxy(40, 6); printf("||                                        ||");
                    gotoxy(40, 7); printf("============================================");
							
		            printf("\n\n\n");
	
			        while ( (c = fgetc(horror)) != EOF)
			        putchar(c); //showing the list
			
		            printf("               ***************************************************************************************************\n"); // spacing design
			        fclose(horror); // file closing
		            }
		            
		            getch();
				
					printf("\n\n\n");
					printf("\t\t\t\t\tPress any key to go back to Menu...");
		
					getch();
					
				}else if(strcmp(sGenre, "Drama") == 0){
					
					strcat(sGenre, ".txt"); // converting name entered to text file
					
					drama = fopen("Drama.txt", "r");
		
		            if(drama != NULL) 
		            {
		            gotoxy(40, 3); printf("============================================");
                    gotoxy(40, 4); printf("||                                        ||");
                    gotoxy(40, 5); printf("||              DRAMA MOVIES              ||");
                    gotoxy(40, 6); printf("||                                        ||");
                    gotoxy(40, 7); printf("============================================");
							
		            printf("\n\n\n");
	
			        while ( (c = fgetc(drama)) != EOF)
			        putchar(c); //showing the list
			
					printf("               ***************************************************************************************************\n"); // spacing design			            
					fclose(drama); // file closing
		            }
		            
		            getch();
				
					printf("\n\n\n");
					printf("\t\t\t\t\tPress any key to go back to Menu...");
		
					getch();
		            
				}else if(strcmp(sGenre, "Sci-Fi") == 0){
					
					strcat(sGenre, ".txt"); // converting name entered to text file
					
					scifi = fopen("Sci-Fi.txt", "r");
		
		            if(scifi != NULL) 
		            {
		            gotoxy(40, 3); printf("============================================");
                    gotoxy(40, 4); printf("||                                        ||");
                    gotoxy(40, 5); printf("||              SCI-FI MOVIES             ||");
                    gotoxy(40, 6); printf("||                                        ||");
                    gotoxy(40, 7); printf("============================================");
							
		            printf("\n\n\n");
	
			        while ( (c = fgetc(scifi)) != EOF)
			        putchar(c); //showing the list
			
					printf("               ***************************************************************************************************\n"); // spacing design							            
					fclose(scifi); // file closing
		            }
		            
		            getch();
				
					printf("\n\n\n");
					printf("\t\t\t\t\tPress any key to go back to Menu...");
		
					getch();
		            
				}else if(strcmp(sGenre, "Adventure") == 0){
					
					strcat(sGenre, ".txt"); // converting name entered to text file
					
					adventure = fopen("Adventure.txt", "r");
		
		            if(adventure != NULL) 
		            {
		            gotoxy(40, 3); printf("============================================");
                    gotoxy(40, 4); printf("||                                        ||");
                    gotoxy(40, 5); printf("||           ADVENTURE MOVIES             ||");
                    gotoxy(40, 6); printf("||                                        ||");
                    gotoxy(40, 7); printf("============================================");
							
		            printf("\n\n\n");
	
			        while ( (c = fgetc(adventure)) != EOF)
			        putchar(c); //showing the list
			
					printf("               ***************************************************************************************************\n"); // spacing design			    
					fclose(adventure); // file closing
		            }
		            
		            getch();
				
					printf("\n\n\n");
					printf("\t\t\t\t\tPress any key to go back to Menu...");
		
					getch();
					
				}
	
				system("cls");
				AdminAccountTab();

			   break;	
			case '5': 
				system("cls");
                HistoryLog();
				break;
            case '6':
                system("cls");
                Login();
                break;
            case '7':
            	system("cls");
                gotoxy(40, 1);printf("S Y S T E M  C L O S I N G  N O W");
                
                gotoxy(45, 6);printf("Press any key to close...");
                exit(0);
                break;
        break;
    }
}

void ViewMovieList() // View movie list for Admin Account
{
	system("cls");
	char genre,c ;
				
				gotoxy(40, 3); printf("============================================");
                gotoxy(40, 4); printf("||                                        ||");
                gotoxy(40, 5); printf("||               MOVIE GENRE'S            ||");
                gotoxy(40, 6); printf("||                                        ||");
                gotoxy(40, 7); printf("============================================");
                gotoxy(40, 8); printf("||                                        ||");
                gotoxy(40, 9); printf("||       [A] Action                       ||");
                gotoxy(40, 10);printf("||       [B] Horror                       ||");
			    gotoxy(40, 11);printf("||       [C] Drama                        ||");
                gotoxy(40, 12);printf("||       [D] Sci-Fi                       ||");
                gotoxy(40, 13);printf("||       [E] Adventure                    ||"); 
				gotoxy(40, 14);printf("||                                        ||");    
			    gotoxy(40, 15);printf("============================================");              
				gotoxy(71, 16); printf("[G] Go Back");
				
				gotoxy(41, 19); printf(" Select MOVIE GENRE'S to view the list: ");
	            genre = getch();
	            
				while ( genre != 'A' && genre != 'a' && genre != 'B' && genre != 'b' && genre != 'C' && genre != 'c' && genre != 'D' && genre != 'd' && genre != 'E' && genre != 'e' && genre != 'G' && genre != 'g')
	            {
                genre = getch();
                }
                
                //FILE pointer for every genres
				FILE * action; 
				FILE * horror;
				FILE * drama;
				FILE * scifi;
				FILE * adventure;
				
				switch(genre)
				{
					case 'A' : case 'a' : //ACTION
						system("cls");
		                action = fopen("Action.txt", "r");
		
		                if(action != NULL) 
		                {
		                gotoxy(40, 3); printf("============================================");
                        gotoxy(40, 4); printf("||                                        ||");
                        gotoxy(40, 5); printf("||              ACTION MOVIES             ||");
                        gotoxy(40, 6); printf("||                                        ||");
                        gotoxy(40, 7); printf("============================================");
							
		                printf("\n\n\n");	
	
			            while ( (c = fgetc(action)) != EOF)
			            putchar(c); //showing the list
			
		                printf("               ***************************************************************************************************\n"); // spacing design
			            fclose(action); // file closing
		                }
		
		
		                printf("\n\t\t\t\t\t\tPress [ENTER] to go back.");
			
		                getch();
			            system("cls");
						ViewMovieList();
						break;
						
				    case 'B' : case 'b' : //HORROR
				    	system("cls");
		                horror = fopen("Horror.txt", "r");
		
		                if(horror != NULL) 
		                {
		                gotoxy(40, 3); printf("============================================");
                        gotoxy(40, 4); printf("||                                        ||");
                        gotoxy(40, 5); printf("||              HORROR MOVIES             ||");
                        gotoxy(40, 6); printf("||                                        ||");
                        gotoxy(40, 7); printf("============================================");
							
		                printf("\n\n\n");
	
			            while ( (c = fgetc(horror)) != EOF)
			            putchar(c); //showing the list
			
		                printf("               ***************************************************************************************************\n"); // spacing design
			            fclose(horror); // file closing
		                }
		
		
		                printf("\n\t\t\t\t\t\tPress [ENTER] to go back.");
			
		                getch();
			            system("cls");
						ViewMovieList();
						break;
						
					case 'C' : case 'c' : //DRAMA
						system("cls");
						drama = fopen("Drama.txt", "r");
		
		                if(drama != NULL) 
		                {
		                gotoxy(40, 3); printf("============================================");
                        gotoxy(40, 4); printf("||                                        ||");
                        gotoxy(40, 5); printf("||              DRAMA MOVIES              ||");
                        gotoxy(40, 6); printf("||                                        ||");
                        gotoxy(40, 7); printf("============================================");
							
		                printf("\n\n\n");
	
			            while ( (c = fgetc(drama)) != EOF)
			            putchar(c); //showing the list
			
						printf("               ***************************************************************************************************\n"); // spacing design			            
						fclose(drama); // file closing
		                }
		
		
		                printf("\n\t\t\t\t\t\tPress [ENTER] to go back.");
			
		                getch();
			            system("cls");
						ViewMovieList();
						break;
						
					case 'D' : case 'd' : //SCI-FI
						system("cls");
						scifi = fopen("Sci-Fi.txt", "r");
		
		                if(scifi != NULL) 
		                {
		                gotoxy(40, 3); printf("============================================");
                        gotoxy(40, 4); printf("||                                        ||");
                        gotoxy(40, 5); printf("||              SCI-FI MOVIES             ||");
                        gotoxy(40, 6); printf("||                                        ||");
                        gotoxy(40, 7); printf("============================================");
							
		                printf("\n\n\n");
	
			            while ( (c = fgetc(scifi)) != EOF)
			            putchar(c); //showing the list
			
						printf("               ***************************************************************************************************\n"); // spacing design							            
						fclose(scifi); // file closing
		                }
		
		
		                printf("\n\t\t\t\t\t\tPress [ENTER] to go back.");
			
		                getch();
			            system("cls");
						ViewMovieList();
						break;
						
					case 'E' : case 'e' : //ADVENTURE
						system("cls");
						adventure = fopen("Adventure.txt", "r");
		
		                if(adventure != NULL) 
		                {
		                gotoxy(40, 3); printf("============================================");
                        gotoxy(40, 4); printf("||                                        ||");
                        gotoxy(40, 5); printf("||           ADVENTURE MOVIES             ||");
                        gotoxy(40, 6); printf("||                                        ||");
                        gotoxy(40, 7); printf("============================================");
							
		                printf("\n\n\n");
	
			            while ( (c = fgetc(adventure)) != EOF)
			            putchar(c); //showing the list
			
						printf("               ***************************************************************************************************\n"); // spacing design			    
						fclose(adventure); // file closing
		                }
		
		
		                printf("\n\t\t\t\t\t\tPress [ENTER] to go back.");
			
		                getch();
			            system("cls");
						ViewMovieList();
						break;		
						
					case 'G' : case 'g' : //GO BACK TO RENT TAB
						system("cls");
						AdminAccountTab();
						break;	
				}
}



int main()
{
	gotoxy(52, 4);printf("W E L C O M E  T O");
    
    gotoxy(40, 5);printf(" _________________________________________");
    gotoxy(40, 6);printf("|                                         |");
    gotoxy(40, 7);printf("|                 Y.M.W.S                 |");
    gotoxy(40, 8);printf("|          (Your Movie, We Share)         |");
    gotoxy(40, 9);printf("|                                         |");
    gotoxy(40, 10);printf("|            VIDEO RENTAL SYSTEM          |");
    gotoxy(40, 11);printf("|_________________________________________|\n\n\n\n\n\n");
    
	
	gotoxy(45, 18);printf("Press any key to continue:");

	getch(); // To get any keyspress to continue to the next tab which is the login
    system("cls");
    Login();
	
	return 0;
    
    
}

