(E) Em Execução (realmente usando a CPU naquele instante)

(P) Pronto (executável; temporariamente parado para dar lugar a outro processo)

(B) Bloqueado (incapaz de executar enquanto um evento externo não ocorrer)

Transições
1. (E->B) O Processo bloqueia aguardando uma entrada
	Quando processo não puder prosseguir
 
2. (E->P) O escalonador seleciona outro processo
	Causada pelo escalonador sem informar o processo

3. (P->E) O escalonador seleciona esse processo
	Causada pelo escalonador sem informar o processo

4. (B->P) A entrada torna-se disponível
	Quando acontece um evento externo pelo qual o processo estava aguardando
