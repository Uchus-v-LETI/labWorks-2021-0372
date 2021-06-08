#pragma once
#include "Dish.h"
#include <vector>
#include <algorithm>
#include <iomanip>

class Menu
{
private:
	vector <dish_info> menu;
public:
	bool flag_for_changes = false;

	void Print(ostream& out);

	size_t size();

	void Add(const dish_info& d);
	// добавление записи в конец бд

	void Delete(size_t N);
	// удаление н-ной записи в бд

	void Edit(size_t N);
	// редактирование н-ной записи в бд

	void Display(ostream& out);
	// вывод бд в виде таблицы

	vector<dish_info> Find_dish(const string& dish);
	vector<dish_info> Find_price(int price);
	vector<dish_info> Find_dish_type(const string& dish_type);
	vector<dish_info> Find_weight(int weight);
	vector<dish_info> Find_restaurant(const string& restaurant);
	// поиск всех блюд с указанным параметром

	void Sort_A_O();
	void Sort_A_O_by_price();
	void Sort_A_O_by_dish_type();
	void Sort_A_O_by_weight();
	void Sort_A_O_by_restaurant();
	// сортировка бд в возрастающем порядке по указанному параметру

	void Sort_D_O();
	void Sort_D_O_by_price();
	void Sort_D_O_by_dish_type();
	void Sort_D_O_by_weight();
	void Sort_D_O_by_restaurant();
	// сортировка бд в убывающем порядке по указанному параметру

	double Arithmetic_mean_price();
	double Arithmetic_mean_weight();
	int Min_price();
	int Max_price();
	int Min_weight();
	int Max_weight();
};

size_t n_size(int n);
