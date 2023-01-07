# minitalk

This project involves creating a communication program that consists of a client and a server.

The communication between the client and server must be done using UNIX signals only, specifically SIGUSR1 and SIGUSR2. The server will acknowledge every message received by sending a signal back to the client. The program should support Unicode characters

The server must be started first and will print its PID after launch. 
The client takes two parameters: the PID of the server, and a string to send to the server. 
The client will send the specified string to the server, and the server will quickly print the received string. 
The server should be able to receive strings from multiple clients in succession without needing to be restarted. 
