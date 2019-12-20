#pragma once
#include <string>
# include "PerfomanceRepository.h"
#include "UserRepository.h"
#include <vector>
class Perfomance {
public:
	std::string TheaterName;
	std::string Date;
	std::string PerfomanceName;
	int Tickets;
	Perfomance() = default;
	Perfomance(std::string TheaterName,std:: string Date,std:: string PerfomanceName,int Tickets)
	{
		this->TheaterName = TheaterName;
		this->Date = Date;
		this->PerfomanceName = PerfomanceName;
		this->Tickets = Tickets;
	}
};

class User {
public:
	std::string Username;
	std::string Password;
	std::string Role;
	User() = default;
	User(std::string Username, std::string Password, std::string Role)
	{
		this->Username = Username;
		this->Password = Password;
		this->Role = Role;
	}
};

static User CurrentUser;
static std::vector<Perfomance> Perfomances;
static std::vector<User> Users;
static PerfomanceRepository perfomanceRepository("");
static UserRepository userRepository("");