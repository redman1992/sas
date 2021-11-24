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

//Menu***********************************************************************************************************************************nbr ligne fichier
int nombreLigneFichier(FILE *ele){
	int count=0,c=0;
	while((c=fgetc(ele))!=EOF){
		if(c=='\n')
			count++;
	}
	return count;
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
		printf("\n\n\t---------------------  Menu  --------------------- \n\n");
	do{
		printf("1 : Ajouter un Compte !\n");
		printf("2 : Ajouter Plusieurs Comptes !\n");
		printf("3 : Operations (Retrait-Depot) !\n");
		printf("4 : Affichage !\n");
		printf("5 : Fidelisation !\n");
		printf("6 : Quitter !\n");	
	}while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6 );
	
	return choix;
}

//Ajouter un compte**************************************************************************************************************Ajout 1 client
void RemplirUnCompte(){
	int i;
	Compte client;
	FILE *ele;
	
	debut:
	ele = fopen("enregistrer.dat","a+");
	printf("\n\n\t---------------------  Ajouter un Compte  --------------------- \n\n");
	printf("Donner Lu numero De Compte: ");
	scanf("%d",&client.numCompte);
	
	//tester si le nombre existe
	if(testerCompteExiste(client.numCompte,ele)==1){
		printf("\nNumero de Compte Existe deja !!! Veuillez saisir un autre !! ");
		Retard(1000000000);
		system("cls");
		goto debut;
	}
	
	printf("Donner le Nom : ");
	scanf("%s",client.nom);
	printf("Donner le Prenom : ");
	scanf("%s",client.prenom);
	printf("Donner le CIN: ");
	scanf("%s",client.cin);
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
	Compte *client=NULL;
	int i=0,nombre,num,pos;
	float montantEntre;
	
	elem=fopen("enregistrer.dat","r");
	nombre = nombreLigneFichier(elem);
	fclose(elem);
	
	ele=fopen("enregistrer.dat","a+");
	rewind(ele);
	
	if(ele==NULL)printf("Erreur lors de la creation du table fichiert\n");
	client = malloc(nombre*sizeof(client));
		if(client == NULL)	printf("Erreur lors de la creation du table client\n");
	printf("%d\n",nombre);
	
	printf("Donner le numero Du Compte : ");
	scanf("%d",&num);
	printf("Donner le Montant a deposer : ");
	scanf("%f",&montantEntre);
	
//	while(fscanf(ele,"%d %s %s %s %f\n",&client[i].numCompte,client[i].cin,client[i].nom,client[i].prenom,&client[i].montant)!=EOF){
//		i++;
//	}
	RemplirTableClient(ele,client );
	
	

	pos=position(client,num,nombre);
	if( pos != -1 ){
		printf("Le Compte existe : \n");
		printf("avant : Num > %d - Nom > %s - Prenom > %s - CIN > %s - Montant > %f\n",client[pos].numCompte,client[pos].nom,client[pos].prenom,client[pos].cin,client[pos].montant);
		client[pos].montant += montantEntre;
		//chargement
			printf(" l'operation va prendre quelque instants  \n");	
			for(i=0;i<10;i++){
					Retard(100000000);
						printf(".");
				}
				
				printf("\n transaction est bien effectuee \n");
			printf("Apres : Num > %d - Nom > %s - Prenom > %s - CIN > %s - Montant > %f\n",client[pos].numCompte,client[pos].nom,client[pos].prenom,client[pos].cin,client[pos].montant);
	}else{
		printf("LE numero que vous avez entre n'existe pas !!\n");
	}
	//ecrire dans un fichier
	
//	remplirFichier(ele3,client,nombre);
	AfficherTableClient(client,nombre);
		printf("test %d\n",nombre);
	
		free(client);
		fclose(ele);
}
