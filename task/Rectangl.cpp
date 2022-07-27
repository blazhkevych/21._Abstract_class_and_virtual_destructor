#include <iostream>
#include "Rectangl.h"
using std::cout;
using std::endl;

// Конструктор с параметрами.
Rectangl::Rectangl(const int m_top_left_corner_x, const int m_top_left_corner_y, const int width, const int height)
	: m_topLeftCorner_X(m_top_left_corner_x),
	m_topLeftCorner_Y(m_top_left_corner_y),
	width(width),
	height(height) {}

// Вывод на экран информации о фигуре.
void Rectangl::Show()
{
	cout << "\tRectangle : " << endl
		<< "m_topLeftCorner_X = " << m_topLeftCorner_X << endl
		<< "m_topLeftCorner_Y = " << m_topLeftCorner_Y << endl
		<< "width = " << width << endl
		<< "height = " << height << endl;
}

// Сохранение фигуры в файл.
void Rectangl::Save(FILE* f_wright)
{
	char str[20] = { "Rectangl" };
	fwrite(str, 20, 1, f_wright);
	fwrite(&m_topLeftCorner_X, sizeof(m_topLeftCorner_X), 1, f_wright);
	fwrite(&m_topLeftCorner_Y, sizeof(m_topLeftCorner_Y), 1, f_wright);
	fwrite(&width, sizeof(width), 1, f_wright);
	fwrite(&height, sizeof(height), 1, f_wright);
}

// Считывание фигуры из файла.
void Rectangl::Load(FILE* f_read)
{
	char value_1[10]{'\0'}, value_2[10]{'\0'}, value_3[10]{'\0'}, value_4[10]{'\0'};
	fgets(value_1, sizeof(int), f_read);
	m_topLeftCorner_X = atoi(value_1);

	fgets(value_2, sizeof(int), f_read);
	m_topLeftCorner_Y = atoi(value_2);

	fgets(value_3, sizeof(int), f_read);
	width = atoi(value_3);

	fgets(value_4, sizeof(int), f_read);
	height = atoi(value_4);
}