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
        char buffer[62];
        int byte_recive = recvGetLine(buffer, sizeof(buffer));
        string response;

        while(byte_recive > 0) {
            response = response + buffer + "\n";
            byte_recive = recvGetLine(buffer, sizeof(buffer));
        }
        print(response);
    }
}

void HttpClient::putFile(const string& hostname, const string& fileName, const string& fileContent)
{
    string request;
    request = "PUT /api/file HTTP/1.1\r\n";
    request = request + "Host: " + hostname + "\r\n";
    request = request + "Access-Control-Allow-Origin: *\r\n";
    request = request + "Content-Type: multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW\r\n\r\n";
    request = request + "------WebKitFormBoundary7MA4YWxkTrZu0gW\r\n";
    request = request + "Content-Disposition: form-data; name=\"file\"; filename=\"test.txt\"\r\n";
    request = request + "Content-Type: text/plain\r\n\r\n";
    request = request + fileContent + "\r\n";
    request = request + "------WebKitFormBoundary7MA4YWxkTrZu0gW--\r\n\r\n";

    print(request);
    int byte_sent = sendStringRequest(request);
    if(byte_sent > 0) {
        char buffer[31];
        int byte_recive = recvGetLine(buffer, sizeof(buffer));
        string response;

        while(byte_recive > 0) {
            response = response + buffer + "\n";
            byte_recive = recvGetLine(buffer, sizeof(buffer));
        }
        print(response);
    }
}





