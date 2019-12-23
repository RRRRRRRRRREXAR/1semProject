#pragma once
#include <string>
class Perfomance
{
public:
	std::string TheaterName;
	std::string Date;
	std::string PerfomanceName;
	int Tickets;
	Perfomance() = default;
	Perfomance(std::string TheaterName,std:: string Date,std:: string PerfomanceName,int Tickets)
	{
		this->TheaterName = TheaterName;
		this->Date = Date;
		this->PerfomanceName = PerfomanceName;
		this->Tickets = Tickets;
	}
	
};

