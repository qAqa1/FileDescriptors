#include "DescriptorÑollection.h"

using namespace std;
using namespace helpFunctions;

DescriptorÑollection::DescriptorÑollection() {}

void DescriptorÑollection::operator>>(Descriptor addDescriptor) { descriptors.push_back(addDescriptor); }

DescriptorÑollection DescriptorÑollection::SelectByProcessName( std::string processName) const
{
	DescriptorÑollection selected;

	for (int i = 0; i < size(); i++)
	{
		if (descriptors[i].processName == processName)
		{
			selected >> descriptors[i];
		}
	}

	return selected;
}

DescriptorÑollection DescriptorÑollection::SelectByFileName( std::string fileName) const
{
	DescriptorÑollection selected;

	for (int i = 0; i < size(); i++)
	{
		if (descriptors[i].fileName == fileName)
		{
			selected >> descriptors[i];
		}
	}

	return selected;
}

void DescriptorÑollection::updateAllFromOS()
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

size_t DescriptorÑollection::size() const
{
	return descriptors.size();
}

DescriptorÑollection DescriptorÑollection::operator[]( std::string processName) const { return SelectByProcessName(processName); }

DescriptorÑollection DescriptorÑollection::operator|( std::string fileName) const { return SelectByFileName(fileName); }

DescriptorÑollection DescriptorÑollection::AllFromOS()
{
	vector<string> apart = Split(CMD::GetDescriptorCSV(), '\n');

	DescriptorÑollection allDescriptorsInOS;

	for (int i = 1; i < apart.size(); i++)
	{
		if (apart[i][0] == '"')
		{
			allDescriptorsInOS >> Descriptor::Parse(apart[i]);
		}
	}

	return allDescriptorsInOS;
}

DescriptorÑollection DescriptorÑollection::Empty() { return DescriptorÑollection(); }

bool DescriptorÑollection::IsEmpty() { return size() == 0; }

DescriptorÑollection::operator std::string() const
{
	string result;

	result += "ID|Ïîëüçîâàòåëü|PID|Èìÿ ïğîöåññà|Èìÿ ôàéëà ïğîöåññà";

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

DescriptorÑollection::~DescriptorÑollection() {}
