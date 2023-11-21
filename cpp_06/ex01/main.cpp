#include "./Data.hpp"
#include "./Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main(void)
{
	Data		data;
	Data		*data_ptr =&data;
	Data		*new_ptr;

	uintptr_t	raw;

	data.id = 5;
	data.name = "numero five";

	std::cout << data_ptr <<std::endl;
	std::cout << data_ptr->id << ", " << data_ptr->name <<std::endl<<std::endl;

	raw = Serializer::serialize(data_ptr);
	std::cout << raw <<std::endl<<std::endl;


	new_ptr = Serializer::deserialize(raw);
	std::cout << new_ptr <<std::endl;
	std::cout << new_ptr->id << ", " << new_ptr->name <<std::endl<<std::endl;

	std::cout << (new_ptr == data_ptr) <<std::endl<<std::endl;

	return 0;
}