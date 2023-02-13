/*********************************************************************/
/* Manipulation de fichiers binaires. */
/* Organisation sequentielle physique. */
/* Taille d'enregistrement fixe. */
/* Adressage par numero d'enregistrement (de 0 a nbenreg-1) */
/*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "OrgSeqPhys.h"

int main()
{
	//FILE* fichier = NULL; // pointeur sur le fichier
	//char* fileName = NULL; // nom du fichier
	return 0;
}

/***********************************************************/
/* Creer un fichier sequentiel physique */
/* IN : nom du fichier a creer */
/* OUT : 0 en cas de succes, -1 en cas d'erreur */
/***********************************************************/
int createFileSeqPhys(char* fileName)
{
	FILE * fichier = NULL;
	int erreur = -1;
	fichier = fopen(fileName, "wb");
	if (fichier!=NULL)
	{
		fclose(fichier);
		erreur = 0;
	}
	return erreur;
}

/***********************************************************/
/* Ajouter un enregistrement a un fichier sequentiel */
/* physique */
/* IN : nom du fichier, pointeur vers l'enregistrement */
/* OUT : 0 en cas de succes, -1 en cas d'erreur */
/***********************************************************/
int writeFileSeqPhys(char* fileName, EnrSeqPhys* record)
{
	FILE* fichier = NULL;
	int erreur = 0;

	fichier = fopen(fileName, "ab");
	if (fichier != NULL)
	{
		if (fwrite(record, sizeof(EnrSeqPhys), 1, fichier) == 1)
			erreur = 0;
		else
			erreur = -1;
		fclose(fichier);
	}
	else
		erreur = -1;

	return erreur;
}

/***********************************************************/
/* Lire un enregistrement dans un fichier sequentiel */
/* physique */
/* IN : nom du fichier, pointeur vers l'enregistrement */
/* position de l'enregistrement */
/* OUT : 0 en cas de succes, -1 en cas d'erreur */
/***********************************************************/
int readFileSeqPhys(char* fileName, EnrSeqPhys* record, long position)
{
	FILE* fichier = NULL;
	int erreur = 0;
	int offset = position * sizeof(EnrSeqPhys); // offset de l'enregistrement a lire

	fichier = fopen(fileName, "rb");
	if (fichier != NULL)
	{
		if (fseek(fichier, offset, SEEK_SET) == 0)
		{
			if (fread(record, sizeof(EnrSeqPhys), 1, fichier) == 1)
				erreur = 0;
			else
				erreur = -1;
		}
		else
			erreur = -1;
		fclose(fichier);
	}
	else
		erreur = -1;

	return erreur;
}

/***********************************************************/
/* Donner le nombre d'enregistrements dans un fichier */
/* sequentiel physique */
/* IN : nom du fichier */
/* OUT : nombre d'enregistrements dans le fichier, */
/* -1 en cas d'erreur */
/***********************************************************/
int nbRecordsFileSeqPhys(char* fileName)
{
	FILE* fichier = NULL;
	int erreur = 0;
	long position = 0;

	fichier = fopen(fileName, "rb");
	if (fichier != NULL)
	{
		if (fseek(fichier, 0, SEEK_END) == 0)
		{
			position = ftell(fichier);
			erreur = position / sizeof(EnrSeqPhys);
		}
		else
			erreur = -1;
		fclose(fichier);
	}
	else
		erreur = -1;

	return erreur;
}

/***********************************************************/
/* Chercher un enregistrement dans un fichier sequentiel */
/* physique */
/* IN : nom du fichier, pointeur sur la valeur cherchee, */
/* position de depart pour la recherche, */
/* pointeur sur l'enregistrement trouve */
/* OUT : numero de l'enregistrement trouve, */
/* INT_MAX si pas trouve */
/* -1 en cas d'erreur */
/***********************************************************/
int searchFileSeqPhys(char* fileName, char* value, long startpos, EnrSeqPhys* record)
{
	FILE* fichier = NULL;
	EnrSeqPhys temp = { 0 }; // penser a initialiser cette variable correctement
	int erreur = 0;
	int found = 0;

	fichier = fopen(fileName, "rb");
	if (fichier != NULL)
	{
		if (fseek(fichier, startpos * sizeof(EnrSeqPhys), SEEK_SET) == 0)
		{
			while ((fread(&temp, sizeof(EnrSeqPhys), 1, fichier) != 0) && (!found))
			{
				// Comparer l'enregistrement lu avec la valeur cherchee
				if (strcmp(value, temp->dummy) == 0)
					//TODO
				{
					found = 1;
				}
			}
			if (found != 0)
			{
				memcpy(record, &temp, sizeof(EnrSeqPhys));
				erreur = (ftell(fichier) / sizeof(EnrSeqPhys)) - 1;
			}
			else
				erreur = INT_MAX;
		}
		else
			erreur = -1;
		fclose(fichier);
	}
	else
		erreur = -1;

	return erreur;
}

/***********************************************************/
/* Modifier un enregistrement dans un fichier sequentiel */
/* physique */
/* IN : nom du fichier, numero de l'enregistrement */
/* a modifier, pointeur sur l'enregistrement */
/* mis a jour */
/* OUT : 0 en cas de succes, -1 en cas d'erreur */
/***********************************************************/
int updateFileSeqPhys(char* fileName, long position, EnrSeqPhys* record)
{
	FILE* fichier = NULL;
	int erreur = 0;

	fichier = fopen(fileName, "rb+");
	if (fichier != NULL)
	{
		if (fseek(fichier, position * sizeof(EnrSeqPhys), SEEK_SET) == 0)
		{
			if (fwrite(record, sizeof(EnrSeqPhys), 1, fichier) == 1)
				erreur = 0;
			else
				erreur = -1;
		}
		else
			erreur = -1;
		fclose(fichier);
	}
	else
		erreur = -1;

	return erreur;
}
