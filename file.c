#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
   FILE *fp = fopen("contacts.txt", "w");
    if(fp == NULL)
    {
        printf(RED"--Error opening file\n");
        return;
    }
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
    fclose(fp); 
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.txt", "r");

    if(fp == NULL)
    {
        addressBook->contactCount = 0;
        printf("No contacts file found\n");
        return;
    }
    addressBook->contactCount = 0;

    while(addressBook->contactCount < 100 &&
          fscanf(fp, "%[^,],%[^,],%s\n",
                 addressBook->contacts[addressBook->contactCount].name,
                 addressBook->contacts[addressBook->contactCount].phone,
                 addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }
    fclose(fp);
}
