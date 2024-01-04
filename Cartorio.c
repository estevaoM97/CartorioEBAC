#include <stdio.h> //bibliot�ca de comunica��o
#include <stdlib.h> //aloca��o de memoria
#include <locale.h> //alocao de texto por regiao
#include <string.h> //resposavel pelas strings

    
	
	int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o CPF a ser registrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //copiar volres das strings
	FILE *file; //cria arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor inicial
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o encontrado.\n");
		system("pause");
	}
	
	if(file != NULL)
	{
	printf("Usuario deletado com sucesso");
	system("pause");
	}
	
}


int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	 
	    system("cls");
	 	 
        setlocale(LC_ALL,"portuguese"); //definindo linguagem
 
        printf("### Programinha Show EBAC ###\n\n"); //inicio do menu
        printf("escolha a op��o desejada no menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - consultar nomes\n");
        printf("\t3 - deletar nomes\n\n");
	    printf("Op��o: "); //fim do menu

        scanf("%d",&opcao); //armazenando a escolha do usuario
    
        system("cls");
        
        switch(opcao)
        {
        	case 1:
        	registro();
	        break;
	        
	        case 2:
	        consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    default:
		    printf("essa op��o nao exsite\n");
		    system("pause");
		    break;
		}
    
}
}
