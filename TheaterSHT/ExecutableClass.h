#pragma once
#include <iostream>
#include "DataStructures.h"
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