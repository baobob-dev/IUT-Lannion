DROP SCHEMA parcoursup CASCADE;
CREATE SCHEMA parcoursup;
SET SCHEMA 'parcoursup';

CREATE TABLE formation (
    cod_aff_form                    VARCHAR(20) not null,
    filiere_libelle_detaille        VARCHAR(20) not null,
    coordonnees_gps                 VARCHAR(20) not null,
    list_com                        VARCHAR(20) not null,
    concours_communs_banque_epreuve VARCHAR(20) not null,
    url_formation                   VARCHAR(20) not null,
    tri                             VARCHAR(20) not null,
    CONSTRAINT formation_pk PRIMARY KEY (cod_aff_form)
);

CREATE TABLE filiere (
    filiere_id                   INT         not null,
    filiere_libelle              VARCHAR(20) not null,
    filiere_libelle_tres_abrege  VARCHAR(20) not null,
    filiere_libelle_abrege       VARCHAR(20) not null,
    filiere_libelle_detaille_bis VARCHAR(20) not null,
    CONSTRAINT filiere_pk PRIMARY KEY (filiere_id)
);

CREATE TABLE academie (
    academie_nom VARCHAR(20) not null,
    CONSTRAINT academie_pk PRIMARY KEY (academie_nom)
);

CREATE TABLE etablissement (
    etablissement_code_uai VARCHAR(20) not null,
    etablissement_nom      VARCHAR(20) not null,
    etablissement_statut   VARCHAR(20) not null,
    CONSTRAINT etablissement_pk PRIMARY KEY (etablissement_code_uai)
);

CREATE TABLE commune (
    commune_nom VARCHAR(20)
);

CREATE TABLE departement (
    departement_code VARCHAR(20) not null,
    departement_nom  VARCHAR(20) not null,
    CONSTRAINT departement_pk PRIMARY KEY (departement_nom)
);

CREATE TABLE region (
    region_nom VARCHAR(20) not null,
    CONSTRAINT region_pk PRIMARY KEY (region_nom)
);

---

