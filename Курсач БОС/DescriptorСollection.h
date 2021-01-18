#pragma once
#include "Descriptor.h"
#include "CMD.h"

// ����� ��� ������ � �������������
class Descriptor�ollection
{
private:
	Descriptor�ollection();
	std::vector<Descriptor> descriptors;
	void operator >> (Descriptor addDescriptor);
	Descriptor�ollection SelectByProcessName ( std::string processName) const;
	Descriptor�ollection SelectByFileName( std::string fileName) const;
public:
	void updateAllFromOS();
	size_t size() const;
	Descriptor�ollection operator [] ( std::string processName) const;
	Descriptor�ollection operator | ( std::string fileName) const;
	static Descriptor�ollection AllFromOS();
	static Descriptor�ollection Empty();
	bool IsEmpty();
	operator std::string() const;
	~Descriptor�ollection();
};

