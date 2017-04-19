#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "ShapeDrawer.h"

using namespace std;

int main(int argc, char *agrv)
{
	int size;
	int shape;
	CShapeDrawer drawer;

	while (true)
	{
		cout << "input size : ";
		cin >> size;
		drawer.SetSize(size);

		cout << "choose shape (1. Triangle 2. Star 3. Heart) : ";
		cin >> shape;
		drawer.DrawShape((Shape)shape);
	
		system("pause");
		system("cls");
	}

	return 0;
}