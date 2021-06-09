#include "Dish.h"

bool operator == (const dish_info& d_1, const dish_info& d_2)
{
	return (d_1.dish == d_2.dish) 
		&& (d_1.price == d_2.price) 
		&& (d_1.dish_type == d_2.dish_type) 
		&& (d_1.weight == d_2.weight)
		&& (d_1.restaurant == d_2.restaurant);
}

bool operator != (const dish_info& d_1, const dish_info& d_2)
{
	return !(d_1 == d_2);
}

bool operator > (const dish_info& d_1, const dish_info& d_2)
{
	if (d_1.dish != d_2.dish) return d_1.dish > d_2.dish;
	else if (d_1.price != d_2.price) return d_1.price > d_2.price;
	else if (d_1.dish_type != d_2.dish_type) return d_1.dish_type > d_2.dish_type;
	else if (d_1.weight != d_2.weight) return d_1.weight > d_2.weight;
	else return d_1.restaurant > d_2.restaurant;
}

bool operator < (const dish_info& d_1, const dish_info& d_2)
{
	return d_2 > d_1;
}

bool operator <=(const dish_info& d_1, const dish_info& d_2)
{
	return !(d_1 > d_2);
}

bool operator >=(const dish_info& d_1, const dish_info& d_2)
{
	return !(d_1 < d_2);
}

ostream& operator<< (ostream& out, const dish_info& d)//Перегрузка оператора вывода для элемента структуры
{
	string separator = " - ";
	out << d.dish << separator << d.price << " rubles" << separator << d.dish_type << separator << d.weight << " gramms" << separator << d.restaurant;
	return out;
}
// dish_name, price, dish_type, weight, restaurant_name

void clear(string& s)
{
	if (s[s.size() - 1] == ',')
	{
		s.erase(s.end() - 1);
	}
}

istream& operator>> (istream& in, dish_info& d)
{
	string price_, weight_;
	in >> d.dish >> price_;
	clear(d.dish);
	clear(price_);
label_1:
	try
	{
		d.price = stoi(price_);
	}
	catch (const invalid_argument&)
	{
		cout << "Valid price is a number" << endl;
		cin >> price_;
		goto label_1;
	}
	in >> d.dish_type >> weight_;
	clear(d.dish_type);
	clear(weight_);
label_2:
	try
	{
		d.weight = stoi(weight_);
	}
	catch (const invalid_argument&)
	{
		cout << "Valid weight is a number" << endl;
		cin >> weight_;
		goto label_2;
	}
	in >> d.restaurant;
	clear(d.restaurant);
	return in;
}
