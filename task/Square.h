#pragma once
#include "Shape.h"
#include <ostream>
using std::ostream;

// Square — квадрат, который характеризуется координатами левого
// верхнего угла и длиной стороны.
class Square : public Shape
{
	int m_topLeftCorner_X;							// Координата X левого верхнего угла.
	int m_topLeftCorner_Y;							// Координата Y левого верхнего угла.
	int m_sideLength;								// Длина стороны.
public:
	// Конструктор с параметрами.
	Square(const int m_top_left_corner_x, const int m_top_left_corner_y, const int m_side_length);
	// Методы :
	virtual void Show() override;					// Вывод на экран информации о фигуре.
	void Save(FILE* f_wright) override;				// Сохранение фигуры в файл.	
	void Load(FILE* f_read) override;				// Считывание фигуры из файла.
};