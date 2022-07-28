/*
############################################ ЗАДАНИЕ ###########################################
				Абстрактный класс и виртуальный деструктор
	Создайте абстрактный класс Shape для рисования плоских фигур.
Определите виртуальные методы:
	 Show() — вывод на экран информации о фигуре;
	 Save() — сохранение фигуры в файл;
	 Load() — считывание фигуры из файла.
	Определите производные классы:
	 Square — квадрат, который характеризуется координатами левого
верхнего угла и длиной стороны;
	 Rectangl — прямоугольник с заданными координатами левого
верхнего угла и размерами;
	 Circle — окружность с заданными координатами центра и радиусом.
	Создайте динамический массив фигур и сохраните фигуры в файл. Затем
загрузите фигуры из файла в другой массив и отобразите информацию о
каждой фигуре.
################################################################################################
03.00.35
*/

#include <io.h>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include "Circle.h"
#include "Rectangl.h"
#include "Shape.h"
#include "Square.h"
using std::cout;
using std::cin;
using std::endl;

Shape* RandomShapeGenerator()
{
	int minValue = 0;	// Минимальное значение для поля значения фигуры.
	int maxValue = 99;	// Максимальное значение для поля значения фигуры.

	int randValue_1{ 0 }, randValue_2{ 0 }, randValue_3{ 0 }, randValue_4{ 0 };
	randValue_1 = rand() % (maxValue - minValue + 1) + minValue;	// Случайное числовое значение для 1-го поля фигуры.
	randValue_2 = rand() % (maxValue - minValue + 1) + minValue;	// Случайное числовое значение для 2-го поля фигуры.
	randValue_3 = rand() % (maxValue - minValue + 1) + minValue;	// Случайное числовое значение для 3-го поля фигуры.
	randValue_4 = rand() % (maxValue - minValue + 1) + minValue;	// Случайное числовое значение для 4-го поля фигуры.

	int n = rand() % 3;
	switch (n)
	{
	case 0: return new Square{ randValue_1, randValue_2, randValue_3 };
	case 1: return new Rectangl{ randValue_1, randValue_2, randValue_3, randValue_4 };
	case 2: return new Circle{ randValue_1, randValue_2, randValue_3 };
	}
}

int main()
{
	SetConsoleCP(1251);
	/*
	Задает кодовую страницу ввода, используемую консолью, связанной с вызывающим процессом.
	Консоль использует страницу входного кода для преобразования ввода с клавиатуры
	в соответствующее символьное значение.
	*/
	SetConsoleOutputCP(1251);
	/*
	Задает выходную кодовую страницу, используемую консолью, связанной с вызывающим процессом.
	Консоль использует свою кодовую страницу вывода для преобразования символьных значений,
	записанных различными функциями вывода, в изображения, отображаемые в окне консоли.
	*/

	srand(time(NULL));

	cout << "\t\t\t\tEnter quantity figures: ";
	int size{ 0 };
	cin >> size;

	Shape* p_base_class = nullptr;								// Указатель на базовый класс.
	Shape** shapeArr = new Shape * [size];
	for (int i = 0; i < size; i++)								// Запись фигур в массив.
	{
		p_base_class = RandomShapeGenerator();
		shapeArr[i] = p_base_class;
	}

	for (int i = 0; i < size; i++)								// Вывод фигур в консоль.	
		shapeArr[i]->Show();

	// Сохранение в файл.
	const char fileNameWrite[20]{ "shapes.bin" };
	FILE* f_wright{ nullptr };
	fopen_s(&f_wright, fileNameWrite, "wb");
	if (f_wright == nullptr)
	{
		perror("Error opening");
		exit(1);
	}

	for (int i = 0; i < size; i++)								// Запись фигур в файл.
		shapeArr[i]->Save(f_wright);
	fclose(f_wright);

	// Чтение из файла.
	char fileNameRead[20]{ "shapes.bin" };
	FILE* f_read{ nullptr };
	fopen_s(&f_read, fileNameRead, "rb");
	if (f_read == nullptr)
	{
		perror("Error opening");
		exit(1);
	}

	Shape* p_base_class_for_file = nullptr;						// Указатель на базовый класс.
	Shape** shapeArrFromFile = new Shape * [size] {};
	char whatIsThis[20]{ '\0' };
	for (int i = 0; i < size; i++)
	{
		fread(whatIsThis, sizeof(whatIsThis), 1, f_read);
		if (strcmp(whatIsThis, "Square") == 0)					// Определяем какой класс считываем.
		{
			p_base_class_for_file = new Square{ 0,0,0 };
			shapeArrFromFile[i] = p_base_class_for_file;
			shapeArrFromFile[i]->Load(f_read);
		}
		else if (strcmp(whatIsThis, "Rectangl") == 0)			// Определяем какой класс считываем.
		{
			p_base_class_for_file = new Rectangl{ 0,0,0,0 };
			shapeArrFromFile[i] = p_base_class_for_file;
			shapeArrFromFile[i]->Load(f_read);
		}
		else if (strcmp(whatIsThis, "Circle") == 0)				// Определяем какой класс считываем.
		{
			p_base_class_for_file = new Circle{ 0,0,0 };
			shapeArrFromFile[i] = p_base_class_for_file;
			shapeArrFromFile[i]->Load(f_read);
		}
	}
	fclose(f_read);

	// Вывод обьектов, считанных в массив из файла.
	cout << "\n\t\t\t\tFrom file." << endl;
	for (int i = 0; i < size; i++)								// Вывод фигур в консоль.	
		shapeArrFromFile[i]->Show();

	for (int i = 0; i < size; i++)								// Очистка памяти от двумерного динамического массива.
		delete[] shapeArr[i];
	delete[] shapeArr;

	for (int i = 0; i < size; i++)								// Очистка памяти от двумерного динамического массива.
		delete[] shapeArrFromFile[i];
	delete[] shapeArrFromFile;

	return 0;
}