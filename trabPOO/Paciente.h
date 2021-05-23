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
	Paciente(string n, int id);
	void add_consulta(int id, string data, float custo, string diagnostico);
	void print();
};
