#include "Cell.h"

Cell::Cell()
{
	m_color = white;
}
	
void Cell::setValue(const std::string& v)
{
	m_value = v;
}

void Cell::setColor(Color c)
{
	m_color = c;
}

std::string Cell::getValue()
{
	return m_value;
}

Color Cell::getColor()
{
	return m_color;
}

int Cell::toInt()
{
	int x = std::stoi(m_value);
	return x;
}

double Cell::toDouble()
{
	double d = std::stod(m_value);
	return d;
}

Date Cell::toDate()
{
	Date d{};
	d.setDay(m_value);
	d.setMonth(m_value);
	d.setYear(m_value);
	return d;
}

void Cell::reset()
{
	m_value = {};
	m_color = white;
}