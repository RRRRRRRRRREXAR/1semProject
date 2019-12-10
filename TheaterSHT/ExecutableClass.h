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
			UserRepository.CreateRecord(newUser);
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
			for (int i = 0; i < Users.GetSize();i++) {
				if (Users[i].Username==userName) {
					Users.removeAt(i);
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
			for (int i = 0; i < Users.GetSize();i++) {
				if (Users[i].Username==username) {
					std::cout << "Input new password" << std::endl;
					std::cin >> newPassword;
					Users[i].Password = newPassword;
					UserRepository.UpdateFile(Users);
					std::cout << "Password succesfully changed"<<std::endl;
					return 0;
				}
			}
			std::cout << "User with this username does not exist" << std::endl;
			return 1;
		}
	}
};