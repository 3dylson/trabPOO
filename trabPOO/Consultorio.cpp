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
			cout << "Paciente: " << id_p << " Nome: " << p->get_nome() << " registado a consulta: " << id_c << " Custo: " << custo << endl;
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
	cout << "O paciente: " << id_p << " nao existe!" << endl;
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

bool Consultorio::remover_servico(int id) {
	Servico* s = find_servico(id);
	if (s != NULL) {
		cout << "Servico " << id << " removido.\n";
		servicos.erase(s);
		delete s;

		return true;
	}
	else {
		cout << "Servico " << id << " nao existe.\n";
		return false;
	}
}

void Consultorio::print_pacientes() const {
	Colecao<Paciente>::iterator it;
	for (it = pacientes.begin(); it != pacientes.end(); it++) {
		cout << "\t" << (*it).get_nome() << endl;
	}
}

void Consultorio::print_servicos() const {
	ColecaoHibrida<Servico*>::iterator it;
	for (it = servicos.begin(); it != servicos.end(); it++) {
		cout << "\t" << (*it)->get_id() << " - " << (*it)->get_data() << " - " << (*it)->get_custo() << endl;
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

	cout << "Todas consultas associadas ao Paciente: " << p->get_nome() << " ID - " << id_p << "Consultas: " << endl;
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