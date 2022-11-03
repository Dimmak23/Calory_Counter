#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person: QObject
{
	Q_OBJECT
	public:
		double getMass() const {return mass;}
		void setMass(double const &mass) {this->mass = mass;}
	signals:
		void massChanged();
	private:
		double mass {};
};

#endif // PERSON_H
