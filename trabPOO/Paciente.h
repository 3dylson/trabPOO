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

	int get_id() const;

	void set_id(int id);

	bool add_consulta(int id, const string& data, float custo, const string& diagonostico);

	Consulta* find_consulta(int id);

	Colecao<Consulta> get_consultas() const;
};
