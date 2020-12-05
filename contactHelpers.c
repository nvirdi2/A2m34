//==============================================
// Name:           Navdeep Virdi
// Student Number: 166485193
// Email:          nvirdi2@myseneca.ca
// Section:        NAA
// Date:           Dec 4th, 2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5
#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)     //Fuction called clearKeyboard
{
    while (getchar() != '\n');      
}




// pause function definition goes here:
void pause(void)           //Fuction called pause 
{
    printf("(Press Enter to Continue)");    
    clearKeyboard();
}




// getInt function definition goes here:
int getInt(void)                //Fuction called getInt
{
    int valid;
    char lookover = 'x';

    scanf("%d%c", &valid, &lookover);

    	while (lookover != '\n') 
		{
       		clearKeyboard();
        	printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        	scanf("%d%c", &valid, &lookover);
    	}
    return valid;
}




// getIntInRange function definition goes here:
int getIntInRange(int min, int max)          //Fuction called getIntInRange with a integer called min and max 
{
    int getIntInRange = getInt();

    	while (getIntInRange < min || getIntInRange > max ) 
		{
        	printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        	getIntInRange = getInt();
    	}
    return getIntInRange; 
}




// yes function definition goes here:
int yes(void)        //Fuction called yes 
{
	char valid = 'x';
	char lookover = 'x';
	int invalid = -1;


	scanf(" %c%c", &valid, &lookover);


	while (!((lookover == '\n') && ((valid == 'Y') || (valid == 'y') || (valid == 'n') || (valid== 'N'))))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &valid, &lookover);
	}


	if ((valid == 'Y') || (valid == 'y')) 
	{
		invalid = 1;
	}
	else if ((valid == 'N') || (valid == 'n')) 
	{
		invalid = 0;
	}
	return invalid;
}




// menu function definition goes here:
int menu(void)                  //Fuction called menu
{
    int choice;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");

    choice = getIntInRange(0, 6);
    return choice;
}




// contactManagerSystem function definition goes here:
void contactManagerSystem(void)                     //Fuction called contactManagerSystem
{
	struct Contact contacts[MAXCONTACTS] = 
	{ { { "Rick", {'\0'}, "Grimes" },
    	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
    	{ "4161112222", "4162223333", "4163334444" } },
    {
    		{ "Maggie", "R.", "Greene" },
    		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
    		{ "9051112222", "9052223333", "9053334444" } },
	{
				{ "Morgan", "A.", "Jones" },
				{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, 
				{ "7051112222", "7052223333", "7053334444" } },
    {
    				{ "Sasha", {'\0'}, "Williams" },
    				{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
    				{ "9052223333", "9052223333", "9054445555" } },
	};
	
	int choice;
	int completed = 0;

	while (!completed)
	{
		choice = menu();
		printf("\n");
		switch (choice)
		{
			case 1:
				displayContacts(contacts, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 2:
				addContact(contacts, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 3:
				updateContact(contacts, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 4:
				deleteContact(contacts, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 5:
				searchContacts(contacts, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 6:
				sortContacts(contacts, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			
			default:
		printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1)
			{
				printf("\nContact Management System: terminated");
				completed = 1;
			}
			printf("\n");
		}
	}
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+
// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])        //Fuction called getTenDigitPhone with a character type called phoneNum
{
	int neededInput;     //integer needed input for the user that will be entered 
	char cellNum[11];      //the cellnum entered by the user
	int k;           //integer k declared as 0
	
	do
	{
		neededInput = 0;     //the neededInput will be at zero in the start of this loop

		scanf("%10s", cellNum);       //take the 10 digits from the user and store it into cellNum
        clearKeyboard();         //calls the function clearKeyboard(): from milestone 1 & 2

        if (strlen(cellNum) == 10)   //the stringlenght of the cellNum is set to only 10!   
        {
			for (k = 0; k < strlen(cellNum); k++)    //for k to start at 0 and k will be less than the cellphone number string lenght, this loop will increment up
			{
				if ((!isdigit(cellNum[k])) && (!isspace(cellNum[k])))      // if the value of the in the string are not digits and there is spaces then 
				{
					neededInput = 1;      //then return back to statement and give only 10 digits
				}
        	}
		}
        else
        {
			neededInput = 1;      //else give a 10 digit phone number 
        }

		if (neededInput != 0)       //if the enter values still dont match the properities then it will be = to 1 and it will print out the statement
		{
			printf("Enter a 10-digit phone number: ");   //give a 10 digits only number for the cellphone number
		}
    } while (neededInput == 1);        // this will continue while the input needed will be one until you gave the give and loop will break
	
	strcpy(phoneNum, cellNum);    //copy the string value from cellNum to the phoneNum.
}



// findContactIndex:
//Fuction called findContactIndex using the contacts struct array, an iteger called size and a constant character variable called cellNum
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int j;                      //integer j declared as 0
	int contactFound = -1;     //integer contactfound index is declared as -1

	for (j = 0; contactFound == -1 && j < size; j++)    //for the variable j set as 0 and contactfound set as -1, j will be less than size and will count up by 1
	{
		if (strcmp(contacts->numbers.cell, cellNum) == 0)  //will compare the two strings for cell number in the array contacts and the cellNum entered by user
		{
			contactFound = j;     //if it does equal to 0 then contact index will be equal to j or else
		}
		else
		{
			contacts++;    //contacts count up but 1 each time and check each
		}
		
	}
	return contactFound;    //return the -1 contactFound
}




// displayContactHeader
// Put empty function definition below:
void displayContactHeader (void)     //Fuction called displayContactHeader
{
	printf("+-----------------------------------------------------------------------------+\n");      //print out header 
	printf("|                              Contacts Listing                               |\n");     //print out header 
	printf("+-----------------------------------------------------------------------------+\n");    //print out header 
}




// displayContactFooter
// Put empty function definition below:
void displayContactFooter (int count)         //Fuction called displayContactFooter with a integer called count
{
	printf("+-----------------------------------------------------------------------------+\n");     //print out footer 
	printf("Total contacts: %d\n", count);   //counts the total contacts stored with the  max of 5 and prints it out
	printf("\n");
}




// displayContact:
// Put empty function definition below:
void displayContact (const struct Contact* contact)            //Fuction called displayContact using the const struct Contacts
{
	printf(" %s", contact->name.firstName);       // print out the contacts first name

	if(*contact->name.middleInitial == 0)     // if they say no to the 	 name then print out a space 
	{
		printf(" ");   // if they said no then enter a empty space there
	}
	else
	{
		printf(" %s ", contact->name.middleInitial);      //print out the middle name if needed if they said yes 
	}
	
	printf("%s\n", contact->name.lastName);      // print out the contacts last name

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);       // print out cell, home, and business number
	printf("       %d %s, ",contact->address.streetNumber, contact->address.street);   // print out the street number and the street name

	if(contact->address.apartmentNumber)
	{
	printf("Apt# %d, ", contact->address.apartmentNumber);     //print out apartment number if needed
	}

	printf("%s, %s\n", contact->address.city, contact->address.postalCode);     //print out adress city name and postal code
}




// displayContacts:
// Put empty function definition below:
void displayContacts (const struct Contact contacts[], int size)             //Fuction called displayContacts using the const struct Contacts and integer called size
{
	int y;        // integer y declared as 0
	int count = 0;     // integer count declared as 0

	displayContactHeader();      //display the function displayContactHeader

	for (y = 0; y < size; y++)    // for the y integer equal to 0, and it is less than size, and it will increment up by 1
	{

		if (strlen(contacts[y].name.firstName) != 0)      //if the string line for the contacts and the vairable in the loop y for the firstname is doesnt equal to 0
		{
			displayContact(&contacts[y]);     //then display the contact found
			count++;      //and count up

		}
	}
	displayContactFooter(count);    //display the function displayContactFooter
}




// searchContacts:
// Put empty function definition below:
void searchContacts (const struct Contact contacts[], int size)       //Fuction called searchContacts using the const struct Contacts and integer called size
{
	char cellNum[11];  // the char cell phone number is equal to 11 characters
	int contactFound;    // the integer for contactFound is for the index of the array that user is looking for

	printf("Enter the cell number for the contact: ");    // askes the user the cellphone for the contacts
	getTenDigitPhone (cellNum);        // the tengetdigitphone number function is called up again and the users input is cellNum is stored

	contactFound = findContactIndex(contacts, size, cellNum);    // the contactsFound looks there the index to find the matching number

	if (contactFound != -1)       //if it contactFound does equals to 1 then it will continue this loop
	{
		printf("\n");          //print out empty new line
		displayContact(&contacts[contactFound]);      //calles the displayContact function and prints it out for the contact entered
		printf("\n");            //print out empty new line
	}
	else 
	{
		printf("*** Contact NOT FOUND ***\n\n");       //if it equal to no (!= 1) then it will print out contact was not found 
	}
}


// addContact:
// Put empty function definition below:
void addContact (struct Contact contacts[], int size)      //Fuction called addContact using the const struct Contacts and integer called size 
{
	int q;            // integer q declared as 0

	for (q = 0; q < size; q++)       // for the q integer equal to 0, and it is less than size, and it will increment up by 1 
	{
		if (strlen(contacts[q].numbers.cell) == 0)       //if the string line for the contacts and the vairable in the loop q for the cell phone number is equal to 0
		{
		getContact(&contacts[q]);     //get the contact and the name,address, and numbers
		printf("--- New contact added! ---\n\n");        //print out that the loop was 
		break;              //break loop
		}

	else if (q == size - 1)       //if not that loop then print out that the array is full
	{
		printf("*** ERROR: The contact list is full! ***\n");       //print out message which means the list is full
		printf("\n");
	}
  }
}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)      //Fuction called updateContact using the const struct Contacts and integer called size
{
	char cellNum[11];                // the char cell phone number is equal to 11 characters
	int contactFound;               // the integer for contactFound is for the index of the array that user is looking for 
	int yesorNo;                   // the users input choice if they want to delete the contacts

	printf ("Enter the cell phone number for the contact: ");        // askes the user the cellphone for the contacts
	getTenDigitPhone(cellNum);                        // the tengetdigitphone number function is called up again and the users input is cellNum is stored

	contactFound = findContactIndex(contacts, size, cellNum);   // the contactsfound looks there the index to find the matching number

	if (contactFound != -1)          //if it contactFound does equals to 1 then it will continue this loop
	{
		printf("\nContact found:\n");        // contact found is printed out
		displayContact(&contacts[contactFound]);      //calles the displayContact function and prints it out for the contact entered
		printf("\n");                  //print out empty new line

		printf("Do you want to update the name? (y or n): ");
		yesorNo = yes();                 //calles the yes function to see if they got the matching result
	
		if(yesorNo == 1)                //if it yesorNo equals to the yes (1) then it will continue this loop
		{
			getName(&contacts[contactFound].name);    //uses getName and will replace by what the users name being updated
		}

		printf("Do you want to update the address? (y or n): ");
		yesorNo = yes();                  //calles the yes function to see if they got the matching result

		if(yesorNo == 1)                //if it yesorNo equals to the yes (1) then it will continue this loop
		{
			getAddress(&contacts[contactFound].address);      //uses getAddress and will replace by what the users address being updated
		}

		printf("Do you want to update the numbers? (y or n): ");
		yesorNo = yes();                //calles the yes function to see if they got the matching result

		if(yesorNo == 1)              //if it yesorNo equals to the yes (1) then it will continue this loop
		{
			getNumbers(&contacts[contactFound].numbers);        //uses getNumbers and will replace by what the users numbers being updated
		}

		printf("--- Contact Updated! ---\n");           //contact has been updated
		printf("\n");
	}
	else 
	{
		printf("*** Contact NOT FOUND ***\n\n");      //if it equal to no (!= 1) then it will print out contact was not found 
	}
	
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)      //Fuction called deleteContact using the const struct Contacts and integer called size
{
	struct Contact rearrange = { { "\0" } };      // struct for contacts for te rearrange
	char cellNUM[11];                            // the char cell phone number is equal to 11 characters
	int contactFound;                           // the integer for contactFound is for the index of the array that user is looking for 
	int yesorNo;                               // the users input choice if they want to delete the contacts
 
	printf("Enter the cell phone number for the contact: ");         // askes the user the cellphone for the contacts
	getTenDigitPhone(cellNUM);                                      // the tengetdigitphone number function is called up again and the users input is cellNum is stored

	contactFound = findContactIndex(contacts, size, cellNUM);     // the contactsfound looks there the index to find the matching number

	if (contactFound != -1)            //if they find the index then continue this loop
	{
		printf ("\nContact found:\n");             // contact found is printed out 
		displayContact(&contacts[contactFound]);      //calles the displayContact function and prints it out for the contact entered
		printf("\n");                   //print out empty new line
		printf("CONFIRM: Delete this contact? (y or n): ");     //askes yes or no is they want to delete the contact
		yesorNo = yes();           //calles the yes function to see if they got the matching result

	if (yesorNo == 1)             //if it yesorNo equals to the yes (1) then it will continue this loop
	{
		contacts[contactFound] = rearrange;         // finds the contacts in the struct array 
		printf("--- Contact deleted! ---\n");       //contact has been deleted
	}
	printf("\n");               //print out empty new line
	}
	else 
	{
		printf("*** Contact NOT FOUND ***\n");         //if it equal to no (!= 1) then it will print out contact was not found 
	}
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)       //Fuction called sortContacts using the const struct Contacts and integer called size
{
	int i;       //integer called i declared with z
	int x;       //integer called x declared with x
	struct Contact rearrange;         //struct called rearrange for the sorting option

	for (i = 0; i < size-1; i++)     //iis equal to 0 and is going to be size -1 and iit will increment up by 1
	{

		for (x = i+1; x < size; x++) //while that is looping another loop will run and will it uses the variable x. x is going to be i + 1 and less than size but will increment by one 
		{

			if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[x].numbers.cell) != 0)     //if the
			{

				if (strcmp(contacts[i].numbers.cell, contacts[x].numbers.cell) > 0)  //if the string lenght of loop i and x for the cellphone number is greater than 0
				{

					rearrange = contacts[i];   //the struct equals to contacts loop i
					contacts[i] = contacts[x];      //and then i equals to x
					contacts[x] = rearrange;    //which means x will sort it using i and will rearrage to contacts
	
				}
			}
		}
	}
	printf("--- Contacts sorted! ---\n");     //final outcome message saying the loop finished and worked "Contacts sorted!"
}
