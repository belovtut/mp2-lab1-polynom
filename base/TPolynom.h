#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "TLinkedList.h"
#include "TMonom.h"

#include <iostream>
#include <string>

class TPolynom
{
private:
	TLinkedList<TMonom> monoms;         // Список мономов, составляющих полином

	void transform();                   // Метод для преобразования полинома (удаление нулевых мономов)

public:
	// Конструкторы
	TPolynom() {};                      // Конструктор по умолчанию
	TPolynom(const string& polynom);    // Конструктор с параметром - строкой, представляющей полином
	TPolynom(const TPolynom& other);    // Конструктор копирования

	// Перегрузка оператора вывода для вывода полинома в поток
	friend ostream& operator<<(ostream& os, const TPolynom& polynom);

	void add_monom(const TMonom& monom);                  // Метод для добавления монома к полиному
	double calculate(double x, double y, double z) const; // Метод для вычисления значения полинома в заданной точке
	string to_string() const;                             // Метод для преобразования полинома в строку

	// Перегрузка операторов присваивания и арифметических операторов для полиномов
	TPolynom& operator=(const TPolynom& other);
	TPolynom operator+(const TPolynom& other) const;
	TPolynom operator-(const TPolynom& other) const;
	TPolynom operator*(double number) const;
	TPolynom operator*(const TPolynom& other) const;

	// Комбинированные арифметические операторы для полиномов
	TPolynom& operator+=(const TPolynom& other);
	TPolynom& operator-=(const TPolynom& other);
	TPolynom& operator*=(double number);
	TPolynom& operator*=(const TPolynom& other);

	// Перегрузка операторов сравнения для полиномов
	bool operator==(const TPolynom& other) const;
	bool operator!=(const TPolynom& other) const;

};


#endif
