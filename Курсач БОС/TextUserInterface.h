#pragma once

#include <Windows.h>
#include <Winuser.h>

#include <conio.h>
#include "CMD.h"

#include "Descriptor�ollection.h"

// ����� ���������� �� ������� � �������������
class TextUserInterface
{
private:
	Descriptor�ollection all = Descriptor�ollection::Empty();
	TextUserInterface();
public:
	void Update();
	void Menu();
	void SelectByProcessName();
	void SelectByFileName();
	void PrintDescriptors();
	static TextUserInterface StartWithAllDescriptors();
	~TextUserInterface();
};

