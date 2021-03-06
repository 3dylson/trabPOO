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

	bool add_paciente(const string n, int id);

	Paciente* find_paciente(int id);

	Servico* find_servico(const int& id);

	bool atribuir_consulta(int id_c, string data, float custo, const string d, int id_p);

	bool atribuir_exame(int id_p, int id_e, string data, float custo, Tipologia t, int id_c);

	bool remover_paciente(int id);

	bool remover_consulta(int id_c, int id_p);

	bool remover_exame(int id_e, int id_c, int id_p);

	void print_pacientes() const;

	void print_servicos() const;

	float get_valor_total_faturado() const;

	void set_valor_total_faturado(float valor_total_faturado);

	void print_valor_total() const;

	void print_consultas_paciente(int id_p);

	int num_paciente() const;

	int num_servico() const;
};
