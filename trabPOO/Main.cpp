// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "Consultorio.h"

int main()
{
	cout << endl << "|-------------------------|" << endl;
	cout << endl << "|     Consultorio xpto    |" << endl;
	cout << endl << "|-------------------------|" << endl;
	cout << "\n" << endl;

	Consultorio xpto("xpto");
	cout << "Adicionar paciente 1:" << endl;
	xpto.add_paciente("Pedro", 1);
	cout << "Adicionar o mesmo paciente: " << endl;
	xpto.add_paciente("Pedro", 1);
	cout << "Adicionar paciente 2 e 3:" << endl;
	xpto.add_paciente("Maria", xpto.num_paciente() + 1);
	xpto.add_paciente("Rui", xpto.num_paciente() + 1);
	cout << "------------------------------\n";
	cout << "Listar pacientes: " << endl;
	xpto.print_pacientes();
	cout << "Remover paciente 3: " << endl;
	xpto.remover_paciente(3);
	cout << "------------------------------\n";
	cout << "Sera que ha algum Rui id = 3 ?\n";
	Paciente* r = xpto.find_paciente(3);
	if (r != NULL) r->print();
	else cout << "Nao\n";
	cout << "------------------------------\n";
	cout << "Sera que ha algum Pedro id = 1 ?\n";
	Paciente* p = xpto.find_paciente(1);
	if (p != NULL) p->print();
	else cout << "Nao\n";
	cout << "------------------------------\n";
	xpto.print_valor_total();
	cout << "Atribuir consulta a pacientes" << endl;
	xpto.atribuir_consulta(1, "01/01/01", 5.99, "Lorem ipsum dolor sit amet.", 1);
	xpto.atribuir_consulta(xpto.num_servico() + 1, "02/01/01", 3.99, "Lorem ipsum dolor sit amet.", 1);
	cout << "Listar servicos: " << endl;
	xpto.print_servicos();
	xpto.print_valor_total();
	cout << "------------------------------\n";
	cout << "Atribuir exames a consultas: " << endl;
	xpto.atribuir_exame(1, xpto.num_servico() + 1, "01/01/01", 10.25, Check_up, 1);
	xpto.atribuir_exame(1, xpto.num_servico() + 1, "02/01/01", 13.25, Analise_Clinicas, 1);
	xpto.print_valor_total();
	cout << "------------------------------\n";
	xpto.print_consultas_paciente(1);
}