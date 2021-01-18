// ¬ариант:
// —писок открытых дискрипторов, файлов указанного процесса,
// с указанием информации дл€ файла полный путь доступа

// ѕеред использованием ввести в консоль это:
// openfiles /local on
// и перезагрузить компютер

// если Windows 64 битна€, то компилировать на 64 бита; если 32 битна€, то на 32

#include "TextUserInterface.h"

#include <Windows.h>

int main()
{
	//setlocale(LC_ALL, "Russian");

	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //установка кодовой страницы win-cp 1251 в поток 

	// создание экзэпл€ра класса дл€ общени€ с пользователем и запрос дескрипторов
	TextUserInterface TUI = TextUserInterface::StartWithAllDescriptors();

	// вызов главного меню программы
	TUI.Menu();
}
