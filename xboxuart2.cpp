#include <iostream>
#include"serialport.h"
#include "XboxPadRead.h"
#include<string>
#include<stdlib.h>
#include <Windows.h>
#include <Xinput.h>
#include "CurrentConnection.h"

using namespace std;
const char* port = "\\\\.\\COM5";
XINPUT_STATE stan;
SerialPort arduino(port);
string command;

int main()
{
	checkPad(stan);
	deadzone(&stan);
	//showVal(stan);
	ConnectionCheck(arduino);

	while (arduino.isConnected())
	{
		command = PadControl(stan);
		
		while(command == "F")
		{
				char* charArray = new char[command.size()];
				copy(command.begin(), command.end(), charArray);
				//charArray[command.size()] = '\n';
				arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
				if (arduino.readSerialPort(output, MAX_DATA_LENGTH));
				cout << output << endl;
				delete[]charArray;
			command = " ";
		}
	}
	
	/*	while (arduino.isConnected())
		{
			cout << PadControl(stan) << endl;
		
//if (stan.Gamepad.wButtons == 32)
//{
//	command = "ok";
//	char* charArray = new char[command.size() + 1];
//	copy(command.begin(), command.end(), charArray);
//	charArray[command.size()] = '\n';
//	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
//	Sleep(100);
//	cout << "ok" << endl;
//	//if (arduino.readSerialPort(output, MAX_DATA_LENGTH));
//	//cout << output << endl;
//	//delete[] charArray;
//}
//else if (stan.Gamepad.sThumbLY > 50)
//{
//	command = "no";
//	char* charArray = new char[command.size() + 1];
//	copy(command.begin(), command.end(), charArray);
//	charArray[command.size()] = '\n';
//	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
//	Sleep(100);
//	if (arduino.readSerialPort(output, MAX_DATA_LENGTH))
//		cout << output << endl;
//	delete[] charArray;
//}

		}*/
	return 0;
}
