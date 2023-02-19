#include <iostream>
#include "Cell.h"

class Spreadsheet
{
private:
	Cell** m_cells;
	int c_rows;
	int c_columns;
public:
	Spreadsheet(int rows, int columns);
	void setCellAt(int r, int c, Cell cl);
	void setCellAt(int r, int c, const std::string& s);
	Cell getCellAt(int r, int c);
	void addRow(int r);
	void removeRow(int r);
	void addColumn(int c);
	void removeColumn(int r);
	void swapRows(int r1, int r2);
	void swap(Cell* s1, Cell* s2);
	void swapColumns(int c1, int c2);
	~Spreadsheet();
};
