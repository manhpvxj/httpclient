#ifndef HTTPTCPCLIENT_H_INCLUDED
#define HTTPTCPCLIENT_H_INCLUDED

#include "tcpclient.h"

class HttpClient: public TcpClient
{
private:
    TcpClient tcp;
public:
    void head(const string& hostname);
    void post(const string& hostname, const string& data);
    void putFile(const string& hostname, const string& fileName, const string& fileContent );
};


#endif // ECHOTCPCLIENT_H_INCLUDED

