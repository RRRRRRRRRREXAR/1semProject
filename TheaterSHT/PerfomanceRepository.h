#pragma once
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <ios>
#include <vector>
#include "DataStructures.h"
#include "Perfomance.h"
class PerfomanceRepository 
{
private:
	std::ofstream myfile;
	std::ifstream rf;
	std::string Path;
public:
	PerfomanceRepository(std::string Path)
	{
		myfile = std::ofstream(Path, std::ios_base::app);
		this->Path = Path;
		rf = std::ifstream(Path);
	}
	void CreateRecord(Perfomance entity) 
	{
		if (!myfile.is_open()) {
			myfile.open(Path,std::ios_base::app);
			
		}
		if (myfile.is_open())
		{
			myfile << entity.TheaterName << " " << entity.Date << " " << entity.PerfomanceName << " " << entity.Tickets << std::endl;
		}
		myfile.close();
	}
	void UpdatePerfomanceRepository(std::vector<Perfomance> entities) 
	{
		if (!myfile.is_open())
		{
			myfile.open(Path);

		}
		std::ofstream tempFile;
		tempFile.open("temp1.txt");
		for (int i = 0; i < entities.size(); ++i)
		{
			tempFile << entities[i].TheaterName << " " << entities[i].Date << " " << entities[i].PerfomanceName << " " << entities[i].Tickets << std::endl;
		}
		myfile.close();
		tempFile.close();
		remove("Perfomances.txt");
		rename("temp1.txt", "Performances.txt");

	}
	std::vector<Perfomance> GetRecords(){
		std::vector<Perfomance> newList;
		if (!rf.is_open()) 
		{
			rf.open(Path);
		}
		
		
		if (rf.is_open()) 
		{
			
			std::string TheaterName;
			std::string Date;
			std::string PerfomanceName;
			int Tickets;
			while (rf >> TheaterName >> Date >> PerfomanceName >> Tickets)
			{
				newList.push_back(Perfomance(TheaterName, Date, PerfomanceName, Tickets));
			}
			
			rf.close();
			return newList;
		}
		
		newList.empty();
		return newList;
		
		
	}
};

