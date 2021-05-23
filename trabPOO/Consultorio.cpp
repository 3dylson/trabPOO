#include "Consultorio.h"


Consultorio::Consultorio(string n) : nome(n) {}

bool Consultorio::add_paciente(string n, int id) {
	Paciente p(n, id);
	return pacientes.insert(p);
}
bool Consultorio::add_consulta(int id, string data, float custo, string diagnostico) {
	Consulta c(id, data, custo, diagnostico);
	return servicos.insert(c); // ??
}

bool Consultorio::atribuir_consulta(int id_c, int id_p) {
	Consulta c(id_c);
	servicos.find(Consulta* c);

}
bool atribuir_exame(int id_e, string data, float custo, int id_c, Tipologia tp) {
	Exame ex(id_e, data, custo, tp);
	ex
}// mudar p bool no diagrama
float valor_faturacao(); //double ou float??
void print_consultas_paciente(int id_p);