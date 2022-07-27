#pragma once
#include "Shape.h"

// Rectangl — прямоугольник с заданными координатами левого
// верхнего угла и размерами.
class Rectangl : public Shape
{
	int m_topLeftCorner_X;							// Координата X левого верхнего угла.
	int m_topLeftCorner_Y;							// Координата Y левого верхнего угла.
	int width;										// Ширина.
	int height;										// Высота.
public:
	// Конструктор с параметрами.
	Rectangl(const int m_top_left_corner_x, const int m_top_left_corner_y, const int width, const int height);
	// Методы :
	virtual void Show() override;					// Вывод на экран информации о фигуре.
	void Save(FILE* f_wright) override;				// Сохранение фигуры в файл.	
	void Load(FILE* f_read) override;				// Считывание фигуры из файла.
};