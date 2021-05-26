#include "Consulta.h"

#include <iostream>

#include "Paciente.h"

Consulta::Consulta() : Servico(NULL, NULL, NULL)
{
	paciente = NULL;
}

Consulta::Consulta(int id, const string& data, float custo, const string& diagonostico, Paciente* paciente)
	: Servico(id, data, custo),
	diagonostico(diagonostico)
{
	this->paciente = paciente;
}

Consulta::Consulta(int id, const string& data, float custo) : Servico(id, data, custo)
{
	paciente = NULL;
	diagonostico = "";
}

string Consulta::get_diagonostico() const
{
	return diagonostico;
}

void Consulta::set_diagonostico(const string& diagonostico)
{
	this->diagonostico = diagonostico;
}

Paciente* Consulta::get_paciente() const
{
	return paciente;
}

void Consulta::set_paciente(Paciente* paciente)
{
	if (paciente == NULL)
	{
		this->paciente = paciente;
		cout << this->paciente->get_nome() << " registado a consulta: " << this->get_id() << endl;
	}

	Paciente* p = this->get_paciente();
	cout << "Consulta: " << this->get_id() << " ja se encontra atribuida ao paciente: " << p->get_nome() << "- " << p->get_id() << endl;
}

bool Consulta::add_exame(Exame& exame)
{
	return exames.insert(&exame);
}

void Consulta::print() const
{
	Servico::print();
	cout << "Diagonostico: " << this->get_diagonostico() << endl;
	Colecao<Exame*>::iterator i;
	for (i = exames.begin(); i != exames.end(); i++) (**i).print();
}