#pragma once
#include <string>
class User
{
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

