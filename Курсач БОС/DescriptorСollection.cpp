#include "Descriptor�ollection.h"

using namespace std;
using namespace helpFunctions;

Descriptor�ollection::Descriptor�ollection() {}

void Descriptor�ollection::operator>>(Descriptor addDescriptor) { descriptors.push_back(addDescriptor); }

Descriptor�ollection Descriptor�ollection::SelectByProcessName( std::string processName) const
{
	Descriptor�ollection selected;

	for (int i = 0; i < size(); i++)
	{
		if (descriptors[i].processName == processName)
		{
			selected >> descriptors[i];
		}
	}

	return selected;
}

Descriptor�ollection Descriptor�ollection::SelectByFileName( std::string fileName) const
{
	Descriptor�ollection selected;

	for (int i = 0; i < size(); i++)
	{
		if (descriptors[i].fileName == fileName)
		{
			selected >> descriptors[i];
		}
	}

	return selected;
}

void Descriptor�ollection::updateAllFromOS()
{
	descriptors.clear();
	vector<string> apart = Split(CMD::GetDescriptorCSV(), '\n');

	for (int i = 1; i < apart.size(); i++)
	{
		if (apart[i][0] == '"')
		{
			descriptors.push_back(Descriptor::Parse(apart[i]));
		}
	}
}

size_t Descriptor�ollection::size() const
{
	return descriptors.size();
}

Descriptor�ollection Descriptor�ollection::operator[]( std::string processName) const { return SelectByProcessName(processName); }

Descriptor�ollection Descriptor�ollection::operator|( std::string fileName) const { return SelectByFileName(fileName); }

Descriptor�ollection Descriptor�ollection::AllFromOS()
{
	vector<string> apart = Split(CMD::GetDescriptorCSV(), '\n');

	Descriptor�ollection allDescriptorsInOS;

	for (int i = 1; i < apart.size(); i++)
	{
		if (apart[i][0] == '"')
		{
			allDescriptorsInOS >> Descriptor::Parse(apart[i]);
		}
	}

	return allDescriptorsInOS;
}

Descriptor�ollection Descriptor�ollection::Empty() { return Descriptor�ollection(); }

bool Descriptor�ollection::IsEmpty() { return size() == 0; }

Descriptor�ollection::operator std::string() const
{
	string result;

	result += "ID|������������|PID|��� ��������|��� ����� ��������";

	int number = 0;

	for (Descriptor descriptor : descriptors)
	{
		if (number != 0)
		{
			result += "\n";
			result += to_string(number);
			result += ") ";
			result += (string)descriptor;
		}	
		number++;
	}

	return result;
}

Descriptor�ollection::~Descriptor�ollection() {}
