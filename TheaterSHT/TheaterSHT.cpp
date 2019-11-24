// TheaterSHT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include "ExecutableClass.h"
#include "File.h"

int main()
{
	std::map<std::string,Executable> Executables;
	File<Perfomance> myfile = File<Perfomance>("Perfomances.txt");
	Perfomance newPerfomance;
	newPerfomance.Date = "govno";
	newPerfomance.PerfomanceName = "gov";
	newPerfomance.TheaterName = "no";
	newPerfomance.Tickets=12;
	myfile.CreateRecord(newPerfomance);
}

