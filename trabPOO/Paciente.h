#pragma once
#include <string>
#include "Colecao.h"
#include "Consulta.h"

class Paciente
{
	string nome;
	int id;
	Colecao<Consulta> consultas;
public:

	Paciente(const string& nome, int id);

	bool operator<(const Paciente& p) const;

	string get_nome() const;

	void set_nome(const string& nome);

	int get_id();

	void set_id(int id);

	void print() const;

	Consulta* find_consulta(int id);

	bool add(const Consulta& c);

	bool remover_consulta(int id_c);

	int num_consulta() const;
};
