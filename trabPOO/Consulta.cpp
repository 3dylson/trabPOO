#include "Consulta.h"

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
	this->paciente = paciente;
}

bool Consulta::add_exame(int id, const string& data, float custo, Tipologia tipo)
{
	Exame* e0 = find_exame(id);
	if (e0 = NULL)
	{
		Exame e(id, data, custo, tipo);
		e.set_consulta(this);
		return exames.insert(e);
	}
}

Exame* Consulta::find_exame(int id)
{
	Exame e;
	e.set_id(id);
	return exames.find(e);
}