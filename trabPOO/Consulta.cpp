#include "Consulta.h"

Consulta::Consulta(int id, const string& data, float custo, const string& diagonostico)
	: Servico(id, data, custo),
	diagonostico(diagonostico)
{}

void Consulta::add_exame(int id, string data, float custo, Tipologia tipo){
	Exame ex(id, data, custo, tipo);
	ex.atribuir_consulta(this);
	exames.insert(ex);
}

void Consulta::atribuir_paciente(Paciente* p) {
	paciente = p;
}