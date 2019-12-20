#pragma once
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <ios>
#include <vector>
#include "DataStructures.h"
#include "User.h"
class UserRepository 
{
private:
	std::ofstream myfile;
	std::ifstream rf;
	std::string Path;
public:
	UserRepository(std::string Path) 
	{
		myfile = std::ofstream(Path, std::ios_base::app);
		this->Path = Path;
		rf = std::ifstream(Path);
	}
	void CreateRecord(User entity)
	{
		if (!myfile.is_open()) 
		{
			myfile.open(Path,std::ios_base::app);
			
		}
		if (myfile.is_open())
		{
			myfile << entity.Username << " " << entity.Password << " " << entity.Role<<std::endl;
		}



		myfile.close();
	}
	void UpdateFile(std::vector<User> entities) {
		if (!myfile.is_open()) {
			myfile.open(Path);

		}

		
		myfile.close();
	}
	std::vector<User> GetRecords(){
		std::vector<User> newList;
		if (!rf.is_open()) {
			rf.open(Path);
		}
		
		
		if (rf.is_open()) {
			std::string Username;
			std::string Password;
			std::string Role;
			//UserRepository newRecord;
			while (rf >> Username >> Password >> Role)
			{
				newList.push_back(User(Username, Password, Role));
			}
			

			rf.close();
			return newList;
		}
		
		newList.empty();
		return newList;
		
		
	}
};

