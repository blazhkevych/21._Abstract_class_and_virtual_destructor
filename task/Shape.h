#pragma once
#include <cstdio>

// Абстрактный класс Shape для рисования плоских фигур.
class Shape abstract
{
public:
	virtual void Show() abstract;								// Вывод на экран информации о фигуре.	
	virtual void Save(FILE* f_wright) abstract;					// Сохранение фигуры в файл.	
	virtual void Load(FILE* f_read) abstract;					// Считывание фигуры из файла.
	virtual ~Shape();											// Деструктор.
};