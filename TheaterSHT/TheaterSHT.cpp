// TheaterSHT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include "ExecutableClass.h"
#include "File.h"
template<typename T>
void test(T input) {
	std::cout << T;
}
int main()
{
	std::map<std::string,Executable> Executables;
	UserRepository = File<User>("Users.txt");
	PerfomanceRepository = File<Perfomance>("Perfomances.txt");
	
	User s;
	s.Password = "123";
	s.Role = "admin";
	s.Username = "lol";
	UserRepository.CreateRecord(s);
	UserRepository.GetRecords();

}

