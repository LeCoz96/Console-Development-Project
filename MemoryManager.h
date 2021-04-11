#pragma once
#include<iostream>
#include<string>

static int TotalHeapMemory = 0;
// New Overloads
inline void* operator new(size_t size, const char* filename, int line)
{
	TotalHeapMemory += size;
	void* ptr = new char[size];
	std::cout << "Size = " << size << " bytes " << "filename = " << filename << " line = " << line << std::endl;
	std::cout << "Total heap allocation = " << TotalHeapMemory << " bytes " << std::endl;

	return ptr;
}

inline void* operator new[](size_t size, const char* filename, int line)
{
	TotalHeapMemory += size;
	void* ptr = new char[size];
	std::cout << "Size = " << size << " bytes " << "filename = " << filename << " line = " << line << std::endl;
	std::cout << "Total heap allocation = " << TotalHeapMemory << " bytes " << std::endl;

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
