#include "Header.h"
BattleField::BattleField () {
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
}
int charToInt(char pCh) {
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
int& BattleField::operator()(char playerChoiceChar, int playerChoiceInt) //проверка корректности проводится на входе, после ввода юзера
{
	return m_BattleField[charToInt(playerChoiceChar)][playerChoiceInt - 1];
}

void playerShot(char playersChoiceChar, int playersChoiceInt, BattleField& playerField) {
	if (playerField(playersChoiceChar, playersChoiceInt) > 0)
		std::cout << "Hit! Shoot again" << std::endl;
	else
		std::cout << "Miss!" << std::endl;
}
