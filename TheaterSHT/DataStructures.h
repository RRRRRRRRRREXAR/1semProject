#pragma once
#include <string>
#include "List.h"
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
static List<Perfomance> Perfomances;
static List<User> Users;