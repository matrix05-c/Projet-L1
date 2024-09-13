#include "Client.hpp"

Client::Client()
    : _num(0)
{}

Client::Client(qint32 num)
    : _num(num)
{}

Client::Client(qint32 num, QString nom)
    : _num(num)
    , _nom(nom)
{}

Client Client::createFromQuery(QSqlQuery &query)
{
    Client client;
    client.setNum(query.value("NUMCLIENT").toInt());
    client.setNom(query.value("NOM").toString());
    client.setAdresse(query.value("ADRESSE").toString());
    client.setTelephone(query.value("TELEPHONE").toString());

    return client;
}

qint32 Client::getNum() const
{
    return _num;
}

void Client::setNum(qint32 num)
{
    _num = num;
}

QString Client::getNom() const
{
    return _nom;
}

void Client::setNom(const QString &nom)
{
    _nom = nom;
}

QString Client::getAdresse() const
{
    return _adresse;
}

void Client::setAdresse(const QString &adresse)
{
    _adresse = adresse;
}

QString Client::getTelephone() const
{
    return _telephone;
}

void Client::setTelephone(const QString &telephone)
{
    _telephone = telephone;
}
