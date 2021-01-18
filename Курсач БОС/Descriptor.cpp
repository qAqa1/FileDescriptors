#include "helpFunctions.h"
#include "Descriptor.h"

using namespace std;
using namespace helpFunctions;

Descriptor::operator const std::string() { return ToLine(); }

string const Descriptor::ToString()
{
	string result;
	result += "ID:           " + ID + "\n";
	result += "Пользователь: " + user + "\n";
	result += "PID:          " + PID + "\n";
	result += "Имя процесса: " + processName + "\n";
	result += "Имя файла:    " + fileName;
	return result;
}

Descriptor Descriptor::Parse(string CSV_string)
{
	CSV_string.erase(std::remove(CSV_string.begin(), CSV_string.end(), '"'), CSV_string.end());
	vector <string> apart = Split(CSV_string, ',');
	return Descriptor(apart[0], apart[1], apart[2], apart[3], apart[4]);
	
}

std::string const Descriptor::ToLine()
{
	const string border = "|";
	return ID + border + user + border + PID + border + processName + border + fileName;
}

Descriptor::Descriptor(std::string ID, std::string user, std::string PID, std::string processName, std::string fileName) :
	ID(ID), user(user), PID(PID), processName(processName), fileName(fileName)
{
}

Descriptor::~Descriptor() {}
