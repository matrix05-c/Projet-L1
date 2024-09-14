#include "Reservation.hpp"

Reservation::Reservation()
    : _num(0)
    , _numClient(0)
    , _numVehicule(0)
    , _dateDep(QDate::fromString("010101", "ddmmyy"))
{}

Reservation::Reservation(qint32 num)
    : _num(num)
    , _numClient(0)
    , _numVehicule(0)
    , _dateDep(QDate::fromString("010101", "ddmmyy"))
{}

Reservation::Reservation(qint32 num, qint32 numCli, qint32 numVeh, QDate dateDep)
    : _num(num)
    , _numClient(numCli)
    , _numVehicule(numVeh)
    , _dateDep(dateDep)
{}

Reservation Reservation::createFromQuery(QSqlQuery &query)
{
    Reservation res;
    res.setNum(query.value("NUMRESERVATION").toInt());
    res.setNumClient(query.value("NUMCLIENT").toInt());
    res.setNumVehicule(query.value("NUMVEHICULE").toInt());
    res.setDateDep(query.value("DATEDEPART").toDate());
    res.setDateRes(query.value("DATERESERVATION").toDate());
    res.setNbPers(query.value("NOMBREPERSONNE").toInt());

    return res;
}

qint32 Reservation::getNum() const
{
    return _num;
}

void Reservation::setNum(qint32 num)
{
    _num = num;
}

QDate Reservation::getDateRes() const
{
    return _dateRes;
}

void Reservation::setDateRes(const QDate &dateRes)
{
    _dateRes = dateRes;
}

qint32 Reservation::getNbPers() const
{
    return _nbPers;
}

void Reservation::setNbPers(qint32 nbPers)
{
    _nbPers = nbPers;
}

qint32 Reservation::getNumClient() const
{
    return _numClient;
}

void Reservation::setNumClient(qint32 numClient)
{
    _numClient = numClient;
}

qint32 Reservation::getNumVehicule() const
{
    return _numVehicule;
}

void Reservation::setNumVehicule(qint32 numVehicule)
{
    _numVehicule = numVehicule;
}

QDate Reservation::getDateDep() const
{
    return _dateDep;
}

void Reservation::setDateDep(const QDate &dateDep)
{
    _dateDep = dateDep;
}
