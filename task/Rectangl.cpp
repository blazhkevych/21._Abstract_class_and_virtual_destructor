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
	int value_1, value_2, value_3, value_4;
	fread(&value_1, sizeof(value_1), 1, f_read);
	m_topLeftCorner_X = value_1;

	fread(&value_2, sizeof(value_2), 1, f_read);
	m_topLeftCorner_Y = value_2;

	fread(&value_3, sizeof(value_3), 1, f_read);
	width = value_3;

	fread(&value_4, sizeof(value_4), 1, f_read);
	height = value_4;
}