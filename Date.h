#include <string>
class Date
{
private:
	int year;
	int month;
	int day;
public:
	void setDay(const std::string& s);
	void setMonth(const std::string& s);
	void setYear(const std::string& s);
	int getDayAt();
	int getMonthAt();
	int getYearAt();
};
