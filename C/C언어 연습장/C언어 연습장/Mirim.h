// 구조체, 열거형, 전역변수를 모아논 헤드
// 전성우가 만듬

#pragma once
#pragma warning (disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// 음료수 종류 열거형
typedef enum drinkName{
	Coke = 1, Sprite, Juice
}DrinkName;

// 음료수 구조체 (종류, 가격)
typedef struct drink
{
	DrinkName name;
	int price;
}Drink;

// 음료수 구조체를 초기화하는 함수
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

// 음료수 노드
typedef struct DrinkNode
{
	Drink drink;
	struct DrinkNode *prev;
	struct DrinkNode *next;
}Node;

// 자판기 리스트의 헤드
Node *Head = NULL;

// 음료 개수
int cokeTmp = 0;
int juiceTmp = 0;
int spriteTmp = 0;

// 사용자 잔액
int balance = 0;
// 관리자 잔액
int stack = 0;