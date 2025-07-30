#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "operations .h"
using namespace std;
int main(int argc, char** argv) {
    check_valid_arg(argc, argv, 3,"<username> <password>");
    const string username{argv[1]};
    const string password{argv[2]};
    password_analysis(username,password);
    return 0;

}