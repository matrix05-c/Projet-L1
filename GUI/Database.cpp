#include "Database.hpp"

Database::Database() {}

bool Database::setupConnection()
{
    _db = new QSqlDatabase();
    *_db = QSqlDatabase::addDatabase("QMYSQL");
    _db->setDatabaseName("reservation");
    _db->setHostName("localhost");
    return _db->open("root", "root");
}

void Database::setupQuery()
{
    _query = new QSqlQuery(*_db);
}

QMap<qint32, Client> Database::getClientList()
{
    QMap<qint32, Client> clientList;

    _query->prepare("SELECT * FROM CLIENT");

    while (_query->next()) {
        Client tempCli =
            Client::createFromQuery(*_query);
        clientList[tempCli.getNum()] = tempCli;
    }

    return clientList;
}

QMap<qint32, Vehicule> Database::getVehiculeList()
{
    QMap<qint32, Vehicule> vehiculeList;

    _query->prepare("SELECT * FROM VEHICULE");

    while (_query->next()) {
        Vehicule tempRes =
            Vehicule::createFromQuery(*_query);
        vehiculeList[tempRes.getNum()] = tempRes;
    }

    return vehiculeList;
}

QVector<Calendrier> Database::getCalendrierList()
{
    QVector<Calendrier> calList;

    _query->prepare("SELECT * FROM CALENDRIER");

    while (_query->next()) {
        calList.append(
            Calendrier::createFromQuery(*_query)
        );
    }

    return calList;
}

QMap<qint32, Reservation> Database::getReservationList()
{
    QMap<qint32, Reservation> resList;

    _query->prepare("SELECT * FROM RESERVATION");

    while (_query->next()) {
        Reservation tempRes =
            Reservation::createFromQuery(*_query);
        resList[tempRes.getNum()] = tempRes;
    }

    return resList;
}

bool Database::addClient(Client client)
{
    _query->prepare("INSERT INTO CLIENT VALUE (?, ?, ?, ?)");
    _query->addBindValue(client.getNum());
    _query->addBindValue(client.getNom());
    _query->addBindValue(client.getAdresse());
    _query->addBindValue(client.getTelephone());

    return _query->exec();
}

bool Database::addVehicule(Vehicule vehicule)
{
    _query->prepare("INSERT INTO VEHICULE VALUE (?, ?, ?)");
    _query->addBindValue(vehicule.getNum());
    _query->addBindValue(vehicule.getNbPlace());
    _query->addBindValue(vehicule.getNbPlaceDispo());

    return _query->exec();
}

bool Database::addCalendrier(Calendrier calendrier)
{
    _query->prepare("INSERT INTO CALENDRIER VALUE (?)");
    _query->addBindValue(calendrier.getDateDep());

    return _query->exec();
}

bool Database::addReservation(Reservation reservation)
{
    _query->prepare("INSERT INTO VEHICULE VALUE (?, ?, ?, ?, ?, ?)");
    _query->addBindValue(reservation.getNum());
    _query->addBindValue(reservation.getNumClient());
    _query->addBindValue(reservation.getNumVehicule());
    _query->addBindValue(reservation.getDateDep());
    _query->addBindValue(reservation.getDateRes());

    return _query->exec();
}
