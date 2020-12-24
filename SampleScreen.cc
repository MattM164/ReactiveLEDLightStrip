#include "pch.h"
#include <iostream>
#include "ArduSerial.h"
#include <windows.h>
#include <string>
#include <vector>
#include <numeric>

#include <stdio.h>

typedef WINAPI COLORREF (*GETPIXEL)(HDC, int, int);

std::string data = "-1";
std::string package = "";
int pix = 0;


int ared1 = 0;
int agreen1 = 0;
int ablue1 = 0;

int ared2 = 0;
int agreen2 = 0;
int ablue2 = 0;

int ared3 = 0;
int agreen3 = 0;
int ablue3 = 0;


std::string red ="";
std::string green ="";
std::string blue ="";

std::string red1 ="";
std::string green1 ="";
std::string blue1 ="";

std::string red2 ="";
std::string green2 ="";
std::string blue2 ="";

std::string red3 ="";
std::string green3 ="";
std::string blue3 ="";

int ared = 0;
int agreen = 0;
int ablue = 0;


void setup()
{
	// Serial27 means access Arduino on COM27 ***************
	Serial4.begin(9600);//9600

	std::cout << "Starting..." << std::endl;

	//while (!Serial4);

	//while (Serial4.available())
		//Serial4.read();

	std::cout << "Connected" << std::endl;
}




void loop(){
	std::cout << "Sending data: " << data << std::endl;
	Serial4.println(data + "\n");

	std::cout << "Looking for echo..." << std::endl;
	while (Serial4.available() < data.length());

	std::cout << "Found the following echo:" << std::endl;
		while (Serial4.available())
		printf("%c", Serial4.read());

	//std::cout << std::endl << "Waiting before transmitting again..." << std::endl;
	//Sleep(1000);
}




int main()
{

	//string data = "";

	HINSTANCE _hGDI = LoadLibrary("gdi32.dll");


	setup();

	if(_hGDI){
	while (true){



		GETPIXEL pGetPixel = (GETPIXEL)GetProcAddress(_hGDI, "GetPixel");
		HDC _hdc = GetDC(NULL);
		if(_hdc)
		{
				//POINT _cursor;
				//GetCursorPos(&_cursor);
				int startPixel = 0; //960 is halway
				int yPixel = 300; //320
				int lengthOfPixels = 4;
				int pixelOffset = 120;

				//for (size_t i = 0; i < lengthOfPixels; i++) {

					std::vector<int> reds;
					std::vector<int> greens;
					std::vector<int> blues;

					COLORREF _color = (*pGetPixel) (_hdc, 320, yPixel);//320
					COLORREF _color1 = (*pGetPixel) (_hdc, 640, yPixel);//640
					COLORREF _color2 = (*pGetPixel) (_hdc, 960, yPixel);//960
					COLORREF _color3 = (*pGetPixel) (_hdc, 1280, yPixel);//1280

					ared = GetRValue(_color);
					agreen = GetGValue(_color);
					ablue = GetBValue(_color);


					ared1 = GetRValue(_color1);
					agreen1 = GetGValue(_color1);
					ablue1 = GetBValue(_color1);

					ared2 = GetRValue(_color2);
					agreen2 = GetGValue(_color2);
					ablue2 = GetBValue(_color2);

					ared3 = GetRValue(_color3);
					agreen3 = GetGValue(_color3);
					ablue3 = GetBValue(_color3);


				  /*
					reds.push_back(ared);
					greens.push_back(agreen);
					blues.push_back(ablue);

					reds.push_back(ared1);
					greens.push_back(agreen1);
					blues.push_back(ablue1);
					reds.push_back(ared2);
					greens.push_back(agreen2);
					blues.push_back(ablue2);
					reds.push_back(ared3);
					greens.push_back(agreen3);
					blues.push_back(ablue3);

					float redaverage = std::accumulate( reds.begin(), reds.end(), 0.0)/reds.size();
					float greenaverage = std::accumulate( greens.begin(), greens.end(), 0.0)/greens.size();
					float blueaverage = std::accumulate( blues.begin(), blues.end(), 0.0)/blues.size();


						//std::cout << reds[0] << std::endl;


					ared = redaverage;
					agreen = greenaverage;
					ablue = blueaverage;
					*/


				//}

//////////////FinalValues
				int _red = ared;
				int _green = agreen;
				int _blue = ablue;

				int _red1 = ared1;
				int _green1 = agreen1;
				int _blue1 = ablue1;
				int _red2 = ared2;
				int _green2 = agreen2;
				int _blue2 = ablue2;
				int _red3 = ared3;
				int _green3 = agreen3;
				int _blue3 = ablue3;

				/////////


					if(_red < 10){
						red = std::to_string(_red) + "--";
					}else if(_red >= 10 && _red < 100){
						red = std::to_string(_red) + "-";
					}else if(_red >= 100){
						red = std::to_string(_red);
					}
					if(_green < 10){
						green = std::to_string(_green) + "--";
					}else if(_green >= 10 && _green < 100){
						green = std::to_string(_green) + "-";
					}else if(_green >= 100){
						green = std::to_string(_green);
					}
					if(_blue < 10){
						blue = std::to_string(_blue) + "--";
					}else if(_blue >= 10 && _blue < 100){
						blue = std::to_string(_blue) + "-";
					}else if(_blue >= 100){
						blue = std::to_string(_blue);
					}


					if(_red1 < 10){
						red1 = std::to_string(_red1) + "--";
					}else if(_red1 >= 10 && _red1 < 100){
						red1 = std::to_string(_red1) + "-";
					}else if(_red1 >= 100){
						red1 = std::to_string(_red1);
					}
					if(_green1 < 10){
						green1 = std::to_string(_green1) + "--";
					}else if(_green1 >= 10 && _green1 < 100){
						green1 = std::to_string(_green1) + "-";
					}else if(_green1 >= 100){
						green1 = std::to_string(_green1);
					}
					if(_blue1 < 10){
						blue1 = std::to_string(_blue1) + "--";
					}else if(_blue1 >= 10 && _blue1 < 100){
						blue1 = std::to_string(_blue1) + "-";
					}else if(_blue1 >= 100){
						blue1 = std::to_string(_blue1);
					}

					if(_red2 < 10){
						red2 = std::to_string(_red2) + "--";
					}else if(_red2 >= 10 && _red2 < 100){
						red2 = std::to_string(_red2) + "-";
					}else if(_red2 >= 100){
						red2 = std::to_string(_red2);
					}
					if(_green2 < 10){
						green2 = std::to_string(_green2) + "--";
					}else if(_green2 >= 10 && _green2 < 100){
						green2 = std::to_string(_green2) + "-";
					}else if(_green2 >= 100){
						green2 = std::to_string(_green2);
					}
					if(_blue2 < 10){
						blue2 = std::to_string(_blue2) + "--";
					}else if(_blue2 >= 10 && _blue2 < 100){
						blue2 = std::to_string(_blue2) + "-";
					}else if(_blue2 >= 100){
						blue2 = std::to_string(_blue2);
					}

					if(_red3 < 10){
						red3 = std::to_string(_red3) + "--";
					}else if(_red3 >= 10 && _red3 < 100){
						red3 = std::to_string(_red3) + "-";
					}else if(_red3 >= 100){
						red3 = std::to_string(_red3);
					}
					if(_green3 < 10){
						green3 = std::to_string(_green3) + "--";
					}else if(_green3 >= 10 && _green3 < 100){
						green3 = std::to_string(_green3) + "-";
					}else if(_green3 >= 100){
						green3 = std::to_string(_green3);
					}
					if(_blue3 < 10){
						blue3 = std::to_string(_blue3) + "--";
					}else if(_blue3 >= 10 && _blue3 < 100){
						blue3 = std::to_string(_blue3) + "-";
					}else if(_blue3 >= 100){
						blue3 = std::to_string(_blue3);
					}


				//data = std::to_string(_red) + " " + std::to_string(_green) + " " + std::to_string(_blue);
				data = red + " " + green + " " + blue +  " " + red1 + " " + green1 + " " + blue1 +  " " + red2 + " " + green2 + " " + blue2 +  " " + red3 + " " + green3 + " " + blue3 +  " ";// + '\n';
				//package = "echo " + data + " > COM5";
				//////////////////////This can be deleted without destroying everything, might not work//
				char * sendData = new char[package.size() + 1];
				copy(package.begin(), package.end(), sendData);
				sendData[package.size()] = '\0';
				/////////////////////////////////////////////////////////////////////////////////////////
				system(sendData);
				delete[] sendData;

				//system("CLS");

				printf("Red: 0x%02x\n", _red);
				printf("Green: 0x%02x\n", _green);
				printf("Blue: 0x%02x\n", _blue);
				std::cout << "Data to send: " << data << std::endl;


		}
		FreeLibrary(_hGDI);
		//Sleep(1000);            /////////////////////////////////Sleep, Just in case/////////////////




		//data = std::to_string(pix);
		//loop();
		Serial4.println(data);
		std::cout << data << std::endl;
		//Sleep(25);

	}
}

	return 0;
}
