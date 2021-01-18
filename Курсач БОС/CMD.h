#pragma once
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

#include "helpFunctions.h"

// пространство имён для работы с консолью
namespace CMD
{
	std::string Execute(std::string command);
	std::string GetDescriptorCSV();
	void Clear();
};

