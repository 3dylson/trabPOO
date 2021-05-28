#include "Paciente.h"

#include <iostream>

Paciente::Paciente(const string& nome, int id)
	: nome(nome),
	id(id)
{
}

bool Paciente::operator<(const Paciente& p) const
{
	return id < p.id;
}

string Paciente::get_nome() const
{
	return nome;
}

void Paciente::set_nome(const string& nome)
{
	this->nome = nome;
}

int Paciente::get_id()
{
	return id;
}

void Paciente::set_id(int id)
{
	this->id = id;
}

void Paciente::print() const
{
	cout << "Paciente: " << this->get_nome() << " ID: " << this->id << endl;
	Colecao<Consulta>::iterator i;
	for (i = consultas.begin(); i != consultas.end(); i++)
		(i)->print();
}

Consulta* Paciente::find_consulta(int id)
{
	Consulta c(id, "", NULL, "");
	return consultas.find(c);
}

bool Paciente::add(const Consulta& c)
{
	return consultas.insert(c);
}

bool Paciente::remover_consulta(int id_c)
{
	Consulta* c = find_consulta(id_c);

	if (c)
	{
		if (c->num_exames() > 0)
		{
			cout << "Impossivel remover a consulta: " << id_c << " contem exames associadas!" << endl;
		}
		else
		{
			cout << "Consulta ID: " << id_c << " foi removida!\n";
			consultas.erase(*c);
			return true;
		}
	}
	else
	{
		cout << "Consulta de id " << id_c << " nao existe.\n";
	}
}

int Paciente::num_consulta() const
{
	return consultas.size();
}