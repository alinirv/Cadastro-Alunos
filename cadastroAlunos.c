#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAMNOME 50
#define TAMSOBRENOME 50

typedef struct data 
{
 int dia;
 int mes;
 int ano;
} data;

typedef struct registro 
{
 char nome [TAMNOME];
 char sobrenome [TAMSOBRENOME];
 data datadenascimento;
 int prontuario;
 char curso [4];
} aluno;

void imprimiAluno(aluno *aluno);

void pesquisaNomeAluno(aluno *alunos, int * id)
{
    char nome [TAMNOME];
    int i = 0;
    printf("Digite o nome do aluno:\n");
    scanf("%s",nome );

    for(i=0; i <= *id; i++)
    {
        if (strcmp(nome,alunos[i].nome) == 0)
        {
            imprimiAluno(&alunos[i]);        
        }
    }       

}

void imprimiAluno(aluno *aluno)
{
    printf("Aluno: %s %s\n",aluno -> nome, aluno -> sobrenome);
    printf("Prontuario: %d\n",aluno -> prontuario);
    printf("Data Nascimento: %d/%d/%d\n",aluno-> datadenascimento.dia, aluno-> datadenascimento.mes, aluno-> datadenascimento.ano);
    printf("Curso: %s\n\n",aluno->curso);    
}

void ListarAlunos(aluno *alunos, int *id)
{
    int i = 0;

    for(i=0; i <= *id; i++)
    {
        imprimiAluno(&alunos[i]);      
    }
}

void cadastroAluno(aluno *alunos, int *cont)
{
    printf ("\n Digite os dados do aluno:");
    printf ("\n Nome:");
    scanf("%s",alunos[*cont].nome );
    printf ("\n Sobrenome: ");
    scanf ("%s",alunos[*cont].sobrenome );
    printf ("\n Dia do nascimento: ");
	scanf ("%d",&alunos[*cont].datadenascimento.dia );
    printf ("\n Mês do nscimento: ");
	scanf ("%d",&alunos[*cont].datadenascimento.mes);
    printf ("\n Ano do nescimento: ");
	scanf ("%d",&alunos[*cont].datadenascimento.ano );    
    printf ("\n Prontuario: ");
	scanf ("%d",&alunos[*cont].prontuario );
    printf ("\n Curso: ");
	scanf ("%s",alunos[*cont].curso );
    *cont++;
}

int menuPesquisa()
{
    int op;
    printf("Digite uma das opcoes de pesquisa abaixo:\n");
    printf("1 - Nome do aluno\n");
    printf("2 - Nome e sobrenome do aluno\n");
    printf("3 - Prontuario\n");
    printf("4 - Data de nascimento\n");
    printf("5 - Curso\n");
    printf("0 - Voltar\n");
    scanf("%d", &op);
    return op;
}

void gerenciadorPesquisa(aluno *alunos, int *id)
{
    int i = 1;
    while (i != 0)
    {
        int resp = menuPesquisa();
        switch(resp )
        {
            case 1: pesquisaNomeAluno(alunos, id); break;
            case 2: printf("em producao pesquisa nome e sobrenome!\n"); break;
            case 3: printf("em producao pesquisar prontuario\n"); break;
            case 4: printf("em producao pesquisa data nescimento!\n"); break;
            case 5: printf("em producao pesquisa curso!\n"); break;
            case 0: i = 0; break;
            default: printf("Opcao invalida!!! Escolha novamente!\n"); break;
        }
    }
}

int menuPrincipal()
{
    int op;
    printf("Digite uma das opcoes abaixo:\n");
    printf("1 - Cadastrar  aluno\n");
    printf("2 - Listar todos os alunos\n");
    printf("3 - Pesquisar\n");
    printf("4 - Listar por ordem\n");
    printf("0 - Sair\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    aluno alunos[1000];
    int idAluno = 0; 
    int i = 1;

    while (i != 0)
    {
        int resp = menuPrincipal();

        switch(resp )
        {
            case 1: cadastroAluno(alunos, &idAluno); break;
            case 2: ListarAlunos(alunos, &idAluno); break;
            case 3: gerenciadorPesquisa(alunos, &idAluno); break;
            case 4: printf("em producao listar por ordem!\n"); break;
            case 0: i = 0, printf("Obrigado por usar nosso programa!!!\n") ; break;
            default: printf("Opcao invalida!!! Escolha novamente!\n"); break;
        }
    }
}