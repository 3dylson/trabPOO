#pragma once
#include <string>
#include "Colecao.h"
#include "Servico.h"
#include "Paciente.h"

class Consultorio
{
	string nome;
	Colecao<Paciente> pacientes;
	Colecao<Servico> servicos;
public:

	Consultorio(string n);

	bool add_paciente(string n, int id);

	Paciente* find_paciente(int id);

	bool add_consulta(int id, string data, float custo);

	Servico* find_servico(int id);

	bool atribuir_consulta(int id_c, int id_p, const string& d);

	bool atribuir_exame(int id_e, string data, float custo, int id_c); // mudar p bool no diagrama

	float valor_faturacao(); //double ou float??

	void print_consultas_paciente(int id_p);
};
