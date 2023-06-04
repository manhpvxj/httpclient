#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include "tcpsocket.h"
#include <fstream>

class TcpClient
{
protected:

    bool connected;
public:
    TcpSocket localsocket;
    TcpClient();
    ~TcpClient();
    bool isConnected() { return connected;}
    bool open(const string& serverHost, unsigned short port);
    bool open(const string& serverHost, const string& port);
    void close();
protected:
    int sendStringRequest(const string& request);
    int sendDataBuffer(const char* buffer, unsigned int bufLen);
    int recvGetLine(char* buf,unsigned int maxLen);
    int recvDataBuffer(char* buffer, unsigned int bufLen);
    void print(const string& msg);
    void printLn(const string& msg);
private:

};
#endif // _TCP_CLIENT_H_
