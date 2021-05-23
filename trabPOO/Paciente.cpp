#include "Paciente.h"
#include "Consulta.h"


Paciente::Paciente(string n, int id) : nome(n), id(id) {}

void Paciente::add_consulta(int id, string data, float custo, string diagnostico) {
	Consulta c(id, data, custo, diagnostico);
	c.atribuir_paciente(this);
	consultas.insert(c);
}
void print() {

}