#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //blibioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //Biclioteca responsavel por cuidar das string



int registro()//função responsavel por cadastrar os usuarios no sistemas
{
	//inicio de criação de variaveis/string
	setlocale(LC_ALL,"Portuguese");
	char arquivo[60];
	char CPF [60];
	char Nome[60];
	char sobrenome[60];
	char cargo[60];

	
	printf("Digite o CPF a ser cadsatrado :");//coletando as informaçoes do usuario 
	scanf("%s",CPF);//%s = armazenamento de string
	
	strcpy(arquivo, CPF);//Responsavel por copiar os valores das string
	
	FILE *file;// crir o arquivo 
	file=fopen(arquivo,"w");//cria o arquivo "w" = significa escrever
	fprintf(file,CPF);//salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");// atualização do arquivo
	fprintf(file,"\tNome:");
	fclose(file);
	
	
	printf("Digite o nome a ser cadstrado: ");//coletando as informaçoes do usuario 
	scanf("%s",Nome);//%s = armazenamento de string
	
	file = fopen(arquivo,"a");// atualização do arquivo 
	fprintf(file,Nome);// atualização do arquivo com a informção
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tsobrenome:");
	fclose(file);
	
	
	printf("Digite o sobrenome:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tcargo: ");
	fclose(file);
	
	
	
	printf("Qual o seu cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
	file = fopen(arquivo,"a");
	fprintf(file,".");
	fclose(file);
	
	system("pause");
	
}
	

int deletar()//função responsavel por deletar os usuarios do sistema
{
char CPF[60];

printf("Digite o CPF a ser deletado: ");
scanf("%s",CPF);// armazenamendo de string

remove(CPF);

FILE*file;
file=fopen(CPF,"r");//Leitura do arquivo

if(file == NULL)//mensagem se ele não for encontrado
{
	printf("o Usuario não foi encontrado!\n");
	system("pause");
	
	
}

 else// mensagem se o usuario for deletado
{
	fclose(file);
	
	remove(CPF);
	printf("Usúario foi deletado com sucesso!\n");
	system("pause");
}	

fclose(file); 
}
	
	


int consulta()// função responsavel por consutar os usuarios
{
	setlocale(LC_ALL,"Portuguese");
	char CPF[40];
	char conteudo [200];
	
	printf("Qual CPF Deseja consultar: ");
	
	scanf("%s",CPF);
	
	FILE*file;
	file=fopen(CPF,"r");//Leitura do arquivo
	
	if(file==NULL)
	{
		printf("Não foi localizado");
	}
	
    while(fgets(conteudo,200, file)!=NULL)//monstra as informçoes encontradas
    {
     	printf("\nEssas são a informaçoes do usuario\nCPF: ");
     	printf("%s",conteudo);
     	printf("\n\n");
	}
	fclose(file); 
	system("pause");
	
}

int main(){
	
	int opcao=0; //Definindo as variaveis
	
     int x=1;
	 
	  for(x==1;x==1;) //repetição   
	 {
	
	  system("cls");
		
	
	
	
	 setlocale(LC_ALL,"Portuguese");

	 printf("\t\t Cartório da EBAC \n\n");
     //INICIO DO MENU
	
     printf("Escolha a opeção desejada do menu: \n\n");
      
	 printf("\t1 - registrar nomes\n" );
     
	 printf("\t2 - consultar nomes\n");

	 printf("\t3 - Deletar nomes\n\n ");
	 
	 printf("\t4 - Sair do sistema.\n\n ");
	 
	 
     
	 printf("Opção:  ");//Final do menu

	 scanf("%d", &opcao);//Armazenando a escolha do Usuario 

	 system("cls");// responsavel por limpar a tela 
	 
	 
	 switch(opcao)
	 {
	 
	 case 1:
	 	registro();//chamda de funçoes
		break;
		
       case 2:
	 	consulta();//chamda de funçoes
		break;
		
	 case 3:
	     deletar();//chamda de funçoes
		break;	   
	 	   
	  case 4:
	  printf("Obrigado o utilizar o sistema!!");	  
	  return 0; 
	 	   break;
	 	   
	 default:// não existe uma opeção
	 		printf("Não existe esta opeção!\n\n");
		printf("Por favor retorne ao Menu!\n\n");
		system("pause");
		break;
	
}
}


}


	
