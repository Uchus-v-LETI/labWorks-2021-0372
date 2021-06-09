#pragma once
#include <iostream>
#include <string>

using namespace std;
struct dish_info		//Структура объекта
{
	string dish;		//название
	int price = 0;			//цена
	string dish_type;	//тип
	int weight = 0;			//вес
	string restaurant;  //заведение
};

//Перегрузка операторов, для дальнейшего использования в сортировках и других функциях

bool operator == (const dish_info& s_1, const dish_info& s_2);
bool operator != (const dish_info& s_1, const dish_info& s_2);

bool operator > (const dish_info& s_1, const dish_info& s_2); 
bool operator < (const dish_info& s_1, const dish_info& s_2);
bool operator <=(const dish_info& s_1, const dish_info& s_2);
bool operator >=(const dish_info& s_1, const dish_info& s_2);

ostream& operator<< (ostream& out, const dish_info& d);
// ������: "cabbage pie - 100 rubles - baked products - 350 gramms - Teremok auto"

istream& operator>> (istream& in, dish_info& d);
// ��� ������ ��������� ������ �� �����: dish_name, price, dish_type, weight, restaurant_name

void clear(string& s);