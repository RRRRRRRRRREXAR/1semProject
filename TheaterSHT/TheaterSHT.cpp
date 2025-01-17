﻿// TheaterSHT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	std::map<std::string,Executable*> Executables;
	userRepository = UserRepository("Users.txt");
	perfomanceRepository = PerfomanceRepository("Perfomances.txt");
	Executables.insert(std::make_pair("Login", new Login()));
	Executables.insert(std::make_pair("CreateUser", new CreateUser()));
	Executables.insert(std::make_pair("DeleteUser", new DeleteUser()));
	Executables.insert(std::make_pair("ChangePassword", new ChangePassword()));
	Executables.insert(std::make_pair("ListOfPerfomances", new ListOfPerfomances()));
	Executables.insert(std::make_pair("CreatePerfomance", new CreatePerfomance()));
	Executables.insert(std::make_pair("SortPerfomancesByName", new SortPerfomancesByName()));
	Executables.insert(std::make_pair("SortPerfomancesByTheaterName", new SortPerfomancesByTheaterName()));
	Executables.insert(std::make_pair("SortPerfomancesByTickets", new SortPerfomancesByTickets()));

	//Perfomance newPerfomance;
	//newPerfomance.Date = "12/03/2002";
	//newPerfomance.PerfomanceName = "Jaba";
	//newPerfomance.TheaterName = "Kola";
	//newPerfomance.Tickets=120;
	//std::vector<User> Users;
	////perfomanceRepository.CreateRecord(newPerfomance);

	Perfomances = perfomanceRepository.GetRecords();
	////r.pop_back();
	//perfomanceRepository.UpdatePerfomanceRepository(r);
	//User* newUser = new User("Yura","123","Admin");
	//userRepository.CreateRecord(*newUser);
	Users = userRepository.GetRecords();
	//Users.clear();
	//userRepository.UpdateFile(Users);
	while (true)
	{
		std::string userInput;
		std::cin >> userInput;
		try
		{
			Executables[userInput]->Execute();
		}
		catch (const std::exception&)
		{
			std::cout << "Error";
		}
	}
	/*for (int i = 0; i < r.size(); ++i)
	{
		std::cout << r[i].TheaterName << std::endl;
		std::cout << r[i].PerfomanceName << std::endl;
		std::cout << r[i].Tickets << std::endl;
		std::cout << r[i].Date << std::endl;

	}*/


}

