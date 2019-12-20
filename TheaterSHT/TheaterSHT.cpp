// TheaterSHT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include "ExecutableClass.h"
#include <algorithm>
#include "DataStructures.h"
template<typename T>
void test(T input) {
	std::cout << T;
}
int main()
{
	std::map<std::string,Executable> Executables;
	userRepository = UserRepository("Users.txt");
	perfomanceRepository = PerfomanceRepository("Perfomances.txt");
	Perfomance newPerfomance;
	newPerfomance.Date = "no";
	newPerfomance.PerfomanceName = "no";
	newPerfomance.TheaterName = "no";
	newPerfomance.Tickets=12;
	std::vector<User> Users;
	perfomanceRepository.CreateRecord(newPerfomance);

	//std::vector<Perfomance>r = PerfomanceRepository.GetRecords();
	/*for (int i = 0; i < r.size(); ++i)
	{
		std::cout << r[i].TheaterName << std::endl;
		std::cout << r[i].PerfomanceName << std::endl;
		std::cout << r[i].Tickets << std::endl;
		std::cout << r[i].Date << std::endl;

	}*/


}

