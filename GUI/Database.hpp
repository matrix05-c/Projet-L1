#ifndef DATABASE_HPP
#define DATABASE_HPP


// Standard library
#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtCore/QVector>
#include <QtCore/QMap>

// Database library
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

// Entities header
#include "Client.hpp"
#include "Vehicule.hpp"
#include "Calendrier.hpp"
#include "Reservation.hpp"


class Database
{
public:
    Database();

    QMap<qint32, Client> getClientList();
    QMap<qint32, Vehicule> getVehiculeList();
    QVector<Calendrier> getCalendrierList();
    QMap<qint32, Reservation> getReservationList();

    bool addClient(Client client);
    bool addVehicule(Vehicule vehicule);
    bool addCalendrier(Calendrier calendrier);
    bool addReservation(Reservation reservation);

    bool setupConnection();
    void setupQuery();

    void disconnect();

private:
    QSqlDatabase *_db;
    QSqlQuery *_query;
};

#endif // DATABASE_HPP
