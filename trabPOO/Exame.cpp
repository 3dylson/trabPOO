#include "Exame.h"

Exame::Exame(int id, const string& data, float custo, Tipologia tipo)
	: Servico(id, data, custo),
	  tipo(tipo)

{}

void Exame::set_custo(float custo)
{
	float c = Servico::get_custo();
	float final = c + custo;
	
	Servico::set_custo(final);
}

