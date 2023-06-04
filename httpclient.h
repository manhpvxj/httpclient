#ifndef HTTPTCPCLIENT_H_INCLUDED
#define HTTPTCPCLIENT_H_INCLUDED

#include "tcpclient.h"

class HttpClient: public TcpClient
{
private:
public:
    void head(const string& hostname, const string& url);
    void post(const string& hostname, const string& url, const string& data);
};


#endif // ECHOTCPCLIENT_H_INCLUDED

