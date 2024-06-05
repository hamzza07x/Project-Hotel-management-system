//header files
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

//user- defined functions prototypes
void registered(void);

void new(void);

void menu(char email[],int pass);

void availability(char email[],int pass);

void reservation(char userEmail[],int pass);
	
void manage(int pass,char email[]);

int  single(int reserved);

int  doubl(int reserved);

int  suite(int reserved);

int  emailcheck(char email[]);

int  randno(void);

int  emailsimilar(char email[]);

int  passsimilar(int pass);

int  getTotalRooms(char roomType[]);

void updatetotalrooms(int roomsleft,char room[]);

void updateuserinfo(int reserve, int pass, char room[], int nights, int price);
 
int  getuserrooms(char room[],int pass);

int  getnights(char roomType[],int password);

int  getprice(char roomType[],int password);

// Main Function
int  main(void)
{
	int choice;
	
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tWelcome to the hotel!\n");
	printf("----------------------------------------------------------------------------------------------------\n\n");
	printf("1.Registered User.\n");
	printf("2.New User.\n");
	printf("3.Exit.\n\n");
	printf("Your choice:");
	
	if (scanf("%d", &choice) == 1)
	{
		printf("\n");
		switch(choice)
		{
			case 1:		registered();	
					break;
				
			case 2:		new();
					break;
				
			case 3:		printf("\nGoodbye, have a nice day!\n");
					return 0;
					break;
				
			default: 	printf("\nInvalide Choice!, Enter again(1-3)\n\n");
				 	main();	
		}
	}
	else
	{
		printf("\n");
		while (getchar() != '\n');
		printf("Invalide Choice!, Use numbers(1-3)\n\n");
		main();
	} 
}

//Already Registered User-Function 
void registered(void)
{
	char email[50];
	int one,choice,random,pass;
	printf("Enter your email (press 1 to go to menu):\n");
	if(scanf("%d",&one) == 1)
	{
		if(one==1)
		{
			main();
		}
		else
		{
			printf("Invalid Cradentials, enter again (1 to go back)\n");
			registered();
			
		}
	}
	else
	{
		fgets(email,sizeof(email),stdin);
		email[strcspn(email, "\n")] = '\0';
		
		if(emailsimilar(email) == 1)
		{

			while(1)
			{
				printf("\nEnter password (press 1 to go back)\n");
				
				if(scanf("%d",&one) == 1)
				{
				
					if(one==1)
					{
						registered();
						break;
					}
					else
					{
						pass=one;
						
						if(passsimilar(pass)==1)
						{
							printf("\nYou're Logged In To Your Account !!!\n\n");
							menu(email,pass);
							break;
						}
						else
						{
							printf("\nInvalide Password!\n");
						}
					}
				}
					
				else
				{
					printf("\n");
					while (getchar() != '\n');
					printf("I\nnvalid Cradentials use numbers!\n\n");
				}
			}
		}
		
		else
		{
			printf("\nInvalid email! Enter again or register\n");
			registered();
		}
	} 
				
}

// Function For New-User
void new(void)
{
	char name[30], email[50];
	int one,choice,random,two;
	FILE *fp;
	FILE *fp2;
	char filename[20]; 
	printf("Enter your name (press 1 to go back to main menu)\n");
	if(scanf("%d",&one) == 1)
	{
		if(one==1)
		{
			main();
		}
		else
		{
			printf("\nInvalid Cradentials, enter again (1 to go back)\n");
			new();
		}
	}
	else
	{
		fgets(name,sizeof(name),stdin); 
		name[strcspn(name, "\n")] = '\0';
	}
	if(one!=1)
	{
		while(1)
		{
			printf("Enter your email (press 1 to go back)\n");
			if(scanf("%d",&two) == 1)
			{
				if(two==1)
				{
					new();
					break;
				}
				else
				{
					printf("Invalid Number, enter again (1 to go back)\n");
				}
			}
			else
			{
				fgets(email,sizeof(email),stdin);
				email[strcspn(email, "\n")] = '\0';
				printf("\n");
				
				if(emailsimilar(email)==1)
				{ 
				
					printf("The email is already registerd use another or login\n\n");
				}
				else if(emailcheck(email))
				{
				
					printf("--Email is accepted--\n\n");
					break;
				}
				else{
					printf("Invalid Email\n\n");
				}
			}
		}
		if(two!=1)
		{
			printf("Please check and confirm:\n");
			printf("Your name is: %s\n",name);
			printf("Your email is: %s\n\n",email);
			
			for(int i=0;;i++)
			{
				printf("1.Confirm\n");
				printf("2.Enter Again\n\n");
				printf("!!!Note once confirmed, your name and email cannot be changed!!!\n\n");
				printf("Your Choice:\n");
				if (scanf("%d", &choice) == 1)
				{
					if(choice==1)
					{
						printf("Generating your password...\n");
						while(1)
						{
							random=randno();
							if(passsimilar(random)==0){
								break;
							}
							else{}
						}
						printf("Your password is %d\n\n",random);//.......................................................................
						printf("!!Remember your password!!\n");
						break;
					}
					else if(choice ==2){
						new();
						break;
					}
					else{
						printf("Invalid Choice\n");
					}
				}	
				else{
					printf("\n");
					while (getchar() != '\n');
					printf("Invalid Choice enter again!, Use numbers(1-2)\n\n");
				}
			}
			
			if(choice!=2)
			{ 
				fp=fopen("customerInfo.txt", "a");                    // file-open
				fprintf(fp,"\nName: %s\nEmail: %s\nPassword: %d\n", name, email, random);
				fclose(fp);                                          //f-close
				sprintf(filename, "%d.txt", random); 
				fp2=fopen(filename,"w");                    //f-open 
				fprintf(fp2,"Rooms Reserved:\nSingle=0 night=0 price=0\nDouble=0 night=0 price=0\nSuite=0 night=0 price=0\n");
				fclose(fp2);                           // file-close
				do
				{
					printf("1.Go to login\n");
					printf("2.Go to main menu\n");
					printf("Your Choice:\n");
					if (scanf("%d", &choice) == 1)
					{
						if(choice==1){
						
							registered();	
							break;
						}
						else if(choice ==2){
							
							main();
							break;
						}
						else{
							
						 	printf("Invalide Choice!, Enter again(1-2)\n\n");	
						}	
					}
					else{
						printf("\n");
						while (getchar() != '\n');
						printf("Invalide Choice!, Use numbers(1-2)\n\n");	
					}
				}
				while(1);
			}
		}
	}	
}
	
void menu(char email[],int pass)
{
	
	int choice;
	printf("\n1.Check Room Availability.\n");
	printf("2.Make Reservations.\n");
	printf("3.Manage Booking.\n");
	printf("4.Log Out.\n\n");
	printf("Your Choice:");
	if (scanf("%d", &choice) == 1)
	{
		switch(choice)
		{
			case 1:		printf("\n");
					availability(email,pass);	
					break;
					
			case 2:		reservation(email,pass);
					break;
					
			case 3:		manage(pass,email);
					break;
			
			case 4:		printf("\n");
					main();
					break;
			
			default: 	printf("\n");
					printf("Invalide Choice!, Enter again(1-4)\n\n");
					menu(email,pass);	
		}
	}
	else
	{	
		printf("\n");
		while (getchar() != '\n');
		printf("Invalide Choice!, Use numbers(1-4)\n\n");
		menu(email,pass);
	}
}

//Room-Availability Function
void availability(char email[],int pass)
{
	int choice;
	char bedroom[3][20]={"Single Bed", "Double Bed", "Suite Bedroom"};
	
	printf("__________________________________________________________________________________________________________\n");
	printf("|\tRoom Type\t|\tMax People\t|\tRooms Available\t \t|   Price(per night)      |\n");
	printf("|\t%s      |   \t  2\t\t|	\t  %d\t	|	 $10  \t          |\n",bedroom[0], getTotalRooms("Single"));
	printf("|\t%s      |   \t  4\t\t|	\t  %d\t        |	 $20    \t  |\n",bedroom[1] , getTotalRooms("Double"));
	printf("|\t%s   |   \t  6\t\t|	\t  %d\t	|        $30  \t  \t  |\n",bedroom[2] ,getTotalRooms("Suite"));
	printf("|_______________________|_______________________|_______________________________|_________________________|\n");
	printf("\n");
	
	printf("1.Make Reservations.\n");
	printf("2.Manage Booking.\n");
	printf("3.Menu.\n\n");
	printf("Your Choice:");
	if (scanf("%d", &choice) == 1)
	{
		switch(choice)
		{
			case 1:		reservation(email,pass);	
					break;
					
			case 2:		manage(pass,email);
					break;
					
			case 3:		printf("\n");
					menu(email,pass);
					break;
			
			default: 	printf("\n");
					printf("Invalide Choice!, Enter again(1-3)\n\n");
					menu(email,pass);	
		}
	}
	else{
		printf("\n");
		
		while (getchar() != '\n');
		printf("Invalide Choice!, Use numbers(1-3)\n\n");
		availability(email,pass);
	}
	
	
}

//Reservation of Room function
void reservation(char userEmail[],int pass)
{
	int choice,choice3,reserve,totalRooms,max,people,nights,price,total,roomsleft;
	char room[30],choice2;
	
	printf("\nSelect room type:\n");
	printf("1.Single\n");
	printf("2.Double\n");
	printf("3.Suite\n");
	printf("4.Back to menu\n");
	printf("Your Choise: ");
	if (scanf("%d", &choice) == 1){
	
		printf("\n");
		switch(choice)
		{
			case 1:		strcpy(room,"Single");
					max=2;
					price=10;
					break;
				
			case 2:		strcpy(room,"Double");
					max=4;
					price=20;
					break;
				
			case 3:		strcpy(room,"Suite");
					max=6;
					price=30;
					break;
					
			case 4:		menu(userEmail,pass);
					break;
				
			default: 	printf("Invalide Choice!, Enter again(1-4)\n\n");
				 	reservation(userEmail,pass);	
		}
	}
	else
	{
		printf("\n");
		while (getchar() != '\n');
		printf("Invalide Choice!, Use numbers(1-3)\n\n");
		main();
	}
	if(choice!=4)
	{
		while(1)
		{
			printf("Your room type is %s\n",room);
			printf("Continue?(y/n):\n");
			scanf(" %c",&choice2);
			if(choice2=='y' || choice2=='Y')
			{
				 totalRooms = getTotalRooms(room);
			    	if (totalRooms > 0)
				{
					while(1)
					{
						printf("\nEnter number of rooms you want to reserve(Available: %d):\n",totalRooms);
						if(scanf("%d",&reserve)==1)
						{
							if(reserve>totalRooms||reserve<=0){
							
								printf("\nInvalid room quantity\n");
							}
							else
							{
								while(1)
								{
									printf("\nEnter the number of people (max allowed: %d):\n",max*reserve);
									if(scanf("%d",&people)==1)
									{
										if(people>max*reserve||people<=0)
										{
											printf("\nInvalid Cradentials!\n");
										}
										else
										{
											while(1)
											{
												printf("\nEnter number of nights \n");
												if(scanf("%d",&nights)==1)
												{
													if(nights<=0)
													{
														printf("\nInvalid Cradentials!\n");
													}
													else
													{
														total=nights*price*reserve;
														printf("\nRoom type:\t\t\t%s\n",room);
														printf("Number of rooms to reserve:\t%d\n",reserve);
														printf("Number of people: \t\t%d\n",people);
														printf("Number of nights: \t\t%d\n",nights);
														printf("Total bill:     \t\t$%d\n\n",total);
														
														if(strcmp(room, "Single") == 0) {
														    roomsleft = single(reserve);
														}
														 else if(strcmp(room, "Double") == 0){
														    roomsleft = doubl(reserve);
														} 
														else{
														    roomsleft = suite(reserve);
														}
															
														while(1)
														{
															printf("1.Confirm\n");
															printf("2.Enter again\n");
															printf("!! Once Confirmed Reservation will be made !!\n");
															printf("Enter your choice:\n");
															if(scanf("%d",&choice3)==1)
															{
																switch(choice3)
																{
																	case 1:
									 				updateuserinfo(reserve,pass,room,nights,total);  
															updatetotalrooms(roomsleft,room);
															printf("\n-----Reservation made successfully-----\n");	
																	menu(userEmail,pass);
																		break;
																	case 2: reservation(userEmail,pass);
																		break;
																}
																break;
															}
															else
															{
																printf("\n");
																while (getchar() != '\n');
																printf("\nInvalide Cradentials!\n\n");
															}
														}
														break;
												
													}
												}
												else
												{
													printf("\n");
													while (getchar() != '\n');
													printf("\nInvalide Cradentials!\n\n");
												}
											}
											break;
										}
										
									}
									else
									{
										printf("\n");
										while (getchar() != '\n');
										printf("\nInvalide Cradentials!\n\n");
									}
								}
								break;
							} 
							
						}	
						else
						{
							printf("\n");
							while (getchar() != '\n');
							printf("\nInvalide Cradentials!\n\n");
						}
					} 	
		    		}
		    		else
		   		{
					printf("S\norry, no rooms vacant for %s type select another type or comback soon.\n", room);
					reservation(userEmail,pass);
					break;
		    		}
		    		break; 
		    	}
			else if(choice2=='n' || choice=='N')
			{
				reservation(userEmail,pass);
				break;
			}
			else
			{
				printf("\nInvalid Choice try again!\n");
			}
		}
	}
}

//Manage-Booking Function
void manage(int pass,char email[])
{
	int choice;
	int single=getuserrooms("Single",pass), doubl=getuserrooms("Double",pass), suite=getuserrooms("Suite",pass);
	char bedroom[3][20]={"Single Bed", "Double Bed", "Suite Bedroom"};

	printf("__________________________________________________________________________________________________________\n");
	printf("|\tRoom Type\t|\tRooms Reserved\t|\t\tNights\t \t|   Price(per night)      |\n");
	printf("|\t%s      |   \t  %d\t\t|\t\t  %d\t\t|\t %d   \t          |\n",bedroom[0], getuserrooms("Single",pass), getnights("Single",pass), getprice("Single",pass));
	printf("|\t%s      |   \t  %d\t\t|\t\t  %d\t        |\t  %d    \t\t  |\n",bedroom[1] , getuserrooms("Double",pass), getnights("Double",pass), getprice("Double",pass));
	printf("|\t%s   |   \t  %d\t\t|	\t  %d\t\t|         %d  \t  \t  |\n",bedroom[2] , getuserrooms("Suite",pass), getnights("Suite",pass), getprice("Suite",pass));
	printf("|_______________________|_______________________|_______________________________|_________________________|\n");
	
	
	
	printf("\n1.Make Another Reservation.\n");
	printf("2.Menu.\n");
	printf("Your Choice:");
	if (scanf("%d", &choice) == 1)
	{
		switch(choice)
		{
			case 1:		reservation(email,pass);	
					break;
					
			case 2:		printf("\n");
					menu(email,pass);
					break;
			
			default: 	printf("\n");
					printf("Invalide Choice!, Enter again(1-2)\n\n");
					manage(pass,email);	
		}
	}
	else
	{	
		printf("\n");
		while (getchar() != '\n');
		printf("Invalide Choice!, Use numbers(1-2)\n\n");
		availability(email,pass);
	}
}
int single(int reserved)
{
	int totalrooms= getTotalRooms("Single");
	return totalrooms-reserved; 
}
int doubl(int reserved)
{
	int totalrooms= getTotalRooms("Double");
	return totalrooms-reserved; 
}
int suite(int reserved)
{
	int totalrooms= getTotalRooms("Suite");
	return totalrooms-reserved; 
}
int randno(void)
{
	sleep(2);
	int num;
	srand(time(NULL));
	num=rand()%10000;
	if(num<1000)
	{
    		num=num+1000;
    	}
	return num;
}

//This functions takes the email entered by the user and checks if it has the following domains.
int emailcheck(char email[]) 
{
	char *domains[] = {"@gmail.com", "@hotmail.com", "@yahoo.com"};               
    	int numDomains = sizeof(domains) / sizeof(domains[0]),length;                       
    	length = strlen(email);

    	for (int i = 0; i < numDomains; ++i) 
    	{
        	char *include = strstr(email, domains[i]);

        	if (include != NULL && include == email + length - strlen(domains[i]))             
        	{
           		return 1; 
        	}
    	}

    	return 0;  
}

//This function takes the email written for log in and checks if it is present in the customer file.
int emailsimilar(char email[]) 
{
	FILE *fp = fopen("customerInfo.txt", "r");

    	char line[100];  
    	while (fgets(line, sizeof(line), fp) != NULL) 
    	{
        	char *emailInFile = strstr(line, "Email:");
        	if (emailInFile != NULL) 
        	{
            		emailInFile += strlen("Email: ");
            		emailInFile[strcspn(emailInFile, "\n")] = '\0';  

            		if (strcmp(emailInFile, email) == 0) 
            		{
                		fclose(fp);
                		return 1;  
            		}
        	}
    	}

    	fclose(fp);
    	
    return 0;  
}

//This function checks if the password entered for login or the generated password is found in the file or not.
int passsimilar(int pass)
{
	int passInFileInt;
	char line[100];
	FILE *fp = fopen("customerInfo.txt", "r");

	line[100];  
	while (fgets(line, sizeof(line), fp) != NULL) 
	{
		char *passInFile = strstr(line, "Password:");
        	if (passInFile != NULL) 
        	{
            		passInFile += strlen("Password: ");                       
            		passInFileInt = atoi(passInFile);

            		if (passInFileInt == pass) 
            		{
                		fclose(fp);
                		return 1; 
             		}
       	 	}
    	}

	fclose(fp);
    	return 0;  
}

//This fuction returns the total room value for the room type passed as parameter.
int getTotalRooms(char roomType[]) 
{
	FILE *fp = fopen("customerInfo.txt", "r");

	char line[100];  
	int totalRooms = 0;

	while (fgets(line, sizeof(line), fp) != NULL) 
   	{
        	char *typeInFile = strstr(line, roomType);
        	
        	if (typeInFile != NULL) 
        	{
            		typeInFile += strlen(roomType) + 1;  
            		totalRooms = atoi(typeInFile);
            		break;
        	}
    	}

	fclose(fp);
    	return totalRooms;
}

//This function updates the total rooms for the room type that has passed as parameter after user has reserved specific rooms for that type.
void updatetotalrooms(int roomsleft,char room[]) {
	FILE *fp = fopen("customerInfo.txt", "r");
    	FILE *tempFp = fopen("tempFile.txt", "w");

    	char line[100];

    	while (fgets(line, sizeof(line), fp) != NULL) 
    	{
        	char *typeInFile = strstr(line, room);
        	if (typeInFile != NULL) 
        	{
            		fprintf(tempFp, "%s=%d\n", room, roomsleft);
        	} 
        	else 
        	{
            		fputs(line, tempFp);
        	}
    	}

    	fclose(fp);
    	fclose(tempFp);

    	remove("customerInfo.txt");
    	rename("tempFile.txt", "customerInfo.txt");
}

//This function updates the user info about his quantity reserved and total nights and price in his file based on the suitable parameters.
void updateuserinfo(int reserve, int pass, char room[], int nights, int price) 
{
	char filename[100];
	int single, doubleRooms, suite, singleNight, doubleNight, suiteNight, singlePrice, doublePrice, suitePrice;
    	sprintf(filename, "%d.txt", pass);

    	FILE *file = fopen(filename, "r+");
    	if (file == NULL) 
    	{
        	printf("Error opening the file.\n");
        	return;
	}
	
    	fscanf(file, "Rooms Reserved:\nSingle=%d night=%d price=%d\nDouble=%d night=%d price=%d\nSuite=%d night=%d price=%d",
        &single, &singleNight, &singlePrice, &doubleRooms, &doubleNight, &doublePrice, &suite, &suiteNight, &suitePrice);

    	if (strcmp(room, "Single") == 0)
    	{
        	single += reserve;
        	singleNight += nights;
        	singlePrice += price;
    	} 
    	else if (strcmp(room, "Double") == 0) 
    	{
        	doubleRooms += reserve;
        	doubleNight += nights;
        	doublePrice += price;
    	} 
    	else if (strcmp(room, "Suite") == 0) 
    	{
        	suite += reserve;
        	suiteNight += nights;
        	suitePrice += price;
    	} 
    	else 
    	{
        	printf("Invalid room type.\n");
        	fclose(file);
        	return;
    	}
    	
    	fseek(file, 0, SEEK_SET);

    	fprintf(file, "Rooms Reserved:\nSingle=%d night=%d price=%d\nDouble=%d night=%d price=%d\nSuite=%d night=%d price=%d",
        single, singleNight, singlePrice, doubleRooms, doubleNight, doublePrice, suite, suiteNight, suitePrice);

    	fclose(file);
}

//This function gets the user reserved rooms for specific type.
int getuserrooms(char room[],int pass)
{
	char filename[100],line[100]; 
	int totalRooms = 0;
    	sprintf(filename, "%d.txt", pass); 	
    
    	FILE *fp = fopen(filename, "r");

    	while (fgets(line, sizeof(line), fp) != NULL) 
    	{
        	char *typeInFile = strstr(line, room);
        	if (typeInFile != NULL) 
        	{
            		typeInFile += strlen(room) + 1;  
            		totalRooms = atoi(typeInFile);
            		break;
        	}
    	}

    	fclose(fp);
    	return totalRooms;
}

//This function gets the user nights selected for specific room type.
int getnights(char roomType[], int password)
{
	char filename[100], *typeInFile, line[100];  
    	int nights = 0, reservedNights;
   
    	sprintf(filename, "%d.txt", password);

    	FILE *fp = fopen(filename, "r");
   
    	if (fp == NULL) 
    	{
        	perror("Error opening file");
        	exit(EXIT_FAILURE);
    	}

    	while (fgets(line, sizeof(line), fp) != NULL) 
    	{
        	char *typeInFile = strstr(line, roomType);
        	if (typeInFile != NULL) 
        	{
            	typeInFile += strlen(roomType) + 1;  
            
            	sscanf(typeInFile, "%*d night=%d", &reservedNights);
            	nights = reservedNights;
            	break;
        	}
   	}

    	fclose(fp);
    	return nights;
}

//This function gets the total price for each room type which was calculated according to the rooms reserved and the nights.
int getprice(char roomType[], int password) 
{
	char filename[100],line[100];
	int reservedPrice,price = 0;
	sprintf(filename, "%d.txt", password);

    	FILE *fp = fopen(filename, "r");

    	while (fgets(line, sizeof(line), fp) != NULL) 
    	{
        	char *typeInFile = strstr(line, roomType);
        	if (typeInFile != NULL) 
        	{
            		typeInFile += strlen(roomType) + 1;  
            		sscanf(typeInFile, "%*d night=%*d price=%d", &reservedPrice);
            		price = reservedPrice;
            		break;
        	}
    	}

    	fclose(fp);
    	return price;
}
