// ASU CSE310 Fall 2024 Assignment #1
// Name: PO-YI, LIN
// ASU ID: 1228434521
// Description:This is a .h file for the LinkList and all method of cpp file.
//
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//HotelBooking represents a Hotel's booking information
struct HotelBooking//Node
{
    string hotelName;
    string arrivalDate;
    int confirmNum;     //booking confirmation No.
    struct HotelBooking* next;
};

//class LinkedList will contains a linked list of HotelBooking objects
class LinkedList
{
private:
    struct HotelBooking* head;

public:
    LinkedList();
    ~LinkedList();
    int compareBookings(HotelBooking* a, HotelBooking* b);
    bool searchBooking(string hotelName, string arrivalDate, int confirmNum);
    bool addBooking(string hotelName, string arrivalDate, int confirmNum);
    void displayAllBookings();
    void displayBookingsByHotel(string hotelName);
    void displayBookingsByDate(string arrivalDate);
    int countAllBookings();
    int countBookingByHotel(string hotelName);
    int countBookingByDate(string arrivalDate);
    bool cancelOneBooking(string hotelName, string arrivalDate, int confirmNum);
    bool cancelAllBookingsByHotel(string hotelName);
    bool cancelAllBookingsByDate(string arrivalDate);
    bool delayABooking(string hotelName, string oldArrivalDate, int confirmNum, string newArrivalDate);
    bool changeAHotel(string oldHotelName, string arrivalDate, int confirmNum, string newHotelName);
};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
    //Add your own code
    //----
    head = NULL;//Set head to NULL
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the existing linked list.
//It deletes all the nodes including the head and finally prints the number of nodes deleted by it.
//Return value: Prints the number of nodes deleted by it.
LinkedList::~LinkedList()
{
    //Add your own code
    //----
    HotelBooking* current = head;
    HotelBooking* deleteNode = nullptr;
    int count = 0;

    while (current != nullptr) {//free all memory from first to last
        deleteNode = current;
        current = current->next;
        delete deleteNode;//free a node
        count++;
    }

    cout << "The number of deleted bookings is: " << count << "\n";
}


int LinkedList::compareBookings(HotelBooking* a, HotelBooking* b) {//The function I add to help me compareBookings and sort
   
    if (a->hotelName != b->hotelName) {
        return a->hotelName.compare(b->hotelName);//compare can compare each chart of hotelName
    }

    if (a->arrivalDate != b->arrivalDate) {
        return a->arrivalDate.compare(b->arrivalDate);//compare can compare each chartt of arrivalDate
    }
 
    return a->confirmNum - b->confirmNum;//if need to compare confirmNum Positive means true negative means false
}
//**A function to find if the parameterized HotelBooking object is inside the LinkedList or not.
//Return true if it exists and false otherwise.
bool LinkedList::searchBooking(string hotelName, string arrivalDate, int confirmNum)
{
    //Add your own code
    //----
    HotelBooking* current = head;//initial a current help me searching

    if (current == NULL) {//if head is empty
        return false;
    }

    while (current != NULL) {//searching for the corrrect linklist
        if (current->hotelName == hotelName && current->arrivalDate == arrivalDate && current->confirmNum == confirmNum) {
            return true;
        }
        current = current->next;
    }

    return false;//if can not search for
}

//***This is the most important function you need to work on since it build the linked list****
//Creates a new node and inserts it into the list at the right place.
//It also maintains an alphabetical ordering of HotelBookings by hotelName, arrival date
//and confirmation number. i.e. first by hotelName, then by arrival date, last by confirmation
//number. i.e. if two HotelBookings have the same hotelName, then the new HotelBooking should be
//inserted in alphabetical order of their arrival dates. Also it is possible that two or more
//HotelBookings have same hotelName and arrival dates, but their confirmation number must be different
//and they should be inserted into the list by increasing order of the number.
//Return value: true if it is successfully inserted and false in case of failures.
bool LinkedList::addBooking(string hotelName, string arrivalDate, int confirmNum)//08/20/2024
{
    //Add your own code
    //----
    HotelBooking* newNode = new HotelBooking();
    newNode->hotelName = hotelName;
    newNode->arrivalDate = arrivalDate;
    newNode->confirmNum = confirmNum;
    newNode->next = nullptr;
    HotelBooking* current = head;

    if (searchBooking(hotelName,arrivalDate,confirmNum)) {//use searching function to check if there is the booking
        return false;
    }
    if (head == nullptr) {//check is the linklist empty
        head = newNode;
        return true;
    }

    if (compareBookings(newNode, head) < 0) {//use compare to compare for putting as after head
        newNode->next = head;
        head = newNode;
        return true;
    }

    current = head;
    while (current->next != nullptr && compareBookings(newNode, current->next) > 0) {//use compare to compare for putting
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return true;
}

//Display all HotelBookings in the linked list starting from the head.
void LinkedList::displayAllBookings()
{
    //Add your own code
    //----
    HotelBooking* temp = head;//temp of head
    int counter = 0;

    while (temp != nullptr) {//display every booking at LinkList by temp changing
        cout << left << setw(18) << temp->hotelName
            << setw(12) << temp->arrivalDate
            << setw(8) << temp->confirmNum << "\n";
        temp = temp->next;
        counter++;
    }

    cout << "\nTotal # of bookings: " << counter << "\n";
}

//Display all bookings with the specified hotelName.
void LinkedList::displayBookingsByHotel(string hotelName)
{
    //Add your own code
    //----
    HotelBooking* temp = head;
    int counter = 0;

    while (temp != nullptr) {
        if (temp->hotelName == hotelName) {//condition of hotelName
            cout << left << setw(18) << temp->hotelName
                << setw(12) << temp->arrivalDate
                << setw(8) << temp->confirmNum << "\n";
            counter++;
        }
        temp = temp->next;
    }

    if (counter == 0) {
        cout << "\nNo bookings with the specified hotelName found\n";
    }
    else {
        cout << "\nTotal: " << counter << " bookings found with " << hotelName << "\n";
    }
}

//Display all bookings with the specified arrival date
void LinkedList::displayBookingsByDate(string arrivalDate)
{
    //Add your own code
    //----
    HotelBooking* temp = head; 
    int counter = 0;

    while (temp != nullptr) {
        if (temp->arrivalDate == arrivalDate) {//compare by date
            cout << left << setw(18) << temp->hotelName
                << setw(12) << temp->arrivalDate
                << setw(8) << temp->confirmNum << "\n";
            counter++;
        }
        temp = temp->next;
    }

    if (counter == 0) {
        cout << "\nNo bookings with the specified date found\n";
    }
    else {
        cout << "\nTotal: " << counter << " bookings found on " << arrivalDate << "\n";
    }
}

//Returns the total number of bookings in the list
int LinkedList::countAllBookings()
{
    //Add your own code
    //----
    HotelBooking* temp = head; 
    int count = 0;//integer for counting

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

//Returns the total number of bookings by the specified hotel
int LinkedList::countBookingByHotel(string hotelName)
{
    //Add your own code
    //----
    HotelBooking* temp = head; 
    int count = 0;

    while (temp != nullptr) {
        if (temp->hotelName == hotelName) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

//Returns the total number of bookings in the list by the specified arrival date
int LinkedList::countBookingByDate(string arrivalDate)
{
    //Add your own code
    //----
    HotelBooking* temp = head; 
    int count = 0;

    while (temp != nullptr) {
        if (temp->arrivalDate == arrivalDate) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

//Cancel the specified HotelBooking from the list, releases the memory and updates pointers.
//Return true if it is successfully canceled, false otherwise.
bool LinkedList::cancelOneBooking(string hotelName, string arrivalDate, int confirmNum)
{
    //Add your own code
    //----

    if (head == nullptr) {
        return false;
    }

    HotelBooking* current = head;
    HotelBooking* previous = nullptr;

    while (current != nullptr) {//cancel one booking if find connect previous to next
        if (current->hotelName == hotelName && current->arrivalDate == arrivalDate && current->confirmNum == confirmNum) {
            if (current == head) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            delete current;//delete the current node not using
            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}

//Cancel all bookings from a specific hotel, releases the memory and updates pointers.
//Return true if it is successfully canceled, false otherwise. Note: multiple HotelBookings
//might be canceled
bool LinkedList::cancelAllBookingsByHotel(string hotelName)
{
    //Add your own code
    //----
    if (head == nullptr) {
        return false;
    }

    HotelBooking* current = head;
    HotelBooking* previous = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->hotelName == hotelName) {//checking and find every thing proper for condition and delete
            found = true;
            if (current == head) {
                head = current->next;
                delete current;
                current = head;
            }
            else {
                previous->next = current->next;
                delete current;
                current = previous->next; //found
            }
        }
        else {
            previous = current;
            current = current->next;//next one
        }
    }

    return found;
}

//Removes all HotelBookings with the specified date, releases the memory and updates pointers.
//Return true if they are successfully removed, false otherwise. Note: all HotelBookings with
//the same arrival date should be removed from the list.
bool LinkedList::cancelAllBookingsByDate(string arrivalDate)//similar but condition change to date
{
    //Add your own code
    //----
    if (head == nullptr) {
        return false;
    }

    HotelBooking* current = head;
    HotelBooking* previous = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->arrivalDate == arrivalDate) {
            found = true;
            if (current == head) {
                head = current->next;
                delete current;
                current = head; 
            }
            else {
                previous->next = current->next;
                delete current;
                current = previous->next; 
            }
        }
        else {
            previous = current;
            current = current->next;
        }
    }

    return found;
}

//Modifies the arrival date of the given booking. Return true if it modifies successfully and
//false otherwise.
bool LinkedList::delayABooking(string hotelName, string oldArrivalDate, int confirmNum, string newArrivalDate)
{
    //Add your own code
    //----
    HotelBooking* current = head;
    HotelBooking* previous = nullptr;


    while (current != nullptr) {//check is same as name or not
        if (current->hotelName == hotelName &&
            current->arrivalDate == oldArrivalDate &&
            current->confirmNum == confirmNum)
        {
 
            if (previous == nullptr) {

                head = current->next;
            }
            else {
 
                previous->next = current->next;
            }

 
            current->arrivalDate = newArrivalDate;


            HotelBooking* newNode = current;
            newNode->next = nullptr;

            if (head == nullptr || compareBookings(newNode, head) < 0) {
                newNode->next = head;
                head = newNode;
                return true;
            }

            HotelBooking* insertCurrent = head;//re-sorting
            while (insertCurrent->next != nullptr && compareBookings(newNode, insertCurrent->next) > 0) {
                insertCurrent = insertCurrent->next;
            }

            newNode->next = insertCurrent->next;
            insertCurrent->next = newNode;

            return true; 
        }

        previous = current;
        current = current->next;
    }

    return false;
}

//Change a specific booking info. If found it inside the list and change its hotelName successfully, return
//true; otherwise return false. Note: after successfully change its hotelName, the linked list must
//still be in alphabetical order
bool LinkedList::changeAHotel(string oldHotelName, string arrivalDate, int confirmNum, string newHotelName)
{
    //Add your own code
    //----
    HotelBooking* current = head;
    HotelBooking* previous = nullptr;

    while (current != nullptr) {
        if (current->hotelName == oldHotelName && current->arrivalDate == arrivalDate && current->confirmNum == confirmNum) {
            current->hotelName = newHotelName;

            if (head == nullptr || head->next == nullptr) {
                return true;
            }

            if (current == head) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            HotelBooking* newNode = current;
            newNode->next = nullptr; 

 
            HotelBooking* insertCurrent = head;
            HotelBooking* insertPrevious = nullptr;

            while (insertCurrent != nullptr && compareBookings(newNode, insertCurrent) > 0) {//resorting
                insertPrevious = insertCurrent;
                insertCurrent = insertCurrent->next;
            }

            if (insertPrevious == nullptr) {
   
                newNode->next = head;
                head = newNode;
            }
            else {
    
                newNode->next = insertCurrent;
                insertPrevious->next = newNode;
            }

            return true;
        }

        previous = current;
        current = current->next;
    }

    return false; 
}
