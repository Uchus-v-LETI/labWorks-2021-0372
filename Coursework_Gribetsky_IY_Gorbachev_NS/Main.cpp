#include "Menu.h"
#include <fstream>
#include <sstream>

void Options()//Функционал программы
{
	cout << " Options: " << endl
		<< "0) Exit" << endl
		<< "1) Add a dish" << endl
		<< "2) Edit a dish" << endl
		<< "3) Delete a dish" << endl
		<< "4) Sort a menu" << endl
		<< "5) Find a dish" << endl
		<< "6) Current menu" << endl;
}

void table(const vector <dish_info>& menu)//Вывод блюд, найденных в поиске
{
	if (menu.size() == 0)
	{
		cout << "There are no dishes";
	}
	for (unsigned i = 0; i < menu.size(); i++)
	{
		cout << setw(2) << i + 1 << "|"
			<< setw(20) << menu[i].dish << "|"
			<< setw(10) << menu[i].price << "|"
			<< setw(20) << menu[i].dish_type << "|"
			<< setw(10) << menu[i].weight << "|"
			<< setw(20) << menu[i].restaurant << "|" << endl;
	}
	cout << endl;
}

void Find_s(Menu& menu)//Поиск по параметрам
{
	string answer;
	do
	{
		cout << "What parameter you want to find?(1-5)" << endl;
		cin >> answer;
	} while (answer < "1" || answer > "5");
	vector <dish_info> result;
	if (answer == "1")
	{
		string dish;
		cout << "What dish do you want to find?" << endl;
		cin >> dish;
		result = menu.Find_dish(dish);
	}
	if (answer == "2")
	{
		int price;
		cout << "How much dishes have to cost?" << endl;
		string price_;
		cin >> price_;
		clear(price_);
	label_p:
		try
		{
			price = stoi(price_);
		}
		catch (const invalid_argument&)
		{
			cout << "Valid price is a number" << endl;
			cin >> price_;
			goto label_p;
		}
		result = menu.Find_price(price);
	}
	if (answer == "3")
	{
		string dish_type;
		cout << "What dish type do you want to find?" << endl;
		cin >> dish_type;
		result = menu.Find_dish_type(dish_type);
	}
	if (answer == "4")
	{
		int weight;
		cout << "How much dishes have to weigh?" << endl;
		string weight_;
		cin >> weight_;
		clear(weight_);
	label_w:
		try
		{
			weight = stoi(weight_);
		}
		catch (const invalid_argument&)
		{
			cout << "Valid price is a number" << endl;
			cin >> weight_;
			goto label_w;
		}
		result = menu.Find_weight(weight);
	}
	if (answer == "5")
	{
		string restaurant;
		cout << "What restaurant do you want to find?" << endl;
		cin >> restaurant;
		result = menu.Find_restaurant(restaurant);
	}
	table(result);
}

void Sort_s(Menu& menu)//Сортировки
{
	int answer_1;
	do 
	{ 
		cout << "Do you want to sort menu in ascending or descending order?(1/2)" << endl;
		cin >> answer_1; 
	} while (answer_1 != 1 && answer_1 != 2);

	int answer_2;
	do
	{
		cout << "By which parameter do you want to sort the menu?(1-5)" << endl;
		cin >> answer_2;
	} while (answer_2 < 1 || answer_2 > 5);

	if (answer_1 == 1)
	{
		switch (answer_2)
		{
		case 1:
			menu.Sort_A_O();
			break;
		case 2:
			menu.Sort_A_O_by_price();
			break;
		case 3:
			menu.Sort_A_O_by_dish_type();
			break;
		case 4:
			menu.Sort_A_O_by_weight();
			break;
		case 5:
			menu.Sort_A_O_by_restaurant();
			break;
		}
	}
	if (answer_1 == 2)
	{
		switch (answer_2)
		{
		case 1:
			menu.Sort_D_O();
			break;
		case 2:
			menu.Sort_D_O_by_price();
			break;
		case 3:
			menu.Sort_D_O_by_dish_type();
			break;
		case 4:
			menu.Sort_D_O_by_weight();
			break;
		case 5:
			menu.Sort_D_O_by_restaurant();
			break;
		}
	}
	menu.Display(cout);
}

void Chosen_option(Menu& menu)
{
	while (menu.size() == 0)
	{
		cout << "There are no dishes in menu, add at least 1 to start working with it" << endl;
		cout << "Valid format for a dish is: \"dish_name, price, dish_type, weight, restaurant_name\"" << endl;
		dish_info d;
		cin >> d;
		menu.Add(d);
	}
	char opt_;
	Options();
	do
	{
		cout << "Choose an option" << endl;
		cin >> opt_;
	} while (opt_ < '0' || opt_ > '8');
	int opt = opt_ - '0';
	if (opt == 0)
	{
		if(menu.flag_for_changes)
		{
			cout << "Do you want to exit without a save?(1 - Save and exit, 0 - Exit without a save)" << endl;
			bool save = false;
			cin >> save;
			if (save)
			{
				ofstream file;//поток записи данных в файл
				string path;
				cout << "Enter the path to the file: ";
				cin >> path;
				file.open(path);
				while (!file.is_open())
				{
					cout << "Enter correct path to the file: ";
					cin >> path;
					file.open(path);
				}
				menu.Print(file);
				file.close();
			}
			menu.flag_for_changes = false;
		}
		return;
	}
	dish_info d;
	unsigned n;
	string n_;
	switch (opt)
	{
	case 1:
		cout << "Valid Format for a dish is: \"dish_name, price, dish_type, weight, restaurant_name\"" << endl;
		cin >> d;
		menu.Add(d);
		break;
	case 2:
		cout << "What dish do you want to edit?" << endl;
		cin >> n_;
		while (n_ < "0\n" || n_ > (to_string(menu.size())+"\n"))
		{
			cout << "Enter a valid number" << endl;
			cin >> n_;
		} 
		n = stoi(n_);
		menu.Edit(n);
		break;
	case 3:
		cout << "What dish do you want to delete?" << endl;
		cin >> n_;
		while (n_ < "0\n" || n_ >(to_string(menu.size()) + "\n"))
		{
			cout << "Enter a valid number" << endl;
			cin >> n_;
		} 
		n = stoi(n_);
		menu.Delete(n);
		break;
	case 4:
		Sort_s(menu);
		break;
	case 5:
		Find_s(menu);
		break;
	case 6:
		menu.Display(cout);
		break;
	}
	Chosen_option(menu);
}

int main()
{
	ifstream file;//поток для чтения из файла
	string path;
	cout << "Enter the path to the file: ";
	cin >> path;
	file.open(path);
	while (!file.is_open())
	{
		cout << "The path to the file is incorrect, try again: ";
		cin >> path;
		file.open(path);
	} 
	Menu menu;
	string s;
	dish_info d;
	while (getline(file, s))
	{
		stringstream ss(s);
		ss >> d; 
		menu.Add(d);
	}
	file.close();
	
	menu.Display(cout);
	Chosen_option(menu);
	return 0;
}