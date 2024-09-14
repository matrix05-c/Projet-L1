#include "Database.hpp"

Database::Database()
    : _db(nullptr)
    , _query(nullptr)
{}

bool Database::setupConnection()
{
    if (_db) return false;

    _db = new QSqlDatabase();
    *_db = QSqlDatabase::addDatabase("QMYSQL");
    _db->setDatabaseName("projet_fin_annee");
    _db->setHostName("localhost");
    return _db->open("root", "root");
}

void Database::setupQuery()
{
    if (_query) return;
    _query = new QSqlQuery(*_db);
}

void Database::disconnect()
{
    if (_query != nullptr) {
        _query->clear();
        delete _query;
    }
    if (_db != nullptr) {
        _db->close();
        delete _db;
    }
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
        Vehicule tempVeh =
            Vehicule::createFromQuery(*_query);
        vehiculeList[tempVeh.getNum()] = tempVeh;
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
    _query->prepare("INSERT INTO CLIENT VALUE (?, ?, ?, ?, ?)");
    _query->addBindValue(client.getNum());
    _query->addBindValue(client.getNom());
    _query->addBindValue(client.getCharSexe());
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
    _query->prepare("INSERT INTO RESERVATION VALUE (?, ?, ?, ?, ?, ?)");
    _query->addBindValue(reservation.getNum());
    _query->addBindValue(reservation.getNumVeh());
    _query->addBindValue(reservation.getNumClient());
    _query->addBindValue(reservation.getDateDep());
    _query->addBindValue(reservation.getDateRes());
    _query->addBindValue(reservation.getFraisTotal());
    _query->addBindValue(reservation.getAvance());
    _query->addBindValue(reservation.getNumPlace());

    return _query->exec();
}
