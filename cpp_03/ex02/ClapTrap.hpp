#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	private:
		std::string	Name;
		int			Hit_Points;
		int			Energy_Points;
		int			Attack_damage;

	public:
		ClapTrap(std::string name, int hitpoints, int energy_points, int attack_damage);
		ClapTrap(std::string name);
		ClapTrap (const ClapTrap &clap_trap);
		~ClapTrap(void);
		ClapTrap &operator = (ClapTrap const &clap_trap);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	get_name(void) const;
		int			get_hit_points(void) const;
		int			get_energy_points(void) const;
		int			get_attack_damage(void) const;

};



#endif