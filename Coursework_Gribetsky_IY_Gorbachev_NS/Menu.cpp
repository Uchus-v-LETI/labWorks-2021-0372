#include "Menu.h"

void Default_and_encrypt(string& s)
{
	for (char& a : s)
	{
		if (a == ' ')
		{
			a = '_';
		}
		if (a >= 97 && a <= 122)
		{
			a -= 11;
			if (a < 97)
			{
				a += 26;
			}
		}
	}
	
}

void Menu::Print(ostream& out)
{
	for (dish_info d : menu)
	{
		Default_and_encrypt(d.dish);
		Default_and_encrypt(d.dish_type);
		Default_and_encrypt(d.restaurant);
		out << d.dish << ", " << d.price << ", " << d.dish_type << ", " << d.weight << ", " << d.restaurant << endl;
	}
	return;

}

size_t Menu::size()
{
	return menu.size();
}

void Menu::Add(const dish_info& d)
{
	bool flag = true;
	for (const dish_info a : menu)
	{
		if (a == d)
		{
			flag = false;
		}
	}
	if (flag) 
	{
		menu.push_back(d);
	}
	flag_for_changes = true;
	//return;
}

void Menu::Delete(size_t N)
{
	while (N > menu.size() || N < 1)
	{
		cout << "Enter valid dish number" << endl;
		cin >> N;
	};
	N--;
	menu.erase(menu.begin() + N);
	flag_for_changes = true;
	//return;
}

void Menu::Edit(size_t N)
{
	while (N > menu.size() || N < 1)
	{
		cout << "Enter valid dish number" << endl;
		cin >> N;
	};
	N--;
	cout << "What parameter(1-5) do you want to edit?" << endl;
	int p;
	do 
	{
		cin >> p;
	} while (p < 1 || p > 5);
	if (p == 1)
	{
		cout << "How it is called?" << endl;
		cin >> menu[N].dish;
	}
	else if (p == 2)
	{
		cout << "How much does it cost?" << endl;
		string price_;
	label_3:
		try
		{
			menu[N].price = stoi(price_);
		}
		catch (const invalid_argument&)
		{
			cout << "Valid price is a number" << endl;
			cin >> price_;
			goto label_3;
		}
	}
	else if (p == 3)
	{
		cout << "What type of food it is?" << endl;
		cin >> menu[N].dish_type;
	}
	else if (p == 4)
	{
		cout << "How much does it weigh?" << endl;
		string weight_;
	label_4:
		try
		{
			menu[N].weight = stoi(weight_);
		}
		catch (const invalid_argument&)
		{
			cout << "Valid weight is a number" << endl;
			cin >> weight_;
			goto label_4;
		}
	}
	else if (p == 5)
	{
		cout << "Where it is served?" << endl;
		cin >> menu[N].restaurant;
	}
	bool flag = true;
	for (size_t i = 0; i < menu.size(); i++)
	{
		if (i != N && menu[i] == menu[N])
		{
			flag = false;
			cout << "Identical dishes removed" << endl;
		}
	}
	if (!flag)
	{ 
		menu.erase(menu.begin() + N);
	}
	flag_for_changes = true;
}

size_t n_size(int n)
{
	size_t result = 0;
	do
	{
		result++;
		n /= 10;
	} while (n != 0);
	return result;
}
// количество разрядов в числе

void Menu::Display(ostream& out)
{
	if (menu.size() == 0)
	{
		out << "There are no dishes in menu, add at least 1 to start working with it" << endl;
		return;
	}
	cout << "0 - dish number" << endl
		<< "1 - dish itself" << endl
		<< "2 - price of the dish" << endl
		<< "3 - type of the dish" << endl
		<< "4 - weight of rhe dish" << endl
		<< "5 - restaurant where the dish is served" << endl;
	cout << setw(n_size(menu.size())) << "0" << "|" 
		<< setw(30) <<					 "1" << "|"
		<< setw(n_size(Max_price())) <<  "2" << "|"
		<< setw(30) <<					 "3" << "|"
		<< setw(n_size(Max_weight())) << "4" << "|"
		<< setw(30) <<					 "5" << "|" << endl;
	for (size_t i = 0; i < menu.size(); i++)
	{
		cout << setw(n_size(menu.size())) << i+1 << "|"
			<< setw(30) << menu[i].dish << "|"
			<< setw(n_size(Max_price())) << menu[i].price << "|"
			<< setw(30) << menu[i].dish_type << "|"
			<< setw(n_size(Max_weight())) << menu[i].weight << "|"
			<< setw(30) << menu[i].restaurant << "|" << endl;
	}
	cout << endl;
}


vector<dish_info> Menu::Find_dish(const string& dish)
{
	vector <dish_info> result;
	for (size_t i = 0; i < menu.size(); i++)
	{
		if (menu[i].dish == dish)
		{
			result.push_back(menu[i]);
		}
	}
	return result;
}
vector<dish_info> Menu::Find_price(int price)
{
	vector <dish_info> result;
	for (size_t i = 0; i < menu.size(); i++)
	{
		if (menu[i].price == price)
		{
			result.push_back(menu[i]);
		}
	}
	return result;
}
vector<dish_info> Menu::Find_dish_type(const string& dish_type)
{
	vector <dish_info> result;
	for (size_t i = 0; i < menu.size(); i++)
	{
		if (menu[i].dish_type == dish_type)
		{
			result.push_back(menu[i]);
		}
	}
	return result;
}
vector<dish_info> Menu::Find_weight(int weight)
{
	vector <dish_info> result;
	for (size_t i = 0; i < menu.size(); i++)
	{
		if (menu[i].weight == weight)
		{
			result.push_back(menu[i]);
		}
	}
	return result;
}
vector<dish_info> Menu::Find_restaurant(const string& restaurant)
{
	vector <dish_info> result;
	for (size_t i = 0; i < menu.size(); i++)
	{
		if (menu[i].restaurant == restaurant)
		{
			result.push_back(menu[i]);
		}
	}
	return result;
}


void Menu::Sort_A_O()
{
	sort(menu.begin(), menu.end(), [](const dish_info& d_1, const dish_info& d_2) { return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}
void Menu::Sort_A_O_by_price()
{
	sort(menu.begin(), menu.end(), [](const dish_info& d_1, const dish_info& d_2) 
		{ if (d_1.price != d_2.price) return d_1.price < d_2.price; else return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}
void Menu::Sort_A_O_by_dish_type()
{
	sort(menu.begin(), menu.end(), [](const dish_info& d_1, const dish_info& d_2) 
		{ if (d_1.dish_type != d_2.dish_type) return d_1.dish_type < d_2.dish_type; else return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}
void Menu::Sort_A_O_by_weight()
{
	sort(menu.begin(), menu.end(), [](const dish_info& d_1, const dish_info& d_2)
		{ if (d_1.weight != d_2.weight) return d_1.weight < d_2.weight; else return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}
void Menu::Sort_A_O_by_restaurant()
{
	sort(menu.begin(), menu.end(), [](const dish_info& d_1, const dish_info& d_2)
		{ if (d_1.restaurant != d_2.restaurant) return d_1.restaurant < d_2.restaurant; else return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}


void Menu::Sort_D_O()
{
	sort(menu.rbegin(), menu.rend(), [](const dish_info& d_1, const dish_info& d_2) { return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}
void Menu::Sort_D_O_by_price()
{
	sort(menu.rbegin(), menu.rend(), [](const dish_info& d_1, const dish_info& d_2)
		{ if (d_1.price != d_2.price) return d_1.price < d_2.price; else return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}
void Menu::Sort_D_O_by_dish_type()
{
	sort(menu.rbegin(), menu.rend(), [](const dish_info& d_1, const dish_info& d_2)
		{ if (d_1.dish_type != d_2.dish_type) return d_1.dish_type < d_2.dish_type; else return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}
void Menu::Sort_D_O_by_weight()
{
	sort(menu.rbegin(), menu.rend(), [](const dish_info& d_1, const dish_info& d_2)
		{ if (d_1.weight != d_2.weight) return d_1.weight < d_2.weight; else return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}
void Menu::Sort_D_O_by_restaurant()
{
	sort(menu.rbegin(), menu.rend(), [](const dish_info& d_1, const dish_info& d_2)
		{ if (d_1.restaurant != d_2.restaurant) return d_1.restaurant < d_2.restaurant; else return d_1 < d_2; });
	flag_for_changes = true;
	//return;
}


double Menu::Arithmetic_mean_price()
{
	double result = 0;
	for (size_t i = 0; i < menu.size(); i++)
	{
		result += 1.0 * menu[i].price / menu.size();
	}
	return result;
}
double Menu::Arithmetic_mean_weight()
{
	double result = 0;
	for (size_t i = 0; i < menu.size(); i++)
	{
		result += 1.0 * menu[i].weight / menu.size();
	}
	return result;
}
int Menu::Min_price()
{
	int result = menu[0].price;
	for (size_t i = 1; i < menu.size(); i++)
	{
		if (menu[i].price < result)
		{
			result = menu[i].price;
		}
	}
	return result;
}
int Menu::Max_price()
{
	int result = menu[0].price;
	for (size_t i = 1; i < menu.size(); i++)
	{
		if (menu[i].price > result)
		{
			result = menu[i].price;
		}
	}
	return result;
}
int Menu::Min_weight()
{
	int result = menu[0].weight;
	for (size_t i = 1; i < menu.size(); i++)
	{
		if (menu[i].weight < result)
		{
			result = menu[i].weight;
		}
	}
	return result;
}
int Menu::Max_weight()
{
	int result = menu[0].weight;
	for (size_t i = 1; i < menu.size(); i++)
	{
		if (menu[i].weight > result)
		{
			result = menu[i].weight;
		}
	}
	return result;
}