#include "Calendrier.hpp"

Calendrier::Calendrier() {}

Calendrier::Calendrier(QDate dateDepart)
    : _dateDep(dateDepart)
{}

Calendrier Calendrier::createFromQuery(QSqlQuery &query)
{
    Calendrier cal;

    cal = query.value("DATEDEPART").toDate();

    return cal;
}

QDate Calendrier::getDateDep() const
{
    return _dateDep;
}

void Calendrier::setDateDep(const QDate &dateDep)
{
    _dateDep = dateDep;
}
