#pragma once

class Console
{
public:
	void CursorVisibility(bool visible);
	void AlignCenter(int consoleWidth, int consoleHeight);
	void CharWidthLength(int charWidth, int charLength);
	void SetColor(std::string color);
};
