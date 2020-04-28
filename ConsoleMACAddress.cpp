#include "stdafx.h"

#include <stdio.h>
#include <string.h>

#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>
#include <string.h>
#pragma comment(lib, "iphlpapi.lib")

#include <Windows.h>
#include <rpc.h>
#include <rpcdce.h>
#pragma comment(lib, "rpcrt4.lib")
using namespace std;


#include <stdio.h>
#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>
#pragma comment(lib, "iphlpapi.lib")

#include <iostream>
#include <string>
#include <cstring>
#include <atlstr.h>
#include "Serial.h"

//#include "afxwin.h"
//#include "pch.h"
#include <windows.h>

#pragma warning(disable : 4996)


int main() {
    CSerial serial;
    serial.Open(_T("COM5"),GENERIC_READ);
    if (!serial.IsOpen()) {
        printf("Serial is not open.");
        exit(0);
    }
    // Setup the serial port (9600,N81) using hardware handshaking
    serial.Setup(CSerial::EBaud9600, CSerial::EData8, CSerial::EParNone, CSerial::EStop1);
    serial.SetupHandshaking(CSerial::EHandshakeHardware);
    serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);
    while (1)
    {
        //int byData = ReadByte(port);
        //cout << ":" << byData;
        //Sleep(1000);
        DWORD dwBytesRead = 18;
        BYTE  abBuffer[18];
            do
        {
            // Read data from the COM-port
                serial.Read(abBuffer, sizeof(abBuffer), &dwBytesRead);
                    unsigned con[6];
                    string mac((char*)abBuffer);
                    if (!mac.empty()) {
                        cout << "Mac: " << mac << endl;
                      //  Sleep(3000);
                    }
                    /*int c = sscanf(mac.c_str(), "%x %x %x %x %x %x", 
                        con, con + 1, con + 2, con + 3, con + 4, con + 5);

                    printf("mac: %s\n", mac);*/
                    Sleep(2000);
            } while (dwBytesRead == sizeof(abBuffer));
    }
    serial.Close();

}

