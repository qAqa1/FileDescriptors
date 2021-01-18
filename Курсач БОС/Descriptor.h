#pragma once
#include <iostream>
#include <algorithm>
#include "helpFunctions.h"

// класс хранящий информацию о дескрипторе
class Descriptor
{
	friend class DescriptorСollection;
public:
	const std::string ID,
					  user,
					  PID,
					  processName,
					  fileName;

	operator const std::string();
	std::string const ToString();
	~Descriptor();
private:
	static Descriptor Parse(std::string CSV_string);
	std::string const ToLine();
	Descriptor(std::string ID, std::string user, std::string PID, std::string processName, std::string fileName);
};

