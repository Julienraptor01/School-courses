CREATE OR REPLACE PROCEDURE ListeEmpPro AS 
CURSOR CurEmployesProjets IS
SELECT RPAD(nom,15,' ') as nom,
       RPAD(prenom,10,' ') as prenom,
       RPAD(nompro,40,' ') as nompro	 
FROM employes, emppro,projets
WHERE employes.numsecu = emppro.numsecu 
 	AND emppro.numpro = projets.numpro
ORDER BY nompro;
BEGIN
	FOR UnTuple IN CurEmployesProjets
	LOOP
	DBMS_OUTPUT.PUT_LINE(UnTuple.nompro||UnTuple.nom 
       ||UnTuple.prenom);
	END LOOP;
EXCEPTION
	WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE(SQLERRM);
END ListeEmpPro;

