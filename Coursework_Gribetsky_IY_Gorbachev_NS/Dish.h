#pragma once
#include <iostream>
#include <string>

using namespace std;
struct dish_info		// структура для хранения всей информации про определенное блюдо
{
	string dish;		// название блюда
	int price = 0;			// его стоимость
	string dish_type;	// тип блюда
	int weight = 0;			// вес блюда
	string restaurant;  // ресторан, в котором его подают
};

// перегрузка операторов сравнения

bool operator == (const dish_info& s_1, const dish_info& s_2);
// все параметры должны быть одинаковые

bool operator != (const dish_info& s_1, const dish_info& s_2);
// хотя бы 1 параметр у блюд отличается

bool operator > (const dish_info& s_1, const dish_info& s_2); 
// если нет дополнительного условия, то сравнение идет в следующем порядке: название -> стоимость -> тип -> вес -> ресторан

bool operator < (const dish_info& s_1, const dish_info& s_2);
bool operator <=(const dish_info& s_1, const dish_info& s_2);
bool operator >=(const dish_info& s_1, const dish_info& s_2);

// перегрузка операторов ввода и вывода с потока

ostream& operator<< (ostream& out, const dish_info& d);
// пример: "cabbage pie - 100 rubles - baked products - 350 gramms - Teremok auto"

istream& operator>> (istream& in, dish_info& d);
// как должна выглядеть строка на входе: dish_name, price, dish_type, weight, restaurant_name

void clear(string& s);
