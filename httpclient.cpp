#include "httpclient.h"
#include <iostream>

void HttpClient::head(const string& hostname)
{
    // add code here
    string request;

    request = "HEAD /api HTTP/1.1\r\n";
    request = request + "Host: " + hostname + "\r\n";
    request = request + "User-Agent: Simple HTTP Client version 1.0\r\n";
    request = request + "Connection: keep-alive\r\n";
    request = request + "Keep-Alive: timeout=60\r\n\r\n";

    int byte_sent = sendStringRequest(request);
    if(byte_sent > 0) {
        char buffer[52];

        int byte_recive = recvGetLine(buffer, sizeof(buffer));
        string response;

        while(byte_recive > 0) {
            response = response + buffer + "\n";
            byte_recive = recvGetLine(buffer, sizeof(buffer));
        }
        print(response);
    }
}

void HttpClient::post(const string& hostname, const string& data)
{
    // add code here
    print("status: " + tcp.isConnected());
    string request;
    request = "POST /api/" + data + " HTTP/1.1\r\n";
    request = request + "Host: " + hostname + "\r\n";
    request = request + "Access-Control-Allow-Origin: *\r\n";
    request = request + "User-Agent: Simple HTTP Client version 2.0\r\n";
    request = request + "Content-Type: application/json\r\n";
    request = request + "Connection: keep-alive\r\n";
    request = request + "Keep-Alive: 60\r\n\r\n";
    int byte_sent = sendStringRequest(request);
    if(byte_sent > 0) {
        char buffer[52];
        int byte_recive = recvGetLine(buffer, sizeof(buffer));
        string response;

        while(byte_recive > 0) {
            response = response + buffer + "\n";
            byte_recive = recvGetLine(buffer, sizeof(buffer));
        }
        print(response);
    }
}





