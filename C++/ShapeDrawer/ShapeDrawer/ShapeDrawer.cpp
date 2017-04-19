#include "ShapeDrawer.h"

using namespace std;

void CShapeDrawer::drawTrinangle()
{
	/*int row, temp;

	temp = size;
	for (row = 1; row <= size; row++)
	{
		for (int i = 1; i < temp; i++)
		{
			cout << " ";
		}
		temp--;

		for (int i = 1; i <= 2 * row - 1; i++)
		{
			cout << "*";
		}
		cout << endl;
	}*/

	for (int i = size, j = 0; i > 0, j < size; i--, j++)
	{
		if (i == size)
		{
			cout.width(i);	cout << "*";
		}
		else if (i == 1)
		{
			for (int k = 0; k < size; k++)
			{
				cout << "*";
				cout.width(2);
			}
		}
		else if (0 < i || size > i)
		{
			cout.width(i);
			cout << "*";

			cout.width(j * 2);
			cout << "*";
		}
		cout << endl;
	}
}

void CShapeDrawer::drawStar()
{
	//cout << "º° x " << size;

	for (int i = size, j = 0; i > 0, j < size; i--, j++)
	{
		if (i == size)
		{
			cout.width(i + size + 1);	
			cout << "*";
		}
		else if (0 < i || size > i)
		{
			cout.width(i + size + 1);	
			cout << "*";
			
			cout.width(j * 2); 
			cout << "*";
		}
		cout << endl;
	}

	for (int i = size, j = 0; j < size / 2; i--, j++)
	{
		if (i == size)
		{
			cout.fill('*'); 
			cout.width(size + 1); 
			cout << "";

			cout.fill(' '); 
			cout.width((size * 2) - 1); 
			cout << "";

			cout.fill('*');	
			cout.width(size + 1); 
			cout << "";
			
			cout.fill(' ');
		}
		else
		{
			cout.width(j * 2);	
			cout << "*";

			cout.width((i * 3) + size - j + 2);	
			cout << "*";
		}
		cout << endl;
	}

	for (int i = size, j = 0; j < size; i--, j++)
	{
		if (i > (size / 2))
		{
			if (j == (size / 2))
			{
				cout.width(i); cout << "*";
				cout.width(i * 3 - 1); cout << "*";
				cout.width(i * 3 - 1); cout << "*";
			}
			else
			{
				cout.width(i); cout << "*";
				cout.width((size * 2) + (j * 2) + 2); cout << "*";
			}
		}
		else if (i <= (size / 2))
		{
			if (i == (size / 2))
			{
				cout.width(i); cout << "*";
				cout.width(size - j + (i * 2)); cout << "*";
				cout.width((j * 3 - size - i) * 2 + 2); cout << "*";
				cout.width(size - j + (i * 2));	cout << "*";
			}
			else
			{
				cout.width(i); cout << "*";
				cout.width(size - j + (i * 2)); cout << "*";
				cout.width((j * 3 - size - i) * 2 + 1); cout << "*";
				cout.width(size - j + (i * 2) + 1);	cout << "*";
			}
		}
		cout << endl;
	}
}

void CShapeDrawer::drawHeart()
{
	if (size % 2 == 0)
	{
		size++;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0 && (j >= size / 5 && j <= size / 2 - size / 5) || i == 0 && (j >= size / 2 + size / 5 && j <= (size - 1) - size / 5)
				|| i > 0 && i <= size / 5 && (j == size / 5 - i || j == size / 2 + size / 5 - i || j == size / 2 - size / 5 + i || j == (size - 1) - size / 5 + i)
				|| (i > size / 5 && i <= size / 2) && (j == 0 || j == size - 1)
				|| i > size / 2 && (j == i - size / 2 || j == (size - 1) - (i - size / 2)))
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void CShapeDrawer::SetSize(int size)
{
	this->size = size;
}

void CShapeDrawer::DrawShape(Shape shape)
{
	switch (shape)
	{
	case Triangle:
		drawTrinangle();
		break;

	case Star:
		drawStar();
		break;

	case Heart:
		drawHeart();
		break;

	default:
		break;
	}
}