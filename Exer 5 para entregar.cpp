#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

typedef struct TPessoa{
    char nome[50];
    int codigo;
    int quantVoltas;
    float *tempos;
    float tempostotal;
    float media;
} TPessoa;

int main()
{

	TPessoa *listaPessoas;
	int quantidade,i,v,x,k,maior,y,j,d;
	float menor,somanum,comp,mediaCampeao;
	char nomeVencedor[50];

	setlocale(LC_ALL, "Portuguese");	
	printf("Entre com a quantidade de pessoas: ");
    scanf(" %d",&quantidade);
    int vencedor[quantidade];
    int cont[quantidade];
    maior = 0;
    system("cls");
   // Alocacao de memoria ou leitura das informações
    listaPessoas = (TPessoa *) malloc(sizeof(TPessoa) * quantidade);
    for(i = 0; i < quantidade; i++ )
    {
        v = 0;
        somanum = 0;
        printf("Nome: ");
        scanf(" %[^\n]s", listaPessoas[i].nome);
        printf("Codigo: ");
        scanf(" %d",&listaPessoas[i].codigo);
        printf("Quantidades de voltas: ");
        scanf(" %d", &listaPessoas[i].quantVoltas);
        if(maior < listaPessoas[i].quantVoltas)
	 	{
	 		maior = listaPessoas[i].quantVoltas;
	 	}
		listaPessoas[i].tempos = (float *) malloc(listaPessoas[i].quantVoltas * sizeof(float));
		for(k = 0; k < listaPessoas[i].quantVoltas; k++)
		{
	 		printf("Tempo[em minutos]:");
	 		scanf(" %f", &listaPessoas[i].tempos[k]);
	 		listaPessoas[i].tempostotal = listaPessoas[i].tempostotal + listaPessoas[i].tempos[k];
	 		somanum = listaPessoas[i].tempostotal;
	 		listaPessoas[i].media = somanum/listaPessoas[i].quantVoltas;
		}
		printf(" \n");
		system("cls");
	}

	
	//VOLTA MAIS RAPIDA
	menor = listaPessoas[0].tempos[0];
	for(i = 0; i < quantidade; i++)
	{
		for(k = 0; k < listaPessoas[i].quantVoltas; k++)
		{
	 		if(menor > listaPessoas[i].tempos[k])
	 		{
	 			menor = listaPessoas[i].tempos[k];
			}
		}
	}
	 	
	//VENCEDOR
	d = 0;
	j = 0;
	comp = 5000;
	for(i = 0; i < quantidade; i++)
	{
		if(listaPessoas[i].quantVoltas == maior)
		{
			d++;
			vencedor[j]= i;
			j++;
	 		if(d >= 2)
	 		{
	 		    for(y = 0; y < d; y++)
	 			{
	 				if(comp > listaPessoas[vencedor[y]].tempostotal)
	 				{
	 					comp = listaPessoas[vencedor[y]].tempostotal;
						strcpy(nomeVencedor,listaPessoas[vencedor[y]].nome);
						mediaCampeao = listaPessoas[vencedor[y]].media;	
					}
				}
			}
			else
			{
				strcpy(nomeVencedor,listaPessoas[i].nome);
			}
		}			
	}
	 
	//QUEM FICOU ABAIXO DA MEDIA DAS VOLTA DO CAMPEAO	
	for(i = 0; i < quantidade; i++ )
	{
		x = 0;
		for(k = 0; k < listaPessoas[i].quantVoltas; k++)
		{
	 		if(listaPessoas[i].tempos[k] < mediaCampeao )
	 		{
	 			x++;
	 			cont[i] = x;
			}
			else
			{
				cont[i] = x;
			}
		}
	}
	
	//Dados dos atletas
	printf("|	Campeão/Volta mais rapida	|\n");
	printf("Campeão: %s\n",nomeVencedor);	
	printf("A volta mais rapida: %.2f\n", menor);
	printf(" \n");
	printf("|   	DADOS DOS ATLETAS		|\n");
	for(i = 0; i < quantidade; i++ )
	{
		printf("Nome: %s\n", listaPessoas[i].nome);
		printf("Código: %d\n", listaPessoas[i].codigo);
		printf("O tempo total: %.2f\n", listaPessoas[i].tempostotal);
		printf("A média de voltas do atleta: %.2f\n ", listaPessoas[i].media);
		printf("Quantidade de volta(s) que o atleta ficou abaixo da média do campeão: %d\n", cont[i]);
		printf(" \n");
	}
	
	for(i = 0; i < quantidade;i++)
	{
		free(listaPessoas[i].tempos);
	}
		
	free(listaPessoas);
}

	
	
