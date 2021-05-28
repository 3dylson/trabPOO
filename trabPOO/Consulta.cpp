#include "Consulta.h"

#include <iostream>

#include "Paciente.h"

Consulta::Consulta(int id, const string& data, float custo, const string& diagonostico, Paciente* paciente)
	: Servico(id, data, custo),
	diagonostico(diagonostico)
{
	this->paciente = paciente;
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

bool Consulta::set_paciente(Paciente* paciente)
{
	if (paciente == NULL)
	{
		this->paciente = paciente;
		cout << this->paciente->get_nome() << " registado a consulta: " << this->get_id() << endl;
		return true;
	}

	Paciente* p = this->get_paciente();
	cout << "Consulta: " << this->get_id() << " ja se encontra atribuida ao paciente: " << p->get_nome() << "- " << p->get_id() << endl;
}

bool Consulta::add(const Exame& exame)
{
	float update_custo = exame.get_custo() + this->get_custo();
	this->set_custo(update_custo);
	return exames.insert(exame);
}

int Consulta::num_exames() const
{
	return exames.size();
}

Exame* Consulta::find_exame(int& id)
{
	Exame e(id, "", NULL, Check_up);
	return exames.find(e);
}

bool Consulta::operator<(const Consulta& c) const
{
	return id < c.id;
}

void Consulta::print() const
{
	cout << "Consulta -" << endl;
	Servico::print();
	cout << "Diagonostico: " << this->get_diagonostico() << " Custo: " << get_custo() << endl;
	cout << "Estao associados " << this->num_exames() << " exames a consulta: " << this->get_id() << endl;
	Colecao<Exame>::iterator i;
	for (i = exames.begin(); i != exames.end(); i++)
		(i)->print();
}