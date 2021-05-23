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

	Exame(int id, const string& data, float custo, Tipologia tipo);


	void set_custo(float custo);


	
};
