#include "TextUserInterface.h"

using namespace std;

void TextUserInterface::Update()
{
	CMD::Clear();
	cout << "������ ���������� � ������������, ��� ����� ������ ���� �����, ���������� ���������...";
	all.updateAllFromOS();
	CMD::Clear();
	cout << (string)all;
	cout << endl << endl << "�������� " << all.size() << " ������������";
}

void TextUserInterface::Menu()
{
	cout << endl << endl << endl << "������� ����:";
	cout << endl << "  ������� 1, ����� ����� ��� ����������� ��� ��������";
	cout << endl << "  ������� 2, ����� ����� ��� ����������� ��� �����";
	cout << endl << "  ������� 3, ����� ������� �� ����� ��� �����������";
	cout << endl << "  ������� 0, ����� �������� ������ ������������ (����� ������ ��������� �����)";
	cout << endl << "  ������� Escape, ����� ������� ���������";

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
	cout << endl << endl << "������� ��� ��������: ";
	string processName;
	cin >> processName;
	cin.sync();
	cin.clear();

	cin.ignore(LLONG_MAX, '\n');
	Descriptor�ollection query = all[processName];

	if (query.IsEmpty())
	{
		cout << endl << endl << "������������ ������� �������� �� ����������";
		return;
	}

	cout << endl << (string)query << endl << endl;
	cout << "����� ������������: " << all.size() << " / ����������� ������� ��������: " << query.size();
}

void TextUserInterface::SelectByFileName()
{
	cout << endl << endl << "������� ������ ���� � �����: ";
	
	const int  USER_INPUT_SIZE = 3000;

	char userInput[USER_INPUT_SIZE + 1] = {};
	cin.getline(userInput, USER_INPUT_SIZE);
	string fileName(userInput);

	cin.sync();
	cin.clear();

	Descriptor�ollection query = all |fileName;

	if (query.IsEmpty())
	{
		cout << endl << endl << "������������ ������� ����� �� ����������";
		return;
	}

	cout << endl << (string)query << endl << endl;
	cout << "����� ������������: " << all.size() << " / ���������� ������ ����: " << query.size();
}

void TextUserInterface::PrintDescriptors()
{
	cout << endl << (string)all << endl << endl;
	cout << "����������� ������������: " << all.size();
}

TextUserInterface TextUserInterface::StartWithAllDescriptors()
{
	TextUserInterface TUI;
	TUI.Update();
	return TUI;
}

TextUserInterface::TextUserInterface() {}

TextUserInterface::~TextUserInterface() {}
