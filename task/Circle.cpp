#include <iostream>
#include "Circle.h"
using std::cout;
using std::endl;

// Конструктор с параметрами.
Circle::Circle(const int m_center_coordinate_x, const int m_center_coordinate_y, const int radius)
	: m_centerCoordinate_X(m_center_coordinate_x),
	m_centerCoordinate_Y(m_center_coordinate_y),
	radius(radius) {}

// Вывод на экран информации о фигуре.
void Circle::Show()
{
	cout << "\tCircle : " << endl
		<< "m_centerCoordinate_X = " << m_centerCoordinate_X << endl
		<< "m_centerCoordinate_Y = " << m_centerCoordinate_Y << endl
		<< "radius = " << radius << endl;
}

// Сохранение фигуры в файл.	
void Circle::Save(FILE* f_wright)
{
	char str[20] = { "Circle" };
	fwrite(str, 20, 1, f_wright);
	fwrite(&m_centerCoordinate_X, sizeof(m_centerCoordinate_X), 1, f_wright);
	fwrite(&m_centerCoordinate_Y, sizeof(m_centerCoordinate_Y), 1, f_wright);
	fwrite(&radius, sizeof(radius), 1, f_wright);
}

// Считывание фигуры из файла.
void Circle::Load(FILE* f_read)
{
	char value_1[10]{'\0'}, value_2[10]{'\0'}, value_3[10]{'\0'};
	fgets(value_1, sizeof(int), f_read);
	m_centerCoordinate_X = atoi(value_1);

	fgets(value_2, sizeof(int), f_read);
	m_centerCoordinate_Y = atoi(value_2);

	fgets(value_3, sizeof(int), f_read);
	radius = atoi(value_3);
}