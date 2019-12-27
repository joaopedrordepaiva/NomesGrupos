/****************************************************************************
*   $MCI Módulo de implementação: Módulo NOME
*
*   Arquivo gerado:              NOME.C
*   Letras identificadoras:      NOM
*
*   Projeto: Projeto Nome
*   Autores: jpp - João Pedro Paiva
*
*   $HA Histórico de evolução:
*       Versão  Autor   Data        Observações
*       1.00    jpp     11/12/2019  Início do desenvolvimento
*       2.00    jpp     14/12/2019  Término das funçoes de nome e grupo
*       3.00    jpp     15/12/2019  Término das funçoes de lista de grupos e
*                                   divisão
*       4.00    jpp     19/12/2019  Escolha randômica
*       5.00    jpp     26/12/2019  Redistribuição
*
****************************************************************************/

#include "LISTA.H"
#include "NOME.H"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/********************* Variáveis encapuladas no módulo *********************/

/************** Protótipos das funções encapuladas no módulo ***************/

char NOM_stringComprimento(char string[]);

NOM_tpCondRet NOM_stringCopia(char string1[], char string2[]);

NOM_tpCondRet NOM_vaiPara(NOM_tppCabecaNome lista, char pos);

/**************** Código das funções exportadas pelo módulo ****************/

/****************************************************************************
*
*	$FC Função:
*       NOM Armazenar vários nomes de um arquivo txt em uma lista.
*
****************************************************************************/
NOM_tpCondRet NOM_criarListaDeNomes(NOM_tppCabecaNome *listaGrupo, char *nomeArquivoDeNomes, char *numTotalDeAlunos)
{

    FILE *pArquivoDeNomes;
    char stringNome[64], comprimentoStringNome, *mallocStringNome;

    if (LIS_criarLista(free, listaGrupo) != LIS_CondRetOK)
        return NOM_CondRetFaltouMemoria;

    srand(time(NULL));

    pArquivoDeNomes = fopen(nomeArquivoDeNomes, "r");

    if (!pArquivoDeNomes)
        return NOM_CondRetFaltouMemoria;

    *numTotalDeAlunos = 0;

    while (fgets(stringNome, 64, pArquivoDeNomes))
    {

        ++*numTotalDeAlunos;

        comprimentoStringNome = NOM_stringComprimento(stringNome);

        mallocStringNome = (char *)malloc(comprimentoStringNome);

        NOM_stringCopia(mallocStringNome, stringNome);

        if (LIS_InserirNoApos(*listaGrupo, mallocStringNome) != LIS_CondRetOK)
            return NOM_CondRetFaltouMemoria;
    }

    fclose(pArquivoDeNomes);

    return NOM_CondRetOK;
}

/****************************************************************************
*
*	$FC Função:
*       NOM Imprimir uma lista de nomes.
*
****************************************************************************/
NOM_tpCondRet NOM_imprimirGrupo(NOM_tppCabecaNome listaGrupo)
{

    char *stringNome;

    LIS_vaiParaPrimeiroNo(listaGrupo);

    do /* Enquanto não chegou ao final da lista */
    {
        LIS_obterConteudo(listaGrupo, (void **)&stringNome);
        printf("%s\n", stringNome);

    } while (LIS_vaiParaProximoNo(listaGrupo) == LIS_CondRetOK);

    printf("\n");

    return NOM_CondRetOK; /* Retorna condição de teste bem sucedido */
}

/****************************************************************************
*
*	$FC Função:
*       NOM Destruir uma lista de nomes.
*
****************************************************************************/
NOM_tpCondRet NOM_destruirGrupo(NOM_tppCabecaNome listaGrupo)
{
    LIS_DestruirLista(listaGrupo);

    return NOM_CondRetOK;
}

/****************************************************************************
*
*	$FC Função:
*       NOM Distribuir nomes em grupos randômicamente.
*
****************************************************************************/
NOM_tpCondRet NOM_criarListaDeGrupos(NOM_tppCabecaNome *listaDeGrupos, NOM_tppCabecaNome listaDeNomes, const char numDeGrupos, const char numDeAlunosEmCadaGrupo, char numTotalDeAlunos)
{
    NOM_tppCabecaNome listaGrupo;

    char *stringNome, *mallocStringNome, comprimentoStringNome, posNovaListaDeNomes;

    if (LIS_criarLista((void (*)(void *))NOM_destruirGrupo, listaDeGrupos) != LIS_CondRetOK)
        return NOM_CondRetFaltouMemoria;

    for (char i = 0; i < numDeGrupos; i++)
    {
        if (LIS_criarLista(free, &listaGrupo) != LIS_CondRetOK)
            return NOM_CondRetFaltouMemoria;

        for (int j = 0; j < numDeAlunosEmCadaGrupo; j++)
        {

            if (!numTotalDeAlunos)
                break;

            posNovaListaDeNomes = (char)(rand() % (int)numTotalDeAlunos);

            NOM_vaiPara(listaDeNomes, posNovaListaDeNomes);

            LIS_obterConteudo(listaDeNomes, (void **)&stringNome);

            comprimentoStringNome = NOM_stringComprimento(stringNome);

            mallocStringNome = (char *)malloc(comprimentoStringNome);

            NOM_stringCopia(mallocStringNome, stringNome);

            if (LIS_InserirNoApos(listaGrupo, mallocStringNome) != LIS_CondRetOK)
                return NOM_CondRetFaltouMemoria;

            LIS_ExcluirNo(listaDeNomes);

            --numTotalDeAlunos;
        }

        if (LIS_InserirNoApos(*listaDeGrupos, listaGrupo) != LIS_CondRetOK)
            return NOM_CondRetFaltouMemoria;
    }

    LIS_vaiParaPrimeiroNo(*listaDeGrupos);

    while (numTotalDeAlunos)
    {

        posNovaListaDeNomes = (char)(rand() % (int)numTotalDeAlunos);

        NOM_vaiPara(listaDeNomes, posNovaListaDeNomes);

        LIS_obterConteudo(listaDeNomes, (void **)&stringNome);

        comprimentoStringNome = NOM_stringComprimento(stringNome);

        mallocStringNome = (char *)malloc(comprimentoStringNome);

        NOM_stringCopia(mallocStringNome, stringNome);

        LIS_obterConteudo(*listaDeGrupos, (void **)&listaGrupo);

        if (LIS_InserirNoApos(listaGrupo, mallocStringNome) != LIS_CondRetOK)
            return NOM_CondRetFaltouMemoria;

        LIS_ExcluirNo(listaDeNomes);

        --numTotalDeAlunos;

        LIS_vaiParaProximoNo(*listaDeGrupos);
    }

    return NOM_CondRetOK; /* Retorna condição de teste bem sucedido */
}

/****************************************************************************
*
*	$FC Função:
*       NOM Imprimir uma lista de grupos.
*
****************************************************************************/
NOM_tpCondRet NOM_imprimirListaDeGrupos(NOM_tppCabecaNome listaDeGrupos)
{

    NOM_tppCabecaNome listaGrupo;
    char vContadorDeGrupos;

    LIS_vaiParaPrimeiroNo(listaDeGrupos);

    vContadorDeGrupos = 1;

    do /* Enquanto não chegou ao final da lista */
    {
        printf("Grupo %d:\n",vContadorDeGrupos++);
        LIS_obterConteudo(listaDeGrupos, (void **)&listaGrupo);
        NOM_imprimirGrupo(listaGrupo);

    } while (LIS_vaiParaProximoNo(listaDeGrupos) == LIS_CondRetOK);

    return NOM_CondRetOK; /* Retorna condição de teste bem sucedido */
}

/****************************************************************************
*
*	$FC Função:
*       NOM Destruir uma lista de grupos.
*
****************************************************************************/
NOM_tpCondRet NOM_destruirListaDeGrupos(NOM_tppCabecaNome listaDeGrupos)
{
    LIS_DestruirLista(listaDeGrupos);

    return NOM_CondRetOK;
}

/****************************************************************************
*
*	$FC Função:
*       NOM Redistribuir nomes.
*
****************************************************************************/
NOM_tpCondRet NOM_redistribuirListaDeGrupos(NOM_tppCabecaNome *listaDeGrupos, const char numDeGrupos, const char numDeAlunosEmCadaGrupo, char numTotalDeAlunos)
{
    NOM_tppCabecaNome listaDeNomes;
    NOM_tppCabecaNome listaGrupoAtual;
    char *stringNome, comprimentoStringNome, *mallocStringNome;

    if (LIS_criarLista(free, &listaDeNomes) != LIS_CondRetOK)
        return NOM_CondRetFaltouMemoria;

    LIS_vaiParaPrimeiroNo(*listaDeGrupos);

    do
    {
        LIS_obterConteudo(*listaDeGrupos, (void **)&listaGrupoAtual);
        LIS_vaiParaPrimeiroNo(listaGrupoAtual);
        do
        {
            LIS_obterConteudo(listaGrupoAtual, (void **)&stringNome);
            comprimentoStringNome = NOM_stringComprimento(stringNome);
            mallocStringNome = (char *)malloc(comprimentoStringNome);
            NOM_stringCopia(mallocStringNome, stringNome);
            LIS_InserirNoApos(listaDeNomes, mallocStringNome);
        } while (LIS_vaiParaProximoNo(listaGrupoAtual) == LIS_CondRetOK);

    } while (LIS_vaiParaProximoNo(*listaDeGrupos) == LIS_CondRetOK);

    LIS_DestruirLista(*listaDeGrupos);

    NOM_criarListaDeGrupos(listaDeGrupos, listaDeNomes, numDeGrupos, numDeAlunosEmCadaGrupo, numTotalDeAlunos);

    NOM_destruirGrupo(listaDeNomes);

    return NOM_CondRetOK;
}

/****************************************************************************
*
*	$FC Função:
*       NOM Salvar uma lista de grupos em um marquivo txt.
*
****************************************************************************/
NOM_tpCondRet NOM_salvarListaDeGrupos(NOM_tppCabecaNome listaDeGrupos, char *nomeOutputDeGrupos)
{

    NOM_tppCabecaNome listaGrupo;
    FILE *pArquivoOutputDeGrupos;
    char *stringNome, vContadorDeGrupos;

    pArquivoOutputDeGrupos = fopen(nomeOutputDeGrupos, "w");

    if (!pArquivoOutputDeGrupos)
        return NOM_CondRetFaltouMemoria;

    LIS_vaiParaPrimeiroNo(listaDeGrupos);

    vContadorDeGrupos = 1;

    do /* Enquanto não chegou ao final da lista */
    {

        fprintf(pArquivoOutputDeGrupos, "Grupo %d:\n", vContadorDeGrupos++);

        LIS_obterConteudo(listaDeGrupos, (void **)&listaGrupo);

        LIS_vaiParaPrimeiroNo(listaGrupo);

        do /* Enquanto não chegou ao final da lista */
        {
            LIS_obterConteudo(listaGrupo, (void **)&stringNome);
            fprintf(pArquivoOutputDeGrupos, "%s\n", stringNome);

        } while (LIS_vaiParaProximoNo(listaGrupo) == LIS_CondRetOK);

        fprintf(pArquivoOutputDeGrupos, "\n");

    } while (LIS_vaiParaProximoNo(listaDeGrupos) == LIS_CondRetOK);

    fclose(pArquivoOutputDeGrupos);

    return NOM_CondRetOK; /* Retorna condição de teste bem sucedido */
}

/****************************************************************************
*
*	$FC Função:
*       NOM Copia string2 para string1.
*
****************************************************************************/
NOM_tpCondRet NOM_stringCopia(char string1[], char string2[])
{

    int cont;

    cont = 0;

    do
        if (string2[cont] != '\n')
            string1[cont] = string2[cont];

    while (string2[cont++]);

    return NOM_CondRetOK;
}

/**************** Código das funções encapsuladas no módulo ****************/

/****************************************************************************
*
*	$FC Função:
*       NOM Determina o comprimento de uma string.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais do vetor de caracteres.
*
*
*  $EP Parâmetros
*       $P string - O parâmetro que receberá o endereço do primeiro caractere
*           da string cujo tamanho deseja-se determinar.
*           Este parâmetro é passado por valor.
*
****************************************************************************/
char NOM_stringComprimento(char string[])
{

    char soma;
    int cont;

    soma = (char)0;
    cont = 0;

    do
        if (string[cont] != '\n')
            soma++;
    while (string[cont++]);

    return soma;
}
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       O comprimento da string foi determinado, incluindo o '\0'.
*		Valem as assertivas estruturais do vetor de caracteres.
*
*
*   $FV Valor retornado
*       soma - O comprimento da string passado como parâmetro.
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Anda um certo número de passos para frente ou para trás numa
*       lista.
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista duplamente encadeada.
*
*
*  $EP Parâmetros
*       $P lista - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista duplamente encadeada.
*           Este parâmetro é passado por referência.
*       $P pos - O parâmetro que receberá a posição desejada da lista.
*           Este parâmetro é passado por valor.
*
****************************************************************************/
NOM_tpCondRet NOM_vaiPara(NOM_tppCabecaNome lista, char pos)
{

    LIS_vaiParaPrimeiroNo(lista);

    while (pos)
    {
        LIS_vaiParaProximoNo(lista);
        pos--;
    }

    return NOM_CondRetOK;
}
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       Lista está na posição desejada.
*		Valem as assertivas estruturais da lista duplamente encadeada com
*       cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/
