#include "TextUserInterface.h"

using namespace std;

void TextUserInterface::Update()
{
	CMD::Clear();
	cout << "Запрос информации о дескрипторах, это может занять пару минут, пожалуйста подождите...";
	all.updateAllFromOS();
	CMD::Clear();
	cout << (string)all;
	cout << endl << endl << "Получено " << all.size() << " дескрипторов";
}

void TextUserInterface::Menu()
{
	cout << endl << endl << endl << "Главное меню:";
	cout << endl << "  Нажмите 1, чтобы найти все дескрипторы для процесса";
	cout << endl << "  Нажмите 2, чтобы найти все дескрипторы для файла";
	cout << endl << "  Нажмите 3, чтобы вывести на экран все дескрипторы";
	cout << endl << "  Нажмите 0, чтобы обновить список дескрипторов (может занять некоторое время)";
	cout << endl << "  Нажмите Escape, чтобы закрыть программу";

	while (true)
	{
		switch (_getch())
		{
		case 0x31:
			SelectByProcessName();
			break;
		case 0x32:
			SelectByFileName();
			break;
		case 0x33:
			PrintDescriptors();
			break;
		case 0x30:
			Update();
			break;
		case VK_ESCAPE:
			exit(1);

		}

		Menu();
	}
}

void TextUserInterface::SelectByProcessName()
{
	cout << endl << endl << "Введите имя процесса: ";
	string processName;
	cin >> processName;
	cin.sync();
	cin.clear();

	cin.ignore(LLONG_MAX, '\n');
	DescriptorСollection query = all[processName];

	if (query.IsEmpty())
	{
		cout << endl << endl << "Дескрипторов данного процесса не обнаружено";
		return;
	}

	cout << endl << (string)query << endl << endl;
	cout << "Всего дескрипторов: " << all.size() << " / Принадлежит данному процессу: " << query.size();
}

void TextUserInterface::SelectByFileName()
{
	cout << endl << endl << "Введите полный путь к файлу: ";
	
	const int  USER_INPUT_SIZE = 3000;

	char userInput[USER_INPUT_SIZE + 1] = {};
	cin.getline(userInput, USER_INPUT_SIZE);
	string fileName(userInput);

	cin.sync();
	cin.clear();

	DescriptorСollection query = all |fileName;

	if (query.IsEmpty())
	{
		cout << endl << endl << "Дескрипторов данного файла не обнаружено";
		return;
	}

	cout << endl << (string)query << endl << endl;
	cout << "Всего дескрипторов: " << all.size() << " / Используют данный файл: " << query.size();
}

void TextUserInterface::PrintDescriptors()
{
	cout << endl << (string)all << endl << endl;
	cout << "Колличество дескрипторов: " << all.size();
}

TextUserInterface TextUserInterface::StartWithAllDescriptors()
{
	TextUserInterface TUI;
	TUI.Update();
	return TUI;
}

TextUserInterface::TextUserInterface() {}

TextUserInterface::~TextUserInterface() {}
