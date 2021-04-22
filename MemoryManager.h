#pragma once
#include<iostream>
#include <fstream>
#include<string>

static int TotalHeapMemory = 0;

std::ofstream file("Assets/Output.txt");

// New Overloads
inline void* operator new(size_t size, const char* filename, int line)
{
	TotalHeapMemory += size;
	void* ptr = new char[size];

	if (!file)
	{
		std::cout << "Error loading 'Output.txt'" << std::endl;
	}

	std::cout << "Size = " << size << " bytes " << "filename = " << filename << " line = " << line << std::endl;
	std::cout << "Total heap allocation = " << TotalHeapMemory << " bytes " << std::endl;

	file << "Size = " << size << " bytes " << "filename = " << filename << " line = " << line << std::endl;
	file << "Total heap allocation = " << TotalHeapMemory << " bytes " << std::endl;

	return ptr;
}

inline void* operator new[](size_t size, const char* filename, int line)
{
	TotalHeapMemory += size;
	void* ptr = new char[size];

	if (!file)
	{
		std::cout << "Error loading 'Output.txt'" << std::endl;
	}

	std::cout << "Size = " << size << " bytes " << "filename = " << filename << " line = " << line << std::endl;
	std::cout << "Total heap allocation = " << TotalHeapMemory << " bytes " << std::endl;

	file << "Size = " << size << " bytes " << "filename = " << filename << " line = " << line << std::endl;
	file << "Total heap allocation = " << TotalHeapMemory << " bytes " << std::endl;

	return ptr;

}

// Delete Overloads
// Exception delete: Parameters match the overload new and will be used if the object creation throws an exception
inline void operator delete(void* ptr, const char* filename, int line)
{
	free(ptr);
}

// If successful object creation, the following deletes will be used
inline void operator delete(void* ptr)
{
	free(ptr);
}

inline void operator delete[](void* ptr)
{
	free(ptr);
}


// Exploit the preprocessor
#define new new(__FILE__,__LINE__)
