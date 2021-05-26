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
	Colecao<Exame*> exames;

public:

	Consulta();

	Consulta(int id, const string& data, float custo, const string& diagonostico, Paciente* paciente);

	Consulta(int id, const string& data, float custo);

	string get_diagonostico() const;

	void set_diagonostico(const string& diagonostico);

	Paciente* get_paciente() const;

	void set_paciente(Paciente* paciente);

	bool add_exame(Exame& exame);

	void print() const;
};
