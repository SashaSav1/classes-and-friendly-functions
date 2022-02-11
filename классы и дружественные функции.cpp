//Разработать программу по объектно - ориентированной технологии с использованием дружественных функций.
//Создать класс Прямоугольник с полями длина и ширина.
//И класс Окружность с полем радиус.
//Для каждого класса написать конструктор с параметрами, метод для вывода на экран,
//методы вычисления площадей фигур.
//Создать дружественную обоим классам функцию, которая проверяет, можно ли поместить прямоугольник в круг.
//Создать по одному объекту каждого класса и вызвать метод вывода на экран и дружественную функцию.

#include <iostream>

using namespace std;

class Kryg;

class Primo
{
private:
	float length;
	float wight;
public:
	Primo(float a, float b)
	{
		length = a;
		wight = b;
	}

	void print()
	{
		cout << "Длинна равна " << length << endl;
		cout << "Ширина равна " << wight << endl;
	}

	float S()
	{
		return length * wight;
	}

	friend bool sravn(const Primo &primo, const Kryg &kryg);
};

class Kryg
{
private:
	float radius;
public:
	Kryg(float a)
	{
		radius = a;
	}

	void print()
	{
		cout << "Радиус круга равен " << radius << endl;
	}

	float S()
	{
		return radius * radius * 3.14;
	}

	friend bool sravn(const Primo &primo, const Kryg &kryg);

};

bool sravn(const Primo &primo, const Kryg &kryg)
{
	float d = sqrt((primo.length * primo.length) + (primo.wight * primo.wight));
	if ((kryg.radius * 2) > d)
		return true;
	else return false;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Kryg a(12.5);
	Primo b(3.4, 6);

	a.print();
	b.print();

	cout << "Площадь круга: " << a.S();
	cout << "Площадь прямоугольника: " << b.S();

	if (sravn(b, a) > 0)
	{
		cout << "Прямоугольник входит в круг";
	}
	else
	{
		cout << "Прямоугольник не входит в круг";
	}

}