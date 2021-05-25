#include "Servico.h"

#include <iostream>

Servico::Servico(const int id, const string& data, const float custo)
	: id(id),
	data(data),
	custo(custo)
{
	set_custo(0.0);
}

bool Servico::operator<(const Servico& s) const
{
	return id < s.get_id();
}

int Servico::get_id() const
{
	return id;
}

void Servico::set_id(int id)
{
	this->id = id;
}

string Servico::get_data() const
{
	return data;
}

void Servico::set_data(const string& data)
{
	this->data = data;
}

float Servico::get_custo() const
{
	return custo;
}

void Servico::set_custo(float custo)
{
	this->custo = custo;
}

//void Servico::add_paciente(Paciente* paciente, Consulta* consulta)
//{
//	consulta->set_paciente(paciente);
//}

void Servico::print() const
{
	cout << "ID : " << this->get_id() << "Data : " << this->get_data() << "Custo: " << this->get_custo() << endl;
}

//Servico::operator Consulta()
//{
//	return Consulta(this->get_id(), this->get_data(), this->get_custo());
//}