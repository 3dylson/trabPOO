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
	xpto.atribuir_consulta(1, "01/02/21", 19.99, "lorem", 1);
	xpto.print_valor_total();
	xpto.atribuir_exame(1, 2, "02/12/12", 10.99, Check_up, 1);
	xpto.atribuir_exame(1, 3, "02/12/12", 10.99, Analise_Clinicas, 1);
	xpto.print_consultas_paciente(1);
}