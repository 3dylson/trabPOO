#include "Consulta.h"

Consulta::Consulta(int id, const string& data, float custo, const string& diagonostico)
	: Servico(id, data, custo),
	diagonostico(diagonostico)
{}
