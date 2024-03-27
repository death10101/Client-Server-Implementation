**TCP Socket Communication for Summation: Client-Server Implementation**

**Overview**
This project implements a simple client-server communication system using TCP sockets to perform summation. The client program sends two integers to the server, which calculates their sum and returns the result to the client. Both the client and server programs specify their respective IP addresses and ports for communication.

**Features**

Client Program:
Accepts two integers as input arguments or at runtime.
Establishes a TCP connection with the server.
Sends the integers to the server.
Receives the summation result from the server.
Displays the result to the user.

Server Program:
Listens for incoming TCP connections.
Receives two integers from the client.
Calculates the sum of the integers.
Sends the result back to the client.
Supports concurrent connections from multiple clients.

**Getting Started**
1. Clone the Repository:

  git clone https://github.com/death10101/Client-Server-Implementation.git

2. Compile the Programs:

  gcc client_add.c -o client_add
  gcc server_add.c -o server_add

3. Run the Server:

  ./server_add

4. Run the Client:

  ./client_add <num1> <num2>

5. Replace <num1> and <num2> with the integers you want to sum.

6. View the Result:

  The client program will display the sum received from the server.
  
**Notes**
-Make sure to specify the correct IP addresses and ports for the client and server in the source code before compiling.
-This project assumes that the client and server are running on the same machine for testing purposes. Modify the IP addresses and ports accordingly for remote communication.
-Error handling and input validation have been kept minimal for simplicity. It's recommended to enhance the error handling as per your requirements.

**License**
This project is licensed under the MIT License - see the LICENSE file for details.
