#pragma once
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

#include "helpFunctions.h"

// ������������ ��� ��� ������ � ��������
namespace CMD
{
	std::string Execute(std::string command);
	std::string GetDescriptorCSV();
	void Clear();
};

