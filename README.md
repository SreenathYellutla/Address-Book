# 📒 Address Book Management System in C

A **console-based Address Book Management System** developed in **C programming language**.

This project allows users to store, search, update, delete, and manage contact information such as **Name, Phone Number, and Email Address**.

The project is designed to practice important C programming concepts such as **structures, arrays, strings, pointers, functions, file handling, validation, and menu-driven programming**.

---

## 📌 Features

The Address Book provides the following operations:

### 1. Add Contact

Add a new contact to the Address Book.

Each contact contains:

* Name
* Phone Number
* Email Address

Example:

```text
Name  : Sreenath
Phone : 9876543210
Email : sreenath@gmail.com
```

---

### 2. Search Contact

Contacts can be searched using:

* Name
* Phone Number
* Email Address

The search operation displays the matching contact details.

---

### 3. Duplicate Name Handling

The Address Book allows multiple contacts to have the **same name**.

For example:

```text
Name  : Sreenath
Phone : 9876543210
Email : sree@gmail.com

Name  : Sreenath
Phone : 9123456780
Email : sreenath2@gmail.com
```

If the user searches for:

```text
Enter name:
Sreenath
```

and multiple contacts are found, the program displays all matching contacts and provides a **choice option**.

Example:

```text
Duplicate names found:

1. Name  : Sreenath
   Phone : 9876543210
   Email : sree@gmail.com

2. Name  : Sreenath
   Phone : 9123456780
   Email : sreenath2@gmail.com

Choose contact (1-2): 2
```

After selecting an option, the selected contact is displayed:

```text
Contact Found
------------------------------------------
Name  : Sreenath
Phone : 9123456780
Email : sreenath2@gmail.com
------------------------------------------
```

This allows the user to directly select the required contact instead of searching again using the phone number.

---

### 4. Edit Contact

Existing contact information can be modified.

The user can update details such as:

* Name
* Phone Number
* Email Address

---

### 5. Delete Contact

A contact can be removed from the Address Book.

The program identifies the required contact and deletes it from the contact list.

---

### 6. List All Contacts

Displays all contacts currently stored in the Address Book.

Example:

```text
------------------------------------------------------------
Name             Phone Number          Email
------------------------------------------------------------
Sreenath          9876543210            sree@gmail.com
Rahul             9123456780            rahul@gmail.com
Arun              9988776655            arun@gmail.com
------------------------------------------------------------
```

---

### 7. Save Contacts

The Address Book can store contact information so that it can be used later.

Contact information can be saved using file handling.

---

### 8. Exit

The program provides an option to safely exit the Address Book.

---

# 🛠️ Technologies Used

* **Programming Language:** C
* **Compiler:** GCC
* **IDE:** Visual Studio Code
* **Operating System:** Linux / macOS / Windows
* **Version Control:** Git
* **Repository:** GitHub

---

# 📚 C Concepts Used

This project helps demonstrate the following C programming concepts:

### Basic C

* Variables
* Data types
* Operators
* Conditional statements
* Loops
* Functions

### Arrays and Strings

* Character arrays
* String manipulation
* `strcmp()`
* `strcpy()`
* `strlen()`
* String input and output

### Structures

The project uses structures to store contact information.

Example:

```c
struct Contact
{
    char name[50];
    char phone[20];
    char email[50];
};
```

A collection of contacts can then be maintained using an array of structures.

---

### Pointers

Pointers are used for:

* Passing structures to functions
* Modifying Address Book data
* Accessing structure members
* Working with arrays and strings

Example:

```c
AddressBook *addressBook
```

---

### Functions

The project is divided into different functions to make the program easier to understand and maintain.

Examples:

```c
add_contact()
search_contact()
edit_contact()
delete_contact()
list_contacts()
```

---

### File Handling

File handling can be used to store contacts permanently.

Important functions include:

```c
fopen()
fclose()
fprintf()
fscanf()
fread()
fwrite()
```

---

### Input Validation

The project validates user input before storing it.

Validation can be performed for:

* Name
* Phone number
* Email address

This prevents invalid contact information from being stored.

---

# 📂 Project Structure

The project can be organized as follows:

```text
AddressBook/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── validate.c
├── validate.h
└── README.md
```

### File Description

| File         | Description                                  |
| ------------ | -------------------------------------------- |
| `main.c`     | Contains the main menu and program execution |
| `contact.c`  | Contains contact-related operations          |
| `contact.h`  | Header file containing declarations          |
| `file.c`     | Handles file operations                      |
| `file.h`     | File handling declarations                   |
| `validate.c` | Contains input validation functions          |
| `validate.h` | Validation function declarations             |
| `README.md`  | Project documentation                        |

> The exact files may vary depending on the project implementation.

---

# ▶️ How to Run the Project

## Step 1: Clone the Repository

Clone the project from GitHub:

```bash
git clone <repository-url>
```

Example:

```bash
git clone https://github.com/username/AddressBook.git
```

---

## Step 2: Enter the Project Directory

```bash
cd AddressBook
```

---

## Step 3: Compile the Project

If all C files need to be compiled together:

```bash
gcc *.c -o addressbook
```

---

## Step 4: Run the Program

### Linux / macOS

```bash
./addressbook
```

### Windows

```bash
addressbook.exe
```

---

# 🖥️ Sample Menu

```text
==========================================
           ADDRESS BOOK MENU
==========================================

1. Add Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List Contacts
6. Save Contacts
7. Exit

Enter your choice:
```

---

# 🔎 Sample Search

### Searching by Name

```text
Enter name:
Sreenath
```

If only one contact exists:

```text
Contact Found
------------------------------------------
Name  : Sreenath
Phone : 9876543210
Email : sree@gmail.com
------------------------------------------
```

If multiple contacts have the same name:

```text
Duplicate names found:

1. Name  : Sreenath
   Phone : 9876543210
   Email : sree@gmail.com

2. Name  : Sreenath
   Phone : 9123456780
   Email : sreenath2@gmail.com

Choose contact (1-2): 2
```

The selected contact is then displayed.

---

# 🎯 Project Objectives

The main objectives of this project are:

* To understand **structures in C**
* To practice **arrays of structures**
* To understand **pointers**
* To practice **string manipulation**
* To implement **functions**
* To understand **file handling**
* To implement **input validation**
* To develop a **menu-driven application**
* To understand **modular programming**
* To practice debugging and problem solving
* To learn how to manage a project using **Git and GitHub**

---

# 🚀 Future Improvements

The project can be extended with additional features such as:

* Sort contacts alphabetically
* Search contacts by partial name
* Import/export contacts
* Store contacts in a database
* Add contact groups
* Add favorites
* Improve user interface
* Password protection
* Backup and restore contacts
* Case-insensitive searching

---

# 🧑‍💻 Author

**Sreenath**

C Programming | Embedded Systems | Problem Solving

---

# ⭐ Acknowledgements

This project was developed as a practical exercise to improve understanding of **C programming, data structures, file handling, and software development practices**.

If you find this project useful, consider giving the repository a ⭐ on GitHub.

---

## 📜 License

This project is available for educational and learning purposes.
