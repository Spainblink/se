#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
const int BattleFieldSize = 10;
class BattleField;

class BattleShip
{
private:
	int m_ShipSize = 1;
	int m_HitCount = 1;
	bool m_Oriental = 0;
public:
	BattleShip(int size) : m_ShipSize(size) {};
	friend void getOriental(bool oriental, BattleShip& battleship);
	friend void playerShot(std::string playersChoiceString, int playersChoiceInt, BattleField& playerField);
};
class BattleField
{
private:
	int m_BattleField[10][10];
public:
	BattleField();
	friend void shipWreck(BattleShip& ship);
	friend void getOriental(bool oriental, BattleShip& battleship);
	friend void playerShot(std::string playersChoiceString, int playersChoiceInt, BattleField& playerField);
	void printField();
};
#endif 