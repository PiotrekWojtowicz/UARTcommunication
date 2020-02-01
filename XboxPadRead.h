#ifndef PADREAD_H
#define PADREAD_H
#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <cmath>
#include <iostream>

#pragma comment(lib, "XInput.lib")
#define WIN32_LEAN_AND_MEAN
#define MAX_DATA_LENGTH 255
#define INPUT_DEADZONE 7800
#define XUSER_MAX_COUNT 4

	static DWORD rezultat;
	static int padN = -1;
	static char output[MAX_DATA_LENGTH];
	static char incoming[MAX_DATA_LENGTH];

	void checkPad(XINPUT_STATE& stan) noexcept(false);
	void deadzone(XINPUT_STATE* wsk) noexcept;
	void showVal(XINPUT_STATE& stan) noexcept;

#endif
