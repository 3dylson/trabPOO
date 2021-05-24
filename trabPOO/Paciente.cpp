#include "Paciente.h"

Paciente::Paciente(const string& nome, int id)
	: nome(nome),
	id(id)
{
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
	Consulta c(id, data, custo, diagonostico);
	c.set_paciente(this);
	return consultas.insert(c);
}

Consulta* Paciente::find_consulta(int id)
{
	Consulta c;
	c.set_id(id);
	return consultas.find(c);
}