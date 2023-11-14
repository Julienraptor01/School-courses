CREATE OR REPLACE PROCEDURE listeemppro AS
	CURSOR curemployesprojets IS
	SELECT rpad(nom, 15, ' ')AS nom, rpad(prenom, 10, ' ')AS prenom, rpad(nompro, 40, ' ')AS nompro
	FROM employes, emppro, projets
	WHERE employes.numsecu = emppro.numsecu AND emppro.numpro = projets.numpro
	ORDER BY nompro;
BEGIN
	FOR untuple IN curemployesprojets LOOP
		dbms_output.put_line(untuple.nompro || untuple.nom || untuple.prenom);
	END LOOP;
EXCEPTION
	WHEN OTHERS THEN dbms_output.put_line(sqlerrm);
END listeemppro;