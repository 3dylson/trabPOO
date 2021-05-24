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

Servico* Consultorio::find_servico(int id)
{
	Servico s(id, "", 0.0);
	return servicos.find(s);
}

bool Consultorio::atribuir_consulta(int id_c, string data, float custo, const string& d, int id_p)
{
	Paciente* p = find_paciente(id_p);
	if (p != NULL)
	{
		Servico* s = find_servico(id_c);
		if (s = NULL)
		{
			Servico s2(id_c, data, custo);
			//Consulta c(s->get_id(), s->get_data(), s->get_custo(), d);
			p->add_consulta(s2.get_id(), s2.get_data(), s2.get_custo(), d);
			return servicos.insert(s2);
		}
	}
}

bool Consultorio::atribuir_exame(int id_p, int id_e, string data, float custo, Tipologia t, int id_c)
{
	Paciente* p = find_paciente(id_p);
	if (p != NULL)
	{
		Consulta* c = p->find_consulta(id_c);
		if (c != NULL)
		{
			c->add_exame(id_e, data, custo, t);
		}
	}
}

float Consultorio::valor_faturacao()
{
}

void Consultorio::print_consultas_paciente(int id_p)
{
}