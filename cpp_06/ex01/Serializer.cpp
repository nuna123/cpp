#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* data_ptr)
{
	return (reinterpret_cast<uintptr_t>(data_ptr));
}
Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}