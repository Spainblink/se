#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
const int BattleFieldSize = 10;
class BattleField;

class BattleShip
{
private:
	int m_ShipSize;
	int m_HitCount;
	bool m_Oriental;																	//если false - вертикальное, если true - горизонтальное
public:
	BattleShip(int size);
	int getHitCount();
	int getShipSize();
	void hitCountAfterHit();
	void setOriental(bool oriental);
	bool getOriental();
	void shipWreck(BattleField& battlefield);
	friend void setShipOriental(bool oriental, BattleShip& battleship);					//ориентация корабля
	friend void playerShot(char playersChoiceChar, int playersChoiceInt, BattleField& playerField, BattleShip& battleship);
	friend void BattleField::placeShip(BattleShip& battleship);
};
class BattleField
{
private:
	int m_BattleField[10][10];
public:
	BattleField();
	void placeShip(BattleShip& battleship);										//размещение корабля
	int& operator()(char playersChoiceChar, int playersChoiceInt);				//перегруз индексации  
	friend void BattleShip::shipWreck(BattleField& battlefield);
	friend void setShipOriental(bool oriental, BattleShip& battleship);
	friend void playerShot(char playersChoiceChar, int playersChoiceInt, BattleField& playerField, BattleShip& battleship);
	void printField();
};
#endif 