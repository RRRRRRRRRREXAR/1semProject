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
	void UpdateFile(List<T> entities) {
		if (!myfile.is_open()) {
			myfile.open(Path);

		}
		for (int i = 0; i < entities.GetSize();i++) {
			myfile.write((char*)&entities[i], sizeof(T));
		}
		myfile.close();
	}
	void GetRecords(){
		if (!rf.is_open()) {
			rf.open(Path);
		}
		if (rf.is_open()) {
			List<T> newList;
			T newRecord;

			while(rf.read((char*) & newRecord, sizeof(T))){
				newList.push_back(newRecord);
			}

			rf.close();
			
			return N;
		}
		
	}
};

