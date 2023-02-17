#pragma once
#ifndef _CONSOLE_UTILITY_HPP
#define _CONSOLE_UTILITY_HPP

#include "OS.h"

#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <string>

class CU {
public:

	static void getTerminalSize(short& width, short& height);

	static void clear_console();

};

#endif