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
template<typename T>
void CopyList(List<T>from,List<T>to)
{
	for(int i=0;i<from.GetSize();++i)
	{
		to.push_back(from[i]);
	}
}
int main()
{
	std::map<std::string,Executable> Executables;
	UserRepository = File<User>("Users.txt");
	PerfomanceRepository = File<Perfomance>("Perfomances.txt");
	Perfomance newPerfomance;
	newPerfomance.Date = "no";
	newPerfomance.PerfomanceName = "no";
	newPerfomance.TheaterName = "no";
	newPerfomance.Tickets=12;

	
	CopyList(UserRepository.GetRecords(),Users);

}

