void CriarProcesso();
void VerProcesso();
void TerminarProcesso();

De modo usuário para modo núcleo
O estado atual do processo deve ser salvo
O mapa de bits de memória também deve ser salvo
A MMU deve carregar o mapa de bits do novo
processo
O novo processo deve ser iniciado
Invalidação de toda a memória cache

struct Escalonador {
	int Processo;
	int registradores[32];
	int *pilha;
	int memoriaAlocada;
	char **arquivosAbertos;
	float contabilidade;

	int *prox;
};

struct TabelaProcessos {

	struct Escalonador escalonamento;
};
