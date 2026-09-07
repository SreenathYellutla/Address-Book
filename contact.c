#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
// Displays all contacts after sorting them by Name, Phone, or Email
void listContacts(AddressBook *addressBook) 
{
    int choice;
    printf(CYAN"1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter Your Choice : "RESET);
    scanf("%d", &choice);
    switch (choice){
        case 1:
        // Sort contacts alphabetically by name
        for(int i=0;i<addressBook->contactCount;i++){
            for(int j=0;j<addressBook->contactCount-i-1;j++){
                if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0){
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
                }
            }
        }
        break;
        case 2:
         // Sort contacts in ascending order by phone number
        for(int i=0;i<addressBook->contactCount;i++){
            for(int j=0;j<addressBook->contactCount-i-1;j++){
                if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0){
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
                }
            }
        }
        break;
        case 3:
        // Sort contacts alphabetically by email
        for(int i=0;i<addressBook->contactCount;i++){
            for(int j=0;j<addressBook->contactCount-i-1;j++){
                if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0){
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
                }
            }
        }
        break;
        
    }
    // Print the table heading
    printf(CYAN "+-----+----------------------+--------------+-------------------------------+\n");
    printf(CYAN "| " RESET YELLOW "No. " RESET CYAN "| " RESET YELLOW "Name                " RESET CYAN " |" RESET YELLOW "Phone         " RESET CYAN "| " RESET YELLOW "Email                       " RESET CYAN "  |\n" RESET);
    printf(CYAN "+-----+----------------------+--------------+-------------------------------+\n");
     // Print every contact stored in the AddressBook
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf(CYAN "| " RESET "%-4d" CYAN "| " RESET "%-21s" CYAN "| " RESET "%-13s" CYAN "| " RESET "%-30s"
           CYAN "|\n" RESET,
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
    }   
    printf(CYAN "+-----+----------------------+--------------+-------------------------------+" RESET "\n");   
}
// Initializes the AddressBook and loads contacts from the file
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
}
// Saves all contacts to the file and exits the program
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); 
    exit(EXIT_SUCCESS); 
}
// Validates whether the entered name contains only allowed characters
int validate_name(char *name)
{
    int i=0;
    /*LOOP till name[i] != '\0'
        check name[i] is not in the range of A to Z, a to z, ' ', '.'
            return 0; // invalid
    END LOOP*/
    while(name[i]!='\0'){
        if(!((name[i]>='A' && name[i]<='Z') || (name[i]>='a' && name[i]<='z') || name[i]==' ' || name[i]=='.')){
            return 0;
        }
        i++;
    }
    return 1;
}
// Validates phone number format and checks for duplicate numbers
int validate_phone(char *str,AddressBook *addressBook)
{
     if(str[0]<'6' && str[0]>'9'){
        return -3;
     }    
    if(strlen(str)!=10){
        return -1;
    } 
        
    for(int i=0;str[i]!='\0';i++){
        if(str[i]<'0'||str[i]>'9'){
            return -2;
        }
    }
     // Check whether the phone number already exists
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(str,addressBook->contacts[i].phone)==0){
            return 0;
        }
    }
    // Loop till str[i] != '\0'
    //     check the str[i] is not in the rage '0' to '9'
    //         return 0; invalid
    
    // check unique or not
    //     not => return 0;



    // return 1 // valid; vp
    return 1;
}
// Validates email format and checks for duplicate email IDs
int validate_mail(char *mail,AddressBook *addressBook){
    int a=0;
    int b=0;
    int c=0;
    // Check if the first character of the email is a lowercase letter
    if(!(mail[0]>='a'&&mail[0]<='z'))return -7;
    for(int i=0;mail[i]!='\0';i++){
        if (!((mail[i] >= 'a' && mail[i] <= 'z') ||(mail[i] >= '0' && mail[i] <= '9') ||mail[i] == '@' ||mail[i] == '.'))return -5;

        if(mail[i]=='@'){
            c++;
            a=i;
        }
        if(mail[i]=='.'){
            b=i;
        }
    }
    if(c>1){
        return -1;
    }
    if(c==0 ){
        return -2;
    }
    if(b==0){
        return -4;
    }
    int diff=b-a;
    if(diff==1)return -6;
    if(diff<0)return -3;
     // Check every character in the email
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(mail, addressBook->contacts[i].email) == 0)
            return 0;
    }
    return 1;
}
// Creates a new contact after validating the name, phone number, and email
void createContact(AddressBook *addressBook)
{
    char name[20];
    int valid;

    while(1)
    {
        printf(CYAN"Enter the name : "RESET);
        scanf(" %[^\n]", name);

        valid = validate_name(name);
        if(valid == 1)// valid
            break;
        if(valid==0)printf(RED"-------Invalid Name------\n"RESET);
    }
    char mobile[11];
    // Validates the phone number format and checks for duplicates
    while(1)
    {
        printf(CYAN"Enter the phone : "RESET);
        scanf(" %[^\n]", mobile);

        valid = validate_phone(mobile, addressBook);
        if(valid == 1)// valid
            break;
        else if(valid==-1){
            printf(RED"Invalid Phone number : Must contain 10 numbers \n"RESET);
        }
        else if(valid==-2){
            printf(RED"Invalid Phone number : Not contain numbers \n"RESET);
        }
        else if(valid==-3){
            printf(RED"Invalid Phone number : Not start with 6 to 9 "RESET);
        }
        else if(valid==0){
            printf(RED"Invalid Phone number : Duplicate numbers \n"RESET);
        }
    }
    char mail[30];
    // Validates the email format and checks for duplicates
    while(1)
    {
        printf(CYAN"Enter the mail : "RESET);
        scanf(" %[^\n]", mail);
        valid = validate_mail(mail, addressBook);
        if(valid == 1){
        printf(GREEN"----Contact created succesfully----\n"RESET);
            break;
        }
        // Check for various email validation errors and print corresponding messages
        if(valid==-7)printf(RED"Invalid E-Mail : Email must start with Aplabet\n"RESET);
        if(valid==-1)printf(RED"Invalid E-Mail : Multiple @ symbols are not allowed\n"RESET);
        if(valid==-2)printf(RED"Invalid E-Mail : Missing @\n"RESET);
        if(valid==-3)printf(RED"Invalid E-Mail : (@) Come before (.)\n"RESET);
        if(valid==-4)printf(RED"Invalid E-Mail : Missing (.)\n"RESET);
        if(valid==-5) printf(RED "Invalid E-Mail : Email ID contain only lowercase\n" RESET);
        if(valid==-6) printf(RED "Invalid E-Mail : There must be at least one character between @ and .(dot)\n" RESET);
        if(valid==0)printf(RED"Invalid E-Mail : Duplicate E-mail ID\n"RESET);
    }
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].email, mail);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,mobile);
    addressBook->contactCount++;
}
// Searches for a contact by phone number and displays the contact details if found
int search_by_phone(AddressBook *addressBook)
{
    char str[11];
    printf(CYAN"Enter a phone number : "RESET);
    scanf("  %10s",str);
   for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str, addressBook->contacts[i].phone) == 0)
        {
        printf(GREEN "\nContact Found\n" RESET);
        printf(CYAN "------------------------------------------\n" RESET);
        printf("Phone : %s\n", addressBook->contacts[i].phone);
        printf("Name  : %s\n", addressBook->contacts[i].name);
        printf("Email : %s\n", addressBook->contacts[i].email);
        printf(CYAN "------------------------------------------\n" RESET);
            return i;
        }
    }
    return -1;
}
// Searches for a contact by name and displays the contact details if found
int search_by_name(AddressBook *addressBook)
{
    char str[20];
    int ind=-1;
    int count=0;
    int indexes[100];
    printf(CYAN"Enter name : "RESET);
    scanf(" %[^\n]",str);
    int valid;
    valid = validate_name(str);
    if(valid==0)printf(RED"-------Invalid Name------\n"RESET);
    if(valid==1){

        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str, addressBook->contacts[i].name) == 0)
            {
                indexes[count]=i;
                count++;
        }
        }
    }
    if(count==0){
        printf(RED"\nContact not found\n"RESET);
        return -1;
    }
    else if(count==1){
        ind = indexes[0];
        printf(GREEN "\nContact Found\n" RESET);
        printf(CYAN "------------------------------------------\n" RESET);
        printf("Phone : %s\n", addressBook->contacts[ind].name);
        printf("Name  : %s\n", addressBook->contacts[ind].phone);
        printf("Email : %s\n", addressBook->contacts[ind].email);
        printf(CYAN "------------------------------------------\n" RESET);
        return ind;
    }
    // If multiple contacts with the same name are found, prompt the user to choose one
    else if(count > 1){
        int choice;

        printf(YELLOW"\n----Duplicate names found----\n"RESET);
        printf(CYAN "------------------------------------------\n" RESET);
        for(int i = 0; i < count; i++)
        {
            printf("\n%d. %s  %s  %s\n",
               i + 1,
               addressBook->contacts[indexes[i]].name,
               addressBook->contacts[indexes[i]].phone,
               addressBook->contacts[indexes[i]].email);
        }
        printf(CYAN "------------------------------------------\n" RESET);
        while(1){
            printf("\nChoose contact (1-%d): ", count);
            scanf("%d", &choice);

            if(choice >= 1 && choice <= count)
            {
                int index = indexes[choice - 1];

                printf(GREEN "\nContact Found\n" RESET);
                printf(CYAN "------------------------------------------\n" RESET);
                printf("Name  : %s\n", addressBook->contacts[index].name);
                printf("Phone : %s\n", addressBook->contacts[index].phone);
                printf("Email : %s\n", addressBook->contacts[index].email);
                printf(CYAN "------------------------------------------\n" RESET);

                return index;
            }
            printf(RED "Invalid choice. Try again.\n" RESET);
        }
    }
    return -1;
}
// Searches for a contact by email and displays the contact details if found
int search_by_mail(AddressBook *addressBook){
    char mail[30];
    printf(CYAN"Enter Email: "RESET);
    scanf(" %29s", mail);
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(mail, addressBook->contacts[i].email) == 0)
        {
            printf(GREEN "\nContact Found\n" RESET);
        printf(CYAN "------------------------------------------\n" RESET);
        printf("Phone : %s\n", addressBook->contacts[i].name);
        printf("Name  : %s\n", addressBook->contacts[i].phone);
        printf("Email : %s\n", addressBook->contacts[i].email);
        printf(CYAN "------------------------------------------\n" RESET);
            return i;
        }
    }
    return -1;
}

void searchContact(AddressBook *addressBook) 
{
    int c=0;
    char choise;
    do{
    printf(BLUE"1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n"RESET);
    printf(CYAN"Choose the search option : \n"RESET);
    scanf(" %c", &choise);
    switch(choise)
    {
        case '1':
            search_by_name(addressBook);
            break;
        case '2': 
            search_by_phone(addressBook);
            break;
        case '3': 
            search_by_mail(addressBook);
            break;
        default:
            printf(RED"Invalid input\n"RESET);
            break;
    }
    c++;
    }while(c!=3 && choise>'3');

}
// Edits the name of a contact after validating the new name
void edit_phone(AddressBook *addressBook,int res){
    int valid;
    char mobile[11];
    while(1){
        printf(CYAN"Enter the Edit phone : "RESET);
        scanf(" %[^\n]",mobile);
        valid = validate_phone(mobile, addressBook);// Validate the new phone number
        if(valid==1){
            break;
        }
    }
    strcpy(addressBook->contacts[res].phone,mobile);
}
// Edits the email of a contact after validating the new email
void edit_mail(AddressBook *addressBook,int res){
    int valid;
    char mail[30];
    while(1){
        printf(CYAN"Enter the Edit email : "RESET);
        scanf(" %[^\n]",mail);
        valid = validate_mail(mail, addressBook);// Validate the new email
        if(valid==1){
            break;
        }
    }
    strcpy(addressBook->contacts[res].email,mail);
}
// Edits the name of a contact after validating the new name
void edit_name(AddressBook *addressBook, int res)
{
  
    int valid;
    char name[20];
    while(1)
    {
        printf(CYAN"Enter the Edit name : "RESET);
        scanf(" %[^\n]", name);
        valid = validate_name(name);// Validate the new name
        if(valid == 1)// valid
            break;
    }
    strcpy(addressBook->contacts[res].name, name);
}
// Edits a contact by searching for it and allowing the user to choose which field to edit
void editContact(AddressBook *addressBook)
{
    char Choice;
    char editChoice;
    int res = -1;
    int c=0;
    do{
        printf(BLUE"\n1. Name\n");
        printf("2. Phone\n");
        printf("3. Email\n"RESET);

        printf(CYAN"Choose the search option : \n"RESET);

        scanf(" %c", &Choice);
        // Search for the contact based on the user's choice
        switch(Choice)
        {
            case '1':
                res = search_by_name(addressBook);
                break;

            case '2':
                res = search_by_phone(addressBook);
                break;

            case '3':
                res = search_by_mail(addressBook);
                break;

            default:
                printf(RED"--Invalid Choice--\n"RESET);
                continue;
        }
        break;
       
    }while(1);
    // If the contact is not found, return from the function
    printf(BLUE"\nEdit\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n"RESET);
    printf(CYAN"Enter your choice: "RESET);
    scanf(" %c", &editChoice);
    switch(editChoice)
    {
        case '1':
            edit_name(addressBook, res);
            break;

        case '2':
            edit_phone(addressBook, res);
            break;

        case '3':
            edit_mail(addressBook, res);
            break;

        default:
            printf(RED"Invalid Choice\n"RESET);
            return;
    }
    printf(GREEN"\nContact Updated Successfully.\n"RESET);
}
// Deletes a contact by searching for it and removing it from the AddressBook
void deleteContact(AddressBook *addressBook)
{
    char choice;
    int index = -1;
    printf(BLUE"Delete By\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n"RESET);
    printf(CYAN"Choose the search option : "RESET);
    scanf(" %c",&choice);
    // Search for the contact based on the user's choice
    switch(choice)
    {
        case '1':
            index = search_by_name(addressBook);
            break;

        case '2':
            index = search_by_phone(addressBook);
            break;

        case '3':
            index = search_by_mail(addressBook);
            break;

        default:
            printf(RED"Invalid Choice\n"RESET);
            return;
    }
    if(index == -1)
    {
        printf(RED"Contact Not Found\n"RESET);
        return;
    }
    for(int i=index;i<addressBook->contactCount-1;i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i+1];
    }
    addressBook->contactCount--;
    printf(GREEN"Contact Deleted Successfully\n"RESET);

}
