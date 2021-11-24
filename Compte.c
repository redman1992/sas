#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Fonction du retard***********************************************************************************fonction retard
void Retard(int j){
	int k,i;
		for(i=0;i<j;i++)
			k=j;
}

//definition de la structure***********************************************************************************************************structure
typedef struct compte{
	int numCompte;
	char nom[20],prenom[20],cin[20];
	float montant;
}Compte;

//*******************************************************************************************return nombre de ligne d'un fichier
int count_line(FILE *fichier)
{
		int line=0,c =0;
		while((c=fgetc(fichier)) != EOF )
			{
				if(c == '\n')
					{
						line++;
					}
			}
					return line;
}

//************************************************************************************************************Nombre de compte existe DATA
int retourNombreCompte(){
	FILE *ele;
	int nbr;
	ele = fopen("enregistrer.dat","r");
	nbr=count_line(ele);
	fclose(ele);
	return nbr;
}

//tester si un Compte existe par son numro*********************************************************test if num exist table struct return pos

int position(Compte *client,int num,int taille){
	int pos = -1,i;
	for(i=0;i<taille;i++){
		if(client[i].numCompte==num)
			pos=i;
	}
	return pos;
}

//tester si un Compte existe par son numro*******************************************************************************test if num exist fichier
int testerCompteExiste(int numero,FILE *ele){
int existe=0;
Compte client;
	
	while(fscanf(ele,"%d %s %s %s %f\n",&client.numCompte,client.cin,client.nom,client.prenom,&client.montant)!=EOF){
		if(numero == client.numCompte){
				existe = 1;
			}
		}	
		return existe;
}

//**************************************************************************************************************teset if CIN existe lor de remplissage

int testerCinExiste(char Cin[20],FILE *ele){
int existe=0;
Compte client;
	
	while(fscanf(ele,"%d %s %s %s %f\n",&client.numCompte,client.cin,client.nom,client.prenom,&client.montant)!=EOF){
		if(strcmp(client.cin,Cin) == 0){
				existe = 1;
			}
		}	
		return existe;
}

//Menu******************************************************************************************************************************Remplir un table de client
void RemplirTableClient(FILE *ele,Compte *client ){
	int i=0;
	while(fscanf(ele,"%d %s %s %s %f\n",&client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,&client[i].montant)!=EOF){
		i++;
	}
	
}
//Menu******************************************************************************************************************************Afficher table de client
void AfficherTableClient(Compte *client,int taille){
	int i;
	for(i=0;i<taille;i++){
		printf("Client %d ------------------------------------->\n",i+1);
			printf("NumC : %d == Nom : %s == Prenom : %s == CIN : %s == Montant %f \n \n",client[i].numCompte,client[i].nom,client[i].prenom,client[i].cin,client[i].montant);
	}
}
//Menu***********************************************************************************************************************************Menu
int menu(){
	int choix;
	do{
		printf("\n\n\t---------------------  Menu  --------------------- \n\n");
		printf("1 : Ajouter un Compte !\n");
		printf("2 : Ajouter Plusieurs Comptes !\n");
		printf("3 : Operations (Retrait-Depot) !\n");
		printf("4 : Affichage !\n");
		printf("5 : Fidelisation !\n");
		printf("6 : Nombre de Compte  !\n");
		printf("7 : Quitter !\n");	
		printf("Donner Votre choix : ");
		scanf("%d",&choix);
		system("cls");
	}while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6 && choix != 7 );
	
	return choix;
}

//Ajouter un compte**************************************************************************************************************Ajout 1 client
void RemplirUnCompte(){
	int i;
	Compte client;
	FILE *ele;
	retour:
	debut:
	ele = fopen("enregistrer.dat","a+");
	printf("\n\n\t---------------------  Ajouter un Compte  --------------------- \n\n");
	printf("Donner Lu numero De Compte: ");
	scanf("%d",&client.numCompte);
	
	
	//tester si le nombre existe
	if(testerCompteExiste(client.numCompte,ele)==1){
		printf("\nNumero de Compte Existe deja !!! Veuillez saisir un autre !! \n");
		Retard(1000000000);
		system("cls");
		goto debut;
	}
	
	printf("Donner le CIN: ");
	scanf("%s",client.cin);
	printf("Donner le Nom : ");
	scanf("%s",client.nom);
	printf("Donner le Prenom : ");
	scanf("%s",client.prenom);
	
	printf("Donner le Montant : ");
	scanf("%f",&client.montant);
	
	//enregistrer dans le fichiers	client.numCompte,client.cin,client.nom,client.prenom,&client.montant
	fprintf(ele,"%d %s %s %s %f\n",client.numCompte,client.cin,client.nom,client.prenom,client.montant);
	fclose(ele);
	//loading
	printf("l'operation va prendre quelque instants  \n");
	for(i=0;i<10;i++){
		Retard(100000000);
		printf(".");
	}
	printf("\nL'opretaion est bien effectuee !!");
	Retard(1000000000);
	system("cls");
	
}

//Ajouter plusieur compte*************************************************************************************************Ajout N clients

void RemplirPlusieurComptes(int nombre){
	int i;
		for(i=0;i<nombre;i++)
			RemplirUnCompte();
}


//Ajouter plusieur compte*************************************************************************************************depot

void DepotMontant(int numero,float montant){
	FILE *ele,*elem;
	Compte client;
	
	ele=fopen("enregistrer.dat","r");
	elem = fopen("newtext.dat","w+");
	
	while(fscanf(ele,"%d %s %s %s %f\n",&client.numCompte,client.cin,client.nom,client.prenom,&client.montant)!=EOF){
		if(client.numCompte==numero){
			client.montant+=montant;
		}
		fprintf(elem,"%d %s %s %s %f\n",client.numCompte,client.cin,client.nom,client.prenom,client.montant);
	}
		fclose(ele);
		fclose(elem);
		remove("enregistrer.dat");
   		rename("newtext.dat","enregistrer.dat");
}

//Ajouter plusieur compte*************************************************************************************************retrait

void RetraitMontant(int numero,float montant){
	FILE *ele,*elem;
	Compte client;
	
	
	ele=fopen("enregistrer.dat","r");
	elem = fopen("newtext.dat","w+");
	
	while(fscanf(ele,"%d %s %s %s %f\n",&client.numCompte,client.cin,client.nom,client.prenom,&client.montant)!=EOF){
		if(client.numCompte==numero && client.montant>montant){
			client.montant-=montant;
		}
		fprintf(elem,"%d %s %s %s %f\n",client.numCompte,client.cin,client.nom,client.prenom,client.montant);
	}
		fclose(ele);
		fclose(elem);
		remove("enregistrer.dat");
   		rename("newtext.dat","enregistrer.dat");
}

//trier*************************************************************************************************trie ascendant
void trierAscendant(Compte *client ,int count){
	int i,pos,j;
	Compte c1;
	float min;
		for(i=0;i<count;i++){
			min = client[i].montant;
			pos=i;
			for(j=i+1;j<count;j++){
				if(min > client[j].montant){
					min=client[j].montant;
					pos = j;
				}
			}
			c1 = client[i];
			client[i]=client[pos];
			client[pos]=c1;
		}
}

//trier***************************************************************************************************************************trie Descendant
void trierDescendant(Compte *client,int count){
	int j,i,pos;
	float max;
	Compte c1;
	for(i=0;i<count;i++){
			max = 	client[i].montant;
			pos=i;
			for(j=i+1;j<count;j++){
				if(max< client[j].montant){
					max=client[j].montant;
					pos = j;
				}
			}
			c1 = client[i];
			client[i]=client[pos];
			client[pos]=c1;
		}
		
}
	

//***************************************************************************************************************************************fonction trie ascendant
//Afficher Account Asciendant (montant)

void afficherListAscendant(){
	Compte Check,Add,c1;
	Compte *client;
	FILE *ele;
	int car,i=0,j,count,pos;
	float min;
	
	//retourner le nombre de ligne

	//Pro
		printf("*********************Affichage*********************\n");
		ele = fopen("enregistrer.dat","r+");	
		count=count_line(ele);
		rewind(ele);
		client = malloc(count * sizeof(client));
			if(client==NULL)
				printf("Erroooooor\n");
				
		while(fscanf(ele,"%d %s %s %s %f\n",&client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,&client[i].montant)!=EOF){
			i++;
		}
		
		//trier
		trierAscendant(client , count);
		//affichage
		 AfficherTableClient(client,count);	
			//	printf("%d \n",count);	
			free(client);
			fclose(ele);
}

//******************************************************************************************************************************Affiche list descendant

void afficherListDescendant(){
	Compte Check,Add,c1;
	Compte *client;
	FILE *ele;
	int car,i=0,j,count,pos;
	float max;
	
	//retourner le nombre de ligne

	//Pr
		printf("*********************Affichage*********************\n");
		ele = fopen("enregistrer.dat","r");	
		count=count_line(ele);
		rewind(ele);
		client = malloc(count * sizeof(client));
			if(client==NULL)
				printf("Erroooooor\n");
				
		while(fscanf(ele,"%d %s %s %s %f\n",&client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,&client[i].montant)!=EOF){
			i++;
		}	
		//trier
		trierDescendant(client,count);
		//affichage	
		AfficherTableClient(client,count);
			free(client);
			fclose(ele);
}


//************************************************************************afficher ascendant par rapport a un nombre

void afficherListAscendantNombre(float somme){
	Compte Check,Add,c1;
	Compte *client;
	FILE *ele;
	int car,i=0,j,count,pos;
	float min;
	
	//retourner le nombre de ligne
	
	//Pr
		printf("*********************Affichage*********************\n");
		ele = fopen("enregistrer.dat","r");	
		count=count_line(ele);
		rewind(ele);
		client = malloc(count * sizeof(client));
			if(client==NULL)
				printf("Erroooooor\n");
				
		while(fscanf(ele,"%d %s %s %s %f\n",&client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,&client[i].montant)!=EOF){
			i++;
		}
		//trier
		trierAscendant(client , count);
		//affichage
			for(i=0;i<count;i++){
				if(client[i].montant>somme){
						printf("%d == %s == %s == %s == %f \n",client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,client[i].montant);	
				}	
			}
			free(client);
			fclose(ele);
}


//************************************************************************afficher ascendant par rapport a un nombre

void afficherListDescendantNombre(float somme){
	Compte Check,Add,c1;
	Compte *client;
	FILE *ele;
	int car,i=0,j,count,pos;
	float min;
	
	//retourner le nombre de ligne

	//Pr
		printf("*********************Affichage*********************\n");
		ele = fopen("enregistrer.dat","r");	
		count=count_line(ele);
		rewind(ele);
		client = malloc(count * sizeof(client));
			if(client==NULL)
				printf("Erroooooor\n");
				
		while(fscanf(ele,"%d %s %s %s %f\n",&client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,&client[i].montant)!=EOF){
			i++;
		}
		//trier
		trierDescendant(client,count);
		
		//affichage
			for(i=0;i<count;i++){
				if(client[i].montant>somme){
						printf("%d == %s == %s == %s == %f \n",client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,client[i].montant);	
				}
				
			}
			free(client);
			fclose(ele);
}

//REmplir fishier a partir d'un tableau
void remplirfichier(Compte *client,int count){
	FILE *e;
	int i;
	e = fopen("test.dat","w+");
	if(e==NULL)printf("Erreur lors de l'ouverture du fichier'");
	for(i=0;i<count;i++){
			printf("NumC : %d == Nom : %s == Prenom : %s == CIN : %s == Montant %f \n \n",client[i].numCompte,client[i].nom,client[i].prenom,client[i].cin,client[i].montant);

	}
	fclose(e);
}
//***************************************************************************************fedilisation

void fedilisation(){
	FILE *ele,*ele1,*ele2;
	Compte *client;
	int count,i=0;
	
	ele = fopen("enregistrer.dat","r");
	count=count_line(ele);
	fclose(ele);
	rewind(ele);
	ele1 = fopen("enregistrer.dat","r+");
	while(fscanf(ele1,"%d %s %s %s %f\n",&client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,&client[i].montant)!=EOF){
			i++;
		}	
		//trier
		trierDescendant(client,count);
		
		for(i=0;i<3;i++){
				client[i].montant+=client[i].montant*0.013;	
			}
			//affichage	
		AfficherTableClient(client,count);
	fclose(ele1);
	rewind(ele1);
	ele2=fopen("test.dat","w+");
		for(i=0;i<count;i++){
				fprintf(ele2,"%d %s %s %s %f\n",client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,client[i].montant);	
			}
	fclose(ele2);
	remove("enregistrer.dat");
   	rename("test.dat","enregistrer.dat");
//	printf("Helloooo");
	
	
}


