#pragma once
#include <string>
#include "Colecao.h"
#include "ColecaoHibrida.h"
#include "Servico.h"
#include "Paciente.h"
#include "Consulta.h"

using namespace std;

class Consultorio
{
	string nome;
	float valor_total_faturado;
	Colecao<Paciente> pacientes;
	ColecaoHibrida<Servico*> servicos;
public:

	Consultorio(string n);

	string get_nome() const;

	bool add_paciente(string n, int id);

	Paciente* find_paciente(int id);

	Servico* find_servico(const int& id);

	bool atribuir_consulta(int id_c, string data, float custo, const string d, int id_p);

	bool atribuir_exame(int id_p, int id_e, string data, float custo, Tipologia t, int id_c);

	bool remover_paciente(int id);

	bool remover_servico(int id);

	void print_paciente() const;

	void print_servicos();

	/*bool add_consulta(int id_c, string data, float custo, int id_p);

	Consulta* find_consulta(int id);*/

	float get_valor_total_faturado() const;

	void set_valor_total_faturado(float valor_total_faturado);

	void print_valor_total() const;

	void print_consultas_paciente(int id_p);
};
