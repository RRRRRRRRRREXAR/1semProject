#pragma once
#include <fstream>
#include <iostream>
#include "List.h"
#include <iterator>
#include <string>
#include <ios>
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
	}
	void UpdateFile() {

	}
	List<T> GetRecords(){
		if (!rf.is_open()) {
			rf.open();
		}
		if (rf.is_open()) {
			T newRecord;
			List<T> newList;
			while (getline(rf,newRecord)) {
				newList.push_back(newRecord);
			}
			return newList;
		}
		else {
			return NULL;
		}
	}
};

