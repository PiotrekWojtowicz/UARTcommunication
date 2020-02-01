#include "CurrentConnection.h"


void ConnectionCheck(SerialPort& arduino)
{
	if (arduino.isConnected())
	{
		std::cout << "Jest polaczone\n";
	}
	else
	{
		std::cout << "Error\n";
	}
}
std::string Packaging(std::string command)
{
	return command;
}
std::string PadControl(XINPUT_STATE &stan)
{
	ZeroMemory(&stan, sizeof(XINPUT_STATE));
	rezultat = XInputGetState(0, &stan);
	deadzone(&stan);
	if (stan.Gamepad.wButtons == 4096)
		return Packaging("K");
	try
	{
		if ((stan.Gamepad.sThumbLX > m_SMALL && stan.Gamepad.sThumbLX < SMALL) && 
			(stan.Gamepad.sThumbLY > m_SMALL && stan.Gamepad.sThumbLY < SMALL)) //deadzone
			throw true;

		if (stan.Gamepad.sThumbLX < ANGLE && stan.Gamepad.sThumbLX > m_ANGLE)
		{
			if (stan.Gamepad.sThumbLY > ZERO && stan.Gamepad.sThumbLY < MEDIUM) // bieg 1
			{
				return Packaging("F");
			}
			else if (stan.Gamepad.sThumbLY > MEDIUM) // bieg 2
			{
				return Packaging("S");
			}
			else if (stan.Gamepad.sThumbLY <ZERO && stan.Gamepad.sThumbLY > m_MEDIUM) // bieg -1
			{
				return Packaging("B");
			}
			else if (stan.Gamepad.sThumbLY < m_MEDIUM) // bieg -2
			{
				return Packaging("O");
			}
		}
		else if (stan.Gamepad.sThumbLX > ANGLE) // skret w prawo
		{
			return Packaging("R");
		}
		else if (stan.Gamepad.sThumbLX < m_ANGLE) // skret w lewo
		{
			return Packaging("L");
		}
		else
			throw true;
	}
	catch (bool v)
	{
		if (v)
			return "";
	}
}