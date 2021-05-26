#pragma once
#include <string>

#include "Servico.h"

using namespace std;
class Consulta;
enum Tipologia { Analise_Clinicas = 1, Imagiologia, Check_up };

class Exame : public Servico
{
	Tipologia tipo;
	Consulta* consulta;

public:

	Exame();

	Exame(int id, const string& data, float custo, Tipologia tipo);

	bool operator<(const Exame& e) const;

	Tipologia get_tipo() const;

	void set_tipo(Tipologia tipo);

	Consulta* get_consulta() const;

	bool set_consulta(Consulta* ce);

	void print() const;
};
