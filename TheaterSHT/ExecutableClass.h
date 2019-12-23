#pragma once
#include <iostream>
#include "DataStructures.h"
#include <algorithm>
class Executable {
public:
	virtual int Execute() {
		std::cout << "Default";
		return 1;
	}
	
};

class CreateUser :public Executable {
public:
	int Execute() {
		if (CurrentUser.Role=="Admin") {
			User newUser;
			std::cout << "Username:" << std::endl;
			std::cin >> newUser.Username;
			for (int i = 0; i < Users.size(); i++) {
				if (Users[i].Username == newUser.Username) {
					std::cout << "Username already exists";
					return 0;
				}
			}
			std::cout << "Password:" << std::endl;
			std::cin >> newUser.Password;
			std::cout << "Role" << std::endl;
			std::cin >> newUser.Role;
			userRepository.CreateRecord(newUser);
			std::cout << "User succesfully created";
			return 1;
		}
		else {
			std::cout << "Forbiden";
		}
	}
};

class DeleteUser :public Executable {
public:
	int Execute() {
		if (CurrentUser.Role=="Admin") {
			std::cout << "Input username"<<std::endl;
			std::string userName;
			std::cin >> userName;
			std::vector<User>::iterator it;
			for (int i = 0; i < Users.size();i++) {
				if (Users[i].Username==userName) {
					it =Users.begin()+i;
					Users.erase(it);
					std::cout << "User successfully deleted";
					return 1;
				}
			}
			std::cout << "User with this username does not exist";
			return 0;
		}
	}
};

class ChangePassword :public Executable {
public:
	int Execute() {
		if (CurrentUser.Role=="Admin") {
			std::cout << "Input username"<<std::endl;
			std::string newPassword;
			std::string username;
			std::cin >> username;
			for (int i = 0; i < Users.size();i++) {
				if (Users[i].Username==username) {
					std::cout << "Input new password" << std::endl;
					std::cin >> newPassword;
					Users[i].Password = newPassword;
					userRepository.UpdateFile(Users);
					std::cout << "Password succesfully changed"<<std::endl;
					return 0;
				}
			}
			std::cout << "User with this username does not exist" << std::endl;
			return 1;
		}
	}
};

class CreatePerfomance :public Executable {
public:
	int Execute() {
		if (CurrentUser.Role=="Admin")
		{
			std::cout << "Input perfomance data"<<std::endl;
			Perfomance newPerfomance;
			std::cout << "Input date" << std::endl;
			std::cin >> newPerfomance.Date;
			std::cout << "Input name" << std::endl;
			std::cin >> newPerfomance.PerfomanceName;
			std::cout << "Input amount of tickets" << std::endl;
			std::cin >> newPerfomance.Tickets;
			std::cout << "Input theater name" << std::endl;
			std::cin >> newPerfomance.TheaterName;
			perfomanceRepository.CreateRecord(newPerfomance);
			return 0;
		}
		return 1;
	};
};

class Login :public Executable
{
public:
	int Execute() {
		if (CurrentUser.Username=="") {
			std::cout << "Input username" << std::endl;
			std::string newPassword;
			std::string username;
			std::cin >> username;
			for (int i = 0; i < Users.size(); i++) {
				if (Users[i].Username == username) {
					std::cout << "Input password" << std::endl;
					std::cin >> newPassword;
					if (Users[i].Password == newPassword)
					{
						CurrentUser = Users[i];
						std::cout << "Succes" << std::endl;
						return 0;
					};
					std::cout << "Wrong password" << std::endl;
					return 1;
				}
			}
			std::cout << "User with this username does not exist" << std::endl;
			return 1;
		}
	}
};

class ListOfPerfomances : public Executable
{
public:
	int Execute()
	{
		Perfomances = perfomanceRepository.GetRecords();
		if (CurrentUser.Username!="") {
			for (int i = 0; i < Perfomances.size(); i++)
			{
				std::cout << Perfomances[i].PerfomanceName + " " + Perfomances[i].TheaterName + " " + Perfomances[i].Date+" "<<Perfomances[i].Tickets << std::endl;
			}
		}
		return 1;
	}
};

bool comparatorPerfomanceName(Perfomance a, Perfomance b)
{
	return a.PerfomanceName < b.PerfomanceName;
}

bool comparatorTheaterName(Perfomance a, Perfomance b)
{
	return a.TheaterName < b.TheaterName;
}

bool comparatorTickets(Perfomance a, Perfomance b)
{
	return a.Tickets < b.Tickets;
}
class SortPerfomancesByName : public Executable
{
public:
	int Execute()
	{
		std::vector<Perfomance> sortedPerfomances = perfomanceRepository.GetRecords();
		
		std::sort(sortedPerfomances.begin(), sortedPerfomances.end(),comparatorPerfomanceName);
		for (int i = 0; i < sortedPerfomances.size(); i++)
		{
			std::cout << sortedPerfomances[i].PerfomanceName + " " + sortedPerfomances[i].TheaterName + " " + sortedPerfomances[i].Date + " " << sortedPerfomances[i].Tickets << std::endl;
		}
		return 0;
	}
};
class SortPerfomancesByTheaterName : public Executable
{
public:
	int Execute()
	{
		std::vector<Perfomance> sortedPerfomances = perfomanceRepository.GetRecords();

		std::sort(sortedPerfomances.begin(), sortedPerfomances.end(), comparatorTheaterName);
		for (int i = 0; i < sortedPerfomances.size(); i++)
		{
			std::cout << sortedPerfomances[i].PerfomanceName + " " + sortedPerfomances[i].TheaterName + " " + sortedPerfomances[i].Date +" "<< sortedPerfomances[i].Tickets << std::endl;
		}
		return 0;
	}
};
class SortPerfomancesByTickets : public Executable
{
public:
	int Execute()
	{
		std::vector<Perfomance> sortedPerfomances = perfomanceRepository.GetRecords();

		std::sort(sortedPerfomances.begin(), sortedPerfomances.end(), comparatorTickets);
		for (int i = 0; i < sortedPerfomances.size(); i++)
		{
			std::cout << sortedPerfomances[i].PerfomanceName + " " + sortedPerfomances[i].TheaterName + " " + sortedPerfomances[i].Date+" " << sortedPerfomances[i].Tickets << std::endl;
		}
		return 0;
	}
};

class SearchPerfomance : public Executable
{
public:
	int Execute()
	{
		std::string searchInput;
		std::vector<Perfomance> results;
		std::cout << "Input search data";
		std::cin >> searchInput;
		Perfomances = perfomanceRepository.GetRecords();
		for (int i =0;i<Perfomances.size();i++)
		{
			if (searchInput.find(Perfomances[i].Date) || searchInput.find(Perfomances[i].PerfomanceName) || searchInput.find(Perfomances[i].TheaterName)) {
				results.push_back(Perfomances[i]);
			}
		}
		for (int i = 0; i < results.size(); i++)
		{
			std::cout << results[i].PerfomanceName + " " + results[i].TheaterName + " " + results[i].Date+ " " << results[i].Tickets << std::endl;
		}
		return 0;
	}
};