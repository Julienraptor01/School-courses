/*********************************************************************/
/* Manipulation de fichiers binaires. */
/* Organisation indexée. */
/* Fichier bidonné (taille BIDONSIZE enregistrements). */
/* Taille d'enregistrement fixe. */
/* Adressage par numero d'enregistrement (de 0 a nbenreg-1) */
/*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "OrgIdx.h"

#define BIDONSIZE 10000

int main()
{
//FILE * fichier = NULL; // pointeur sur le fichier
//char * fileName = NULL; // nom du fichier


	return 0;
}

/***********************************************************/
/* Creer et bidonner un fichier indexe */
/* IN : nom du fichier a creer, nombre d'enregistrements */
/* OUT : 0 en cas de succes, -1 en cas d'erreur */
/***********************************************************/
int createFileIdx(char * fileName, int bidonNb)
{
	FILE * fichier = NULL;
	EnrIdx record= {0};
	int i=0;
	int erreur=0;

	fichier=fopen(fileName,"wb");
	if (fichier!=NULL)
	{
		while((i<bidonNb)&&!erreur)
		{
			if(fwrite(&record,sizeof(EnrIdx),1,fichier)!=1)
				erreur=-1;
			i++;
		}
		fclose(fichier);
	}

	return erreur;
}

/***********************************************************/
/* Allouer la memoire a l'index d'un fichier indexe */
/* IN : pointeur vers le debut de l'index, */
/* nombre d'enregistrements */
/* OUT : 0 en cas de succes, -1 en cas d'erreur */
/***********************************************************/
int allocateIdx(IdxRecord * *index, int bidonNb)
{
	int erreur=-1;

	*index=(IdxRecord *) calloc(bidonNb,sizeof(IdxRecord));
	if (*index!=NULL)
		erreur=0;

	return erreur;
}

/***********************************************************/
/* Construire l'index d'un fichier indexe */
/* IN : nom du fichier */
/* OUT : pointeur sur l'index cree, NULL en cas d'erreur */
/***********************************************************/
IdxRecord * buildIdx(char * fileName)
{
	FILE * fichier = NULL;
	IdxRecord indexRecord= {-1,-1}; // A adapter
	EnrIdx record= {-1}; // A adapter
	int nbElem=0;
	int nbEnreg=0;
	int offset=0;
	IdxRecord * index=NULL;

// Calculer le nombre d'enregistrements dans le fichier
	fichier=fopen(fileName,"rb+");
	if (fichier!=NULL)
	{
		offset=0;
		if(fseek(fichier,offset,SEEK_END)==0)
		{
			nbEnreg=ftell(fichier)/sizeof(EnrIdx);
// Allouer la memoire pour le tableau index
			if(allocateIdx(&index,nbEnreg)==0)
			{
// Lire le fichier en inserant les enregistrements d'index
				offset=0;
				if(fseek(fichier,offset,SEEK_SET)==0)
				{
					nbElem=0;
// Lire un enregistrement dans le fichier
					while(fread(&record,sizeof(EnrIdx),1,fichier))
					{
// Copier les informations necessaires dans l'enregistrement d'index
// A adapter!!!
						indexRecord.idxDummy=record.dummy;
						indexRecord.offset=nbElem;
// Inserer l'enregistrement dans l'index
						insertIdx(index,&indexRecord,nbElem);
						nbElem++;
					}
				}
			}
		}
		fclose(fichier);
	}
	return index;
}

/***********************************************************/
/* Inserer un enregistrement dans un index */
/* IN : pointeur sur l'index, pointeur sur la valeur */
/* a inserer, nombre d'elements deja dans l'index */
/* OUT : */
/* -1 en cas d'erreur */
/***********************************************************/
int insertIdx(IdxRecord * index,IdxRecord * indexRecord,int nbElem)
{
	int i=nbElem;
	int erreur=0;

	while((i>0)&&(compareIdxEnreg(&index[i-1],indexRecord)>0))
	{
		memcpy(&index[i],&index[i-1],sizeof(IdxRecord));
		i--;
	}
	memcpy(&index[i],indexRecord,sizeof(IdxRecord));

	return erreur;
}

/***********************************************************/
/* Comparer le contenu de deux enregistrements d'index */
/* pour les classer */
/* IN : pointeurs vers les enregistrements a comparer */
/* OUT : >0 si rec1>rec2 */
/* =0 si rec1=rec2 */
/* <0 si rec1<rec2 */
/***********************************************************/
int compareIdxEnreg(IdxRecord * rec1,IdxRecord * rec2)
{
	int result=0;
	/*** A implementer en fonction du contexte ***/
	result=(rec1->idxDummy-rec2->idxDummy);

	return result;
}

/***********************************************************/
/* Creer et bidonner un fichier indexe */
/* IN : nom du fichier a creer, nombre d'enregistrements */
/* OUT : 0 en cas de succes, -1 en cas d'erreur */
/***********************************************************/
int writeFileIdx(char * fileName, EnrIdx * record)
{
	FILE * fichier = NULL;
	EnrIdx tempRecord= {0};
	int erreur=0;

// Trouver une place libre grace a l'index

// Ecrire l'enregistrement dans le fichier

// Ajouter l'enregistrement d'index correspondant

	return erreur;
}

/***********************************************************/
/* Lire un enregistrement dans un fichier indexe */
/* IN : nom du fichier, pointeur vers l'enregistrement */
/* position de l'enregistrement */
/* OUT : 0 en cas de succes, -1 en cas d'erreur */
/***********************************************************/
int readFileIdx(char * fileName,EnrIdx * record,long position)
{
	FILE * fichier = NULL;
	int erreur=0;
	int offset = position*sizeof(EnrIdx); // offset de l'enregistrement a lire

	fichier=fopen(fileName,"rb");
	if (fichier!=NULL)
	{
		if(fseek(fichier,offset,SEEK_SET)==0)
		{
			if(fread(record,sizeof(EnrIdx),1,fichier)==1)
				erreur=0;
			else
				erreur=-1;
		}
		else
			erreur=-1;
		fclose(fichier);
	}
	else
		erreur=-1;

	return erreur;
}

/***********************************************************/
/* Chercher un enregistrement dans un index */
/* IN : pointeur sur la valeur cherchee, nombre */
/* d'elements, position dans le fichier */
/* de l'enregistrement trouve */
/* OUT : numero de l'enregistrement trouve, */
/* INT_MAX si pas trouve */
/* -1 en cas d'erreur */
/***********************************************************/

