#include "Date.h"
#include "Colors.h"
class Cell

{
private:
	std::string m_value;
	Color m_color = white;
public:
	Cell();
	void setValue(const std::string& v);
	void setColor(Color c);
	std::string getValue();
	Color getColor();
	int toInt();
	double toDouble();
	Date toDate();
	void reset();
};
