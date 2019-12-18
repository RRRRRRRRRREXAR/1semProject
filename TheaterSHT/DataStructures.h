#pragma once
#include <string>
#include "List.h"
#include "File.h"
#include <vector>
class Perfomance {
public:
	std::string TheaterName;
	std::string Date;
	std::string PerfomanceName;
	int Tickets;
	
};

class User {
public:
	std::string Username;
	std::string Password;
	std::string Role;
};

static User CurrentUser;
static std::vector<Perfomance> Perfomances;
static std::vector<User> Users;
static File<Perfomance> PerfomanceRepository("");
static File<User> UserRepository("");