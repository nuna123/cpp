#include <iostream>

class Contact {
	private:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;

	public:
		int			exists;
		void set_index (int i) {index = i;}
		void set_contact (std::string fst_name, std::string lst_name, std::string nick_name, std::string num)
		{
			exists = 0;
			first_name = fst_name;
			last_name = lst_name;
			nickname = nick_name;
			number = num;
		}
		void print_contact ()
		{
			std::cout << "\t" << index;
			std::cout << "\t" << first_name;
			std::cout << "\t" << last_name;
			std::cout << "\t" << nickname;
			std::cout << "\t" << number;
			std::cout << std::endl;
		}
};

class PhoneBook {
	public:
		Contact contacts[8];
		void add_contact(Contact contact)
		{
			
			int	i;

			i = 0;
			while (i < 8 && contacts[i].exists == 1)
				i++;
			contacts[i] = contact;
			contacts[i].exists = 1;
			contacts[i].set_index(i);
		}

		void print_contacts (void)
		{
			int i = 0;
			while (i < 8 && contacts[i].exists == 1)
				contacts[i++].print_contact();
			
		}

};