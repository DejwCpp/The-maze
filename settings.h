#pragma once

#include <iostream>

class Console
{
public:
	void CursorVisibility(bool visible);
	void AlignCenter(int consoleWidth, int consoleHeight);
	void CharWidthLength(int charWidth, int charHeight);
	void SetColor(std::string color);
};
