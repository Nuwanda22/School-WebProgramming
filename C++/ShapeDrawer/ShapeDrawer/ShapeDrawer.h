#pragma once
#include <iostream>

typedef enum
{
	Triangle = 1,
	Star,
	Heart
} Shape;

class CShapeDrawer
{
private:
	int size;
	void drawTrinangle();
	void drawStar();
	void drawHeart();
	
public:
	void SetSize(int size);
	void DrawShape(Shape shape);
};