#include "Exame.h"

Exame::Exame() : Servico(NULL, NULL, NULL)
{
	consulta = NULL;
}

Exame::Exame(int id, const string& data, float custo, Tipologia tipo)
	: Servico(id, data, custo),
	tipo(tipo)
{
	consulta = NULL;
}

Tipologia Exame::get_tipo() const
{
	return tipo;
}

void Exame::set_tipo(Tipologia tipo)
{
	this->tipo = tipo;
}

Consulta* Exame::get_consulta() const
{
	return consulta;
}

void Exame::set_consulta(Consulta* c) {
	if (consulta == NULL)
		consulta = c;
}