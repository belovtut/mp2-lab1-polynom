#ifndef __MONOM_H__
#define __MONOM_H__

#include <iostream>
#include <sstream>

using namespace std;

struct TMonom
{
	// Минимальная и максимальная степень монома
	static const unsigned int MIN_DEGREE = 0;
	static const unsigned int MAX_DEGREE = 9;

	double coefficient = 1.0; // Коэффициент монома
	unsigned int degree = 0;  // Степень монома

	// Конструкторы
	TMonom(double _coef = 0.0, unsigned int _deg = 0);  // Конструктор с параметрами
	TMonom(const string& str);                          // Конструктор из строки

	// Перегруженный оператор вывода в поток
	friend ostream& operator<<(ostream& os, const TMonom& monom);

	// Операторы сравнения
	bool operator<(const TMonom& other) const;
	bool operator>(const TMonom& other) const;
	bool operator==(const TMonom& other) const;
	bool operator!=(const TMonom& other) const;

	// Метод для проверки эквивалентности степеней двух мономов
	bool equals(const TMonom& other) const;

	// Оператор умножения мономов
	TMonom operator*(const TMonom& other) const;

	// Метод для вычисления значения монома в заданных точках
	double calculate(double x, double y, double z) const; 

	// Метод преобразования монома в строку
	string to_string() const;
};

#endif