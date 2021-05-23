#pragma once
#include "Colecao.h"
#include <string>
#include "Servico.h"
#include "Paciente.h"
#include "Consulta.h"
#include "Exame.h"

class Consultorio
{
	string nome;
	Colecao<Paciente> pacientes;
	Colecao<Servico> servicos;
public:
	Consultorio(string n);
	bool add_paciente(string n, int id);
	bool add_consulta(int id, string data, float custo, string diagnostico);
	bool atribuir_consulta(int id_c, int id_p);
	bool atribuir_exame(int id_e, string data, float custo, int id_c); // mudar p bool no diagrama
	float valor_faturacao(); //double ou float??
	void print_consultas_paciente(int id_p);
};
