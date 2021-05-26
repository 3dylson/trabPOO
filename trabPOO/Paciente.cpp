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

bool Paciente::add_consulta(Consulta& consulta)
{
	return consultas.insert(&consulta);
}

Consulta** Paciente::find_consulta(int& id)
{
	Consulta c(id, "", NULL);
	return consultas.find(&c);
}

Colecao<Consulta*> Paciente::get_consultas() const
{
	return consultas;
}