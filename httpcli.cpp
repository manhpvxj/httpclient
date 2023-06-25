#include "httpcli.h"
#include <iostream>


HttpClientCLI::HttpClientCLI():CmdLineInterface(">")
{
    initCmd();
}

HttpClientCLI::~HttpClientCLI()
{
}


void HttpClientCLI::initCmd()
{
   addCmd("help",CLI_CAST(HttpClientCLI::doHelp));
   // add code here
    addCmd("open", CLI_CAST(HttpClientCLI::doOpen));
    addCmd("head", CLI_CAST(HttpClientCLI::doHead));
    addCmd("close", CLI_CAST(HttpClientCLI::doClose));
    addCmd("post", CLI_CAST(HttpClientCLI::doPost));
    addCmd("put", CLI_CAST(HttpClientCLI::doPut));

}

/*
   open hostname [port]

*/
void HttpClientCLI::doOpen(string cmd_argv[], int cmd_argc)
{
    if(cmd_argc==3)
    {
         // add code
         bool ok = client.open(cmd_argv[1], cmd_argv[2]);
         if (ok) {
            cout <<  "Ket noi thanh cong." << endl;
         }

    }
    else if(cmd_argc==2)
    {
         // add code
         bool ok =  client.open(cmd_argv[1], "http");
         if (ok) {
            cout << "Ket noi thanh cong." << endl;
         }

    }
    else
    {
        cout << "Lenh open khong dung." << endl;
    }
}

void HttpClientCLI::doClose(string cmd_argv[], int cmd_argc)
{
    // add code
    if(client.isConnected()) {
        client.close();
    }
    cout << "Da dong ket noi." << endl;
}

/*
    echo [msg]
*/

void HttpClientCLI::doHead(string cmd_argv[], int cmd_argc)
{
    string resp;
    if(!client.isConnected()) {
           cout << "Chua ket noi toi server." << endl;
           return;
    }
    else if(cmd_argc == 1)
    {
        // add code here
        string hostname = client.localsocket.getHostname();
        client.head(hostname);
    }
    else
    {
        cout << "Error: lenh head khong dung." << endl;
    }
}

void HttpClientCLI::doPost(string cmd_argv[], int cmd_argc)
{
    string mssv;
    string hostname = client.localsocket.getHostname();
    cout << "MSSV: ";
    cin >> mssv;
    client.post(hostname, mssv);
}

void HttpClientCLI::doPut(string cmd_argv[], int cmd_argc)
{

    string fileName;
    string hostname = client.localsocket.getHostname();
    cout<< "Nhap vao ten file: ";
    cin >> fileName;
    string fileDirectory = "C:\\Users\\User\\Desktop\\" + fileName;
    FILE* file = fopen(fileDirectory.c_str(), "r");
    if(file != NULL) {
        client.putFile(hostname, fileDirectory, file);
        fclose(file);
    } else {
        cout << "ERROR: Khong tim thay file" << endl;
    }
}

void HttpClientCLI::doHelp(string cmd_argv[], int cmd_argc)
{
    cout << "Please use the following commands:" << endl;
    cout << "- open  hostname [port]   Mo ket noi den Http server" << endl;
    cout << "- head [url]              Gui yeu cau voi phuong thuc HEAD" << endl;
    cout << "- post                    Gui yeu cau voi phuong thuc POST" << endl;
    cout << "- put                     Gui file voi phuong thuc PUT" << endl;
    cout << "- close                   Dong ket noi" << endl;
    cout << "- help                    Tro giup" << endl;
    cout << "- quit                    Ket thuc chuong trinh" << endl;
}


