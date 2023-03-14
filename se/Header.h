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
	bool m_Oriental;
public:
	BattleShip(int size);
	int getHitCount();
	void hitCountAfterHit();
	void setOriental();
	friend void setShipOriental(bool oriental, BattleShip& battleship);					//ориентация корабля
	friend void playerShot(char playersChoiceChar, int playersChoiceInt, BattleField& playerField, BattleShip& battleship);
	friend void shipWreck(BattleShip& battleship, BattleField& battlefield);
	friend void BattleField::placeShip(BattleShip& battleship);
};
class BattleField
{
private:
	int m_BattleField[10][10];
public:
	BattleField();
	void placeShip(BattleShip& battleship);
	int& operator()(char playersChoiceChar, int playersChoiceInt);				//перегруз индексации  
	friend void shipWreck(BattleShip& battleship, BattleField& battlefield);
	friend void setShipOriental(bool oriental, BattleShip& battleship);
	friend void playerShot(char playersChoiceChar, int playersChoiceInt, BattleField& playerField, BattleShip& battleship);
	void printField();
};
#endif 