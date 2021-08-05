#include "person.h"

Person::Person()
{
    name="";
    lastname="";
    age=1;
}

Person::Person(QString n, QString ln, int a)
{
    name=n;
    lastname=ln;
    age=a;
}

QString Person::getName()
{
    return name;
}

QString Person::getLastName()
{
    return lastname;
}

int Person::getAge()
{
    return age;
}

QString Person::toString()
{
    return name+" "+lastname+" "+QString::number(age);
}
