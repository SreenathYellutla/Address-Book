#include <stdio.h>
#include "contact.h"
int main() 
{
    char choice;
    AddressBook addressBook;
    initialize(&addressBook);
    do 
    {
        printf(CYAN "+===============================================+\n" RESET);
        printf(CYAN "|" YELLOW "                 ADDRESS BOOK                  " CYAN "|\n" RESET);
        printf(CYAN "+===============================================+\n" RESET);
        printf(CYAN "| " RESET "1. Create contact" CYAN "                             |\n" RESET);
        printf(CYAN "| " RESET "2. Search contact" CYAN "                             |\n" RESET);
        printf(CYAN "| " RESET "3. Edit contact" CYAN "                               |\n" RESET);
        printf(CYAN "| " RESET "4. Delete contact" CYAN "                             |\n" RESET);
        printf(CYAN "| " RESET "5. List all contacts" CYAN "                          |\n" RESET);
        printf(CYAN "| " RESET "6. Save and Exit" CYAN "                              |\n" RESET);
        printf(CYAN "+===============================================+\n" RESET);
		printf("\n");		
        printf(ORANGE"Enter your choice: "RESET);
        scanf(" %c",&choice);
        switch (choice) 
        {
            case '1':
                createContact(&addressBook);
                break;
            case '2':
                searchContact(&addressBook);
                break;
            case '3':
                 editContact(&addressBook);
                 break;
             case '4':
                 deleteContact(&addressBook);
                 break;
            case '5':          
                 listContacts(&addressBook);
                 break;
            case '6':
                printf(GREEN"Saving and Exiting...\n"RESET);
                saveContactsToFile(&addressBook);
                break;
            default:
                printf(RED"Invalid choice. Please try again.\n"RESET);
        }
    } while (choice != '6');
    
    return 0;
}
