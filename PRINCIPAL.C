#include "NOME.H"
#include <stdio.h>

int main(int argc, char *argv[])
{

    NOM_tppCabecaNome listaGrupo;

    char *nomeArquivoDeNomes, resposta, numTotalDeAlunos, numDeGrupos, numDeAlunosEmCadaGrupo;

    if (argc > 1)
        nomeArquivoDeNomes = argv[1];

    else
        nomeArquivoDeNomes = "nomes.txt";

    NOM_criarGrupo(&listaGrupo, nomeArquivoDeNomes, &numTotalDeAlunos);

    // NOM_imprimirGrupo(listaGrupo);

    printf("Digite 0 (zero) para escolher o número de grupos ou digite 1 (um) para escolher o número de alunos em cada grupo: ");

    do
        resposta = getch();
    while (resposta != '0' || resposta != '1');

    if (resposta == '0')
    {
        printf("Digite o número de grupos: ");

        do
            numDeGrupos = getch();
        while (numDeGrupos < '1' || numDeGrupos > numTotalDeAlunos);

        numDeAlunosEmCadaGrupo = numTotalDeAlunos/numDeGrupos;
    }

    else
    {
        printf("Digite 0 número de alunos em cada grupo: ");

        do
            numDeAlunosEmCadaGrupo = getch();
        while (numDeAlunosEmCadaGrupo < '1' || numDeAlunosEmCadaGrupo > numTotalDeAlunos);

        numDeGrupos = numTotalDeAlunos/numDeAlunosEmCadaGrupo;
    }

    NOM_destruirGrupo(listaGrupo);

    return 0;
}