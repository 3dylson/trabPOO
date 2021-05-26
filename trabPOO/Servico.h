#pragma once

#include <string>

using namespace std;

class Servico
{
protected:
	int id;
	string data;
	float custo;

public:

	Servico(const int id, const string& data, const float custo);

	virtual bool operator<(const Servico& s) const;

	//Getters e Setters
	int get_id() const;

	void set_id(int id);

	string get_data() const;

	void set_data(const string& data);

	float get_custo() const;

	void set_custo(float custo);

	virtual void print() const;
};
