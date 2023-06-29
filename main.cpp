#include <iostream>
#include "httpcli.h"

using namespace std;

int main()
{
    cout << "Simple HTTP Client ver 2.0" << endl;
    HttpClientCLI cli;
    cli.run();
    return 0;
}
