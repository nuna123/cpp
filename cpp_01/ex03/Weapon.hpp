#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string	type);
		~Weapon(void);
		Weapon(const Weapon &weapon);
		Weapon &operator=(const Weapon &weapon);

		const std::string& getType() const;
		void setType(const std::string new_type);
};

#endif