// Дан список городов и кол-во жителей в каждом городе. Упорядочить по возрастанию числа жителей.
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct City
{
	string name;
	long int population = 0;
};

void Shell_Sort(vector<City>& array, int size)
{
	int temp1, j;
	string temp2;
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			temp1 = array[i].population;
			temp2 = array[i].name;
			for (j = i; j >= step; j -= step)
			{
				if (temp1 < array[j - step].population)
				{
					array[j].population = array[j - step].population;
					array[j].name = array[j - step].name;
				}
				else break;
			}
			array[j].population = temp1;
			array[j].name = temp2;
		}
	}
}

void Hoare(vector <City>& list, int left, int right)
{
	long int pivot = list[(left + right) / 2].population;
	int l = left;
	int j = right;
	do
	{
		while ((list[l].population < pivot) && (l < right))
		{
			l++;
		}
		while ((list[j].population > pivot) && (j > left))
		{
			j--;
		}
		if (l <= j)
		{
			swap(list[l], list[j]);
			l++;
			j--;
		}

	} while (l <= j);

	if (j > left)
		Hoare(list, left, j);
	if (l < right)
		Hoare(list, l, right);
}

int main()
{
	system("chcp 1251 > nul");
	setlocale(LC_ALL, "ru");
	int size, left = 0;
	cout << "Введите кол-во городов: ";
	cin >> size;
	cout << endl;
	vector <City> city(size);
	for (int i = 0; i < size; i++)
	{
		cout << "Город: ";
		cin >> city[i].name;
		cout << "Численость населения: ";
		cin >> city[i].population;
	}
	cout << endl;
	int menu = -1;
	while (menu != 1 && menu != 2)
	{
		cout << "Выбери метод сортировки: \n 1. Хоара \n 2. Шелла \n Ввод: ";
		cin >> menu;
	}
	if (menu == 2)
		Shell_Sort(city, size);
	if (menu == 1)
		Hoare(city, left, size - 1);
	cout << "Результат:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << city[i].name << ": " << city[i].population << endl;
	}
}
