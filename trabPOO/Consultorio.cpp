#include "Consultorio.h"

#include "Consulta.h"

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
	cout << "Paciente: " << p0->get_id() << " ja existe!" << endl;
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
			Consulta consulta(id_c, data, custo, d, p);
			float update_custo = consulta.get_custo() + custo;
			consulta.set_custo(update_custo);
			p->add(consulta);
			Consulta* fc = p->find_consulta(id_c);
			cout << "Paciente: " << id_p << " Nome: " << p->get_nome() << ", registado a consulta: " << id_c << ", Custo: " << custo << endl;
			float total = this->get_valor_total_faturado() + custo;
			this->set_valor_total_faturado(total);
			return servicos.insert(fc);
		}
		else {
			cout << "A consulta: " << id_c << " ja esta atribuida ao paciente: " << p->get_nome() << " ID: " << p->get_id() << endl;
		}
	}
	else {
		cout << "O paciente: " << id_p << " nao existe!" << endl;
	}
}

bool Consultorio::atribuir_exame(int id_p, int id_e, string data, float custo, Tipologia t, int id_c)
{
	Paciente* p = find_paciente(id_p);
	if (p)
	{
		Consulta* c = p->find_consulta(id_c);
		if (c)
		{
			Exame exame(id_e, data, custo, t);
			float update_custo = exame.get_custo() + custo;
			exame.set_custo(update_custo);
			exame.set_consulta(c);
			c->add(exame);
			Exame* fe = c->find_exame(id_e);
			float total = this->get_valor_total_faturado() + custo;
			this->set_valor_total_faturado(total);
			return servicos.insert(fe);
		}

		cout << "A consulta: " << id_c << " nao existe!" << endl;
	}
	else {
		cout << "O paciente: " << id_p << " nao existe!" << endl;
	}
}

bool Consultorio::remover_paciente(int id) {
	Paciente* p = find_paciente(id);
	if (p != NULL) {
		if (p->num_consulta() > 0)
		{
			cout << "Impossivel remover o paciente: " << id << " contem consultas associadas!" << endl;
		}
		else {
			cout << "Paciente " << p->get_nome() << " foi removido!\n";
			pacientes.erase(*p);
			return true;
		}
	}
	else {
		cout << "Paciente de id " << id << " nao existe.\n";
	}
}

bool Consultorio::remover_consulta(int id_c, int id_p)
{
	Paciente* p = find_paciente(id_p);
	if (p)
	{
		Consulta* c = p->find_consulta(id_c);
		if (c)
		{
			if (c->num_exames() > 0)
			{
				cout << "Impossivel remover a consulta: " << id_c << " contem exames associados!" << endl;
			}
			else
			{
				cout << "Consulta Id: " << id_c << ", do paciente: " << p->get_nome() << " foi removida!\n";
				servicos.erase(c);
				p->remover_consulta(id_c);
				return true;
			}
		}
		else {
			cout << "Consulta de id " << id_c << " nao existe.\n";
		}
	}
	else {
		cout << "Paciente de id " << id_p << " nao existe.\n";
	}
}

bool Consultorio::remover_exame(int id_e, int id_c, int id_p)
{
	Paciente* p = find_paciente(id_p);
	if (p)
	{
		Consulta* c = p->find_consulta(id_c);
		if (c)
		{
			Exame* e = c->find_exame(id_e);
			if (e)
			{
				cout << "Exame Id: " << id_e << ", do paciente: " << p->get_nome() << " da consulta: " << id_c << ", foi removida!\n";
				servicos.erase(e);
				c->remover_exame(id_e);
				return true;
			}
			else {
				cout << "Exame de id " << id_e << " nao existe.\n";
			}
		}
		else {
			cout << "Consulta de id " << id_c << " nao existe.\n";
		}
	}
	else {
		cout << "Paciente de id " << id_p << " nao existe.\n";
	}
}

void Consultorio::print_pacientes() const {
	Colecao<Paciente>::iterator it;
	for (it = pacientes.begin(); it != pacientes.end(); it++) {
		cout << "\t" << "Nome: " << (*it).get_nome() << ", Num consultas: " << (*it).num_consulta() << endl;
	}
}

void Consultorio::print_servicos() const {
	ColecaoHibrida<Servico*>::iterator it;
	for (it = servicos.begin(); it != servicos.end(); it++) {
		cout << "\t" << "ID- " << (*it)->get_id() << ", Data- " << (*it)->get_data() << ", Custo- " << (*it)->get_custo() << endl;
	}
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

	cout << "Todas consultas associadas - ";
	p->print();
}

int Consultorio::num_paciente() const
{
	return pacientes.size();
}

int Consultorio::num_servico() const
{
	return servicos.size();
}