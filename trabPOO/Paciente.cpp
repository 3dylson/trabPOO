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

int Paciente::num_consulta() const
{
	return consultas.size();
}