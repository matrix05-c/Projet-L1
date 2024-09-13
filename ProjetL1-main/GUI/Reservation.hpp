/**
 * @file Reservation.cpp
 * @brief Ce fichier contient l'implémentation du table RESERVATION.
 * @date September 10, 2024
 */


#ifndef RESERVATION_HPP
#define RESERVATION_HPP

// Standard library

#include <QtCore/QString>
#include <QtCore/QVariant>

// Database library
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

// Entities header
#include "Client.hpp"
#include "Vehicule.hpp"
#include "Calendrier.hpp"


class Reservation
{
public:
    /**
     * @brief Constructeur par defaut
     */
    Reservation();
    /**
     * @brief Surcharge du constructeur
     * @param num: Identifiant du reservation
     */
    Reservation(qint32 num);
    /**
     * @brief Surcharge du constructeur
     * @param num: le clé primaire du reservation
     * @param client: Identifiant du client qui a fait la réservation
     * @param vehicule: Identifiant du véhicule resérver
     * @param dateDepart: Date de départ
     */
    Reservation(qint32 num, qint32 numCli, qint32 numVeh, QDate dateDep);

    /**
     * @brief fonction static pour l'éxtraction des données à partir du query du DB
     * @param query: le QSqlQuery issue du DB où on stock les données
     * @return un instance de l'object de type Client créer
     */
    static Reservation createFromQuery(QSqlQuery &query);

    // Getter
    qint32 getNum() const;
    qint32 getNumClient() const;
    qint32 getNumVehicule() const;
    QDate getDateDep() const;
    QDate getDateRes() const;
    qint32 getNbPers() const;

    // Setter
    void setNum(qint32 num);
    void setDateRes(const QDate &dateRes);
    void setNbPers(qint32 nbPers);
    void setNumClient(qint32 numClient);
    void setNumVehicule(qint32 numVehicule);
    void setDateDep(const QDate &dateDep);

private:
    qint32 _num;
    qint32 _numClient;
    qint32 _numVehicule;
    QDate _dateDep;
    QDate _dateRes;
    qint32 _nbPers;

};

#endif // RESERVATION_HPP
