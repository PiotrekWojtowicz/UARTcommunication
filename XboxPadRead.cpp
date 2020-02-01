#include "XboxPadRead.h"

void checkPad(XINPUT_STATE& stan) noexcept(false)
{
	try
	{
		for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
		{
			ZeroMemory(&stan, sizeof(XINPUT_STATE));
			rezultat = XInputGetState(i, &stan);
			if (rezultat == ERROR_SUCCESS)
			{
				std::cout << "Pad: " << ++padN << " jest aktywny!\t Status: ON\n";
			}
			else
			{
				std::cout << "Blad przy polaczeniu pada nr: " << i << std::endl;
			}
		}
		if (padN < 0)
			throw false;
	}
	catch (bool V)
	{
		std::cout << "Nie polaczono z zadnym padem!\t Operation status: " << V;
	}
}

void deadzone(XINPUT_STATE* wsk) noexcept
{
	float LX = (*wsk).Gamepad.sThumbLX;
	float LY = (*wsk).Gamepad.sThumbLY;

	float RX = (*wsk).Gamepad.sThumbRX;
	float RY = (*wsk).Gamepad.sThumbRY;

	float pointLength = sqrt(LX * LX + LY * LY);
	float pointLengthR = sqrt(RY * RY + RX * RX);

	float LXfixed = LX / pointLength;
	float LYfixed = LY / pointLength;

	float RXfixed = RX / pointLengthR;
	float RYfixed = RY / pointLengthR;


	float normalizedPointLength = 0;

	if (pointLength > INPUT_DEADZONE)
	{
		if (pointLength > 32767) pointLength = 32767;

		pointLength -= INPUT_DEADZONE;
		normalizedPointLength = pointLength / (32767 - INPUT_DEADZONE);
	}
	else
	{
		pointLength = 0.0;
		normalizedPointLength = 0.0;
		(*wsk).Gamepad.sThumbLX = LXfixed;
		(*wsk).Gamepad.sThumbLY = LYfixed;
	}
	if (pointLengthR > INPUT_DEADZONE)
	{
		if (pointLengthR > 32767) pointLengthR = 32767;

		pointLengthR -= INPUT_DEADZONE;
		normalizedPointLength = pointLengthR / (32767 - INPUT_DEADZONE);
	}
	else
	{
		pointLengthR = 0.0;
		normalizedPointLength = 0.0;
		(*wsk).Gamepad.sThumbRX = RXfixed;
		(*wsk).Gamepad.sThumbRY = RYfixed;
	}
	(*wsk).Gamepad.sThumbRX = ((*wsk).Gamepad.sThumbRX) / 128;
	(*wsk).Gamepad.sThumbRY = ((*wsk).Gamepad.sThumbRY) / 128;
	(*wsk).Gamepad.sThumbLX = ((*wsk).Gamepad.sThumbLX) / 128;
	(*wsk).Gamepad.sThumbLY = ((*wsk).Gamepad.sThumbLY) / 128;
}
void showVal(XINPUT_STATE& stan) noexcept
{
	while (true) {
		system("CLS");
		std::cout << "Btn \t LT \t RT \t LX \t LY \t RX \t RY \t\n";
		std::cout << stan.Gamepad.wButtons << "\t" << stan.Gamepad.bLeftTrigger << "\t" <<
			stan.Gamepad.bRightTrigger << "\t" << stan.Gamepad.sThumbLX << "\t" << stan.Gamepad.sThumbLY <<
			"\t" << stan.Gamepad.sThumbRX << "\t" << stan.Gamepad.sThumbRY << '\n';
		Sleep(10);
		ZeroMemory(&stan, sizeof(XINPUT_STATE));
		rezultat = XInputGetState(0, &stan);
		deadzone(&stan);
	}
}