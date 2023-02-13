/*********************************************************************/
/* Manipulation de fichiers binaires. */
/* Organisation sequentielle logique. */
/* Taille d'enregistrement fixe. */
/* Adressage par numero d'enregistrement (de 0 a nbenreg-1) */
/* Fichier non bidonné */
/*********************************************************************/
typedef struct
{
	// Adapter cette structure aux besoins de l'application
	int dummy;
} PayLoad;

typedef struct
{
	long PTO;
	long PTL;
} Header; // structure destinee a contenir PTO et PTL

typedef struct
{
	PayLoad payload; // contenu fictif a adapter
	long offset; // numero de l'enregistrement suivant dans l'ordre logique choisi. -1 pour le dernier.
} EnrSeqLog;

int createFileSeqLog(char *); // Creer fichier SeqLog
int writeFileSeqLog(char *,PayLoad *); // Ajouter enregistrement SeqLog
int comparePayLoad(PayLoad *,PayLoad *); // Comparer le contenu de deux enregistrements pour les classer
int searchFileSeqLog(char *,char *,long,PayLoad *); // Chercher un enregistrement SeqLog
int deleteFileSeqLog(char *,long deletepos); // Supprimer un enregistrement SeqLog
