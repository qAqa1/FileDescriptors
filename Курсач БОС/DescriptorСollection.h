#pragma once
#include "Descriptor.h"
#include "CMD.h"

// êëàññ äëÿ ğàáîòû ñ äåñêğèïòîğàìè
class DescriptorÑollection
{
private:
	DescriptorÑollection();
	std::vector<Descriptor> descriptors;
	void operator >> (Descriptor addDescriptor);
	DescriptorÑollection SelectByProcessName ( std::string processName) const;
	DescriptorÑollection SelectByFileName( std::string fileName) const;
public:
	void updateAllFromOS();
	size_t size() const;
	DescriptorÑollection operator [] ( std::string processName) const;
	DescriptorÑollection operator | ( std::string fileName) const;
	static DescriptorÑollection AllFromOS();
	static DescriptorÑollection Empty();
	bool IsEmpty();
	operator std::string() const;
	~DescriptorÑollection();
};

