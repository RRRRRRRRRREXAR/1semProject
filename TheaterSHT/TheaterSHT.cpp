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
	newPerfomance.Date = "12/03/2002";
	newPerfomance.PerfomanceName = "Jaba";
	newPerfomance.TheaterName = "Kola";
	newPerfomance.Tickets=120;
	std::vector<User> Users;
	//perfomanceRepository.CreateRecord(newPerfomance);

	std::vector<Perfomance>r = perfomanceRepository.GetRecords();
	r.pop_back();
	perfomanceRepository.UpdatePerfomanceRepository(r);
	/*for (int i = 0; i < r.size(); ++i)
	{
		std::cout << r[i].TheaterName << std::endl;
		std::cout << r[i].PerfomanceName << std::endl;
		std::cout << r[i].Tickets << std::endl;
		std::cout << r[i].Date << std::endl;

	}*/


}

