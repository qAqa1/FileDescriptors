#include "helpFunctions.h"

using namespace std;

std::vector<std::string> helpFunctions::Split(std::string const & s, char separator)
{
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> elems;

	while (std::getline(ss, item, separator))
	{
		elems.push_back(item);
	}
	return elems;
}
