﻿#pragma once
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

	bool add_consulta(int id, string& data, float custo, string& diagnostico, Paciente* paciente);

	void print() const;

	Consulta* find_consulta(int id);

	bool add(const Consulta& c);

	Colecao<Consulta> get_consultas() const;
};
