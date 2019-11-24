#pragma once
#include <iostream>
#include "DataStructures.h"
#include "File.h"
class Executable {
public:
	virtual int Execute() {
		std::cout << "Default";
	}
	
};

class CreateUser :public Executable {
public:
	int Execute() {
		if (CurrentUser.Role=="Admin") {
			User newUser;
			std::cout << "Username:" << std::endl;
			std::cin >> newUser.Username;
			for (int i = 0; i < Users.GetSize(); i++) {
				if (Users[i].Username == newUser.Username) {
					std::cout << "Username already exists";
					return 0;
				}
			}
			std::cout << "Password:" << std::endl;
			std::cin >> newUser.Password;
			std::cout << "Role" << std::endl;
			std::cin >> newUser.Role;

			std::cout << "User succesfully created";
			return 1;
		}
		else {
			std::cout << "Forbiden";
		}
	}
};