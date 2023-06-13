#include "Header.h"
int BattleShip::m_Count = 0;
int charToInt(char pCh);
char setPlayersChar();
int setPlayersInt();
BattleField::BattleField () 
{
	for (int raw = 0; raw < BattleFieldSize; ++raw) {
		for (int col = 0; col < BattleFieldSize; ++col) {
				m_BattleField[raw][col] = 0;
		}
	}
}
void BattleField::printField()
{
	bool answer;
	do {
		std::cout << "Вывести поле ? (1 - вывести, 0 - нет)" << std::endl;
		std::cin >> answer;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while (answer != 1 && answer != 0);
	if (answer) {
		for (int raw = 0; raw < BattleFieldSize; ++raw) {
			for (int col = 0; col < BattleFieldSize; ++col) {
				std::cout << m_BattleField[raw][col] << " ";
			}
			std::cout << std::endl;
		}
	}
}

int& BattleField::operator()(int firstInt, int secondInt)
{
	return m_BattleField[firstInt][secondInt];
}
void BattleField::placeShip(BattleShip& battleship)		//проверка поместится ли корабль по горизонтали или вертикали в методе размещения корабля  
{
	bool oriental;
	char playersChoiceChar = setPlayersChar();
	int playersChoiceInt = setPlayersInt();
	battleship.setCharCoordinate(playersChoiceChar);	//либо строка либо столбец, в зависимости от ориентации
	std::cout << "Размещение корабля" << std::endl;
	do
	{
		std::cout << "Для размещения корабля по вертикали введите - 0, по горизонтали - 1: " << std::endl;
		std::cin >> oriental;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while (oriental != 0 && oriental != 1);
	battleship.setOriental(oriental);
	if (battleship.getOriental())
	{
		if (charToInt(playersChoiceChar) + battleship.getShipSize() >= BattleFieldSize)
		{
			for (int start = BattleFieldSize - 1; start >= (BattleFieldSize - battleship.getShipSize()); --start)
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
		if (playersChoiceInt - 1 + battleship.getShipSize() >= BattleFieldSize)
		{
			for (int start = BattleFieldSize - 1; start >= (BattleFieldSize - battleship.getShipSize()); --start)
			{
				m_BattleField[start][charToInt(playersChoiceChar)] = battleship.getId();
			}
		}
		else 
			for (int start = playersChoiceInt - 1; start < playersChoiceInt - 1 + battleship.getShipSize(); ++start)
			{
				m_BattleField[start][charToInt(playersChoiceChar)] = battleship.getId();
			}
	}
};
BattleShip::BattleShip(int size)
{
	m_ShipSize = size;
	m_Oriental = false;
	m_HitCount = m_ShipSize;
	m_pIntCoordinate = new int[m_ShipSize];
	m_Id = ++m_Count;
};
BattleShip::~BattleShip()
{
	delete[] m_pIntCoordinate;
}
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
	if (this->getOriental())
	{

	}
	else
	{

	}
};

int BattleShip::getHitCount()
{
	return m_HitCount;
}
void BattleShip::setCharCoordinate(char charCoordinate)
{
	m_CharCoordinate = charCoordinate;
}
char BattleShip::getCharCoordinate()
{
	return m_CharCoordinate;
}
void playerShot(BattleField& playerField, std::map<int, BattleShip>& idStorage) 
{
	std::cout << "Стрельба по сектору" << std::endl;
	char playersChoiceChar = setPlayersChar();
	int playersChoiceInt = setPlayersInt();
	while (playerField(playersChoiceInt - 1, charToInt(playersChoiceChar)) > 0)
	{
		std::cout << "Попадание!" << std::endl;
		auto it = idStorage.find(playerField(playersChoiceInt - 1, charToInt(playersChoiceChar)));
		it->second.hitCountAfterHit();
		if (it->second.getHitCount() == 0)
			it->second.shipWreck(playerField);
		std::cout << "Еще выстрел!" << std::endl;
		playerField(playersChoiceInt - 1, charToInt(playersChoiceChar)) = -1;
		it = idStorage.begin();
		//playerShot(playerField, idStorage);
	}
	if(playerField(playersChoiceInt - 1, charToInt(playersChoiceChar)) == 0)
	{
	std::cout << "Промах!" << std::endl;
	playerField(playersChoiceInt - 1, charToInt(playersChoiceChar)) = -1;
	}

}
char setPlayersChar()				//выбор буквы
{
	char playersChoiceChar;
	do 
	{
		std::cout << "Введите стобец от a до j (английский алфавит) :" << std::endl;
		std::cin >> playersChoiceChar;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while (playersChoiceChar != 'a' && playersChoiceChar != 'b' && playersChoiceChar != 'c' && playersChoiceChar != 'd' && playersChoiceChar != 'e' && playersChoiceChar != 'f' && playersChoiceChar != 'g' && playersChoiceChar != 'h' && playersChoiceChar != 'i' && playersChoiceChar != 'j');

	return  playersChoiceChar;
};
int setPlayersInt()				//выбор числа
{
	int playersChoiceInt;
	do
	{
		std::cout << "Введите строку поля от 1 до 10 :" << std::endl;
		std::cin >> playersChoiceInt;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while (playersChoiceInt != 1 && playersChoiceInt != 2 && playersChoiceInt != 3 && playersChoiceInt != 4 && playersChoiceInt != 5 && playersChoiceInt != 6 && playersChoiceInt != 7 && playersChoiceInt != 8 && playersChoiceInt != 9 && playersChoiceInt != 10);

	return playersChoiceInt;
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
