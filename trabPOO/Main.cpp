// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "Consultorio.h"

int main()
{
	Consultorio xpto("xpto");
	xpto.add_paciente("Teste", 1);
	xpto.atribuir_consulta(1, "01/02/21", 19.99, "lorem", 2);
	xpto.print_valor_total();
}