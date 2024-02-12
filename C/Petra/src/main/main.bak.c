/* ************************************************************

	TEST ELEMENTAIRE

	POUR LA COMMANDE DU PETRA.


	IN.PR.E.S.
	LABORATOIRE D'INFORMATIQUE INDUSTRIELLE.

	POSIX - DIGITAL UNIX POSIX 1003.1 ET 1003.1b

   ************************************************************ */

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

struct ACTUATEURS
{
	unsigned CP : 2; // Carrier Position
	unsigned C1 : 1; // Conveyor 1
	unsigned C2 : 1;
	unsigned PV : 1; // Plunger Vacuum
	unsigned PA : 1; // Plunger Activate
	unsigned AA : 1; // Arm Activate
	unsigned GA : 1; // Grapple Activate
};
union
{
	struct ACTUATEURS act;
	unsigned char byte;
} u_act;

struct CAPTEURS
{
	unsigned L1 : 1; // Length 1
	unsigned L2 : 1; // Length 2
	unsigned T : 1;	 /* cablé H */
	unsigned S : 1;	 // Slot
	unsigned CS : 1; // Carrier Stable
	unsigned AP : 1; // Arm Position
	unsigned PP : 1; // Plunger Position
	unsigned DE : 1; // Dispenser Empty
	/*                 unsigned H1 : 1;
					 unsigned H2 : 1;
					 unsigned H3 : 1;
					 unsigned H4 : 1;
					 unsigned H5 : 1;
					 unsigned H6 : 1;
					 unsigned    : 2;	*/
};

union
{
	struct CAPTEURS capt;
	unsigned char byte;
} u_capt;

main()
{
	int fd_petra_in, fd_petra_out;
	int rc, cpt;

	u_act.byte = 0x00;
	printf("actuateurs : %x \n\r", u_act.byte);

	u_act.act.PV = 1;
	printf("actuateurs : %x \n\r", u_act.byte);

	fd_petra_out = open("/dev/actuateursPETRA", O_WRONLY);
	if (fd_petra_in == -1)
	{
		perror("MAIN : Erreur ouverture PETRA_OUT");
		return 1;
	}
	else
		printf("MAIN: PETRA_OUT opened\n");

	fd_petra_in = open("/dev/capteursPETRA", O_RDONLY);
	if (fd_petra_in == -1)
	{
		perror("MAIN : Erreur ouverture PETRA_IN");
		return 1;
	}
	else
		printf("MAIN: PETRA_IN opened\n");

	for (cpt = 0; cpt < 10; cpt++)
	{
		sleep(1);

		read(fd_petra_in, &u_capt.byte, 1);
		printf("CAPTEURS = %x \r\n", u_capt.byte);
	}

	for (cpt = 0; cpt < 10; cpt++)
	{
		printf("ACTUATEURS ecriture d'un 1 \n\r");
		u_act.act.PV = 1;

		rc = write(fd_petra_out, &u_act.byte, 1);
		if (rc <= 0)
		{
			printf("rc: %d\n ", rc);
			perror("");
		}

		sleep(1);

		printf("ACTUATEURS ecriture d'un 0 \n\r");
		u_act.act.PV = 0;
		rc = write(fd_petra_out, &u_act.byte, 1);
		if (rc <= 0)
		{
			printf("rc: %d\n ", rc);
			perror("");
		}

		sleep(1);
	}

	u_act.byte = 0x00;
	write(fd_petra_out, &u_act.byte, 1);
	close(fd_petra_in);
	close(fd_petra_out);
}
