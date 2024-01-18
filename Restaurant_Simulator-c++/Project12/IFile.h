#pragma once
#include <fstream>
class IFile {
	virtual void saveToFile(std::fstream& file) = 0;
	virtual void restoreFromFile(std::fstream& file) = 0;
};
