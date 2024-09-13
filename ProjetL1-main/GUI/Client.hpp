/**
 * @file Client.cpp
 * @brief Ce fichier contient l'impémentation du table CLIENT.
 * @date September 10, 2024
 */


#ifndef CLIENT_HPP
#define CLIENT_HPP

// Standard library

#include <QtCore/QString>
#include <QtCore/QVariant>


// Database library
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


class Client
{
public:
    /**
     * @brief Constructeur par défaut
     */
    Client();
    /**
     * @brief Surcharge du constructeur
     * @param num: l'identifiant du client
     */
    Client(qint32 num);
    /**
     * @brief Surcharge du constructeur
     * @param num: l'identifiant du client
     * @param nom: le nom du client
     */
    Client(qint32 num, QString nom);

    /**
     * @brief fonction static pour l'éxtraction des données à partir du query du DB
     * @param query: le QSqlQuery issue du DB où on stock les données
     * @return un instance de l'object de type Client créer
     */
    static Client createFromQuery(QSqlQuery &query);

    // Getter
    qint32 getNum() const;
    QString getNom() const;
    QString getAdresse() const;
    QString getTelephone() const;

    // Setter
    void setNum(qint32 num);
    void setNom(const QString &nom);
    void setAdresse(const QString &adresse);
    void setTelephone(const QString &telephone);

private:
    qint32 _num;
    QString _nom;
    QString _adresse;
    QString _telephone;

};

#endif // CLIENT_HPP
