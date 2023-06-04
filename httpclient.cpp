#include "httpclient.h"
#include <iostream>

void HttpClient::head(const string& hostname, const string& url)
{
    // add code here
    string request;

    request = "HEAD " + url + " HTTP/1.1\r\n";
    request = request + "Host: " + hostname + "\r\n";
    request = request + "User-Agent: Simple HTTP Client version 1.0\r\n";
    request = request + "Connection: close\r\n\r\n";

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

void HttpClient::post(const string& hostname, const string& url, const string& data)
{
    // add code here
    string request;
    request = "POST " + url + "/" + data + " HTTP/1.1\r\n";
    request = request + "Host: " + hostname + "\r\n";
    request = request + "User-Agent: Simple HTTP Client version 1.0\r\n";
    request = request + "Connection: close\r\n";
    print(request);
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



