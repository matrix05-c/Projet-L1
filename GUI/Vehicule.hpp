#ifndef VEHICULE_HPP
#define VEHICULE_HPP

// Standard library
#include <QtCore/QBEInteger>
#include <QtCore/QVariant>
#include <stdexcept>

// Database library
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


class Vehicule
{
public:
    /**
     * @brief Constructeur par défaut
     */
    Vehicule();
    /**
     * @brief Surcharge du constructeur
     * @param num: l'identifiant du vehicule
     */
    Vehicule(qint32 num);
    /**
     * @brief Surcharge du constructeur
     * @param num: l'identifiant du vehicule
     * @param nbPlace: nombre totale de place du vehicule
     */
    Vehicule(qint32 num, qint32 nbPlace);

    /**
     * @brief fonction static pour l'éxtraction des données à partir du query du DB
     * @param query: le QSqlQuery issue du DB où on stock les données
     * @return un instance de l'object de type Vehicule créer
     */
    static Vehicule createFromQuery(QSqlQuery &query);

    // Getter
    qint32 getNum() const;
    qint32 getNbPlace() const;
    qint32 getNbPlaceDispo() const;

    // Setter
    void setNum(qint32 num);
    void setNbPlace(qint32 nbPlace);
    void setNbPlaceDispo(qint32 nbPlaceDispo);

    /**
     * @brief Reserver [nbPlace] places dans le vehicule
     * @param nbPlace: nombre de places à reserver
     * @exception lance un excéption invalid_argument
     *      si le nombre de places demander est supérieur
     *      au nombre de places disponible
     */
    void bookPlace(qint32 nbPlace);

private:
    qint32 _num;
    qint32 _nbPlace;
    qint32 _nbPlaceDispo;

};

#endif // VEHICULE_HPP
