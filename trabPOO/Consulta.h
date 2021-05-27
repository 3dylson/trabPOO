#pragma once
#include <string>
#include "Colecao.h"
#include "Exame.h"
#include "Servico.h"

using namespace std;
class Paciente;

class Consulta : public Servico
{
	string diagonostico;
	Paciente* paciente;
	Colecao<Exame> exames;

public:

	Consulta(int id, const string& data, float custo, const string& diagonostico, Paciente* paciente);

	Consulta(int id, const string& data, float custo, const string& diagnostico);

	bool operator<(const Consulta& c) const;

	string get_diagonostico() const;

	void set_diagonostico(const string& diagonostico);

	Paciente* get_paciente() const;

	bool set_paciente(Paciente* paciente);

	bool add(const Exame& exame);

	Exame* find_exame(int& id);

	int num_exames() const;

	void print() const;
};
