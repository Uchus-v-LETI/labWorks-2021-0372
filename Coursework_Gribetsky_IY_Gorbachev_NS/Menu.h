#pragma once//защита от повторного включения
#include "Dish.h"
#include <vector>
#include <algorithm>
#include <iomanip>

class Menu
{
private:
	vector <dish_info> menu;
public:
	bool flag_for_changes = false;//есть ли изменения в БД

	void Print(ostream& out);//Вывод БД в поток для записи в файл

	unsigned size();

	void Add(const dish_info& d);//Добавление в меню

	void Delete(unsigned N);//Удаление из меню

	void Edit(unsigned N);//Редактирование

	void Display(ostream& out);//Вывод меню в виде таблицы

	vector<dish_info> Find_dish(const string& dish);//Поиск по названию
	vector<dish_info> Find_price(int price);//Поиск по цене
	vector<dish_info> Find_dish_type(const string& dish_type);//Поиск по типу
	vector<dish_info> Find_weight(int weight);//Поиск по весу
	vector<dish_info> Find_restaurant(const string& restaurant);//Поиск по заведению

	void Sort_A_O();//Восходящий порядок
	void Sort_A_O_by_price();
	void Sort_A_O_by_dish_type();
	void Sort_A_O_by_weight();
	void Sort_A_O_by_restaurant();

	void Sort_D_O();//Нисходящий порядок
	void Sort_D_O_by_price();
	void Sort_D_O_by_dish_type();
	void Sort_D_O_by_weight();
	void Sort_D_O_by_restaurant();
};