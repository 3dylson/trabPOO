#include "Exame.h"

#include <iostream>
#include <ostream>

#include "Consulta.h"

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
	{
		consulta = c;
		cout << "Exame: " << this->get_id() << "- " << this->get_tipo() << " adicionado a consulta: " << c->get_id() << endl;
	}

	Consulta* c1 = this->get_consulta();
	cout << "Exame: " << this->get_id() << "ja se encontra atribuida a consulta: " << c1->get_id() << endl;
}

void Exame::print() const
{
	Servico::print();
	cout << this->get_tipo() << endl;
}