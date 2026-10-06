#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

using namespace std;

int main()
{
    // 1. Create client socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket < 0)
    {
        cout << "Client socket creation failed!" << endl;
        return 1;
    }

    cout << "Client socket created successfully!" << endl;


    // 2. Create server address
    sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");


    // 3. Connect to server
    if (connect(clientSocket, (sockaddr*)&serverAddress,
                sizeof(serverAddress)) < 0)
    {
        cout << "Connection failed!" << endl;
        return 1;
    }

    cout << "Connected to server!" << endl;


    // 4. Send message to server
    const char* message = "Hello Server!";

    send(clientSocket, message, strlen(message), 0);

    cout << "Message sent to server!" << endl;


    // 5. Receive response from server
    char buffer[1024] = {0};

    recv(clientSocket, buffer, sizeof(buffer), 0);

    cout << "Message from server: " << buffer << endl;


    // 6. Close socket
    close(clientSocket);

    return 0;
}