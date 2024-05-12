Phone Directory Application Documentation 📖
Overview 🌐
This C++ program implements a simple phone directory application that allows users to add, display, search, delete, and edit contact information stored in an unordered map. The application is designed to manage contact details such as name, phone numbers (mobile, home, and work), email, and address.

Features 🚀
Add Contact: Insert a new contact into the phone directory.
Display All Contacts: View all contacts currently stored.
Search Contacts: Find a contact based on a query that matches any piece of contact information.
Delete Contact: Remove a contact from the directory using their full name.
Edit Contact: Update the details of an existing contact.
Exit: Close the application.
Code Structure 🏗️
Headers and Namespace
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <string>

using namespace std;
Data Structures
phoneBook Struct: Holds individual contact details.

Field	Type	Description
firstName	string	The contact's first name.
lastName	string	The contact's last name.
eMail	string	The contact's email address.
phoneNumbers	string[]	Array storing mobile, home, work numbers.
address	string	The contact's physical address.
Classes
PhoneDirectory Class: Manages the operations on contacts.

Private Members
contacts: An unordered_map storing phoneBook structs indexed by fullName.
Public Methods
Method	Parameters	Description
addContacts	const phoneBook &newContact	Adds a new contact to the directory.
displayContacts	-	Displays all contacts in the directory.
searchContacts	const string &query	Searches for contacts matching the query.
deleteContacts	const string &fullName	Deletes a contact by their full name.
editContact	const string &fullName, const phoneBook &newContactInfo	Edits and updates a contact's information.
Functions
printIntroduction: Displays a loading sequence and introductory text.
Main Function
int main() {
    PhoneDirectory directory;
    int choice;
    string firstName, lastName, searchQuery;
    phoneBook newContact;
    printIntroduction();  // Display the introduction

    cout << "Home of the Application" << endl;
    do {
        cout << "\nPhone Directory Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contacts\n";
        cout << "4. Delete Contact\n";
        cout << "5. Edit Contact\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Code to prompt user and add contact
                break;
            case 2:
                // Code to display all contacts
                break;
            case 3:
                // Code to prompt user and search contacts
                break;
            case 4:
                // Code to prompt user and delete a contact
                break;
            case 5:
                // Code to prompt user and edit a contact
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
Usage Instructions 📝
Compile the Program: Use a C++ compiler like g++ to compile the code.
g++ phoneBook.cpp -o phoneBook
Run the Program: Start the application by running the compiled executable.
./phoneBook
Follow On-screen Prompts: Use the menu to manage contacts within the application.
Conclusion 🎬
This application serves as a basic example of handling a CRUD (Create, Read, Update, Delete) system using C++ and standard libraries, demonstrating the utility of data structures and user interaction in a console application.
