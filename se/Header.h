#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
const int BattleFieldSize = 10;		//размер поля
class BattleField;

class BattleShip
{
private:
	int m_ShipSize;
	int m_HitCount;
	int m_Id;
	bool m_Oriental;	//если false - вертикальное, если true - горизонтальное
public:
	static int m_Count;
	BattleShip(int size, bool oriental = false);
	int getHitCount();
	int getShipSize();
	int getId();
	void setShipSize();
	void hitCountAfterHit();
	void setOriental(bool oriental);
	bool getOriental();
	void shipWreck(BattleField& battlefield);
	friend void playerShot(BattleField& playerField, BattleShip& battleship);
	friend void BattleField::placeShip(BattleShip& battleship);
};
class BattleField
{
private:
	int m_BattleField[10][10];
public:
	BattleField();
	void placeShip(BattleShip& battleship);										//размещение корабля
	int& operator()(int playersChoiceInt, char playersChoiceChar);				//перегруз индексации  
	friend void BattleShip::shipWreck(BattleField& battlefield);
	friend void playerShot(BattleField& playerField, BattleShip& battleship);
	void printField();
};
#endif 