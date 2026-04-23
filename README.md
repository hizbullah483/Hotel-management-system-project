this was my first semester programming fundamentals project. 

Hotel Room Booking System (C)

A lightweight console-based hotel management system written in **C**. Users can book available rooms, set a checkout password, and later check out by providing the correct password. Room information is stored in a plain text file for persistence.

Note: This is a basic academic-style project. The current implementation uses the room's `isavailable` field to store both availability (1 = free) and a numeric password (when booked). Customer management functions are defined but not yet integrated into the main flow.

Features

- Display room details (number, price, type, availability)
- Load/save room data from/into `rooms.txt`
- Book a room – sets a numeric password and marks it as occupied
- Check out of a room – requires correct password to free the room
- File-based storage (no external database needed)

How to Compile & Run

Compile
Use any C compiler (e.g., `gcc`):
gcc hotel.c -o hotel

Run
./hotel


Make sure rooms.txt exists in the same directory (the program will create it if missing, but pre‑populating it is recommended. see File Format below).

File Format

rooms.txt

Each line represents one room:
room_number room_cost room_type is_available

Example:

101 100.00 D 1
102 150.00 S 0

· room_number : integer 
· room_cost   : float
· room_type   : single character (e.g. D for Double, S for Single)
· is_available: integer – 1 means free, any other number is treated as a password (room booked)

The program currently supports up to 100 rooms.

Usage Example

1. First run – rooms.txt may be empty or missing. The program will still run but you won’t see any rooms.
      Prepare a sample rooms.txt:
   101 120.00 D 1
   102 140.00 D 1
   201 180.00 S 1
   
2. Book a room
   enter room that you want to book
   101
   set up password for the room
   1234
   room booked successfully
  
3. Check out
   enter room that you want to check out of
   101
   enter password
   1234
   room checked out of successfully

Limitations
· Password is stored as an integer (weak security)
· No input validation (e.g non numeric input may crash the program)
· Room data is overwritten each time – concurrency not handled
· Room type uses a single character only



fun fact: I coded this project over the course of a few weeks on an android C compiler during breaks between university classes
