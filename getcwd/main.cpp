#include <iostream>
#include <windows.h>
#include <unistd.h>

#ifndef MAXPATHLEN
#define MAXPATHLEN 2048
#endif // MAXPATHLEN

using namespace std;

std::string get_working_path();

int main()
{
    std::string path = get_working_path();

    cout << "Current Path: " << path << endl;

    return 0;
}

std::string get_working_path()
{
   char temp[MAXPATHLEN];
   return ( getcwd(temp, MAXPATHLEN) ? std::string( temp ) : std::string("") );
}
