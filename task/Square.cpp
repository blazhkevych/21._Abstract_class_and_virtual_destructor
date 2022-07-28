#include <iostream>
#include "Square.h"
using std::cout;
using std::endl;

// Конструктор с параметрами.
Square::Square(const int m_top_left_corner_x, const int m_top_left_corner_y, const int m_side_length)
	: m_topLeftCorner_X(m_top_left_corner_x),
	m_topLeftCorner_Y(m_top_left_corner_y),
	m_sideLength(m_side_length) {	}

// Вывод на экран информации о фигуре.
void Square::Show()
{
	cout << "\tSquare : " << endl
		<< "m_topLeftCorner_X = " << m_topLeftCorner_X << endl
		<< "m_topLeftCorner_Y = " << m_topLeftCorner_Y << endl
		<< "m_sideLength = " << m_sideLength << endl;
}

// Сохранение фигуры в файл.	
void Square::Save(FILE* f_wright)
{
	char str[20] = { "Square" };
	fwrite(str, 20, 1, f_wright);
	int q = m_topLeftCorner_X;
	fwrite(&m_topLeftCorner_X, sizeof(m_topLeftCorner_X), 1, f_wright);
	fwrite(&m_topLeftCorner_Y, sizeof(m_topLeftCorner_Y), 1, f_wright);
	fwrite(&m_sideLength, sizeof(m_sideLength), 1, f_wright);
}

// Считывание фигуры из файла.
void Square::Load(FILE* f_read)
{
	int value_1, value_2, value_3;
	fread(&value_1, sizeof(value_1), 1, f_read);
	m_topLeftCorner_X = value_1;

	fread(&value_2, sizeof(value_2), 1, f_read);
	m_topLeftCorner_Y = value_2;

	fread(&value_3, sizeof(value_3), 1, f_read);
	m_sideLength = value_3;
}