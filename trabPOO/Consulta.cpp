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

Consulta::Consulta(int id, const string& data, float custo, const string& diagnostico)
	: Servico(id, data, custo),
	diagonostico(diagnostico)
{
	paciente = NULL;
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

bool Consulta::add_exame(int id, string data, float custo, Tipologia tipo)
{
	Exame ex(id, data, custo, tipo);
	ex.set_consulta(this);
	return exames.insert(ex);
}

int Consulta::num_exames() const
{
	return exames.size();
}

Exame* Consulta::find_exame(int& id)
{
	Exame e;
	e.set_id(id);
	return exames.find(e);
}

bool Consulta::operator<(const Consulta& c) const
{
	return id < c.id;
}

void Consulta::print() const
{
	Servico::print();
	cout << "Diagonostico: " << this->get_diagonostico() << endl;
	cout << "Estao associados " << this->num_exames() << "exames a consulta: " << this->get_id() << endl;
}