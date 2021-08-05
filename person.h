#ifndef PERSON_H
#define PERSON_H
#include <QString>
class Person
{
private:
    QString name,lastname;
    int age;
public:
    Person(QString n, QString ln, int a);
    Person();
    QString getName();
    QString getLastName();
    int getAge();
    QString toString();

};

#endif // PERSON_H
