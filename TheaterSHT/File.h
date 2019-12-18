#pragma once
#include <fstream>
#include <iostream>
#include "List.h"
#include <iterator>
#include <string>
#include <ios>
#include <vector>
template<typename T>
class File {
private:
	std::ofstream myfile;
	std::ifstream rf;
	std::string Path;
public:
	File(std::string Path) {
		myfile = std::ofstream(Path, std::ios_base::app);
		this->Path = Path;
		rf = std::ifstream(Path);
	}
	void CreateRecord(T entity) {
		if (!myfile.is_open()) {
			myfile.open(Path,std::ios_base::app);
			
		}
		myfile.write((char*)&entity, sizeof(T));
		myfile.close();
	}
	void UpdateFile(std::vector<T> entities) {
		if (!myfile.is_open()) {
			myfile.open(Path);

		}
		for (int i = 0; i < entities.size();i++) {
			myfile.write((char*)&entities[i], sizeof(T));
		}
		myfile.close();
	}
	std::vector<T> GetRecords(){
		std::vector<T> newList;
		if (!rf.is_open()) {
			rf.open(Path);
		}
		
		
		if (rf.is_open()) {
			
			T newRecord;

			while(rf.read((char*) & newRecord, sizeof(T))){
				T tempRecord;
				newList.push_back(tempRecord);
			}

			rf.close();
			return newList;
		}
		
		newList.empty();
		return newList;
		
		
	}
};

