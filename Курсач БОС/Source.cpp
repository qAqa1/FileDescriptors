// �������:
// ������ �������� ������������, ������ ���������� ��������,
// � ��������� ���������� ��� ����� ������ ���� �������

// ����� �������������� ������ � ������� ���:
// openfiles /local on
// � ������������� ��������

// ���� Windows 64 ������, �� ������������� �� 64 ����; ���� 32 ������, �� �� 32

#include "TextUserInterface.h"

#include <Windows.h>

int main()
{
	//setlocale(LC_ALL, "Russian");

	SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); //��������� ������� �������� win-cp 1251 � ����� 

	// �������� ��������� ������ ��� ������� � ������������� � ������ ������������
	TextUserInterface TUI = TextUserInterface::StartWithAllDescriptors();

	// ����� �������� ���� ���������
	TUI.Menu();
}
