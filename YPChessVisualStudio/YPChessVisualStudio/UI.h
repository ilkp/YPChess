#pragma once

#include "State.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

class UI
{
private:
	State* state;
	HANDLE outputH;

public:
	UI(State* state);
	~UI();
	void drawBoard();
};

