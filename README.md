# Gestion de Réservation de Véhicule

## Description

Ce projet permet de gérer les réservations de véhicules en utilisant Qt pour l'interface utilisateur et MySQL/MariaDB pour la gestion de la base de données. Il offre une solution complète pour créer, modifier, supprimer, lister et rechercher des réservations.

## Fonctionnalités

- **Faire une réservation :** Ajouter de nouvelles réservations de véhicules dans le système.
- **Modifier une réservation :** Modifier les détails d'une réservation existante.
- **Supprimer une réservation :** Supprimer une réservation du système.
- **Lister les réservations :** Afficher toutes les réservations enregistrées.
- **Rechercher une réservation :** Rechercher une réservation spécifique en fonction de critères définis.

## Technologies Utilisées

- **Qt** : Pour le développement de l'interface utilisateur.
- **MySQL/MariaDB** : Pour la gestion de la base de données.
- **Windesign** : Pour la modélisation des données.
- **Inkscape** : Pour la création de maquettes et la conception graphique.

## Prérequis

- **Qt 5.15+** (ou Qt 6.x)
- **C++** (compatible avec la version Qt utilisée)
- **MySQL/MariaDB** (pour la base de données)
- **Git** (pour le contrôle de version)
- **Windesign** (pour consulter et éditer les modèles)
- **Inkscape** (pour consulter et éditer les maquettes)

## Installation

1. **Cloner le dépôt GitHub :**
    ```bash
   git clone https://github.com/votre-utilisateur/gestion-reservation-vehicule.git
   cd gestion-reservation-vehicule
   ```

2. **Initialiser la base de donnée :**
    ```bash
    mysql -u [nom utilisateur] -p
    ```
    Entrer le mot de passe de l'utilisateur.  
    Ensuite dans **MySQL/MariaDB** :
    ```bash
    > source ./Model/reservation.SQL;
    ```

## Structure du projet
- **Mockup/ :** Contient des maquette de l'intnrface graphique. Réaliser par Inkscape.
- **Models/ :** Contient les modèles conceptuel et logique pour la structure de la base de données.
- **GUI/ :** Contient les codes source de l'interface graphique de l'application.

## Contributeur
void
