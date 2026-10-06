#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>

using namespace std;

int main()
{
    // 1. Create server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0)
    {
        cout << "Socket creation failed!" << endl;
        return 1;
    }

    cout << "Socket is created successfully!" << endl;


    // 2. Create server address
    sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);


    // 3. Bind socket to IP address and port
    if (bind(serverSocket, (sockaddr*)&serverAddress,
             sizeof(serverAddress)) < 0)
    {
        cout << "Bind failed!" << endl;
        return 1;
    }

    cout << "Bind is successful!" << endl;


    // 4. Start listening for clients
    if (listen(serverSocket, 5) < 0)
    {
        cout << "Listen failed!" << endl;
        return 1;
    }

    cout << "Listen successful!" << endl;


    // 5. Accept a client connection
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    if (clientSocket < 0)
    {
        cout << "Accept failed!" << endl;
        return 1;
    }

    cout << "Client connected!" << endl;


    // 6. Receive message from client
    char buffer[1024] = {0};

    recv(clientSocket, buffer, sizeof(buffer), 0);

    cout << "Message from client: " << buffer << endl;


    // 7. Send response to client
    const char* response = "Hello Client!";

    send(clientSocket, response, strlen(response), 0);

    cout << "Response sent to client!" << endl;


    // 8. Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}