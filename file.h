#ifndef FILE_H
#define FILE_H
#include "contact.h"
// Saves the contacts in the AddressBook to a file named "contacts.txt"
void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);
#endif
