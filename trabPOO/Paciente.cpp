#include "Paciente.h"

#include <iostream>

Paciente::Paciente(const string& nome, int id)
	: nome(nome),
	id(id)
{
}

bool Paciente::operator<(const Paciente& p) const
{
	return id < p.get_id();
}

string Paciente::get_nome() const
{
	return nome;
}

void Paciente::set_nome(const string& nome)
{
	this->nome = nome;
}

int Paciente::get_id() const
{
	return id;
}

void Paciente::set_id(int id)
{
	this->id = id;
}

bool Paciente::add_consulta(int id, const string& data, float custo, const string& diagonostico)
{
	Consulta* c0 = find_consulta(id);
	if (c0 != NULL)
	{
		cout << "A consulta: " << id << " ja existe" << endl;
	}
	Consulta c(id, data, custo, diagonostico);
	c.set_paciente(this);
	cout << "Consulta: " << id << "registada para o paciente: " << this->get_id() << endl;
	return consultas.insert(c);
}

Consulta* Paciente::find_consulta(int id)
{
	Consulta c;
	c.set_id(id);
	return consultas.find(c);
}