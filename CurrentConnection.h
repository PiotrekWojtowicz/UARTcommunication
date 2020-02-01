#ifndef CURRENTCONNECTION_H
#define CURRENTCONNECTION_H
#pragma once
#include <iostream>
#include"serialport.h"
#include "CurrentConnection.h"
#include "XboxPadRead.h"
#include <assert.h>
enum sizes {
	ZERO = 0,
	SMALL = 20,
	ANGLE = 90,
	MEDIUM = 175,
	HIGH = 256
};
enum MinusSizes {
	m_SMALL = -20,
	m_ANGLE = -90,
	m_MEDIUM = -175,
	m_HIGH = -256
};

void ConnectionCheck(SerialPort& arduino);
std::string Packaging(std::string command);
std::string PadControl(XINPUT_STATE &stan);
#endif