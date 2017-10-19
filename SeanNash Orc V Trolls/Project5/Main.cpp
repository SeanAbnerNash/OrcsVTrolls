#include <iostream>
#include <string>
///@Author Sean Nash
///@Login C00217019
//Time Taken 4 Hours
//Known Bugs: Inputting letters when asked for numbers breaks the system, dont know why.
using namespace std;
enum shieldType{METAL,WOOD,CRYSTAL,NONE};//Shield Types
class Character {
private:
	int m_maxHealth;
	int m_currentHealth;
	shieldType m_equippedShield;

	int m_classTimer = 0;//Cooldown time to stop repeated Class Ability use

	int m_acBase = 10;//Value that does not change to Armour Class
	int m_acMod;//A more Permant variable, changes last a whil and modifiy the AC.
	int m_acBuff;//A 1 Turn Change to the value

	int m_attackBase;//Value that does not change to Attack
	int m_attackMod;//A more Permant variable, changes last a whil and modifiy the attack
	int m_attackBuff;//A 1 Turn Change to the value

	int m_damageBase;//Value that does not change to damage
	int m_damageMod;//A more Permant variable, changes last a whil and modifiy the Damage
	int m_damageBuff;//A 1 Turn Change to the value

	bool m_protected;//Can unit take damage on this attack
	int m_classNumber;//Tracks Which Class is it
	int m_raceNumber;//Tracks Which Race is it
	

public:
	void m_setMaxHealth(int t_max);
	int m_getMaxHealth();

	void m_setCurrentHealth(int t_current);
	int m_getCurrentHealth();

	void m_setShield(int t_shield);
	shieldType m_getShield();
	void m_printShield();//Prints shield equipped


	int m_getClassTimer();
	void m_setClassTimer(int t_timer);

	int m_getACBase();

	void m_setACMod(int t_acMod);
	int m_getACMod();

	void m_setACBuff(int t_acBuff);
	int m_getACBuff();

	int m_getAttackBase();

	void m_setAttackMod(int t_attkMod);
	int m_getAttackMod();

	void m_setAttackBuff(int t_attkBuff);
	int m_getAttackBuff();

	int m_getDamageBase();

	void m_setDamageMod(int t_damMod);
	int m_getDamageMod();

	void m_setDamageBuff(int t_damBuff);
	int m_getDamageBuff();

	void m_setProtected(bool t_protected);
	bool m_getProtected();

	void m_setClassNum(int t_classNumb);
	int m_getClassNum();

	void m_setRaceNum(int t_raceNumb);
	int m_getRaceNum();

	void setUpClass(int t_classNum, int t_raceNum);//Sets up class depending on what is chosen and what race is passed

	int m_attack();//Gets Total Attack roll
	virtual int m_damage();//Gets Total Damage roll Virtual
	int m_ac();//Gets total AC

};

class Orc : public Character {
private:
	
public:
	int m_damage();//Orc Damage roll, they deal less damage than trolls

};

class Troll : public Character {
private:
	
public:
	int m_damage();//Troll Damage roll, they deal More damage than Orcs
};

void setUpCharacters(Character *trooperPointer[], int elementsA);//Lets the PLayer set up the Classes 
void battleFunction(Character *trooperPointer[], int elementsA);//The Battle Function where units take turns and actions
void battleTarget(Character *trooperA[], int elementsA, int sender, int reciever, int damageType);//The Damage function, The attacker, the target and the attack type are passed
void battleStatus(Character *trooperPointer[], int elementsA);//Prints the battle screen
void battleHeal(Character *trooperPointer[], int elementsA, int healType, int healAmount, int target);//Heals targets depending on the passed Heal Type


int main(void)
{
	Orc orcSquad[3];
	Troll trollBand[3];
	Character *trooperPointer[6];
	for (int i = 0; i < 3; i++)
	{
		trooperPointer[i] = &orcSquad[i];
		trooperPointer[i+3] = &trollBand[i];//Pointer declaration and linking
	}
	setUpCharacters( trooperPointer , 6 );//Character set up
	system("PAUSE");
	battleFunction(trooperPointer, 6);//Battle

}//END

void Character::m_setMaxHealth(int t_max)
{
	m_maxHealth = t_max;
}

int Character::m_getMaxHealth()
{
	return m_maxHealth;
}

void Character::m_setCurrentHealth(int t_current)
{
	m_currentHealth = t_current;
}

int Character::m_getCurrentHealth()
{
	return m_currentHealth;
}

void Character::m_setShield(int t_shield)
{
	if (t_shield == 1)
	{ 
		m_equippedShield = METAL;
	}
	if (t_shield == 2)
	{
		m_equippedShield = WOOD;
	}
	if (t_shield == 3)
	{
		m_equippedShield = CRYSTAL;
	}
	if (t_shield == 4)
	{
		m_equippedShield = NONE;
	}
}

shieldType Character::m_getShield()
{
	return m_equippedShield;
}

void Character::m_printShield()
{
	if (m_equippedShield == WOOD)
	{ 
		cout << "WOOD SHIELD";
	}
	if (m_equippedShield == METAL)
	{
		cout << "METAL SHIELD";
	}
	if (m_equippedShield == CRYSTAL)
	{
		cout << "CRYSTAL SHIELD";
	}
	if (m_equippedShield == NONE)
	{
		cout << "NO SHIELD";
	}
}

int Character::m_getClassTimer()
{
	return m_classTimer;
}

void Character::m_setClassTimer(int t_timer)
{
	m_classTimer = t_timer;
}

int Character::m_getACBase()
{
	return m_acBase;
}

void Character::m_setACMod(int t_acMod)
{
	m_acMod = t_acMod;
}

int Character::m_getACMod()
{
	return m_acMod;
}

void Character::m_setACBuff(int t_acBuff)
{
	m_acBuff = t_acBuff;
}

int Character::m_getACBuff()
{
	return m_acBuff;
}

int Character::m_getAttackBase()
{
	return m_attackBase;
}

void Character::m_setAttackMod(int t_attkMod)
{
	m_attackMod = t_attkMod;
}

int Character::m_getAttackMod()
{
	return m_attackMod;
}

void Character::m_setAttackBuff(int t_attkBuff)
{
	m_attackBuff = t_attkBuff;
}

int Character::m_getAttackBuff()
{
	return m_attackBuff;
}

int Character::m_getDamageBase()
{
	return m_damageBase;
}

void Character::m_setDamageMod(int t_damMod)
{
	m_damageMod = t_damMod;
}

int Character::m_getDamageMod()
{
	return m_damageMod;
}

void Character::m_setDamageBuff(int t_damBuff)
{
	m_damageBuff = t_damBuff;
}

int Character::m_getDamageBuff()
{
	return m_damageBuff;
}

void Character::m_setProtected(bool t_protected)
{
	m_protected = t_protected;
}

bool Character::m_getProtected()
{
	return m_protected;
}

void Character::m_setClassNum(int t_classNumb)
{
	m_classNumber = t_classNumb;
}

int Character::m_getClassNum()
{
	return m_classNumber;
}

void Character::m_setRaceNum(int t_raceNumb)
{
	m_raceNumber = t_raceNumb;
}

int Character::m_getRaceNum()
{
	return m_raceNumber;
}

void Character::setUpClass(int t_classNum, int t_raceNum)
{
	if (t_raceNum == 1)
	{ 
		m_raceNumber = 1;
		if (t_classNum == 1)//Orc Coward
		{
			m_maxHealth = 20;
			m_currentHealth = 20;
			m_equippedShield = WOOD;
			m_classNumber = 1;

			m_acMod = 3;
			m_acBuff = 0;

			m_attackBase = 2;
			m_attackMod = 2;
			m_attackBuff = 0;

			m_damageBase = 1;
			m_damageMod = 1;
			m_damageBuff = 0;

			m_protected = false;
		
		}
		if (t_classNum == 2)//Orc Meatwall
		{
			m_maxHealth = 30;
			m_currentHealth = 30;
			m_equippedShield = METAL;
			m_classNumber = 2;

			m_acMod = 5;
			m_acBuff = 0;

			m_attackBase = 1;
			m_attackMod = 1;
			m_attackBuff = 0;

			m_damageBase = 1;
			m_damageMod = 2;
			m_damageBuff = 0;

			m_protected = false;

		}
		if (t_classNum == 3)//Orc Native
		{
			m_maxHealth = 15;
			m_currentHealth = 15;
			m_equippedShield = NONE;
			m_classNumber = 3;

			m_acMod = 2;
			m_acBuff = 0;

			m_attackBase = 1;
			m_attackMod = 1;
			m_attackBuff = 0;

			m_damageBase = 0;
			m_damageMod = 0;
			m_damageBuff = 0;

			m_protected = false;
		}
		if (t_classNum == 4)//Orc Warrior
		{
			m_maxHealth = 25;
			m_currentHealth = 25;
			m_equippedShield = NONE;
			m_classNumber = 4;

			m_acMod = 4;
			m_acBuff = 0;

			m_attackBase = 2;
			m_attackMod = 3;
			m_attackBuff = 0;

			m_damageBase = 1;
			m_damageMod = 3;
			m_damageBuff = 0;

			m_protected = false;
		}
	}
	if (t_raceNum == 2)
	{
		m_raceNumber = 2;
		if (t_classNum == 1)//Troll Toughun
		{
			m_maxHealth = 40;
			m_currentHealth = 40;
			m_equippedShield = WOOD;
			m_classNumber = 1;
			m_raceNumber = 2;

			m_acMod = 2;
			m_acBuff = 0;

			m_attackBase = 1;
			m_attackMod = 2;
			m_attackBuff = 0;

			m_damageBase = 2;
			m_damageMod = 1;
			m_damageBuff = 0;

			m_protected = false;
		}

		if (t_classNum == 2)//Troll Stronkun
		{
			m_maxHealth = 35;
			m_currentHealth = 35;
			m_equippedShield = NONE;
			m_classNumber = 2;
			m_raceNumber = 2;

			m_acMod = 2;
			m_acBuff = 0;

			m_attackBase = 2;
			m_attackMod = 2;
			m_attackBuff = 0;

			m_damageBase = 2;
			m_damageMod = 3;
			m_damageBuff = 0;

			m_protected = false;
		}

		if (t_classNum == 3)//Troll Smurtun
		{
			m_maxHealth = 30;
			m_currentHealth = 30;
			m_equippedShield = CRYSTAL;
			m_classNumber = 3;
			m_raceNumber = 2;

			m_acMod = 3;
			m_acBuff = 0;

			m_attackBase = 1;
			m_attackMod = 2;
			m_attackBuff = 0;

			m_damageBase = 2;
			m_damageMod = 0;
			m_damageBuff = 0;

			m_protected = false;
		}

		if (t_classNum == 4)//Troll Ungryun
		{
			m_maxHealth = 50;
			m_currentHealth = 50;
			m_equippedShield = NONE;
			m_classNumber = 4;
			m_raceNumber = 2;

			m_acMod = 0;
			m_acBuff = 0;

			m_attackBase = 4;
			m_attackMod = 2;
			m_attackBuff = 0;

			m_damageBase = 2;
			m_damageMod = 5;
			m_damageBuff = 0;

			m_protected = false;
		}
	}
}

int Character::m_attack()
{
	return (m_attackBase+m_attackMod+m_attackBuff+(rand() % 20 + 1));
}

int Character::m_damage()
{
	return (m_damageBase + m_damageMod + m_damageBuff + (rand() % 4 + 1));
}

int Character::m_ac()
{
	return (m_acBase+m_acMod+m_acBuff);
}

void setUpCharacters(Character * trooperPointer[], int elementsA)
{
	bool orcsDone = false;
	bool trollDone = false;
	int trooperCount = 0;
	int classNumber = 0;
	if (!orcsDone)
	{
		for (trooperCount; trooperCount < 3;)
		{
				system("CLS");
				cout << " Please Pick the Classes of the Orcs" << endl
					<< "1 - Orc Coward, Moderately Tough, Attacks from range like a coward " << endl
					<< "2 - Orc Meatwall,  Tough, Good for standing in peoples way... little else " << endl
					<< "3 - Orc Native,Not Tough, An elf painted green and convinced they'r an orc, blows stuff up" << endl
					<< "4 - Orc Warrior, Fairly Tough, Charge while screaming at all times " << endl;
				std::cin >> classNumber;
				if (classNumber == 1 || classNumber == 2 || classNumber == 3 || classNumber == 4)
				{
					trooperPointer[trooperCount]->setUpClass(classNumber, 1);
					trooperCount++;
					system("PAUSE");
					orcsDone = true;
				}
	
		}
	}
	if (!trollDone)
	{
		for (trooperCount; trooperCount < 6;)
		{
			classNumber = 0;
			system("CLS");
			cout << " Please Pick the Classes of the Trolls" << endl
				<< "1 - Troll Toughun, Tough, Tough for a troll, Like Comparing rocks to other rocks really " << endl
				<< "2 - Troll Stronkun, Tough, Decided To Punch things for fun, Never Stopped " << endl
				<< "3 - Troll Smurtun, Tough, Troll 'Wizard', just a troll that says 'magic' words before punching, No one argues" << endl
				<< "4 - Troll Ungryun, Very Tough, Its unclear if its hungry or angry, The results are generally the same " << endl;
			std::cin >> classNumber;
			if (classNumber == 1 || classNumber == 2 || classNumber == 3 || classNumber == 4)
			{
				trooperPointer[trooperCount]->setUpClass(classNumber, 2);
				trooperCount++;
				trollDone = true;
			}

		}
	}

}

void battleFunction(Character * trooperPointer[], int elementsA)
{
	bool teamDefeated = false;//Is team dead?
	int turnTracker = 0;//Tracks whos turn it is
	int target;
	int actionTracker = 0;//What action a unit chooses
	while (!teamDefeated)//If all one side isnt dead
	{
		turnTracker = 0;
		battleStatus(trooperPointer, 6);//Print Screen
		for (turnTracker; turnTracker < 6;)
		{
			system("CLS");
			battleStatus(trooperPointer, 6);
			target = 30;
			actionTracker = 0;//Reset trackers
			if (trooperPointer[turnTracker]->m_getCurrentHealth() > 0)//If Unit isnt dead
			{
				if (turnTracker < 3)
				{
					cout << "It's Orc " << turnTracker + 1 << "'s turn!  " << endl;
				}
				if (turnTracker >= 3)
				{
					cout << "It's Troll " << turnTracker - 2 << "'s turn! " << endl;
				}//Displays Name
				if (trooperPointer[turnTracker]->m_getRaceNum() == 1)//Orcs go first from 1 -> 3 THen trolls 1 ->3
				{
					if (trooperPointer[turnTracker]->m_getClassNum() == 1)//Orc Coward
					{
						trooperPointer[turnTracker]->m_setACBuff(0);//Reset AC Debuff

						cout << " Action! " << endl
							<< "- 1 Attack one Target! " << endl
							<< "- 2 PANIC FIRE! (ATTACK ONE GUY 3 TIMES WITH -2 TO ATTACK) " << endl;
							if (trooperPointer[turnTracker]->m_getClassTimer() > 0)//Checks cooldown to inform Player
							{
								cout << "On Cooldown for " << trooperPointer[turnTracker]->m_getClassTimer() << " Turns! " << endl;
							}
							cout << "- 3 Hide - +5 AC for One Round" << endl;
						std::cin >> actionTracker;//PLayer Chooses Action
						if (actionTracker == 1)//Normal Attack
						{
							cout << " Select Target, 1 -> 3 " << endl;
							std::cin >> target;//Selects Troll To Attack
							if (target == 1 || target == 2 || target == 3)
							{
								battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);//Attack Function, passing Target +2 to select correct array element
							}
							else//If nothing is selected Nothing happens.
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
						if (actionTracker == 2)//Panic Fire
						{
							if (trooperPointer[turnTracker]->m_getClassTimer() == 0)//If Cooldown is down
							{
								cout << " OH GOD BIG THINGS FIRE AT SOMETHING, 1 -> 3 " << endl;
								std::cin >> target;//Target Selected
								if (target == 1 || target == 2 || target == 3)
								{
									cout << "The Trooper Fire wildly not even looking at the target properly " << endl;
									trooperPointer[turnTracker]->m_setAttackBuff(-2);//Debuffs Attack
									battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);
									battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);
									battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);//3 Attacks against same target
									trooperPointer[turnTracker]->m_setAttackBuff(0);//Reset Attack Debuff
									trooperPointer[turnTracker]->m_setClassTimer(3);//Raises CD
								}
								else//Nothing Right Nothing Happens
								{
									cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
								}
							}
							else//Nothing Right Nothing Happens
							{
								cout << " The Trooper is too tired to do this yet. " << endl;
							}
						}
						if (actionTracker == 3)//Hide
						{
							cout << "The dirty coward hides like a frightened pink skin, no hope for him " << endl;
							trooperPointer[turnTracker]->m_setACBuff(trooperPointer[turnTracker]->m_getACBuff() + 5);//Changes AC buff

						}
						if (trooperPointer[turnTracker]->m_getClassTimer() > 0)//Ticks Down on the Cool Down
						{
							trooperPointer[turnTracker]->m_setClassTimer(trooperPointer[turnTracker]->m_getClassTimer() - 1);
						}
					}
					if (trooperPointer[turnTracker]->m_getClassNum() == 2)//Orc Meatwall
					{

						cout << " Action! " << endl
							<< "- 1 Attack one Target! " << endl
							<< "- 2 Protect one Target! (Negate 1 Attack)";
							if (trooperPointer[turnTracker]->m_getClassTimer() > 0)//CD Display
						{
							cout << " On Cooldown for " << trooperPointer[turnTracker]->m_getClassTimer() << " Turns! " << endl;
						}
							cout << "- 3 Look Tough! " << endl;

						std::cin >> actionTracker;
						if (actionTracker == 1)
						{
							cout << " Select Target, 1 -> 3 " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
						if (actionTracker == 2)
						{
							cout << " Select Target to Protect, 1 -> 3 " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								trooperPointer[target-1]->m_setProtected(true);
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
						if (actionTracker == 3)
						{
							cout << " Select Action, " << endl <<
								"-1 Muscle Flex (+4 Dam for 1 Round)" << endl <<
								"-2 Roar (+5 AC for 1 Round)" << endl <<
								"-3 Whimper (Are you an orc or an elf?)" << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								if (target == 1)
								{
									cout << endl << "Fleeex... Definetly bigger than yesterday. Time to put them to use. " << endl;
									trooperPointer[turnTracker]->m_setDamageBuff(trooperPointer[turnTracker]->m_getDamageBuff() + 4);
								}
								if (target == 2)
								{
									cout << endl << "The mass of muscle and rage roars out a challenge, making any attackers less enthused " << endl;
									trooperPointer[turnTracker]->m_setACBuff(trooperPointer[turnTracker]->m_getACBuff() + 5);
								}
								if (target == 3)
								{
									cout << endl << "The giant mass of muscles and scar tissue whimpers like a baby, the shame will never fade" << endl;
								}
							}
							else
							{
								cout << " The Trooper is confused and just ends up looking silly " << endl;
							}
						}
						else
						{
							trooperPointer[turnTracker]->m_setDamageBuff(0);
						}

					}
					if (trooperPointer[turnTracker]->m_getClassNum() == 3)//Orc Native
					{
						trooperPointer[turnTracker]->m_setACBuff(0);
						cout << " Action! " << endl
							<< "- 1 Attack one Target! " << endl
							<< "- 3 'Orcish' Magic " << endl
							<< "- 4 'Greenskin' Pride " << endl;
						std::cin >> actionTracker;
						if (actionTracker == 1)
						{
							cout << " Select Target, 1 -> 3 " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
						if (actionTracker == 3)
						{
							cout << " Select Spell, " << endl <<
								"- 1 Frenzy (Doubles own Damage Mod, Stacks indefinitely)" << endl <<
								 "- 2 Burning Hands (Auto Hit Low Fire Damage to All Targets, Reduced By Metal Shields " << endl
								<< "- 3 Shocking Grasp (Auto Hit High Electric Damage to Single Target, Negated by Crystal Shield " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								if (target == 1)//Frenzy
								{
									cout << endl << "The badly painted green stick like el..Orc charges into the enemy with no regard for sanity, Even orcs think this is dumn " << endl;
									trooperPointer[turnTracker]->m_setDamageMod(trooperPointer[turnTracker]->m_getDamageMod() * 2);
								}
								if (target == 2)//Burning Hands
								{
									cout << endl << "The badly painted green stick like el..Orc waves their hands around before sending forward a wave of fire " << endl;
										battleTarget(trooperPointer, 6, turnTracker, 3, 2);
										battleTarget(trooperPointer, 6, turnTracker, 4, 2);
										battleTarget(trooperPointer, 6, turnTracker, 5, 2);
								}
								if (target == 3)//Shocking Grasp
								{
									cout << endl << "The badly painted green stick like el..Orc waves their hands around before sending forward a blast of Lightning " << endl;
									cout << " Select Target, 1 -> 3 " << endl;
									std::cin >> target;
									if (target == 1 || target == 2 || target == 3)
									{
										battleTarget(trooperPointer, 6, turnTracker, target + 2, 3);
									}
									else
									{
										cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
									}
								
								}
							}
							else
							{
								cout << " The Trooper is confused and just ends up looking silly " << endl;
							}
						}
						if (actionTracker == 4)
						{
							cout << "The patchy pale skined and green paint elf challenges others to take him on, Even Orcs think this is dumn (AC Drops...significantly) " << endl;
							trooperPointer[turnTracker]->m_setACBuff(trooperPointer[turnTracker]->m_getACBuff() - 10);
						}

						
					}
					if (trooperPointer[turnTracker]->m_getClassNum() == 4)//Orc Warrior
					{
						trooperPointer[turnTracker]->m_setACBuff(0);
						cout << " Action! " << endl
							<< "- 1 Attack one Target! " << endl
							<< "- 2 Display of Courage! Hit All Opponents, Lose Half Max Health!";
						if (trooperPointer[turnTracker]->m_getClassTimer() > 0)
						{
							cout << "On Cooldown for " << trooperPointer[turnTracker]->m_getClassTimer() << " Turns! " << endl;
						}
						cout << "- 3 Tactics! Those things we never use!"		<<	endl
							<<"- 4 Intimidating Display!" << endl;
						std::cin >> actionTracker;
						if (actionTracker == 1)
						{
							cout << " Select Target, 1 -> 3 " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
						if (actionTracker == 2)
						{
							if (trooperPointer[turnTracker]->m_getClassTimer() == 0)
							{
									cout << " The Trooper grins to himself and charges in a display of recklessness that catches the enemey by surprise, and it only cost one arm. " << endl;
									trooperPointer[turnTracker]->m_setAttackBuff(20);
									trooperPointer[turnTracker]->m_setCurrentHealth(trooperPointer[turnTracker]->m_getCurrentHealth() - trooperPointer[turnTracker]->m_getMaxHealth() / 2);
									battleTarget(trooperPointer, 6, turnTracker, 1 + 2, 1);
									battleTarget(trooperPointer, 6, turnTracker, 2 + 2, 1);
									battleTarget(trooperPointer, 6, turnTracker, 3 + 2, 1);
									trooperPointer[turnTracker]->m_setAttackBuff(0);
									trooperPointer[turnTracker]->m_setClassTimer(3);						
							}
							else
							{
								cout << " The Trooper is too tired to do this yet. " << endl;
							}
						}
						if (actionTracker == 3)
						{
							cout << " Select Tactic! " << endl
								<< "- 1 Charge (-2 AC, +5 To Attack)" << endl
								<< "- 2 Charge Screaming (-2 AC, +3 To Damage)" <<endl;
							std::cin >> target;
							if (target == 1 || target == 2 )
							{
								if (target == 1)//Charge
								{
									cout << " Select Target, 1 -> 3 " << endl;
									std::cin >> target;
									if (target == 1 || target == 2 || target == 3)
									{
										cout << "The Trooper charges while cackling madly!" << endl;
										trooperPointer[turnTracker]->m_setAttackBuff(5);
										trooperPointer[turnTracker]->m_setACBuff(-2);
										battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);
										trooperPointer[turnTracker]->m_setAttackBuff(0);
									}
									else
									{
										cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
									}


								}

								if (target == 2)//Screaming Charge
								{
									cout << " Select Target, 1 -> 3 " << endl;
									std::cin >> target;
									if (target == 1 || target == 2 || target == 3)
									{
										cout << "The Trooper charges while SCREAMING LIKE A CAT IN WATER!" << endl;
										trooperPointer[turnTracker]->m_setDamageBuff(3);
										trooperPointer[turnTracker]->m_setACBuff(-2);
										battleTarget(trooperPointer, 6, turnTracker, target + 2, 1);
										trooperPointer[turnTracker]->m_setDamageBuff(0);
									}
									else
									{
										cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
									}
								}
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
						if (actionTracker == 4)
						{
							cout << " The Trooper grins to himself and stabs themself in the leg... and immediately regrets it" << endl;
							trooperPointer[turnTracker]->m_setCurrentHealth(trooperPointer[turnTracker]->m_getCurrentHealth() - 5);
						}
						if (trooperPointer[turnTracker]->m_getClassTimer() > 0)
						{
							trooperPointer[turnTracker]->m_setClassTimer(trooperPointer[turnTracker]->m_getClassTimer() - 1);
						}
					}
				}
				if (trooperPointer[turnTracker]->m_getRaceNum() == 2)
				{
					if (trooperPointer[turnTracker]->m_getClassNum() == 1)//Troll Toughun
					{
						cout << " Action! " << endl
							<< "- 1 Attack one Target! " << endl;
						std::cin >> actionTracker;
						if (actionTracker == 1)
						{
							cout << " Select Target, 1 -> 3 " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								battleTarget(trooperPointer, 6, turnTracker, target - 1, 1);
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
					}
					if (trooperPointer[turnTracker]->m_getClassNum() == 2)//Troll Stronkun
					{
						cout << " Action! " << endl
							<< "- 1 Attack one Target! " << endl;
						std::cin >> actionTracker;
						if (actionTracker == 1)
						{
							cout << " Select Target, 1 -> 3 " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								battleTarget(trooperPointer, 6, turnTracker, target - 1, 1);
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
					}
					if (trooperPointer[turnTracker]->m_getClassNum() == 3)//Troll Smurtun
					{
						cout << " Action! " << endl
							<< "- 1 Attack one Target! " << endl
							<< "- 3 Troll Song! (Heal All trolls by 2)" << endl;
						std::cin >> actionTracker;
						if (actionTracker == 1)
						{
							cout << " Select Target, 1 -> 3 " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								battleTarget(trooperPointer, 6, turnTracker, target - 1, 1);
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
						if (actionTracker == 3)//Troll Song
						{
							cout << " The Trooper starts singing, its truely horrific. His companions start moving if only to win and be allowed to leave " << endl;
							battleHeal(trooperPointer, 6, 2, 2, turnTracker);
						}
					}
					if (trooperPointer[turnTracker]->m_getClassNum() == 4)//Troll Ungryun
					{
						cout << " Action! " << endl
							<< "- 1 Attack one Target! " << endl
							<< "- 2 Feast (Attack One Target, Heal 5 HP Regardless) ";
						if (trooperPointer[turnTracker]->m_getClassTimer() != 0)
						{
							cout << "On Cooldown for " << trooperPointer[turnTracker]->m_getClassTimer() <<" Turns! "<< endl;
						}
						std::cin >> actionTracker;
						if (actionTracker == 1)
						{
							cout << " Select Target, 1 -> 3 " << endl;
							std::cin >> target;
							if (target == 1 || target == 2 || target == 3)
							{
								battleTarget(trooperPointer, 6, turnTracker, target-1, 1);
							}
							else
							{
								cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
							}
						}
						if (actionTracker == 2)//Feast
						{
							if (trooperPointer[turnTracker]->m_getClassTimer() == 0)
							{
								cout << " Select Target, 1 -> 3 " << endl;
								std::cin >> target;
								if (target == 1 || target == 2 || target == 3)
								{
									cout << "The Trooper Lunges forward teeth bared to tear into a morsel " << endl;
									battleTarget(trooperPointer, 6, turnTracker, target - 1, 1);//Attack
									cout << turnTracker - 2 << endl;
									battleHeal(trooperPointer, 6, 3, 5, turnTracker);//Heal
									trooperPointer[turnTracker]->m_setClassTimer(3);//Set CD
								}
								else
								{
									cout << " The Trooper is confused and wildly swings, missingly greatly " << endl;
								}
							}
							else
							{
								cout << " The Trooper is too tired to do this yet. " << endl;
							}
							
						}
						if (trooperPointer[turnTracker]->m_getClassTimer() > 0)
						{
							trooperPointer[turnTracker]->m_setClassTimer(trooperPointer[turnTracker]->m_getClassTimer() - 1);
						}
					}
				}
					
				
					system("PAUSE");
					turnTracker++;//Increments turn Tracker and check if a team is dead
					if (trooperPointer[0]->m_getCurrentHealth() < 0
						&& trooperPointer[1]->m_getCurrentHealth() < 0
						&& trooperPointer[2]->m_getCurrentHealth() < 0)
					{
						teamDefeated = true;
					}
					if (trooperPointer[3]->m_getCurrentHealth() < 0
						&& trooperPointer[4]->m_getCurrentHealth() < 0
						&& trooperPointer[5]->m_getCurrentHealth() < 0)
					{
						teamDefeated = true;
					}

			

			}
		else //If at less than 0 health they get no turn
			{
					cout << "Trooper is Unconsious" << endl;
					turnTracker++;
			}
		}
	}
}


void battleTarget(Character * troopers[], int elementsA, int sender, int reciever, int damageType)
{
	
		if (troopers[reciever]->m_getProtected() == false)
		{
			if (troopers[sender]->m_attack() >= troopers[reciever]->m_ac() && damageType == 1)//Attack roll made against AC with normal weapon attack
			{
			int currentHealth = troopers[reciever]->m_getCurrentHealth();
			int damage = troopers[sender]->m_damage();//Damage Generated
			cout << endl << "The Trooper strikes for " << damage << " Points!" << endl;
			if (troopers[reciever]->m_getShield() == WOOD)//Shields Reduce Damage
			{
				cout << "But their target's Wood Shield reduces the damage by 1! " << endl;
				if (damage - 1 < 0)
				{
					damage = 0;
					cout << "Negating the Damage Entirely! " << endl;
				}
				else
				{
					damage -= 1;
				}
			}
			if (troopers[reciever]->m_getShield() == METAL)
			{
				cout << "But their target's Metal Shield reduces the damage by 3! " << endl;
				if (damage - 3 < 0)
				{
					damage = 0;
					cout << "Negating the Damage Entirely! " << endl;
				}
				else
				{
					damage -= 3;
				}
			}
			if (troopers[reciever]->m_getShield() == CRYSTAL)
			{
				cout << "But their target's Crystal Shield reduces the damage by 2! " << endl;
				if (damage - 2 < 0)
				{
					damage = 0;
					cout << "Negating the Damage Entirely! " << endl;
				}
				else
				{
					damage -= 2;
				}
			}

			currentHealth -= damage;
			troopers[reciever]->m_setCurrentHealth(currentHealth);
		}
			else { cout << " The Trooper Swings and misses, they aren't too happy with that. " << endl; }
		}
		else {//If target protected nothing happens
			cout << " The Trooper Strikes but just before they hit their Opponents Protection blocks the attack. " << endl;
			troopers[reciever]->m_setProtected(false);
		}
		
	
	if(damageType == 2)//Fire Damage
	{ 
		if (troopers[reciever]->m_getProtected() == false)
		{
			int currentHealth = troopers[reciever]->m_getCurrentHealth();
			int damage = troopers[sender]->m_damage() - 2;
			if (damage < 0)
			{
				damage = 2;
			}
			cout << endl << "The Trooper burns their target for " << damage << " Points!" << endl;
			if (troopers[reciever]->m_getShield() == METAL)//Metal Shield Halves Fire Damage
			{
				cout << "But their target's Metal Shield halves the Damage! " << endl;
				damage = damage / 2;

			}
			currentHealth -= damage;
			troopers[reciever]->m_setCurrentHealth(currentHealth);
		}
		else 
		{
			cout << " The Trooper but just before they hit their Opponents Protection blocks the attack. " << endl;
			troopers[reciever]->m_setProtected(false);
		}
	}
	if (damageType == 3)//Electric Damage
	{
		if (troopers[reciever]->m_getProtected() == false)
		{
			int currentHealth = troopers[reciever]->m_getCurrentHealth();
			int damage = troopers[sender]->m_damage() + 4;
			cout << endl << "The Trooper burns their target for " << damage << " Points!" << endl;
			if (troopers[reciever]->m_getShield() == METAL)//Metal Shield Double Elec Damage
			{
				cout << "But their target's Metal Shield Conducts The Charge! Double Damage! " << endl;
				damage = damage * 2;

			}
			if (troopers[reciever]->m_getShield() == CRYSTAL)//Crystal Shield Negates Elec Damage
			{
				cout << "But their target's Crystal Shield Does not conduct the charge! No Damage! " << endl;
				damage = 0;

			}
			currentHealth -= damage;
			troopers[reciever]->m_setCurrentHealth(currentHealth);
		}
		else//Protection Nullifies
		{
			cout << " The Trooper but just before they hit their Opponents Protection blocks the attack. " << endl;
			troopers[reciever]->m_setProtected(false);
		}
	}
}

void battleStatus(Character *trooperPointer[], int elementsA)//Prints Screen
{
	system("CLS");
	cout << endl << "Orc 1 " << trooperPointer[0]->m_getCurrentHealth() << " / " << trooperPointer[0]->m_getMaxHealth() << " AC " << trooperPointer[0]->m_ac() << " ";
	trooperPointer[0]->m_printShield();
	cout << "                    " << " Troll 1 " << trooperPointer[3]->m_getCurrentHealth() << " / " << trooperPointer[3]->m_getMaxHealth() << " AC " << trooperPointer[3]->m_ac() << " "; 
	trooperPointer[3]->m_printShield();
	cout << endl;

	cout << endl << "Orc 2 " << trooperPointer[1]->m_getCurrentHealth() << " / " << trooperPointer[1]->m_getMaxHealth() << " AC " << trooperPointer[1]->m_ac() << " ";
	trooperPointer[1]->m_printShield();
	cout << "                    " << " Troll 2 " << trooperPointer[4]->m_getCurrentHealth() << " / " << trooperPointer[4]->m_getMaxHealth() << " AC " << trooperPointer[4]->m_ac() << " ";
	trooperPointer[4]->m_printShield();
	cout << endl;

	cout << endl << "Orc 3 " << trooperPointer[2]->m_getCurrentHealth() << " / " << trooperPointer[2]->m_getMaxHealth() << " AC " << trooperPointer[2]->m_ac() << " ";
	trooperPointer[2]->m_printShield();
	cout << "                    " << " Troll 3 " << trooperPointer[5]->m_getCurrentHealth() << " / " << trooperPointer[5]->m_getMaxHealth() << " AC " << trooperPointer[5]->m_ac() << " ";
	trooperPointer[5]->m_printShield();
	cout << endl;



	system("PAUSE");
}

void battleHeal(Character * trooperPointer[], int elementsA, int healType, int healAmount, int target)
{
	if (healType == 1)//Heal Single
	{
		if (trooperPointer[target]->m_getRaceNum() == 1)
		{
			target = target - 1;//If heal doesnt raise over Max, heal else leave at max
			if (trooperPointer[target]->m_getCurrentHealth() + healAmount <= trooperPointer[target]->m_getMaxHealth())
			{
				trooperPointer[target]->m_setCurrentHealth(trooperPointer[target]->m_getCurrentHealth() + healAmount);
			}
			else
			{
				trooperPointer[target]->m_setCurrentHealth(trooperPointer[target]->m_getMaxHealth());
			}
		}
		if (trooperPointer[target]->m_getRaceNum() == 2)
		{
			target = target + 2;//If heal doesnt raise over Max, heal else leave at max
			if (trooperPointer[target]->m_getCurrentHealth() + healAmount <= trooperPointer[target]->m_getMaxHealth())
			{
				trooperPointer[target]->m_setCurrentHealth(trooperPointer[target]->m_getCurrentHealth() + healAmount);
			}
			else
			{
				trooperPointer[target]->m_setCurrentHealth(trooperPointer[target]->m_getMaxHealth());
			}

		}

	}
	if (healType == 2)//Heal Team
	{
		if(trooperPointer[target]->m_getRaceNum() == 1)
		{
			for (int i = 0; i < 3; i++)//If heal doesnt raise over Max, heal else leave at max, whole team
			{
				if (trooperPointer[i]->m_getCurrentHealth() + healAmount <= trooperPointer[i]->m_getMaxHealth())
				{
					trooperPointer[i]->m_setCurrentHealth(trooperPointer[i]->m_getCurrentHealth() + healAmount);
				}
				else
				{
					trooperPointer[i]->m_setCurrentHealth(trooperPointer[i]->m_getMaxHealth());
				}
			}
		}
		if (trooperPointer[target]->m_getRaceNum() == 2)
		{
			for (int i = 3; i < 6; i++)//If heal doesnt raise over Max, heal else leave at max, Whole Team
			{
				if (trooperPointer[i]->m_getCurrentHealth() + healAmount <= trooperPointer[i]->m_getMaxHealth())
				{
					trooperPointer[i]->m_setCurrentHealth(trooperPointer[i]->m_getCurrentHealth() + healAmount);
				}
				else
				{
					trooperPointer[i]->m_setCurrentHealth(trooperPointer[i]->m_getMaxHealth());
				}
			}

		}
	}
	if (healType == 3)//Heal Self
	{

			if (trooperPointer[target]->m_getCurrentHealth() + healAmount <= trooperPointer[target]->m_getMaxHealth())//If heal doesnt raise over Max, heal else leave at max
			{
				trooperPointer[target]->m_setCurrentHealth(trooperPointer[target]->m_getCurrentHealth() + healAmount);
			}
			else
			{
				trooperPointer[target]->m_setCurrentHealth(trooperPointer[target]->m_getMaxHealth());
			}
	}
}

int Orc::m_damage()
{
	return (m_getDamageBase() + m_getDamageMod() + m_getDamageBuff() + (rand() % 4 + 1));
}

int Troll::m_damage()
{
	return (m_getDamageBase() + m_getDamageMod() + m_getDamageBuff() + (rand() % 4 + 3));;
}
