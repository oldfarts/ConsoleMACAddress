#include "stdafx.h"

#include <stdio.h>
#include <string.h>

#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>
#include <string.h>
#pragma comment(lib, "iphlpapi.lib")


#include <iostream>
#include "Serial.h"


#pragma warning(disable : 4996)


int main() {
    string com;
    cout << "Give COM port for connection: " << endl;
    cin >> com;
    CSerial serial;
    if (com == "COM5") {
        serial.Open(_T("COM5"), GENERIC_READ);
    }
    else {
        cout << "Not correct COM port" << endl;
        exit(0);
    }
    if (!serial.IsOpen()) {
        printf("Serial is not open.");
        exit(0);
    }
    // Setup the serial port (9600,N81) using hardware handshaking
    serial.Setup(CSerial::EBaud115200, CSerial::EData8, CSerial::EParNone, CSerial::EStop1);
    serial.SetupHandshaking(CSerial::EHandshakeHardware);
    serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);
    while (1)
    {
        DWORD dwBytesRead = 100;
        BYTE  abBuffer[100];
            do
        {
                // Read data from the COM-port (COM5 port manually set)
                serial.Read(abBuffer, sizeof(abBuffer), &dwBytesRead);
                    //unsigned con[6];
                    string mac((char*)abBuffer);
                    if (!mac.empty()) {
                        cout << "Mac: " << mac << endl;
                    }
                    /*int c = sscanf(mac.c_str(), "%x %x %x %x %x %x", 
                        con, con + 1, con + 2, con + 3, con + 4, con + 5);

                    printf("mac: %s\n", mac);*/
                    Sleep(2000);
            } while (dwBytesRead == sizeof(abBuffer));
    }
    serial.Close();

}

