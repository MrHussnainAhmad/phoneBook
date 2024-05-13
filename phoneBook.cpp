#include <iostream>
#include <iomanip>
#include <unordered_map> //for map to store contacts using full name.
#include <chrono>        //for loading bar.
#include <thread>
#include <string>

using namespace std;

struct phoneBook
{
    string firstName, lastName, eMail, phoneNumbers[3], address;
};

class PhoneDirectory
{
private:
    unordered_map<string, phoneBook> contacts;

public:
    void addContacts(const phoneBook &newContact)
    {
        string fullName = newContact.firstName + " " + newContact.lastName;
        contacts[fullName] = newContact;
        cout << "Contact added in directory successfully!" << endl;
    }
    
    void displayContacts()
    {
        if (contacts.empty())
        {
            cout << "Your phone Directory is still empty.\nPlease add contacts first." << endl;
            cout << endl;
            return;
        }
        cout << "--------------------------------------" << endl;
        for (const auto &entry : contacts)
        {
            const phoneBook &contact = entry.second;
            cout << "Name: " << contact.firstName << " " << contact.lastName << endl;
            cout << "Phone Number: " << endl;
            for (int i = 0; i < 3; ++i)
            {
                cout << " - " << contact.phoneNumbers[i] << endl;
            }
            cout << "Email: " << contact.eMail << endl;
            cout << "Address: " << contact.address << endl;
            cout << "--------------------------------------" << endl;
        }
    }

    void searchContacts(const string &query)
    {
        bool found = false;
        cout << "Search Results: " << endl;
        cout << "--------------------------------------" << endl;
        for (const auto &entry : contacts)
        {
            const phoneBook &contact = entry.second;
            if (contact.firstName.find(query) != string::npos ||
                contact.lastName.find(query) != string::npos ||
                contact.phoneNumbers[0].find(query) != string::npos ||
                contact.phoneNumbers[1].find(query) != string::npos ||
                contact.phoneNumbers[2].find(query) != string::npos ||
                contact.eMail.find(query) != string::npos)
            {
                cout << "Name: " << contact.firstName << " " << contact.lastName << endl;
                cout << "Phone Number: " << endl;
                for (int i = 0; i < 3; ++i)
                {
                    if (!contact.phoneNumbers[i].empty())
                    {
                        cout << "- " << contact.phoneNumbers[i] << endl;
                    }
                }
                cout << "Email: " << contact.eMail << endl;
                cout << "Address: " << contact.address << endl;
                cout << "--------------------------------------" << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No matching contact Found, Please check spellings." << endl;
        }
    }

    void deleteContacts(const string &fullName)
    {
        if (contacts.erase(fullName))
        {
            cout << "Contact Deleted Permanently!" << endl;
        }
        else
        {
            cout << "Either contact is not present or Spelling mistake!" << endl;
        }
    }

    void editContact(const string &fullName, const phoneBook &newContactInfo)
    {
        if (contacts.find(fullName) != contacts.end())
        {
            string newFullName = newContactInfo.firstName + " " + newContactInfo.lastName;
            contacts.erase(fullName);
            contacts[newFullName] = newContactInfo;
            cout << "Contact Edited & Updated successfully!" << endl;
        }
        else
        {
            cout << "Contact not found in Directory!" << endl;
        }
    }
};
void printIntroduction()
{
    cout << endl;
    cout << endl;
    cout << "\"Phone Directory Application\"" << endl;
    cout << "Created By \"Hussnain Ahmad\"" << endl;
    cout << "\"BS CS\"" << endl;
    cout << "1153" << endl;
    cout << "IUB" << endl;
    cout << "Loading: ";
    for (int i = 0; i <= 20; ++i)
    {
        cout << "\u25A0";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(250)); // Sleep for 250 milliseconds
    }
    cout << endl;
    cout << endl;
}

int main()
{
    PhoneDirectory directory;
    int choice;
    string firstName, lastName, searchQuery;
    phoneBook newContact;

    printIntroduction();

    cout << "Home of the Application" << endl;

    do
    {
        cout << "\nPhone Directory Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contacts\n";
        cout << "4. Delete Contact\n";
        cout << "5. Edit Contact\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter First Name: ";
            cin >> newContact.firstName;
            cout << "Enter Last Name: ";
            cin >> newContact.lastName;
            cout << "Enter Mobile Number: ";
            cin >> newContact.phoneNumbers[0];
            cout << "Enter Home Number: ";
            cin >> newContact.phoneNumbers[1];
            cout << "Enter Work Number: ";
            cin >> newContact.phoneNumbers[2];
            cout << "Enter Email: ";
            cin >> newContact.eMail;
            cout << "Enter Home Address: ";
            cin >> newContact.address;
            directory.addContacts(newContact);
            break;
        case 2:
            directory.displayContacts();
            break;
        case 3:
            cout << "Enter Full Name or Contact Number: ";
            cin.ignore();
            cin >> searchQuery;
            directory.searchContacts(searchQuery);
            break;
        case 4:
            cout << "Enter Full Name of contact to delete: ";
            cin >> firstName >> lastName;
            directory.deleteContacts(firstName + " " + lastName);
            break;
        case 5:
            cout << "Enter full name of contact to edit: ";
            cin >> firstName >> lastName;
            cout << "Enter new First Name: ";
            cin >> newContact.firstName;
            cout << "Enter new Last Name: ";
            cin >> newContact.lastName;
            cout << "Enter new Mobile Number: ";
            cin >> newContact.phoneNumbers[0];
            cout << "Enter new Home Number: ";
            cin >> newContact.phoneNumbers[1];
            cout << "Enter new Work Number: ";
            cin >> newContact.phoneNumbers[2];
            cout << "Enter new Email: ";
            cin >> newContact.eMail;
            cout << "Enter new Address: ";
            cin >> newContact.address;
            directory.editContact(firstName + " " + lastName, newContact);
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