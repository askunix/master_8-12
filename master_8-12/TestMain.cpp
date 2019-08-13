#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "my_string.h"

using  std::string;
using  std::wstring;
using namespace std;

int main()
{
	char  arr[] = "0000";
	const char data[] = "00600";
	const char test[] = "1101610";
	const char dest[] = "10161100";
	char ch = ' ';
	char sh = 's';
	const char flag[] = "0";
	const char dial[] = "161";

	myString dataString_1(arr, 4);
	cout << dataString_1;

	cout << "Î²²å char :" << endl;
	dataString_1.Append(5, sh);
	cout << dataString_1;

	cout << "Í·¼Ó:" << endl;
	dataString_1.Prepend(test, 7);
	cout << dataString_1;

	cout << "Î²²å char * :" << endl;
	dataString_1.Append(data, 5);
	cout << dataString_1;

	cout << "Î²É¾:" << endl;
	dataString_1.Chop(3);
	cout << dataString_1;

	cout << "Î²²å int :" << endl;
	int i = 9;
	dataString_1.Append((char *)&i, sizeof(int));
	cout << dataString_1;

	cout << "°üº¬×Ó´® int :" << endl;
	if (dataString_1.Contains((char *)&i, sizeof(int)) > 0)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	cout << endl;

	cout << "°üº¬×Ó´® char * :" << endl;
	if (dataString_1.Contains(dial, 3) > 0)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	cout << endl;

	cout << "ÇÐ·Ö Split :" << endl;
	list<string> Lis;
	list<string>::iterator it;
	Lis = dataString_1.Split(flag);
	for (it = Lis.begin(); it != Lis.end(); ++it)
		cout << *it << endl;

	system("pause");
	return 0;
}