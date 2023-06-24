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
};


#endif // ECHOTCPCLIENT_H_INCLUDED

