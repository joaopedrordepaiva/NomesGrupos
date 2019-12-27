#include "NOME.H"
#include <stdio.h>

#define SYS_IS_LINUX

#ifdef SYS_IS_LINUX
#include <termios.h>

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old);         /* grab old terminal i/o settings */
    current = old;              /* make new settings same as old settings */
    current.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo)
    {
        current.c_lflag |= ECHO; /* set echo mode */
    }
    else
    {
        current.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch(void)
{
    char ch;
    initTermios(0);
    ch = getchar();
    resetTermios();
    return ch;
}
#endif

#ifdef SYS_IS_WIN
#include <conios.h>
#endif

int main(int argc, char **argv)
{

    NOM_tppCabecaNome listaDeNomes, listaDeGrupos;

    char nomeArquivoDeNomes[64], nomeOutputDeGrupos[64], resposta, numTotalDeAlunos, numDeGrupos, numDeAlunosEmCadaGrupo, numRestanteDeAlunos;

    if (argc > 1)
        NOM_stringCopia(nomeArquivoDeNomes, argv[1]);

    else
        NOM_stringCopia(nomeArquivoDeNomes, "nomes.txt");

    if (argc > 2)
        NOM_stringCopia(nomeOutputDeGrupos, argv[2]);

    else
        NOM_stringCopia(nomeOutputDeGrupos, "outputGrupos.txt");

    printf("%s -> %s\n", nomeArquivoDeNomes, nomeOutputDeGrupos);

    NOM_criarListaDeNomes(&listaDeNomes, nomeArquivoDeNomes, &numTotalDeAlunos);

    printf("%d\n",numTotalDeAlunos);

    printf("Os nomes encontrados foram:\n");

    NOM_imprimirGrupo(listaDeNomes);

    printf("Digite 0 (zero) para escolher o número de grupos ou digite 1 (um) para escolher o número de alunos em cada grupo.");

    do
        resposta = getch();
    while (resposta != '0' && resposta != '1');

    if (resposta == '0')
    {
        printf("\n\nDigite o número de grupos.\n\n");
        do
            numDeGrupos = getch();
        while (numDeGrupos < '1' && numDeGrupos > numTotalDeAlunos);

        numDeGrupos -= '0';

        numDeAlunosEmCadaGrupo = (char)numTotalDeAlunos / numDeGrupos;

        numRestanteDeAlunos = (char)numTotalDeAlunos % numDeGrupos;
    }

    else
    {
        printf("\n\nDigite 0 número de alunos em cada grupo.\n\n");

        do
            numDeAlunosEmCadaGrupo = getch();
        while (numDeAlunosEmCadaGrupo < '1' && numDeAlunosEmCadaGrupo > numTotalDeAlunos);

        numDeAlunosEmCadaGrupo -= '0';

        numDeGrupos = (char)numTotalDeAlunos / numDeAlunosEmCadaGrupo;

        numRestanteDeAlunos = (char)numTotalDeAlunos % numDeAlunosEmCadaGrupo;
    }

    if (!numRestanteDeAlunos)
        printf("Serão formados %d grupos de %d alunos:\n\n", numDeGrupos, numDeAlunosEmCadaGrupo);

    else
    {
        printf("Digite 0 (zero) para formar %d grupos de %d alunos e %d grupos de %d alunos, ou digite 1 (um) para formar %d grupos de %d alunos e %d grupos de %d alunos\n\n", numDeGrupos - numRestanteDeAlunos, numDeAlunosEmCadaGrupo, numRestanteDeAlunos, numDeAlunosEmCadaGrupo + 1, numDeGrupos, numDeAlunosEmCadaGrupo, 1, numRestanteDeAlunos);

        do
            resposta = getch();
        while (resposta != '0' && resposta != '1');

        if (resposta == '1')
            numDeGrupos++;
    }

    NOM_criarListaDeGrupos(&listaDeGrupos, listaDeNomes, numDeGrupos, numDeAlunosEmCadaGrupo, numTotalDeAlunos);

    NOM_destruirGrupo(listaDeNomes);

    do
    {

        NOM_imprimirListaDeGrupos(listaDeGrupos);

        printf("Digite 0 (zero) para salvar os grupos formados em um arquivo txt, ou digite 1 (um) para redistribuir os grupos de alunos\n\n");

        do
            resposta = getch();
        while (resposta != '0' && resposta != '1');

        if (resposta == '1')
            NOM_redistribuirListaDeGrupos(&listaDeGrupos, numDeGrupos, numDeAlunosEmCadaGrupo, numTotalDeAlunos);

    } while (resposta == '1');

    NOM_salvarListaDeGrupos(listaDeGrupos, nomeOutputDeGrupos);

    NOM_destruirListaDeGrupos(listaDeGrupos);

    return 0;
}