#include "Reservation.hpp"

Reservation::Reservation()
    : _num(0)
    , _numClient(0)
    , _numVeh(0)
    , _dateDep(QDate::fromString("010101", "ddmmyy"))
    , _numPlace(0)
{}

Reservation::Reservation(qint32 num)
    : _num(num)
    , _numClient(0)
    , _numVeh(0)
    , _dateDep(QDate::fromString("010101", "ddmmyy"))
    , _numPlace(0)
{}

Reservation::Reservation(qint32 num, qint32 numCli, qint32 numVeh, QDate dateDep)
    : _num(num)
    , _numClient(numCli)
    , _numVeh(numVeh)
    , _dateDep(dateDep)
    , _numPlace(0)
{}

Reservation Reservation::createFromQuery(QSqlQuery &query)
{
    Reservation res;
    res.setNum(query.value("NUMRES").toInt());
    res.setNumClient(query.value("NUMCLI").toInt());
    res.setNumVeh(query.value("NUMVEH").toInt());
    res.setDateDep(query.value("DATEDEPART").toDate());
    res.setDateRes(query.value("DATERES").toDate());
    res.setNumPlace(query.value("NUMPLACE").toInt());
    res.setFraisTotal(query.value("FRAISTOTAL").toInt());
    res.setAvance(query.value("AVANCE").toInt());

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

qint32 Reservation::getNumClient() const
{
    return _numClient;
}

void Reservation::setNumClient(qint32 numClient)
{
    _numClient = numClient;
}

QDate Reservation::getDateDep() const
{
    return _dateDep;
}

void Reservation::setDateDep(const QDate &dateDep)
{
    _dateDep = dateDep;
}

float Reservation::getFraisTotal() const
{
    return _fraisTotal;
}

void Reservation::setFraisTotal(float fraisTotal)
{
    _fraisTotal = fraisTotal;
}

float Reservation::getAvance() const
{
    return _avance;
}

void Reservation::setAvance(float avance)
{
    _avance = avance;
}

qint32 Reservation::getNumVeh() const
{
    return _numVeh;
}

void Reservation::setNumVeh(qint32 numVeh)
{
    _numVeh = numVeh;
}

qint32 Reservation::getNumPlace() const
{
    return _numPlace;
}

void Reservation::setNumPlace(qint32 NumPlace)
{
    _numPlace = NumPlace;
}
