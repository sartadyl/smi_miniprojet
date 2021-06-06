#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Voiture{
	int idVoiture;
	char marque[15];
	char nomVoiture[15];
	char couleur[7];
	int nbplaces;
	int prixJour;
	char EnLocation[4];
};

struct client{
	int idclient;
	char nom[20];
	char prenom[20];
	int cin;
	int telephone;
	char adress[15];
};

typedef struct{
	int anne;
	int mois;
	int jour;
}date;
struct contratLocation{
	float numContrat;
	int idVoiture;
	int idClient;
	date debut;
	date fin;
	int cout;
};

struct Voiture voiture;
struct client client;
struct contratLocation contrat;

int chercher_client(int Num){
    FILE * F = fopen("Client.txt","r");
	do{
    fscanf(F,"%d\t%s\t%s\t%d\t%d\t%s\n",&client.idclient,&client.nom,&client.prenom,&client.cin,&client.telephone,&client.adress);
    fflush(stdin);
    if(client.idclient==Num){
        return 1;
	}
    }while(!feof(F));
 	fclose(F);
  	return -1;
}


void Modifier_EnLocation(int id){
	FILE *Fich,*F;
  	fflush(stdin);
    F=fopen("Voiture.txt","r");
    Fich=fopen("voiture_tmp.txt","a");
    do{
    	fscanf(F,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",&voiture.idVoiture,&voiture.marque,&voiture.nomVoiture,&voiture.couleur,
		&voiture.nbplaces,&voiture.prixJour,&voiture.EnLocation);
        if(id == voiture.idVoiture){
        	if(strcmp(voiture.EnLocation,"oui") == 0){
        		strcpy(voiture.EnLocation,"non");
				fflush(stdin);
			}else{
				strcpy(voiture.EnLocation,"oui");
				fflush(stdin);
			}
      	}
      	fprintf(Fich,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",voiture.idVoiture,voiture.marque,voiture.nomVoiture,voiture.couleur,voiture.nbplaces,
		voiture.prixJour,voiture.EnLocation);
    }while(!feof(F));
    fclose(F);
    fclose (Fich);
    remove("Voiture.txt");
    rename("voiture_tmp.txt","Voiture.txt");
}


int chercher_contrat(float Num){
    FILE * F;
  	F=fopen("ContratsLocations.txt","r");
	do{
    fscanf(F,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.anne,&contrat.debut.mois,&contrat.debut.jour,
	&contrat.fin.anne,&contrat.fin.mois,&contrat.fin.jour,&contrat.cout);
    fflush(stdin);
    if(contrat.idVoiture==Num){
        return 1;
	}
    }while(!feof(F));
 	fclose(F);
  	return -1;
}

void Louer_voitures(){
    FILE * F;
    float num;
	F=fopen("ContratsLocations.txt","a");
	printf("\nentre le numero de contrat : ");
	scanf("%f",&num);
	while(chercher_contrat(num)==1){
  	  printf("cette contrat deja existe. entrer un nouveau numbre : ");
  	  scanf("%f",&num);
	}
	
	FILE * F2 = fopen("Voiture.txt","a");
    int idvoiture;
	printf("\nentrer le ID de la voiture : ");
	scanf("%d",&idvoiture);
	if(chercher_voiture(idvoiture)!=1){
		system("cls");
  	  	printf("cette voiture n'exist pas");
  	  	contrat_menu();
	}
	fscanf(F,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",&voiture.idVoiture,&voiture.marque,&voiture.nomVoiture,&voiture.couleur,&voiture.nbplaces,
	&voiture.prixJour,&voiture.EnLocation);
	
	if(strcmp(voiture.EnLocation,"oui") == 0){
		system("cls");
		printf("la voiture n’est pas disponible");
		contrat_menu();
	}

	FILE * F3 = fopen("Client.txt","a");
    int idclient;
	printf("\nentrer le ID de le client : ");
	scanf("%d",&idclient);
	if(chercher_client(idclient)!=1){
		system("cls");
  	  	printf("cet client n'exist pas");
  	  	client_menu();
	}

	contrat.numContrat = num;
	fflush(stdin);
	contrat.idVoiture = idvoiture;
	fflush(stdin);
	contrat.idClient = idclient;
	fflush(stdin);
	printf("donner la date du debut (anne) : ");
	scanf("%d",&contrat.debut.anne);
	fflush(stdin);
	printf("donner la date du debut (mois) : ");
	scanf("%d",&contrat.debut.mois);
	fflush(stdin);
	printf("donner la date du debut (jour) : ");
	scanf("%d",&contrat.debut.jour);
	fflush(stdin);
	printf("donner la date du fin (anne) : ");
	scanf("%d",&contrat.fin.anne);
	fflush(stdin);
	printf("donner la date du fin (mois) : ");
	scanf("%d",&contrat.fin.mois);
	fflush(stdin);
	printf("donner la date du fin (jour) : ");
	scanf("%d",&contrat.fin.jour);
	fflush(stdin);
	printf("donner le cout : ");
	scanf("%d",&contrat.cout);
	fflush(stdin);
    fprintf(F,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",contrat.numContrat,contrat.idVoiture,contrat.idClient,contrat.debut.anne,contrat.debut.mois,contrat.debut.jour,
	contrat.fin.anne,contrat.fin.mois,contrat.fin.jour,contrat.cout);
    fclose(F);   
}


void Visualiser_contrat(){
	float num;
    printf("donner le numero de contrat pour le recherche : ");
    scanf("%f",&num);
    FILE * F=fopen("ContratsLocations.txt","r");
    do{	
	fscanf(F,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.anne,&contrat.debut.mois,&contrat.debut.jour,
	&contrat.fin.anne,&contrat.fin.mois,&contrat.fin.jour,&contrat.cout);	
   		if(num == contrat.numContrat){
   			printf("\nle numero de contrat : %f",contrat.numContrat);
			printf("\nle ID de voiture     : %d",contrat.idVoiture);
			printf("\nle ID de client      : %d",contrat.idClient);
			printf("\nla date du debut     : %d/%d/%d",contrat.debut.anne,contrat.debut.mois,contrat.debut.jour);
			printf("\nla date du fin       : %d/%d/%d",contrat.fin.anne,contrat.fin.mois,contrat.fin.jour);
			printf("\nle cout              : %d",contrat.cout);
   		}
    }while(!feof(F));
    fclose(F);
}

void Supprimer_contrat(){
	float num;
	printf("entrer le numero de contrat que vous voulez supprimer:");
	scanf("%f",&num);
	fflush(stdin);
    FILE * Fich,*F;
	F=fopen("ContratsLocations.txt","r");
    Fich=fopen("contrat_tmp.txt","a");
    do{
    	fscanf(F,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.anne,&contrat.debut.mois,&contrat.debut.jour,
		&contrat.fin.anne,&contrat.fin.mois,&contrat.fin.jour,&contrat.cout);
    	if (num != contrat.numContrat){
               fprintf(Fich,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",contrat.numContrat,contrat.idVoiture,contrat.idClient,contrat.debut.anne,contrat.debut.mois,contrat.debut.jour,
	contrat.fin.anne,contrat.fin.mois,contrat.fin.jour,contrat.cout);
        }
    }while(!feof(F));
    fclose(Fich);
    fclose (F);
    remove("ContratsLocations.txt");
    rename("contrat_tmp.txt","ContratsLocations.txt");
    printf("supression reussite");
}

void Modifier_contrat(){
	FILE *Fich;
	FILE * F;
	float num;
	printf("donner le numero de contrat que vous voulez modifier:");
 	scanf("%f",&num);
  	fflush(stdin);
    F=fopen("ContratsLocations.txt","r");
    Fich=fopen("contrat_tmp.txt","a");
    do{
    	fscanf(F,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.anne,&contrat.debut.mois,&contrat.debut.jour,
		&contrat.fin.anne,&contrat.fin.mois,&contrat.fin.jour,&contrat.cout);
        if(num == contrat.idVoiture){
			contrat.numContrat = num;
			fflush(stdin);
			printf("donner le ID de voiture : ");
			scanf("%d",&contrat.idVoiture);
			fflush(stdin);
			printf("donner le ID de client : ");
			scanf("%d",&contrat.idClient);
			fflush(stdin);
			printf("donner la date du debut (anne) : ");
			scanf("%d",&contrat.debut.anne);
			fflush(stdin);
			printf("donner la date du debut (mois) : ");
			scanf("%d",&contrat.debut.mois);
			fflush(stdin);
			printf("donner la date du debut (jour) : ");
			scanf("%d",&contrat.debut.jour);
			fflush(stdin);
			printf("donner la date du fin (anne) : ");
			scanf("%d",&contrat.fin.anne);
			fflush(stdin);
			printf("donner la date du fin (mois) : ");
			scanf("%d",&contrat.fin.mois);
			fflush(stdin);
			printf("donner la date du fin (jour) : ");
			scanf("%d",&contrat.fin.jour);
			fflush(stdin);
			printf("donner le cout : ");
			scanf("%d",&contrat.cout);
			fflush(stdin);
      	}
      	fprintf(Fich,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",contrat.numContrat,contrat.idVoiture,contrat.idClient,contrat.debut.anne,contrat.debut.mois,contrat.debut.jour,
		contrat.fin.anne,contrat.fin.mois,contrat.fin.jour,contrat.cout);
    }while(!feof(F));
    fclose(F);
    fclose (Fich);
    remove("ContratsLocations.txt");
    rename("contrat_tmp.txt","ContratsLocations.txt");
    printf("la modification est reussi");
}

Retourner_voitures(){
	int id;
	printf("entrer le Id de voiture que vous voulez retourner : ");
	scanf("%d",&id);
	fflush(stdin);
    FILE * Fich,*F;
	F=fopen("ContratsLocations.txt","r");
    Fich=fopen("contrat_tmp.txt","a");
    do{
    	fscanf(F,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.anne,&contrat.debut.mois,&contrat.debut.jour,
		&contrat.fin.anne,&contrat.fin.mois,&contrat.fin.jour,&contrat.cout);
    	if (id != contrat.idVoiture){
               fprintf(Fich,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",contrat.numContrat,contrat.idVoiture,contrat.idClient,contrat.debut.anne,contrat.debut.mois,contrat.debut.jour,
	contrat.fin.anne,contrat.fin.mois,contrat.fin.jour,contrat.cout);
        }
    }while(!feof(F));
    fclose(Fich);
    fclose (F);
    remove("ContratsLocations.txt");
    rename("contrat_tmp.txt","ContratsLocations.txt");
    printf("retourn reussite");
    Modifier_EnLocation(contrat.idVoiture);
}

contrat_menu(){
	int choix;
		do{
		printf("\n                           \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                           \xb3 Location d'une voiture \xb3");
		printf("\n                           \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	    printf("\n\n");
   		printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    	printf("\n               \xba                                              \xba");
	    printf("\n               \xba    Visualiser contrat....................1   \xba");
    	printf("\n               \xba    Louer voitures........................2   \xba");
    	printf("\n               \xba    Retourner voiture.....................3   \xba");
    	printf("\n               \xba    Modifier contrat......................4   \xba");
    	printf("\n               \xba    Suprimer contrat......................5   \xba");
    	printf("\n               \xba    Retour................................6   \xba");
    	printf("\n               \xba                                              \xba");
    	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    	printf("\n\n                                Votre choix  :  ");
		scanf("%d",&choix);
		
		while(choix<1 || choix>6){
			printf("choix pas valide : ");
			scanf("%d",&choix);
		}
		
		switch(choix){
			case 1: system("cls");Visualiser_contrat();break;
			case 2: system("cls");Louer_voitures();break;
			case 3: system("cls");Retourner_voitures();break;
			case 4: system("cls");Modifier_contrat();break;
			case 5: system("cls");Supprimer_contrat();break;
			case 6: system("cls");main_menu();break;
    	}
	}while(1);
	
}



void Ajouter_client(){
    FILE * F;
    int id;
	F=fopen("Client.txt","a");
	printf("\nentrer le ID de client        : ");
	scanf("%d",&id);
	while(chercher_client(id)==1){
  	  printf("cette client deja existe. entrer un nouveau ID : ");
  	  scanf("%d",&id);
	}

	client.idclient = id;
	fflush(stdin);
	printf("donner la nom de client       : ");
	gets(client.nom);
	fflush(stdin);
	printf("donner le prenom de client    : ");
	gets(client.prenom);
	fflush(stdin);
	printf("donner le CIN de client       : ");
	scanf("%d",&client.cin);
	fflush(stdin);
	printf("donner le telephone de client : ");
	scanf("%d",&client.telephone);
	fflush(stdin);
	printf("donner le adress de client    : ");
	gets(client.adress);
	fflush(stdin);
	
    fprintf(F,"%d\t%s\t%s\t%d\t%d\t%s\n",client.idclient,client.nom,client.prenom,client.cin,client.telephone,client.adress);
    fclose(F);
}

void Supprimer_client(){
	char r;
	int id;
	printf("entrer le ID de client que vous voulez supprimer:");
	scanf("%d",&id);
	fflush(stdin);
    FILE * Fich,*F;
	F=fopen("Client.txt","r");
    Fich=fopen("client_tmp.txt","a");
    do{
    	fscanf(F,"%d\t%s\t%s\t%d\t%d\t%s\n",&client.idclient,&client.nom,&client.prenom,&client.cin,&client.telephone,&client.adress);
    	if (id != client.idclient){
               fprintf(Fich,"%d\t%s\t%s\t%d\t%d\t%s\n",client.idclient,client.nom,client.prenom,client.cin,client.telephone,client.adress);
        }
    }while(!feof(F));
    fclose(Fich);
    fclose (F);
    remove("Client.txt");
    rename("client_tmp.txt","Client.txt");
    printf("supression reussite");
}

void Modifier_client(){
	FILE *Fich,*F;
	int id;
	printf("donner le ID de client que vous voulez modifier:");
 	scanf("%d",&id);
  	fflush(stdin);
    F=fopen("Client.txt","r");
    Fich=fopen("client_tmp.txt","a");
    do{
    	fscanf(F,"%d\t%s\t%s\t%d\t%d\t%s\n",&client.idclient,&client.nom,&client.prenom,&client.cin,&client.telephone,&client.adress);
        if(id == client.idclient){
			client.idclient = id;
			fflush(stdin);
			printf("donner la nom de client       : ");
			gets(client.nom);
			fflush(stdin);
			printf("donner le prenom de client    : ");
			gets(client.prenom);
			fflush(stdin);
			printf("donner le CIN de client       : ");
			scanf("%d",&client.cin);
			fflush(stdin);
			printf("donner le telephone de client : ");
			scanf("%d",&client.telephone);
			fflush(stdin);
			printf("donner le adress de client    : ");
			gets(client.adress);
			fflush(stdin);
      	}
      	fprintf(Fich,"%d\t%s\t%s\t%d\t%d\t%s\n",client.idclient,client.nom,client.prenom,client.cin,client.telephone,client.adress);
    }while(!feof(F));
    fclose(F);
    fclose (Fich);
    remove("Client.txt");
    rename("client_tmp.txt","Client.txt");
    printf("la modification est reussi");
}

void Lister_client(){
    FILE * F = fopen("Client.txt","r");
    if (F == NULL){
        printf ("ce fichier n'existe pas ");
    }
    else{
    	printf("la list des clients\n\n");
    	do{
      	 	if(fscanf(F,"%d\t%s\t%s\t%d\t%d\t%s\n",&client.idclient,&client.nom,&client.prenom,&client.cin,&client.telephone,&client.adress) != EOF){
				fflush(stdin);
   				printf("\nle ID de client        : %d",client.idclient);
				printf("\nla nom de client       : %s",client.nom);
				printf("\nle prenom de client    : %s",client.prenom);
				printf("\nle CIN de client       : %d",client.cin);
				printf("\nle telephone de client : %d",client.telephone);
				printf("\nl'adress de client     : %s",client.adress);
				printf("\n");
			}	
   		}while(!feof(F));
   	}
    fclose(F);
}

client_menu(){
	int choix;
		do{
		printf("\n                           \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                           \xb3 Gestion des clients \xb3");
		printf("\n                           \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	    printf("\n\n");
   		printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    	printf("\n               \xba                                              \xba");
	    printf("\n               \xba    List des client.......................1   \xba");
    	printf("\n               \xba    Ajouter client........................2   \xba");
    	printf("\n               \xba    Modifier client.......................3   \xba");
    	printf("\n               \xba    Suprimer client.......................4   \xba");
    	printf("\n               \xba    Retour................................5   \xba");
    	printf("\n               \xba                                              \xba");
    	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    	printf("\n\n                                Votre choix  :  ");
		scanf("%d",&choix);
	
		while(choix<1 || choix>5){
			printf("choix pas valide : ");
			scanf("%d",&choix);
		}
		
		switch(choix){
			case 1: system("cls");Lister_client();break;
			case 2: system("cls");Ajouter_client();break;
			case 3: system("cls");Modifier_client();break;
			case 4: system("cls");Supprimer_client();break;
			case 5: system("cls");main_menu();break;	
    	}
	}while(1);
	
}





int chercher_voiture(int Num){
    FILE * F;
  	F=fopen("Voiture.txt","r");
	do{
    fscanf(F,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",&voiture.idVoiture,
	&voiture.marque,&voiture.nomVoiture,&voiture.couleur,&voiture.nbplaces,
	&voiture.prixJour,&voiture.EnLocation);
    fflush(stdin);
    if(voiture.idVoiture==Num){
        return 1;
	}
    }while(!feof(F));
 	fclose(F);
  	return -1;
}

void Ajouter_voiture(){
    FILE * F;
    int id;
	F=fopen("Voiture.txt","a");
	printf("\nentre le ID de voiture : ");
	scanf("%d",&id);
	while(chercher_voiture(id)==1){
  	  printf("cette voiture deja existe. entrer un nouveau ID : ");
  	  scanf("%d",&id);
	}

	voiture.idVoiture = id;
	fflush(stdin);
	printf("donner la marque de voiture : ");
	gets(voiture.marque);
	fflush(stdin);
	printf("donner le nom de voiture : ");
	gets(voiture.nomVoiture);
	fflush(stdin);
	printf("donner le couleur de voiture : ");
	gets(voiture.couleur);
	fflush(stdin);
	printf("donner le nombre des places: ");
	scanf("%d",&voiture.nbplaces);
	fflush(stdin);
	printf("donner le prix de jour : ");
	scanf("%d",&voiture.prixJour);
	fflush(stdin);
	printf("donner le EnLocation : ");
	gets(voiture.EnLocation);
	fflush(stdin);
	
    fprintf(F,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",voiture.idVoiture,voiture.marque,voiture.nomVoiture,voiture.couleur,voiture.nbplaces,
	voiture.prixJour,voiture.EnLocation);
    fclose(F);
}

void Supprimer_voiture(){
	char r;
	int id;
	printf("entrer le ID de voiture que vous voulez supprimer:");
	scanf("%d",&id);
	fflush(stdin);
    FILE * Fich,*F;
	F=fopen("Voiture.txt","r");
    Fich=fopen("voiture_tmp.txt","a");
    do{
    	fscanf(F,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",&voiture.idVoiture,&voiture.marque,&voiture.nomVoiture,&voiture.couleur,
		&voiture.nbplaces,&voiture.prixJour,&voiture.EnLocation);
    	if (id != voiture.idVoiture){
               fprintf(Fich,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",voiture.idVoiture,voiture.marque,voiture.nomVoiture,voiture.couleur,voiture.nbplaces,
	voiture.prixJour,voiture.EnLocation);
        }
    }while(!feof(F));
    fclose(Fich);
    fclose (F);
    remove("Voiture.txt");
    rename("voiture_tmp.txt","Voiture.txt");
    printf("supression reussite");
}

void Modifier_voiture(){
	FILE *Fich,*F;
	int id;
	printf("donner le ID de voiture que vous voulez modifier:");
 	scanf("%d",&id);
  	fflush(stdin);
    F=fopen("Voiture.txt","r");
    Fich=fopen("voiture_tmp.txt","a");
    do{
    	fscanf(F,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",&voiture.idVoiture,&voiture.marque,&voiture.nomVoiture,&voiture.couleur,
		&voiture.nbplaces,&voiture.prixJour,&voiture.EnLocation);
        if(id == voiture.idVoiture){
			voiture.idVoiture = id;
			fflush(stdin);
			printf("donner la marque de voiture : ");
			gets(voiture.marque);
			fflush(stdin);
			printf("donner le nom de voiture : ");
			gets(voiture.nomVoiture);
			fflush(stdin);
			printf("donner le couleur de voiture : ");
			gets(voiture.couleur);
			fflush(stdin);
			printf("donner le nombre des places: ");
			scanf("%d",&voiture.nbplaces);
			fflush(stdin);
			printf("donner le prix de jour : ");
			scanf("%d",&voiture.prixJour);
			fflush(stdin);
			printf("donner le EnLocation : ");
			gets(voiture.EnLocation);
			fflush(stdin);
      	}
      	fprintf(Fich,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",voiture.idVoiture,voiture.marque,voiture.nomVoiture,voiture.couleur,voiture.nbplaces,
		voiture.prixJour,voiture.EnLocation);
    }while(!feof(F));
    fclose(F);
    fclose (Fich);
    remove("Voiture.txt");
    rename("voiture_tmp.txt","Voiture.txt");
    printf("la modification est reussi");
}

void Lister_voiture(){
    FILE * F = fopen("Voiture.txt","r");
    if (F == NULL){
        printf ("ce fichier n'existe pas ");
    }
    else{
    	printf("la list des voitures\n\n");
    	do{
      	 	if(fscanf(F,"%d\t%s\t%s\t%s\t%d\t%d\t%s\n",&voiture.idVoiture,&voiture.marque,&voiture.nomVoiture,&voiture.couleur,
			&voiture.nbplaces,&voiture.prixJour,&voiture.EnLocation) != EOF){
				fflush(stdin);
   				printf("\nle ID de voiture      : %d",voiture.idVoiture);
				printf("\nla marque de voiture  : %s",voiture.marque);
				printf("\nle nom de voiture     : %s",voiture.nomVoiture);
				printf("\nle couleur de voiture : %s",voiture.couleur);
				printf("\nle nombre des places  : %d",voiture.nbplaces);
				printf("\nle prix de jour       : %d",voiture.prixJour);
				printf("\nle EnLocation         : %s",voiture.EnLocation);
				printf("\n");
			}	
   		}while(!feof(F));
   	}
    fclose(F);
}

void voiture_menu(){
	int choix;
		do{
		printf("\n                           \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n                           \xb3 gestion des voitures  \xb3");
		printf("\n                           \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	    printf("\n\n");
   		printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    	printf("\n               \xba                                              \xba");
	    printf("\n               \xba    List des voitures.....................1   \xba");
    	printf("\n               \xba    Ajouter une voiture...................2   \xba");
    	printf("\n               \xba    Modifier une voiture..................3   \xba");
    	printf("\n               \xba    Suprimer une voiture..................4   \xba");
    	printf("\n               \xba    Retour................................5   \xba");
    	printf("\n               \xba                                              \xba");
    	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    	printf("\n\n                                Votre choix  :  ");
		scanf("%d",&choix);
		
		while(choix<1 || choix>5){
			printf("choix pas valide : ");
			scanf("%d",&choix);
		}
		
		switch(choix){
			case 1: system("cls");Lister_voiture();break;
			case 2: system("cls");Ajouter_voiture();break;
			case 3: system("cls");Modifier_voiture();break;
			case 4: system("cls");Supprimer_voiture();break;
			case 5: system("cls");main_menu();break;
    	}
	}while(1);
}




main_menu(){
    int choix;
    do{
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principal  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n\n");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Location..............................1   \xba");
    printf("\n               \xba    Gestion voitures......................2   \xba");
    printf("\n               \xba    Gestion clients.......................3   \xba");
    printf("\n               \xba    Quitter...............................4   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");
    
    scanf("%d",&choix);
	
		switch(choix){
			case 1: system("cls");contrat_menu();break;
			case 2: system("cls");voiture_menu();break;
			case 3: system("cls");client_menu();break;
			case 4: exit(0);
			default:
				while(choix<1 || choix>4){
					printf("choix pas valide : ");
					scanf("%d",&choix);
				};
				break;
    	}
	}while(1);
	return 0;
}

main(){
	main_menu();
}

