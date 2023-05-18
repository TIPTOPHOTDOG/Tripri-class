#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

namespace triptiArrayTools
{
	void setRandomSeed()
	{
		srand(time(NULL));
	}

	void createSortedArray(int*& items, int lenght, int reverse)
	{
		delete[] items;
		items = new int[lenght];
		for (int i = 0; i < lenght; ++i)
		{
			items[i] = lenght * reverse - i * reverse * 2 - reverse + i + 1;
		}
	}

	void createRandomArray(int*& items, int lenght, bool clearRandom)
	{
		delete[] items;
		items = new int[lenght];
		if (clearRandom)
		{
			setRandomSeed();
		}
		for (int i = 0; i < lenght; ++i)
		{
			items[i] = rand();
		}
	}

	void showArray(int* items, int lenght)
	{
		for (int i = 0; i < lenght; ++i)
		{
			cout << items[i] << "  ";
			if (!(i % 10) && (i != 0))
			{
				cout << endl;
			}
		}
		cout << endl << "----" << endl;
	}

	int** createMatrix(int size, int maxWay)
	{
		int** matrix = new int* [size];
		for (int i = 0; i < size; ++i)
		{
			matrix[i] = new int[size];
		}

		for (int i = 0; i < size; ++i)
		{
			matrix[i][i] = 0;
			for (int j = i + 1; j < size; ++j)
			{
				int temp;
				temp = rand() % maxWay;
				matrix[i][j] = temp;
				matrix[j][i] = temp;
			}
		}
		return matrix;
	}
};

class Tripti
{
private:
	short ENTER;
	short BACKSPACE;
	int consoleLineLen;
	string lines[8];
public:
	Tripti();
	Tripti(int lineLen);
	void logo();
	void print(string item);
	void print(string item, bool english);
	void print(string* items, int size, bool english);
	void print(string* items, int size, bool english, int firstNumber);
	void print(int* items, int size, int elementSize, bool compression);
	void print(double* items, int size, int elementSize, bool compression);
	void print(int** matrix, int sizeX, int sizeY, int elementSize);
	string input();
	string input(string item);
	void createLines();
};

/*

Функция для заполнения станадртных строк которые будут использоваться для быстрого вывода.

*/

void Tripti::createLines()
{
	lines[0] = 201;
	lines[7] = 200;
	lines[1] = 201;
	lines[6] = 200;
	lines[2] = 204;
	for (int i = 0; i < consoleLineLen - 3; ++i)
	{
		lines[0] += 205;
		lines[7] += 205;
		if (i != 5)
		{
			lines[1] += 205;
			lines[6] += 205;
			lines[2] += 205;
		}
		else
		{
			lines[1] += 203;
			lines[6] += 202;
			lines[2] += 206;
		}
	}
	lines[0] += 187;
	lines[1] += 187;
	lines[6] += 188;
	lines[7] += 188;
	lines[2] += 185;
}

void Tripti::logo()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);

	string planePrint = "11111111111111111111111111111111111111111111111111111111112111222222222222221111222222222111111111111111112222222222111111111112222222221111111111111122222222222222111111111111112222222222111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112112██████████████2112█████████21111111111111112██████████21111111112█████████21111111111112██████████████21111111111112██████████211121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111222222██2222221111222222222██2111111111111112222██222211111111111222222222██211111111111222222██222222111111111111112222██2222111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111111112██21111111111111111112██211111111111111112██2111111111111111111111112██21111111111111112██211111111111111111111112██2111111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111111112██21111111111111111112██211111111111111112██2111111111111111111111112██21111111111111112██211111111111111111111112██2111111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111111112██2111111111122222222██2111111111111111112██211111111111111222222222██211111111111111112██211111111111111111111112██2111111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111111112██21111111112████████211111111111111111112██211111111111112█████████21111111111111111112██211111111111111111111112██2111111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111111112██21111111112██22222██21111111111111111112██211111111111112██222222211111111111111111112██211111111111111111111112██2111111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111111112██21111111112██211112██2111111111111111112██211111111111112██211111111111111111111111112██211111111111111111111112██2111111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111111112██21111111112██2111112█2111111111111112222██222211111111112██211111111111111111111111112██211111111111111111112222██2222111121111111111111111111111111111111111111111111111111111111111511111111111111111111111111111111111111111111111111111111112111111112██21111111112██2111112██21111111111112██████████21111111112██211111111111111111111111112██21111111111111111112██████████2111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111112211111111111221111111221111111111111122222222221111111111122111111111111111111111111111221111111111111111111122222222221111211111111111111111111111111111111111111111111111111111111115";
	string planeBack = "111111111111111111111111111111111111111111111111111111111121111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111111r1.M\"\"\"bgd1111111db111111\`7MM\"\"\"Mq.1\`7MM\"\"\"Mq.111111\`7MM\"\"\"Yp,1\`7MMF\'111\`7MF\'MMP\"\"MM\"\"YMM1111111111111111111111111r1111111111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111111r,MI1111\"Y111111;MM:1111111MM111\`MM.11MM111\`MM.1111111MM1111Yb111\`MA11111,V11P\'111MM111\`711111111111111111111__,11r1111111111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111111r\`MMb.111111111,V^MM.111111MM111,M9111MM111,M911111111MM1111dP1111VM:111,V11111111MM1111111pd*\"*b.11pd*\"*b.1\`7MM11r1111111111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111111r11\`YMMNq.1111,M11\`MM111111MMmmdM91111MMmmdM9111111111MM\"\"\"bg.11111MM.11M\'11111111MM111111(O)111j81(O)111j8111MM11r1111111111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111111r.11111\`MM1111AbmmmqMA11111MM111111111MM11YM.111111111MM1111\`Y11111\`MM1A\'111111111MM1111111111,;j911111,;j9111MM11r1111111111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111111rMb11111dM111A\'11111VML1111MM111111111MM111\`Mb.1111111MM1111,9111111:MM;1111111111MM1111111,-=\'11111,-=\'111111MM11r1111111111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111111rP\"Ybmmd\"11.AMA.111.AMMA..JMML.11111.JMML.1.JMM.1111.JMMmmmd911111111VF111111111.JMML.1111Ammmmmmm1Ammmmmmm1.JMML.r1111111111211111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111121111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111211111111111111111111111111111111111111111111111111111111115";
	string pullSimb[10];
	string mainLine;
	system("chcp 866 > null");

	pullSimb[1] = 177;
	pullSimb[2] = 178;
	pullSimb[3] = 219;
	string str;
	for (int temp = 0; temp <= 7; ++temp) {
		for (int i = 0; i < planeBack.size(); ++i)
		{
			if (planeBack[i] == '1')
			{
				str += pullSimb[1];
			}
			else if (planeBack[i] == '2')
			{
				str += pullSimb[2];
			}
			else if (planeBack[i] == '3')
			{
				str += pullSimb[3];
			}
			else if (planeBack[i] == '5')
			{
				str += "\n";
				mainLine += str;
				str = "";
			}
			else if (planeBack[i] == ' ')
			{
				str += 255;

			}
			else if (planeBack[i] == '█')
			{
				str += pullSimb[3];
			}
			else if (planeBack[i] != 'r')
			{
				str+= planeBack[i];
			}
		}
		if (temp == 3)
		{
			for (int i = 0; i < planePrint.size(); ++i)
			{
				if (planePrint[i] == '0')
				{
					str += pullSimb[0];
				}
				if (planePrint[i] == '1')
				{
					str += pullSimb[1];
				}
				if (planePrint[i] == '2')
				{
					str += pullSimb[2];
				}
				if (planePrint[i] == '3')
				{
					str += pullSimb[3];
				}
				if (planePrint[i] == '5')
				{
					str += "\n";
					mainLine += str;
					str = "";

				}
				if (planePrint[i] == ' ')
				{
					str += 255;

				}
				if (planePrint[i] == '█')
				{
					str += pullSimb[3];
				}
			}
		}
	}
	cout << mainLine << endl;
	int a = _getch();
}

/*

Конструктор класса, для вывод псевдографики.
Ставит стандартную длину консоли 80;
Также выводит Лого Tripti;

*/

Tripti::Tripti()
{
	ENTER = 13;
	BACKSPACE = 8;
	logo();
	system("cls");
	consoleLineLen = 80;
	createLines();
}

/*

Конструктор класса, для вывод псевдографики.
Присваивает длину одной строки в консоли на получаемое значение lineLen;
Также выводит Лого Tripti;

*/

Tripti::Tripti(int lineLen)
{
	ENTER = 13;
	BACKSPACE = 8;
	logo();
	system("cls");
	consoleLineLen = lineLen;
	createLines();
}

/*

Функция для вывода одной строки, которая будет обрамлена с двух сторон символом "║".

*/

void Tripti::print(string item)
{
	string str;
	system("chcp 866 > null");
	cout << lines[0] << " \n" << char(186) << " ";
	system("chcp 1251 > null");
	for (int i = 0; str.size() + item.size() + 4 < consoleLineLen; ++i)
	{
		str += 255;
	}
	cout << item;
	system("chcp 866 > null");
	cout << str << char(186) << "\n" << lines[7] << "\n";
}

/*

Функция для вывода одной строки, которая будет обрамлена с двух сторон символом "║".
Имеет проверку на использование не английского языка.

*/

void Tripti::print(string item, bool english)
{
	if (!english)
	{
		print(item);
		return;
	}
	string str;
	system("chcp 866 > null");
	str = lines[0];
	str += "\n";
	str += 186;
	str += 255;
	str += item;
	for (int i = 0; str.size() + 2 < consoleLineLen; ++i)
	{
		str += 255;
	}
	str += 186;
	str += "\n";
	str += lines[7];
	str += "\n";
	cout << str;
}

/*

Функция для вывода массива строк, каждая из которых будет обрамления символом "║" с двух сторон.

*/

void Tripti::print(string* items, int size, bool english)
{
	if (!english)
	{
		for (int i = 0; i < size; ++i)
		{
			print(items[i]);
		}
		return;
	}
	string mainLine;
	mainLine = lines[0];
	mainLine += "\n";
	for (int i = 0; i < size; ++i)
	{
		string str;
		str = char(186);
		str += 255;
		str += items[i];
		for (int i = 0; str.size() + 2 < consoleLineLen; ++i)
		{
			str += 255;
		}
		str += 186;
		str += "\n";
		mainLine += str;
	}
	mainLine += lines[7];
	mainLine += "\n"; 
	cout << mainLine;
}

/*

Функция для вывода массива строк, каждая из которых будет обрамления символом "║" с двух сторон.я же 
В рамке слева будет находится номер строки.

*/

void Tripti::print(string* items, int size, bool english, int firstNumber)
{
	system("chcp 866 > null");
	string mainLine;
	mainLine = lines[1];
	mainLine += "\n";
	for (int i = 0; i < size; ++i)
	{
		string str;
		str = 186;
		str += 255;
		str += to_string(i);
		while (str.size() < 6)
		{
			str += 255;
		}
		str += 186;
		str += 255;
		str += items[i];
		while (str.size() < consoleLineLen - 2)
		{
			str += 255;
		}
		str += 186;
		str += "\n";
		mainLine += str;
		if (i != size)
		{
			mainLine += lines[2];
			mainLine += "\n";
		}
	}
	mainLine += lines[6];
	mainLine += "\n";
	cout << mainLine;
}

/*

Функция для вывода массива чисел типа int.
Все числа выводятся в рамке
В строке находится максимально доступное количсетво чисел в строке
Для определения определения этого количества используется параметр elementSize

*/

void Tripti::print(int* items, int size, int elementSize, bool compression)
{
	string mainline;
	string str;
	elementSize++;
	mainline = lines[0];
	mainline += "\n";
	str = 186;
	str += 255;
	int i = 0;
	for (int i = 0; i < size; ++i)
	{
		if (str.size() + elementSize + 2 > consoleLineLen)
		{
			while (str.size() + 2 < consoleLineLen)
			{
				str += 255;
			}
			str += 186;
			str += "\n";
			mainline += str;
			str = 186;
			str += 255;
			if (compression)
			{
				i = size - i;
				compression = false;
			}
		}
		
		if (str.size() + to_string(items[i]).size() + 2 < consoleLineLen)
		{
			int count = 0;
			while(count + to_string(items[i]).size() < elementSize)
			{
				count++;
				str += 255;
			}
			str += to_string(items[i]);
		}
	}
	for (int i = 0; str.size() + 2 < consoleLineLen; ++i)
	{
		str += 255;
	}
	str += 186;
	str += "\n";
	mainline += str;
	mainline += lines[7];
	mainline += "\n";
	cout << mainline;
}

/*

Функция для вывода массива чисел типа double.
Все числа выводятся в рамке
В строке находится максимально доступное количсетво чисел в строке
Для определения определения этого количества используется параметр elementSize

*/

void Tripti::print(double* items, int size, int elementSize, bool compression)
{
	string mainline;
	string str;
	elementSize += 8;
	mainline = lines[0];
	mainline += "\n";
	str = 186;
	str += 255;
	for (int i = 0; i < size; ++i)
	{
		if (str.size() + elementSize + 2 > consoleLineLen)
		{
			while (str.size() + 2 < consoleLineLen)
			{
				str += 255;
			}
			str += 186;
			str += "\n";
			mainline += str;
			str = 186;
			str += 255;
			if (compression)
			{
				i = size - i;
				compression = false;
			}
		}

		if (str.size() + to_string(items[i]).size() + 2 < consoleLineLen)
		{
			int count = 0;
			while (count + to_string(items[i]).size() < elementSize)
			{
				count++;
				str += 255;
			}
			str += to_string(items[i]);
		}
	}
	for (int i = 0; str.size() + 2 < consoleLineLen; ++i)
	{
		str += 255;
	}
	str += 186;
	str += "\n";
	mainline += str;
	mainline += lines[7];
	mainline += "\n";
	cout << mainline;
}

/*

Функция для вывод матриц, с использованием символов псевдографики

*/

void Tripti::print(int** matrix, int sizeX, int sizeY, int elementSize)
{
	string mainLine;
	string str;
	mainLine = lines[0] + '\n';
	str = 186;
	str += 255;
	str += 255;
	elementSize++;
	for (int i = 0; i < elementSize; ++i)
	{
		str += 255;
	}
	for (int i = 0; i < sizeX; ++i)
	{
		int count = 0;
		while (count + to_string(i+1).size() < elementSize)
		{
			count++;
			str += 255;
		}
		str += to_string(i+1);
	}
	while (str.size() + 2 < consoleLineLen)
	{
		str += 255;
	}
	str += 186;
	str += '\n';
	mainLine += str;
	for (int i = 0; i < sizeY; ++i)
	{	
		str = 186;
		str += 255;
		while (str.size() + to_string(i+1).size() - 2 < elementSize)
		{
			str += 255;
		}
		str += to_string(i+1);
		str += 255;
		for (int j = 0; j < sizeX; ++j)
		{
			int count = 0;
			while (count + to_string(matrix[i][j]).size() < elementSize)
			{
				count++;
				str += 255;
			}
			str += to_string(matrix[i][j]);
		}
		while (str.size()+2 < consoleLineLen)
		{
			str += 255;
		}
		str += 186;
		str += '\n';
		mainLine += str;
	}
	mainLine += lines[7] + '\n';
	cout << mainLine;
}

/*

Функция для ввода данных, данный вводятся до первого перехода на следующую строку.

*/

string Tripti::input()
{
	string line;
	char a;
	cout << lines[0];
	system("chcp 866 > null");
	cout << "\n" << char(186) << char(255);
	system("chcp 1251 > null");
	a = _getch();
	while (a != ENTER)
	{
		if (a != BACKSPACE)
		{
			cout << a;
			line += a;
		}
		else if (line.size() > 0)
		{
			string newline;
			newline = "";
			cout << "\b \b";
			int i = 0;
			while (newline.size() < line.size() - 1)
			{ 
				newline += line[i];
				i++;
			}
			line = newline;
		}
		a = _getch();
	}
	string str;
	while (str.size() + line.size() < consoleLineLen - 4)
	{
		str += 255;
	}
	system("chcp 866 > null");
	str += 186;
	str += "\n";
	cout << str << lines[7] << "\n";
	return line;
}

/*

функция для ввода данных с клавиатуры, перед вводом будет выведена строка item

*/

string Tripti::input(string item)
{
	string line;
	char a;
	cout << lines[0];
	system("chcp 866 > null");
	cout << "\n" << char(186) << char(255);
	system("chcp 1251 > null");
	cout << item;
	a = _getch();
	while (a != ENTER)
	{
		if (a != BACKSPACE)
		{
			cout << a;
			line += a;
		}
		else if (line.size() > 0)
		{
			string newline;
			newline = "";
			cout << "\b \b";
			int i = 0;
			while (newline.size() < line.size() - 1)
			{
				newline += line[i];
				i++;
			}
			line = newline;
		}
		a = _getch();
	}
	string str;
	while (str.size() + line.size() + item.size() + 4 < consoleLineLen)
	{
		str += 255;
	}
	system("chcp 866 > null");
	str += 186;
	str += "\n";
	cout << str << lines[7] << "\n";
	return line;
}