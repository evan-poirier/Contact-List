#include <iostream>
#include <string>

#include "p3.h"

using namespace std;

Info::Info() {
    this->name = "No Name Set";
    this->value = "No Value Set";
    this->next = nullptr;
}

Info::Info(std::string name, std::string value, Info *next) {
    this->name = name;
    this->value = value;
    this->next = next;
}

Info* Info::GetNext() {
    return this->next;
}

void Info::PrintNode() {
    cout << "\t" << this->name << " | " << this->value << endl;
}

Contact::Contact() {
    this->first = "No First Set";
    this->last = "No Last Set";
    this->next = nullptr;
    this->headInfoList = nullptr;
    this->tailInfoList = nullptr;
}

Contact::Contact(std::string first, std::string last, Contact *next) {
    this->first = first;
    this->last = last;
    this->next = next;
    this->headInfoList = nullptr;
    this->tailInfoList = nullptr;
}

Contact* Contact::GetNext() {
    return this->next;
}

void Contact::PrintNode() {
    cout << "Contact Name: " << this->first << " " << this->last << endl;
}

ContactList::ContactList() {
    this->headContactList = nullptr;
    this->tailContactList = nullptr;
    this->count = 0;
}

int ContactList::getCount() {
    return this->count;
}

// print the specified contact and its information
// 1. return false and print nothing if the contact is not in the list
// 2. otherwise return true and print the contact
// IMPORTANT: i didnt make the info or contact classes be able to print to "os", will have to fix
bool ContactList::printContact(std::ostream &os, std::string first, std::string last) {
    return true;
}

// print all contacts and their information
// print nothing if the list is empty
void ContactList::print(std::ostream &os) {
    Contact *currContact = headContactList;

    while (currContact != nullptr) {
        currContact->PrintNode();
        
        Info *currInfo = currContact->headInfoList;
        
        while (currInfo != nullptr) {
            currInfo->PrintNode();
            currInfo = currInfo->GetNext();
        }

        currContact = currContact->GetNext();
    }
}

// add a contact to the back of the list
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the back of the list
// - do not forget to update count
bool ContactList::addContact(std::string first, std::string last) {
    Contact *newContact = new Contact(first, last, nullptr);

    Contact *currContact = this->headContactList;
    bool contactExists = false;
    
    while (currContact != nullptr) {
        if (currContact->first == first && currContact->last == last) {
            contactExists = true;
        }
        currContact = currContact->GetNext();
    }
    
    if (contactExists) {
        return false;
    }

    if (this->headContactList == nullptr) {
        this->headContactList = newContact;
        this->tailContactList = newContact;
    } else {
        this->tailContactList->next = newContact;
        this->tailContactList = newContact;
    }

    this->count ++;

    return true;
}

// add info to the back of a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the back of the contact's list and return true
bool ContactList::addInfo(std::string first, std::string last, std::string infoName, std::string infoVal) {
    Info *newInfo = new Info(infoName, infoVal, nullptr);

    Contact *currContact = this->headContactList;

    bool contactExists = false;

    // go through list of contacts. if contact is found, stop on that node.
    while (currContact != nullptr) {
        if (currContact->first == first && currContact->last == last) {
            contactExists = true;
            break;
        }
        currContact = currContact->GetNext();
    }

    // if the specified contact wasnt found
    if (!contactExists) {
        return false;
    }

    Info *currInfo = currContact->headInfoList;

    // for found contact node, see if info is already there
    while (currInfo != nullptr) {
        // if it is, update value and end function
        if (infoName == currInfo->name) {
            currInfo->value = infoVal;
            return true;
        }
        currInfo = currInfo->GetNext();
    }

    if (currContact->headInfoList == nullptr) {
        currContact->headInfoList = newInfo;
        currContact->tailInfoList = newInfo;
    } else {
        currContact->tailInfoList->next = newInfo;
        currContact->tailInfoList = newInfo;
    }
    
    return true;
}

// add a contact to the list in ascending order by last name
//     if last names are equal, then order by first name ascending
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the list
// - do not forget to update count
// - compare strings with the built-in comparison operators: <, >, ==, etc.
// - a compare method/function is recommended
bool ContactList::addContactOrdered(std::string first, std::string last) {
    return true;
}

// add info to a contact's info list in ascending order by infoName
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the contact's list and return true
bool ContactList::addInfoOrdered(std::string first, std::string last, std::string infoName, std::string infoVal) {
    return true;
}

// remove the contact and its info from the list
// 1. return false and do nothing if the contact is not in the list
// 2. otherwise return true and remove the contact and its info
// - do not forget to update count
bool ContactList::removeContact(std::string first, std::string last) {
    return true;
}

// remove the info from a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. return false and do nothing if the info is not in the contact's info list
// 3. otherwise return true and remove the info from the contact's list
bool ContactList::removeInfo(std::string first, std::string last, std::string infoName) {
    return true;
}

// destroy the list by removing all contacts and their infos
ContactList::~ContactList() {

}

// deep copy the source list
// - do not forget to update count
ContactList::ContactList(const ContactList &src) {

}

// remove all contacts and their info then deep copy the source list
// - do not forget to update count
const ContactList &ContactList::operator=(const ContactList &src) {
    if (this != &src) {

    }
    return *this;
}
