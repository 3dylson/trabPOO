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

bool Exame::operator<(const Exame& e) const
{
	return id < e.id;
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

bool Exame::set_consulta(Consulta* ce)
{
	if (consulta == NULL)
	{
		consulta = ce;
		cout << "Exame: " << this->get_id() << " , do Tipo - " << this->get_tipo() << " adicionado a consulta." << endl;
		return true;
	}

	cout << "Exame: " << this->get_id() << " ja se encontra atribuido" << endl;
}

void Exame::print() const
{
	Servico::print();
	cout << "Tipo: " << this->get_tipo() << endl;
}