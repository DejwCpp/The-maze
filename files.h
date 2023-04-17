#pragma once

#include <fstream>

class File
{
public:
	void SaveScore(std::ofstream getFile, double score);
	double GetBestScore(std::ifstream getFile);
	void LoadControlsData(std::ifstream getFile, char up, char down, char left, char right);
	void ChangeControlsData(std::ofstream getFile, char up, char down, char left, char right);
};
