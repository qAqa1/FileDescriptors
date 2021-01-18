#include "CMD.h"

using namespace std;
using namespace helpFunctions;

// ����� �������������� ������ � ������� ���:
// openfiles /local on
// � ������������� ��������

namespace
{
	// ������� ��� ��������� ������� ������������ � ������� ��� ��������� �����
	//const string DESCRIPTORS_TABLES_COMMAND = "openfiles /query /fo table /nh";

	// ������� ��� ��������� CSV ������� ������������
	const string DESCRIPTORS_CSV_COMMAND = "openfiles /query /fo CSV /v";
}

std::string CMD::Execute(string command)
{
	const char* cmd = command.c_str();
	char buffer[128];
	std::string result = "";
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try
	{
		while (fgets(buffer, sizeof buffer, pipe) != NULL) { result += buffer; }
	}
	catch (...)
	{
		_pclose(pipe);
		throw;
	}
	_pclose(pipe);
	return result;
}

string CMD::GetDescriptorCSV() { return CMD::Execute(DESCRIPTORS_CSV_COMMAND); }

void CMD::Clear() { system("cls"); }
