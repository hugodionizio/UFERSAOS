Saída normal (voluntária)
Chamadas ao sistema
• Unix e MINIX: exit
• Windows: ExitProcess

Saída por erro (voluntária)
Instrução ilegal, referência à memória inexistente ou divisão por zero
No MINIX um processo pode dizer ao SO que deseja tratar certos erros sozinho

Erro fatal (involuntário)
Ex: tentar compilar um arquivo que não existe

Cancelamento por um outro processo (involuntário)
No Unix e MINIX: kill
No Windows: TerminateProcess
