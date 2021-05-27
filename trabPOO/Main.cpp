// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "Consultorio.h"

int main()
{
	Consultorio xpto("xpto");
	xpto.add_paciente("Teste", 1);
	xpto.add_paciente("Luis", 2);
	
	xpto.remover_paciente(2);
	xpto.remover_paciente(9);

	xpto.print_paciente();
	
}