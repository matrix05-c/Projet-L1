DROP DATABASE IF EXISTS reservation;

CREATE DATABASE IF NOT EXISTS reservation;
USE reservation;
# -----------------------------------------------------------------------------
#       TABLE : VEHICULE
# -----------------------------------------------------------------------------

CREATE TABLE IF NOT EXISTS VEHICULE
 (
   NUMVEHICULE INTEGER NOT NULL  ,
   NOMBREPLACES INTEGER NOT NULL  ,
   NOMBREPLACESDISPO INTEGER NOT NULL  
   , PRIMARY KEY (NUMVEHICULE) 
 ) 
 comment = "";

# -----------------------------------------------------------------------------
#       TABLE : CLIENT
# -----------------------------------------------------------------------------

CREATE TABLE IF NOT EXISTS CLIENT
 (
   NUMCLIENT INTEGER NOT NULL  ,
   NOM CHAR(32) NOT NULL  ,
   ADRESSE CHAR(32) NULL  ,
   TELEPHONE CHAR(11) NULL  
   , PRIMARY KEY (NUMCLIENT) 
 ) 
 comment = "";

# -----------------------------------------------------------------------------
#       TABLE : CALENDRIER
# -----------------------------------------------------------------------------

CREATE TABLE IF NOT EXISTS CALENDRIER
 (
   DATEDEPART DATE NOT NULL  
   , PRIMARY KEY (DATEDEPART) 
 ) 
 comment = "";

# -----------------------------------------------------------------------------
#       TABLE : RESERVATION
# -----------------------------------------------------------------------------

CREATE TABLE IF NOT EXISTS RESERVATION
 (
   NUMRESERVATION INTEGER NOT NULL  ,
   NUMCLIENT INTEGER NOT NULL  ,
   NUMVEHICULE INTEGER NOT NULL  ,
   DATEDEPART DATE NOT NULL  ,
   DATERESERVATION DATETIME NOT NULL  ,
   NOMBREPERSONNE INTEGER NOT NULL  
   , PRIMARY KEY (NUMRESERVATION) 
 ) 
 comment = "";


# -----------------------------------------------------------------------------
#       CREATION DES REFERENCES DE TABLE
# -----------------------------------------------------------------------------


ALTER TABLE RESERVATION 
  ADD FOREIGN KEY FK_RESERVATION_CLIENT (NUMCLIENT)
      REFERENCES CLIENT (NUMCLIENT) ;


ALTER TABLE RESERVATION 
  ADD FOREIGN KEY FK_RESERVATION_VEHICULE (NUMVEHICULE)
      REFERENCES VEHICULE (NUMVEHICULE) ;


ALTER TABLE RESERVATION 
  ADD FOREIGN KEY FK_RESERVATION_CALENDRIER (DATEDEPART)
      REFERENCES CALENDRIER (DATEDEPART) ;

