#include "Consultorio.h"

#include <iostream>

Consultorio::Consultorio(string n) : nome(n)
{
	set_valor_total_faturado(0.0);
}

string Consultorio::get_nome() const
{
	return nome;
}

bool Consultorio::add_paciente(string n, int id)
{
	Paciente* p0 = find_paciente(id);
	if (p0 == NULL)
	{
		Paciente p(n, id);
		cout << "Paciente " << p.get_nome() << " adicionado." << endl;
		return pacientes.insert(p);
	}
	cout << "Paciente: " << p0->get_id() << " já existe!" << endl;
}

Paciente* Consultorio::find_paciente(int id)
{
	Paciente p("", id);
	return pacientes.find(p);
}

Servico* Consultorio::find_servico(const int& id)
{
	Servico s(id, "", 0.0);
	return servicos.find(&s);
}

bool Consultorio::atribuir_consulta(int id_c, string data, float custo, string d, int id_p)
{
	Paciente* p = find_paciente(id_p);
	if (p)
	{
		Consulta* c = p->find_consulta(id_c);
		if (!c)
		{
			p->add_consulta(id_c, data, custo, d, p);
			Consulta* fc = p->find_consulta(id_c);
			cout << "Paciente: " << id_p << " registado a consulta: " << id_c << endl;
			float total = this->get_valor_total_faturado() + custo;
			this->set_valor_total_faturado(total);
			return servicos.insert(fc);
		}

		cout << "A consulta: " << id_c << " ja esta atribuida!" << endl;
	}

	cout << "O paciente: " << id_p << " nao existe!" << endl;
}

bool Consultorio::atribuir_exame(int id_p, int id_e, string data, float custo, Tipologia t, int id_c)
{
	Paciente* p = find_paciente(id_p);
	if (p != NULL)
	{
		Servico* c = find_servico(id_c);
		if (c)
		{
			/*Exame exame(id_e, data, custo, t);
			p->find_consulta(id_c).*/

			Consulta* fc = p->find_consulta(id_c);
			fc->add_exame(id_e, data, custo, t);
			Exame* fe = fc->find_exame(id_e);
			float total = this->get_valor_total_faturado() + custo;
			this->set_valor_total_faturado(total);
			return servicos.insert(fe);
		}

		cout << "A consulta: " << id_c << " nao existe!" << endl;
	}
	cout << "O paciente: " << id_p << " nao existe!" << endl;
}

float Consultorio::get_valor_total_faturado() const
{
	return valor_total_faturado;
}

void Consultorio::set_valor_total_faturado(float valor_total_faturado)
{
	this->valor_total_faturado = valor_total_faturado;
}

void Consultorio::print_valor_total() const
{
	cout << "Valor total faturado pelo consultorio: " << this->get_nome() << " = " << this->get_valor_total_faturado() << endl;
}

void Consultorio::print_consultas_paciente(int id_p)
{
	Paciente* p = find_paciente(id_p);
	if (p == NULL)
	{
		cout << "Paciente: " << id_p << "nao existe!" << endl;
	}

	cout << "Todas consultas associadas ao Paciente: " << p->get_nome() << " ID - " << id_p << endl;
	p->print();
}