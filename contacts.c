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
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h>



// getName:
void getName(struct Name* name)
{
    char choice;


    printf("Please enter the contact's first name: ");
    scanf("%31[^\n]", name->firstName);
    clearKeyboard();


    printf("Do you want to enter a middle initial(s)? (y or n): ");
    choice = yes();


        if (choice)
        {
            printf("Please enter the contact's middle initial(s): ");
            scanf("%6[^\n]", name->middleInitial);
            clearKeyboard();
        }
        else 
        {
            name->middleInitial[0] = '\0';
        }


    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}




// getAddress:
void getAddress(struct Address* address)
{
    char choice;
    int NUMBER;


    printf("Please enter the contact's street number: ");
    NUMBER = getInt();


        while (NUMBER < 0)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
            NUMBER = getInt();
        }
    address->streetNumber = NUMBER;


    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();


    printf("Do you want to enter an apartment number? (y or n): ");
    choice = yes();


        if (choice)
        {
            printf("Please enter the contact's apartment number: ");
            NUMBER = getInt();
        while (NUMBER < 0) 
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            NUMBER = getInt();
        }


        address->apartmentNumber = NUMBER;
    }
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();


    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}




// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char choice;

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    choice = yes();


        if (choice == 1)
        {
            printf("Please enter the contact's home phone number: ");
            getTenDigitPhone(numbers->home);
        }
        else 
        {
        numbers->home[0] = 0; 
        }
    printf("Do you want to enter a business phone number? (y or n): ");
    choice = yes();

        if (choice == 1)
        {
            printf("Please enter the contact's business phone number: ");
            getTenDigitPhone(numbers->business);
        }
        else
        {
            numbers->business[0] = 0;
        }
}





// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);

}
