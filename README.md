## Table of Contents
- [Introduction](#introduction)
- [Hotel Management System Overview](#hotel-management-system-overview)
- [Main Functionality](#main-functionality)
- [Registration and Login](#registration-and-login)
- [Room Availability](#room-availability)
- [Reservation System](#reservation-system)
- [Booking Management](#booking-management)
- [Utility Functions](#utility-functions)
- [File Handling](#file-handling)
- [Conclusion](#conclusion)
- [Contact](#contact)

## Introduction
Assalam o Alaikum!

My name is Muhammad Hamza, and I am currently pursuing a Bachelor’s degree in Computer Science at FAST NUCES, Pakistan.

## Hotel Management System Overview
This project implements a basic hotel booking system using C. It includes functionalities such as:
1. Registration and login
2. Room availability checking
3. Reservation
4. Booking management

The system uses file handling to store user data.

## Main Functionality
The code begins by including necessary header files:
1. `<stdio.h>`
2. `<time.h>`
3. `<stdlib.h>`
4. `<unistd.h>`
5. `<string.h>`

Function prototypes are declared at the start to provide an overview of the available functions.

## Registration and Login
In the `main()` function, users are welcomed and presented with options:
1. Logging in
2. Registering as a new user
3. Exiting the program

The `registered()` function handles the login by checking the email and password against stored data in `customerInfo.txt`. For new users, the `new()` function helps them register by generating a random password, ensuring valid email input, and storing the data.

## Room Availability
Room availability includes the following types:
1. Single
2. Double
3. Suite

It is handled by the `availability()` function.

## Reservation System
Users can make reservations in the `reservation()` function, where they specify room type, number of rooms, people, and nights of stay. The program calculates the cost and updates availability accordingly.

## Booking Management
The `manage()` function allows users to view their booking details, such as the number of rooms booked, nights stayed, and total price. It also provides an option to make another reservation or return to the main menu.

## Utility Functions
Several utility functions help with email validation, password generation, and updating user room data.

## File Handling
All data is managed using files to ensure persistence across sessions.

## Conclusion
This hotel booking management system offers a simple yet functional approach to managing user registration, reservation, and booking using C and file handling.

## Contact
Thank you for taking the time to review my project. I appreciate your feedback and suggestions. If you have any further questions or comments, feel free to reach out. I look forward to improving and learning more in this journey!

Email: [p230577@cfd.nu.edu.pk](mailto:p230577@cfd.nu.edu.pk)

Have a great day ahead!
