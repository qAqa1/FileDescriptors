#pragma once

#include <Windows.h>
#include <Winuser.h>

#include <conio.h>
#include "CMD.h"

#include "DescriptorСollection.h"

// класс отвечающий за общение с пользователем
class TextUserInterface
{
private:
	DescriptorСollection all = DescriptorСollection::Empty();
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

