#ifndef RESERVATION_HPP
#define RESERVATION_HPP

// Standard library
#include <QtCore/QBEInteger>
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
     * @param numCli: Identifiant du client qui a fait la réservation
     * @param numVeh: Identifiant du vehicule reserver
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
    qint32 getNumVeh() const;
    QDate getDateDep() const;
    QDate getDateRes() const;
    qint32 getNumPlace() const;
    float getFraisTotal() const;
    float getAvance() const;

    // Setter
    void setNum(qint32 num);
    void setDateRes(const QDate &dateRes);
    void setNumClient(qint32 numClient);
    void setNumVeh(qint32 numVeh);
    void setDateDep(const QDate &dateDep);
    void setNumPlace(qint32 NumPlace);
    void setFraisTotal(float fraisTotal);
    void setAvance(float avance);


private:
    qint32 _num;
    qint32 _numClient;
    qint32 _numVeh;
    QDate _dateDep;
    QDate _dateRes;
    qint32 _numPlace;
    float _fraisTotal;
    float _avance;

};

#endif // RESERVATION_HPP
