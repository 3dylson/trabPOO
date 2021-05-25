#include "Consulta.h"

#include <iostream>

#include "Paciente.h"

Consulta::Consulta() : Servico(NULL, NULL, NULL)
{
	paciente = NULL;
}

Consulta::Consulta(int id, const string& data, float custo, const string& diagonostico)
	: Servico(id, data, custo),
	diagonostico(diagonostico)
{
	paciente = NULL;
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
	cout << "Consulta: " << this->get_id() << "ja se encontra atribuida ao paciente: " << p->get_nome() << "-" << p->get_id() << endl;
}

bool Consulta::add_exame(int id, const string& data, float custo, Tipologia tipo)
{
	Exame* e0 = find_exame(id);
	if (e0 == NULL)
	{
		Exame e(id, data, custo, tipo);
		e.set_consulta(this);
		cout << "Exame: " << id << " adicionado a consulta: " << this->get_id() << endl;
		return exames.insert(e);
	}
	cout << "O exame: " << id << " já existe na consulta: " << this->get_id() << endl;
}

Exame* Consulta::find_exame(int id)
{
	Exame e;
	e.set_id(id);
	return exames.find(e);
}