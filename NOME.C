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
*
****************************************************************************/

#include "LISTA.H"
#include "NOME.H"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/********************* Variáveis encapuladas no módulo *********************/

/************** Protôtipos das funções encapuladas no módulo ***************/

/**************** Código das funções exportadas pelo módulo ****************/

/****************************************************************************
*
*	$FC Função:
*       NOM Armazenar vários nomes de um arquivo txt em uma lista.
*
****************************************************************************/
NOM_tpCondRet NOM_criarGrupo(NOM_tppCabecaNome *listaGrupo, char *nomeArquivoDeNomes, char *numTotalDeAlunos)
{

    FILE *pArquivoDeNomes;
    char stringNome[100], comprimentoStringNome, *mallocStringNome;

    if (LIS_criarLista(free, listaGrupo) != LIS_CondRetOK)
        return NOM_CondRetFaltouMemoria;

    pArquivoDeNomes = fopen(nomeArquivoDeNomes, "r");

    if (!pArquivoDeNomes)
        return NOM_CondRetFaltouMemoria;

    *numTotalDeAlunos = 0;

    while (fgets(stringNome, 100, pArquivoDeNomes))
    {

        comprimentoStringNome = (char) strlen(stringNome);

        mallocStringNome = (char *)malloc(comprimentoStringNome + 1);

        strcpy(mallocStringNome, stringNome);

        if (LIS_InserirNoApos(*listaGrupo, mallocStringNome) != LIS_CondRetOK)
            return NOM_CondRetFaltouMemoria;

        ++*numTotalDeAlunos;
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

    printf("\n");

    LIS_vaiParaPrimeiroNo(listaGrupo);

    do /* Enquanto não chegou ao final da lista */
    {
        LIS_obterConteudo(listaGrupo, (void **)&stringNome);
        printf("%s", stringNome);

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

    char *stringNome, *mallocStringNome, comprimentoStringNome;

    if (LIS_criarLista((void (*)(void *))NOM_destruirGrupo, listaDeGrupos) != LIS_CondRetOK)
        return NOM_CondRetFaltouMemoria;

    LIS_vaiParaPrimeiroNo(listaDeNomes);

    for (char i = 0; i < numDeGrupos; i++)
    {
        if (LIS_criarLista(free, &listaGrupo) != LIS_CondRetOK)
            return NOM_CondRetFaltouMemoria;

        for (int j = 0; j < numDeAlunosEmCadaGrupo; j++)
        {

            if (!numTotalDeAlunos)
                break;
                
            LIS_obterConteudo(listaDeNomes, (void **)&stringNome);

            comprimentoStringNome = (char) strlen(stringNome);

            mallocStringNome = (char *)malloc(comprimentoStringNome + 1);

            strcpy(mallocStringNome, stringNome);

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

        LIS_obterConteudo(listaDeNomes, (void **)&stringNome);

        comprimentoStringNome = (char) strlen(stringNome);

        mallocStringNome = (char *)malloc(comprimentoStringNome + 1);

        strcpy(mallocStringNome, stringNome);

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
NOM_tpCondRet NOM_imprimirGrupos(NOM_tppCabecaNome listaDeGrupos)
{

    NOM_tppCabecaNome listaGrupo;

    LIS_vaiParaPrimeiroNo(listaDeGrupos);

    do /* Enquanto não chegou ao final da lista */
    {
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

/**************** Código das funções encapsuladas no módulo ****************/
