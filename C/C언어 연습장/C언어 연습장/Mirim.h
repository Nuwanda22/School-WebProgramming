// ����ü, ������, ���������� ��Ƴ� ���
// �����찡 ����

#pragma once
#pragma warning (disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// ����� ���� ������
typedef enum drinkName{
	Coke = 1, Sprite, Juice
}DrinkName;

// ����� ����ü (����, ����)
typedef struct drink
{
	DrinkName name;
	int price;
}Drink;

// ����� ����ü�� �ʱ�ȭ�ϴ� �Լ�
Drink init(DrinkName name)
{
	Drink drink;
	drink.name = name;

	switch (drink.name)
	{
	case Coke:
		drink.price = 700;
		break;
	case Sprite:
		drink.price = 800;
		break;
	case Juice:
		drink.price = 1000;
		break;
	default:
		drink.price = 6974;
		break;
	}
	return drink;
}

// ����� ���
typedef struct DrinkNode
{
	Drink drink;
	struct DrinkNode *prev;
	struct DrinkNode *next;
}Node;

// ���Ǳ� ����Ʈ�� ���
Node *Head = NULL;

// ���� ����
int cokeTmp = 0;
int juiceTmp = 0;
int spriteTmp = 0;

// ����� �ܾ�
int balance = 0;
// ������ �ܾ�
int stack = 0;