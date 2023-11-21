#include <iostream>
#include <vector>

class ASpell;
class Warlock
{
	private:
		std::string name;
		std::string title;
		std::std::vector<ASpell *> spells;

	public:
		Warlock();
		~Warlock();
		Warlock(std::string name, std::string title);
		const Warlock &operator=(const Warlock &src);
		Warlock(const Warlock &src);

		const std::string &getName(void) const;
		const std::string &getTitle(void) const;

		// void setName (const std::string &name);
		void setTitle (const std::string &title);

		void introduce() const;

		void learnSpell(ASpell *spell_ptr);
};