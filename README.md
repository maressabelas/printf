*Esse projeto foi desenvolvido como parte do currículo da 42 por <marbelas>*

DESCRIÇÃO: 
Esse projeto e uma reproducao da funcao original printf, que e responsavel por output de diferentes formas. e uma otima oportunidade de aprender sobre funcoes variadicas

INSTRUÇÕES:
--> Para executar o makefille: 
make all: para compilar e gerar as arquivos .o
make fclen: para limpar a compilação e os arquivos .o

--> Para testar a funcionalidade do projeto, é possivel criar uma main, mais ou menos assim: 
#include "printf.h"

int	main()
{
	ft_printf("%s", "word!");
	ft_printf("%d", 42);
	ft_printf("x", 255);
	return (0);
}

... e/ou usar um tester, eu indico o printfTester da Tripouille
 link p instalacão: https://github.com/grouville/valgrind_42
no readme do tester, voce encontra os comandos para executar o tester corretamente 

RECURSOS:
O manual foi a base principal para o desenvolvimento desse projeto, especialmente o 'va_arg'. a metodologia pear to pear, sites e blogs foram pecas importantes. IA foi usada para correcoes e testes.  
