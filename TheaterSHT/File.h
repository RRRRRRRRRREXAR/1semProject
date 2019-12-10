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
	List<T> GetRecords(){
		if (!rf.is_open()) {
			rf.open();
		}
		if (rf.is_open()) {
			List<T> newList;
			while(true){
				T newRecord;
				rf.read((char*)&newRecord, sizeof(T));
				if (newRecord!=nullptr) {
					newList.push_back(newRecord);
				}
				else {
					break;
				}
			}
			rf.close();
			return newList;
		}
		
	}
};

