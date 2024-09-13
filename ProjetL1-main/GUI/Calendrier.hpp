/**
 * @file Calendrier.cpp
 * @brief Ce fichier contient l'implémentation du table CALENDRIER.
 * @date September 10, 2024
 */


#ifndef CALENDRIER_HPP
#define CALENDRIER_HPP

// Standard library
#include <QtCore/QVariant>
#include <QtCore/QDate>

// Database library
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


class Calendrier
{
public:
    /**
     * @brief Constructeur par défaut
     */
    Calendrier();
    /**
     * @brief Surcharge Constructeur
     * @param dateDepart: le date de départ
     */
    Calendrier(QDate dateDepart);

    /**
     * @brief fonction static pour l'éxtraction des données à partir du query du DB
     * @param query: le QSqlQuery issue du DB où on stock les données
     * @return un instance de l'object de type Calendrier créer
     */
    static Calendrier createFromQuery(QSqlQuery &query);

    QDate getDateDep() const;
    void setDateDep(const QDate &dateDep);

private:
    QDate _dateDep;

};

#endif // CALENDRIER_HPP
