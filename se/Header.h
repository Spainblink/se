#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
#include <map>
const int BattleFieldSize = 10;		//размер поля
class BattleField;

class BattleShip
{
private:
	int m_ShipSize;
	int m_HitCount;
	int m_Id;
	char m_CharCoordinate;
	bool m_Oriental;	//если false - вертикальное, если true - горизонтальное
public:
	int* m_pIntCoordinate;	//запись координат для метода shipWreck()
	static int m_Count;
	BattleShip(int size);
	~BattleShip();
	int getHitCount();
	int getShipSize();
	int getId();
	char getCharCoordinate();
	void setCharCoordinate(char charCoordinate);
	void setShipSize();
	void hitCountAfterHit();
	void setOriental(bool oriental);
	bool getOriental();
	void shipWreck(BattleField& battlefield);
	friend void playerShot(BattleField& playerField, std::map<int, BattleShip>& idStorage);
};
class BattleField
{
private:
	int m_BattleField[10][10];
public:
	BattleField();
	void placeShip(BattleShip& battleship);										//размещение корабля
	int& operator()(int, int);													//перегрузка индексации
	friend void BattleShip::shipWreck(BattleField& battlefield);
	friend void playerShot(BattleField& playerField, std::map<int, BattleShip>& idStorage);
	void printField();
};
#endif 