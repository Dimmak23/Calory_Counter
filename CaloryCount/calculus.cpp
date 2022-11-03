#include "calculus.h"
#include "./ui_calculus.h"
#include <cmath>

calculus::calculus(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::calculus)
{
	ui->setupUi(this);

	//Initialize constants
	value.a = coVec.at(0).a;
	value.b = coVec.at(0).b;
	value.c = coVec.at(0).c;
	value.d = coVec.at(0).d;

	//Customize initial Calory Counter label color
	ui->CaloryCountLabel->setStyleSheet("color: rgb(170, 0, 0)");

	//Customize increment/decrement steps for spin boxes
	ui->timeSBox->setSingleStep(0.25);
	ui->massSBox->setSingleStep(0.5);
	ui->massSBox->setMaximum(120);
	ui->speedSBox->setSingleStep(0.1);

	//We also can produce initial calculations
//	ui->timeSBox->setMinimum(0.01);
//	ui->massSBox->setMinimum(1);

	//Initialize the members with values from the ui
	m_person.setMass(ui->massSBox->value());
	m_time = ui->timeSBox->value();
	m_speed = ui->speedSBox->value();

	//connect ui components to respective slots
	connect(
				ui->massSBox,
				&QDoubleSpinBox::valueChanged,
				this,
				&calculus::massChanged
				);
	connect(
				ui->timeSBox,
				&QDoubleSpinBox::valueChanged,
				this,
				&calculus::timeChanged
				);
	connect(
				ui->speedSBox,
				&QDoubleSpinBox::valueChanged,
				this,
				&calculus::speedChanged
				);

	//Change coefficients of formula when grade level changed
	connect(
				ui->gradeLevel,
				&QComboBox::currentIndexChanged,
				this,
				&calculus::levelChanged
				);

	//Display the calory count
	connect(
				this,
				&calculus::caloryCountChanged,
				[&](){
		ui->CaloryCountLabel->setText(QString::number(m_calory_count));
	}
				);

	//Change calory label color depending on calory value
	connect(
				this,
				&calculus::caloryCountChanged,
				this,
				&calculus::changeCaloryLabelColor
				);


	//Do initial calculation
	calculateCalories();

}

void calculus::massChanged(double const &mass)
{
	m_person.setMass(mass);
	calculateCalories();
}

void calculus::timeChanged(double const &time)
{
	m_time = time;
	calculateCalories();
}

void calculus::speedChanged(double const &speed)
{
	m_speed = speed;
	calculateCalories();
}

void calculus::calculateCalories()
{
	m_calory_count = ( value.a * pow(m_speed, 3) + value.b * pow(m_speed, 2) + value.c * m_speed + value.d
						 ) * m_person.getMass() * m_time;

	emit caloryCountChanged();
}

void calculus::changeCaloryLabelColor()
{
	if (m_calory_count >= 3000)
		ui->CaloryCountLabel->setStyleSheet("color: rgb(0, 170, 0)");
	else
		ui->CaloryCountLabel->setStyleSheet("color: rgb(170, 0, 0)");
}

void calculus::levelChanged(const int &index)
{
	value.a = coVec.at(index).a;
	value.b = coVec.at(index).b;
	value.c = coVec.at(index).c;
	value.d = coVec.at(index).d;
	calculateCalories();
}

calculus::~calculus()
{
	delete ui;
}

