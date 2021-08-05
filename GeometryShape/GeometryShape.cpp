#include <iostream>
#include <fstream>
#include <string>

//Создайте абстрактный класс Shape для рисования плоских фигур.Определите виртуальные методы :
//•	Show() — вывод на экран информации о фигуре,
//•	Save() — сохранение фигуры в файл,
//•	Load() — считывание фигуры из файла.Определите производные классы :
//•	Square — квадрат, который характеризуется
//  координатами левого верхнего угла и длиной стороны;
//•	Rectangle — прямоугольник с заданными координатами верхнего левого угла и размерами;
//•	Circle — окружность с заданными координатами цен - тра и радиусом;
//•	Ellipse — эллипс с заданными координатами верхнего угла описанного вокруг него прямоугольника со сто - ронами, параллельными осям координат, и размерами этого прямоугольника.
//Создайте массив фигур, сохраните фигуры в файл, загру - зите в другой массив и отобразите информацию о каждой из фигур.

//Create an abstract Shape class for drawing flat shapes.Define virtual methods :
// • Show () - display information about the figure,
// • Save () - save the shape to a file,
// • Load () - reading the shape from the file. Define derived classes:
// • Square - a square that characterizes
//  the coordinates of the upper left corner and side length;
// • Rectangle - a rectangle with the specified coordinates of the upper left corner and dimensions;
// • Circle - a circle with the specified center coordinates and radius;
// • Ellipse - an ellipse with the specified coordinates of the upper corner of the rectangle described around it with sides parallel to the coordinate axes, and the dimensions of this rectangle.
// Create an array of shapes, save the shapes to a file, load into another array, and display information about each of the shapes.




using namespace std;

class Shape {
protected:
	int x;
	int y;
public:
	Shape(int x, int y)
		:x{ x }, y{ y } {}
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;

};

class Square : public Shape {
private:
	double a;
public:
	Square(int x, int y, double a)
		:Shape(x, y), a{ a } {}

	void Show() {
		cout << "Координаты верхнего левого угла (" << x << ';' << y << ')' << endl;
		cout << "Длинна стороны:" << a << endl;
	}
	void Save() {
		ofstream out("file.txt", ios::app);
		if (out.is_open())
		{
			out << "Квадрат: " << endl;
			out << "Координаты верхнего левого угла (" << x << ';' << y << ')' << endl;
			out << "Длинна стороны:" << a << endl;
		}
		out.close();
	}
	void Load() {
		string square_info;
		ifstream in("file.txt");
		if (in.is_open()) {
			while (getline(in, square_info)) {
				cout << square_info << endl;
			}
		}
	}
};

class Rectangle : public Shape {
protected:
	double a;
	double b;
public:
	Rectangle(int x, int y, double a, double b)
		:Shape(x, y), a{ a }, b{ b } {}

	void Show() {
		cout << "Координаты верхнего левого угла (" << x << ';' << y << ')' << endl;
		cout << "Длинна сторон " << "a=" << a << "b=" << b << endl;
	}
	void Save() {
		ofstream out("file.txt", ios::app);
		if (out.is_open())
		{
			out << "Прямоугольник: " << endl;
			out << "Координаты верхнего левого угла (" << x << ';' << y << ')' << endl;
			out << "Длинна сторон " << "a=" << a << " b=" << b << endl;
			out << endl;
		}
		out.close();
	}
	void Load() {
		string rect_info;
		ifstream in("file.txt");
		if (in.is_open()) {
			while (getline(in, rect_info)) {
				cout << rect_info << endl;
				cout << endl;
			}
		}
	}
};

class Circle : public Shape {
private:
	double rad;
public:
	Circle(int x, int y, double rad)
		:Shape(x, y), rad{ rad } {}

	void Show() {
		cout << "Координаты центра (" << x << ';' << y << ')' << endl;
		cout << "Радиус: " << rad << endl;
	}
	void Save() {
		ofstream out("file.txt", ios::app);
		if (out.is_open())
		{
			out << "Круг: " << endl;
			out << "Координаты центра (" << x << ';' << y << ')' << endl;
			out << "Радиус: " << "a=" << rad << endl;
			out << endl;
		}
		out.close();
	}
	void Load() {
		string circle_info;
		ifstream in("file.txt");
		if (in.is_open()) {
			while (getline(in, circle_info)) {
				cout << circle_info << endl;
				cout << endl;
			}
		}
	}
};

class Ellipse : public Rectangle {
private:
	double big_rad;
	double small_rad;
public:
	Ellipse(int x, int y, double a, double b)
		: Rectangle(x, y, a, b) {}

	void Show() {
		cout << "Координаты верхнего левого угла описанный вокруг элипса (" << x << ';' << y << ')' << endl;
		cout << "Длинна сторон " << "a=" << a << "b=" << b << endl;
		cout << "Больший радиус элипса: " << b / 2 << endl;
		cout << "Меньший радиус элипса: " << a / 2 << endl;
	}
	void Save() {
		ofstream out("file.txt", ios::app);
		if (out.is_open())
		{
			out << "Координаты верхнего левого угла описанный вокруг элипса (" << x << ';' << y << ')' << endl;
			out << "Длинна сторон " << "a=" << a << "b=" << b << endl;
			out << "Больший радиус элипса: " << b / 2 << endl;
			out << "Меньший радиус элипса: " << a / 2 << endl;
		}
		out.close();
	}
	void Load() {
		string elipse_info;
		ifstream in("file.txt");
		if (in.is_open()) {
			while (getline(in, elipse_info)) {
				cout << elipse_info << endl;
				cout << endl;
			}
		}
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Square sq(1, 1, 4);
	Rectangle rec(2, 2, 3, 6);
	Circle cir(4, 4, 8);
	Ellipse ell(7, 8, 4, 12);

	//sq.Save();
	//rec.Save();
	//cir.Save();
	//ell.Save();

	sq.Load();
}
