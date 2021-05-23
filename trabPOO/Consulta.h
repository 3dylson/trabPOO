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

	Consulta(int id, const string& data, float custo, const string& diagonostico);
};
