#include <stdio.h>
#include <stdlib.h>
#include "Compte.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
 
	int option,nbr,num,choix;
	
	float montant;
	
	do{
		choix = menu();
	
		switch(choix){
			case 1 : RemplirUnCompte();
						break;
						
			case 2 : printf("Donner le Nombre de Client Voulu : ");
						scanf("%d",&nbr);
						RemplirPlusieurComptes(nbr);
						break;
					
			case 3 : do{
						printf("Vouler-ous deposer (option : 1) ou retirer (option : 2) :");
						scanf("%d",&option);
						system("cls");
						}while(option !=1 && option != 2 );
						if(option==1){//*********************************************deposer de l'argent
							printf("Donner le numero du Compte : ");
							scanf("%d",&num);
							printf("Donner le Montant a deposer : ");
							scanf("%f",&montant);
							DepotMontant(num,montant);
							printf("L'operation est bien effectuee !!");
						}else{//****************************************************retirer de l'argent
								printf("Donner le numero du Compte : ");
							scanf("%d",&num);
							printf("Donner le Montant a deposer : ");
							scanf("%f",&montant);
							RetraitMontant(num,montant);
							printf("L'operation est bien effectuee !!");
						}
						break;
						
			case 4 :do{ system("cls");
						printf("Vous Avez 4 option : \n 1 : Afficher liste Ascendant\n 2 : Afficher liste Descendant\n 3 : Afficher Liste Ascendant a un montant donner\n 4 : Afficher Liste Descendant a un montant donner\n");
						scanf("%d",&option);
						system("cls");
						}while( option !=1 && option !=2 && option != 3 && option != 4 );
						if(option == 1){
							afficherListAscendant();
						}
						else if(option == 2){
							afficherListDescendant();
						}
						else if(option  == 3){
							printf("Donner un montant : ");
							scanf("%f",&montant);
							afficherListAscendantNombre(montant);
						}else{
							printf("Donner un montant : ");
							scanf("%f",&montant);
							afficherListDescendantNombre(montant);
							
						}
						break;
						
			case 5 : printf("Vous avez Ajoute 1.3 pourcent pour les 3 Premiers !!!\n");//*******************************>>>à fixer
						fedilisation();
						Retard(1000000000);
						system("cls");
						break;
						
			case 6 : printf("Nombre de Client Existe est >>>>> %d\n",retourNombreCompte());
						Retard(1000000000);
						system("cls");
						break;
			
			default : printf("Aurevoir!!!\n");
						Retard(1000000000);
						system("cls");
						break;
		
		
			}
				
					
		
		}while(choix!=7);
	
	printf("A Bientot ! \n");
	
//	RemplirUnCompte();
//	afficherListAscendant();
	
//	RemplirPlusieurComptes(3);
//	fedilisation();
	return 0;
}
