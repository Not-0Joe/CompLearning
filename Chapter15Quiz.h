#pragma once
#include <string>
#include <string_view>
// chapter 15 quiz  of learncpp.com 

/*First, let’s create an scoped enumeration of monster types named MonsterType. Include the following
monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, 
and Zombie. Add an additional maxMonsterTypes enumerator so we can count how many enumerators there are.*/

class Monster
{
public:
	
	enum Type
	{
		dragon,
		goblin, 
		orgre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		axMonsterType,
	};
	
	explicit Monster(Type type, const std::string_view name, const std::string_view roar, int hp)
		: m_type{ type }, m_name {name}, m_roar{ roar }, m_hp{ hp } { }


	std::string getTypeString() const
	{
		// we want to return the string name of the type we will use a switch on the enum

		switch (m_type)
		{
			case Type::dragon:
			{
				return "Dragon";
				break;
			}
			case Type::goblin:
			{
				return "goblin";
				break;
			}
			case Type::orgre:
			{
				return "orgre";
				break;
			}
			case Type::orc:
			{
				return "orc";
				break;
			}
			case Type::skeleton:
			{
				return "skeleton";
				break;
			}
			case Type::troll:
			{
				return "troll";
				break;
			}
			case Type::vampire:
			{
				return "vampire";
				break;
			}
			case Type::zombie:
			{
				return "zombie";
				break;
			}
			default: return "invalid";
			
		}

	}

	void print()
	{
		if (m_hp <= 0)
		{
			std::cout << m_name << " the " << getTypeString() << " is dead\n";
			return; 
		}

		std::cout << m_name << " the " << getTypeString() << " has " << m_hp << " hit points and says " << m_roar << "\n";


	}

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hp; 
};

// skipping over finshing the implemtation of this since i have already done this on other projects with more complex generation logic
// also i would ideally split this up into the muliple files cpp for defintions and the header with the class protoypes and constructor

