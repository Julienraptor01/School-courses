/*********************************************************************/
/* Manipulation de fichiers binaires. */
/* Organisation sequentielle physique. */
/* Taille d'enregistrement fixe. */
/* Adressage par numero d'enregistrement (de 0 a nbenreg-1 */
/*********************************************************************/
typedef struct
{
 int dummy; // contenu fictif a adapter
} EnrSeqPhys;

int createFileSeqPhys(char *); // Creer fichier SeqPhys
int writeFileSeqPhys(char *,EnrSeqPhys *); // Ajouter enregistrement SeqPhys
int readFileSeqPhys(char *,EnrSeqPhys *,long); // Lire enregistrement SeqPhys
int nbRecordsFileSeqPhys(char *); // Nombre d'enregistrements dans le fichier
int searchFileSeqPhys(char *,char *,long,EnrSeqPhys *); // Chercher un enregistrement SeqPhys
int updateFileSeqPhys(char *,long, EnrSeqPhys *); // Modifier un enregistrement SeqPhys
