#ifndef SERIALIER_HPP
#define SERIALIER_HPP

#include "./Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		const Serializer& operator=(const Serializer &src);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif