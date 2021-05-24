#include "Consultorio.h"

Consultorio::Consultorio(string n) : nome(n)
{}

bool Consultorio::add_paciente(string n, int id)
{
	Paciente p(n, id);
	return pacientes.insert(p);
}

Paciente* Consultorio::find_paciente(int id)
{
	Paciente p("", id);
	return pacientes.find(p);
}

bool Consultorio::add_consulta(int id, string data, float custo)
{
	Servico s(id, data, custo);
	//s = new Consulta(s.get_id(), s.get_data(), s.get_custo(), d);
	//Consulta c(id, data, custo, d);
	return servicos.insert(s);
}

Servico* Consultorio::find_servico(int id)
{
	Servico s(id, "", 0.0);
	return servicos.find(s);
}

bool Consultorio::atribuir_consulta(int id_c, int id_p, const string& d)
{
	Paciente* p = find_paciente(id_p);
	if (p != NULL)
	{
		Servico* s = find_servico(id_c);
		if (s != NULL)
		{
			//Consulta c(s->get_id(), s->get_data(), s->get_custo(), d);
			p->add_consulta(s->get_id(), s->get_data(), s->get_custo(), d);
		}
	}
}

bool Consultorio::atribuir_exame(int id_e, string data, float custo, int id_c)
{
}

float Consultorio::valor_faturacao()
{
}

void Consultorio::print_consultas_paciente(int id_p)
{
}