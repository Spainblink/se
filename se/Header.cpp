#include "Header.h"
int BattleShip::m_Count = 0;
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
int& BattleField::operator()(int playerChoiceInt, char playerChoiceChar) //�������� ������������ ���������� �� �����, ����� ����� �����
{
	return m_BattleField[playerChoiceInt - 1][charToInt(playerChoiceChar)];
}
void BattleField::placeShip(BattleShip& battleship)
{
	bool oriental;
	char playersChoiceChar;
	int playersChoiceInt;
	std::cout << "������� 1 - ���� ������� ����������� ������������� ��� 0 - ���� ����������� : " << std::endl;
	std::cin >> oriental;
	std::cout << "\n������� ������ ��� ���������� ������� �� a �� j (���������� �������) :" << std::endl;
	std::cin >> playersChoiceChar;
	std::cout << "\n������� ������ ��� ���������� ������� �� 1 �� 10 :" << std::endl;
	std::cin >> playersChoiceInt;
	battleship.setOriental(oriental);
	if (battleship.getOriental())
	{
		if (charToInt(playersChoiceChar) + battleship.getShipSize() > (BattleFieldSize - 1))
		{
			for (int start = BattleFieldSize - 1; start > (BattleFieldSize - 1) - battleship.getShipSize(); --start)
			{
				m_BattleField[playersChoiceInt - 1][start] = battleship.getId();
			}
		}
		else
		{
			for (int start = charToInt(playersChoiceChar); start < charToInt(playersChoiceChar) + battleship.getShipSize(); ++start)
			{
				m_BattleField[playersChoiceInt - 1][start] = battleship.getId();
			}
		}
	}
	else if (battleship.getOriental() == false)
	{
		if ((playersChoiceInt - 1) + battleship.getShipSize() > BattleFieldSize - 1)
		{
			for (int start = BattleFieldSize - 1; start > (BattleFieldSize - 1) - battleship.getShipSize(); --start)
			{
				m_BattleField[start][charToInt(playersChoiceChar)] = battleship.getId();
			}
		}
	}
};
BattleShip::BattleShip(int size, bool oriental = false)
{
	m_ShipSize = size;
	m_Oriental = oriental;
	m_HitCount = m_ShipSize;
	m_Id = ++m_Count;
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
void setPlayersChar(char& playersChoiceChar)				//����� �����
{
do
{
	std::cout << "Choose letter to shoot (from 'a' to 'j' only)" << std::endl;
	std::cin >> playersChoiceChar;

} while (playersChoiceChar != 'a' && playersChoiceChar != 'b' && playersChoiceChar != 'c' && playersChoiceChar != 'd' && playersChoiceChar != 'e' && playersChoiceChar != 'f' && playersChoiceChar != 'g' && playersChoiceChar != 'h' && playersChoiceChar != 'i' && playersChoiceChar != 'j');
};
void setPlayersInt(int& playersChoiceInt)				//����� �����
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
int BattleShip::getId()
{
	return m_Id;
}
