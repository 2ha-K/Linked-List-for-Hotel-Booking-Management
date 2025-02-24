# Linked List for Hotel Booking Management

## Overview  
This project implements a **Linked List** to manage hotel bookings efficiently.  
It supports **insertion, deletion, searching, sorting, and modification** of bookings  
while maintaining an **ordered linked list** structure.

## Features  
- **Linked List Implementation**:
  - Stores **Hotel Booking records** dynamically in a **sorted linked list**.
  - Ensures bookings are **ordered by hotel name, date, and confirmation number**.

- **Booking Operations**:
  - `addBooking` – Insert a new booking in **sorted order**.
  - `cancelOneBooking` – Remove a specific booking.
  - `searchBooking` – Check if a booking exists.
  - `displayAllBookings` – Print all bookings.
  - `displayBookingsByHotel` / `displayBookingsByDate` – Filter bookings by hotel or date.
  - `countAllBookings` / `countBookingByHotel` / `countBookingByDate` – Count bookings.
  - `cancelAllBookingsByHotel` / `cancelAllBookingsByDate` – Remove all bookings for a hotel or date.
  - `delayABooking` – Modify a booking's **arrival date** while maintaining order.
  - `changeAHotel` – Modify a booking's **hotel name** and adjust position accordingly.

- **Interactive Menu**:
  - Add, delete, print, find, modify, and cancel bookings dynamically.

## Files  
- `Assignment1.cpp` – Main program that handles user input and executes linked list operations.  
- `LinkedList.h` – Implements the **Linked List structure and its operations**.

## Compilation & Execution  
### **1. Compile the program:**  
```bash
g++ Assignment1.cpp -o Assignment1
