#include "Header.h"
BattleField::BattleField () 
{
	for (int raw = 0; raw < BattleFieldSize; ++raw) {
		for (int col = 0; col < BattleFieldSize; ++col) {
			m_BattleField[raw][col] = 0;
		}
	}
};
void BattleField::printField()
{
	for (int raw = 0; raw < BattleFieldSize; ++raw) {
		for (int col = 0; col < BattleFieldSize; ++col) {
			std::cout << m_BattleField[raw][col] << " ";
		}
		std::cout << std::endl;
	}
};
int& BattleField::operator()(char playerChoiceChar, int playerChoiceInt) //проверка корректности проводитс€ на входе, после ввода юзера
{
	return m_BattleField[charToInt(playerChoiceChar)][playerChoiceInt - 1];
}
void BattleField::placeShip(BattleShip& battleship)
{
	bool oriental;
	char playersChoiceChar;
	int playersChoiceInt;
	std::cout << "¬ведите 1 - если корабль располагаем горизонтально или 0 - если вертикально : " << std::endl;
	std::cin >> oriental;
	std::cout << std::endl;
	std::cout << "¬ведите стобец дл€ размещени€ корабл€ от a до j (английский алфавит) :" << std::endl;
	std::cin >> playersChoiceChar;
	std::cout << std::endl;
	std::cout << "¬ведите строку дл€ размещени€ корабл€ от 1 до 10 :" << std::endl;
	std::cin >> playersChoiceInt;
	battleship.setOriental(oriental);
	if (battleship.getOriental() && ((charToInt(playersChoiceChar) + battleship.getShipSize()) > (BattleFieldSize - 1)))
	{

	}
};
BattleShip::BattleShip(int size)		
{
	m_ShipSize = size;
		m_HitCount = m_ShipSize;
		m_Oriental = false;
};
int BattleShip::getShipSize()
	{
		return m_ShipSize;
	};
void BattleShip::setOriental(bool oriental)
{
	m_Oriental = oriental;
};
bool BattleShip::getOriental()
{
	return m_Oriental;
};
void BattleShip::hitCountAfterHit() {
	--m_HitCount;
};
void BattleShip::shipWreck(BattleField& battlefield) 
{

};

int BattleShip::getHitCount()
{
	return m_HitCount;
}
void playerShot(char playersChoiceChar, int playersChoiceInt, BattleField& playerField, BattleShip& battleship)
{
	if (playerField(playersChoiceChar, playersChoiceInt) > 0)
	{
		battleship.hitCountAfterHit();
		std::cout << "Hit! Shoot again" << std::endl;
	}
	else
		std::cout << "Miss!" << std::endl;
}
void setPlayersChar(char& playersChoiceChar)				//выбор буквы
{
do
{
	std::cout << "Choose letter to shoot (from 'a' to 'j' only)" << std::endl;
	std::cin >> playersChoiceChar;

} while (playersChoiceChar != 'a' && playersChoiceChar != 'b' && playersChoiceChar != 'c' && playersChoiceChar != 'd' && playersChoiceChar != 'e' && playersChoiceChar != 'f' && playersChoiceChar != 'g' && playersChoiceChar != 'h' && playersChoiceChar != 'i' && playersChoiceChar != 'j');
};
void setPlayersInt(int& playersChoiceInt)				//выбор числа
{
	do
	{
		std::cout << "Choose number to shoot (from '1' to '10' only)" << std::endl;
		std::cin >> playersChoiceInt;

	} while (playersChoiceInt != 1 && playersChoiceInt != 2 && playersChoiceInt != 3 && playersChoiceInt != 4 && playersChoiceInt != 5 && playersChoiceInt != 6 && playersChoiceInt != 7 && playersChoiceInt != 8 && playersChoiceInt != 9 && playersChoiceInt != 10);
};
int charToInt(char pCh)
{
	switch (pCh)
	{
	case 'a':
		return 0;
	case 'b':
		return 1;
	case 'c':
		return 2;
	case 'd':
		return 3;
	case 'e':
		return 4;
	case 'f':
		return 5;
	case 'g':
		return 6;
	case 'h':
		return 7;
	case 'i':
		return 8;
	case 'j':
		return 9;
	default:
		break;
	}
}
void setShipOriental(bool oriental, BattleShip& battleship)
{
	std::cout << battleship.m_Oriental << std::endl;
};
