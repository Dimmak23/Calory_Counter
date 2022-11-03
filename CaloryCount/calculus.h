#ifndef CALCULUS_H
#define CALCULUS_H

#include <QWidget>
#include "person.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class calculus; }
QT_END_NAMESPACE

class calculus: public QWidget
{
		Q_OBJECT
	public:
		calculus(QWidget *parent = nullptr);
		~calculus();
	private slots:
		void calculateCalories();
		void massChanged(double const &mass);
		void timeChanged(double const &time);
		void speedChanged(double const &speed);
		void levelChanged(int const &index);
		void changeCaloryLabelColor();
	signals:
		void caloryCountChanged();
	private:
		Ui::calculus *ui;
		Person m_person;
		double m_time {};
		double m_speed {};
		double m_calory_count {};
		struct coeffs
		{
				double a{};
				double b{};
				double c{};
				double d{};
		};
		static inline const std::vector<coeffs> coVec
		{
			{0.0215, -0.1765, 0.871, 1.4577},
			{0.0171, -0.1062, 0.608, 1.86},
			{0.0184, -0.1134, 0.6566, 1.92},
			{0.0196, -0.1205, 0.7053, 1.98}
		};
		coeffs value{};

};

#endif // CALCULUS_H
