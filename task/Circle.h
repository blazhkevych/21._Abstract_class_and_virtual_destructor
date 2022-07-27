#pragma once
#include "Shape.h"

// Circle — окружность с заданными координатами центра и радиусом.
class Circle final : public Shape
{
	int m_centerCoordinate_X;					// Координата центра по X.
	int m_centerCoordinate_Y;					// Координата центра Y.
	int radius;									// Радиус.
public:
	// Конструктор с параметрами.
	Circle(const int m_center_coordinate_x, const int m_center_coordinate_y, const int radius);
	// Методы :
	virtual void Show() override;				// Вывод на экран информации о фигуре.
	void Save(FILE* f_wright) override;			// Сохранение фигуры в файл.	
	void Load(FILE* f_read) override;			// Считывание фигуры из файла.
};