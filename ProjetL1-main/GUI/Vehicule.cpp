#include "Vehicule.hpp"

Vehicule::Vehicule()
    : _num(0)
{}

Vehicule::Vehicule(qint32 num)
    : _num(num)
{}

Vehicule::Vehicule(qint32 num, qint32 nbPlace)
    : _num(num)
    , _nbPlace(nbPlace)
{}

Vehicule Vehicule::createFromQuery(QSqlQuery &query)
{
    Vehicule veh;
    veh.setNum(query.value("NOMBREPLACES").toInt());
    veh.setNbPlace(query.value("NOMBREPLACES").toInt());
    veh.setNbPlaceDispo(query.value("NOMBREPLACESDISPO").toInt());

    return veh;
}

qint32 Vehicule::getNum() const
{
    return _num;
}

void Vehicule::setNum(qint32 num)
{
    _num = num;
}

qint32 Vehicule::getNbPlace() const
{
    return _nbPlace;
}

void Vehicule::setNbPlace(qint32 nbPlace)
{
    _nbPlace = nbPlace;
}

qint32 Vehicule::getNbPlaceDispo() const
{
    return _nbPlaceDispo;
}

void Vehicule::setNbPlaceDispo(qint32 nbPlaceDispo)
{
    _nbPlaceDispo = nbPlaceDispo;
}

void Vehicule::bookPlace(qint32 nbPlace)
{
    if (_nbPlaceDispo < nbPlace)
        throw std::invalid_argument("No more place");

    _nbPlaceDispo -= nbPlace;
}
