-- Soit le schéma BD contenant les tables Auteurs, Ouvrages et AEcrit.

-- Donner le résultat de la commande :

SELECT 'GRANT SELECT ON ' || table_name || ' TO SCOTT ;'
FROM user_tables
ORDER BY 1;

-- Les éléments de la réponse doivent être donnés dans l’ordre


GRANT SELECT ON AUTEURS TO SCOTT ;
GRANT SELECT ON OEUVRES TO SCOTT ;
GRANT SELECT ON AECRIT TO SCOTT ;