#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "TStack.h"
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class TPostfix
{
private:
	string infix;                       // Входное инфиксное выражение
	vector<string> postfix;             // Постфиксное выражение
	vector<string> lexems;              // Лексемы инфиксного выражения
	static map<char, int> priority;     // Приоритет операторов
	map<string, double> operands;       // Операнды с их значениями
	set<string> parsed_operands;        // Множество уже разобранных операндов

	void Parse();                       // Разбиение инфиксного выражения на лексемы
	void ToPostfix();                   // Преобразование инфиксного выражения в постфиксное

public:
	TPostfix(string infx = "a+b*c");    // Конструктор класса, принимает строку инфиксного выражения

	string GetInfix() const;            // Получение инфиксного выражения
	vector<string> GetPostfix() const;  // Получение постфиксного выражения
	vector<string> GetOperands() const; // Получение списка операндов

	double Calculate(const map<string, double>& values = {}); // Вычисление значения выражения
};

#endif