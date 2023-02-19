#include "Spreadsheet.h"
#include <string>

Spreadsheet::Spreadsheet(int rows, int columns)
{
	if (rows == 0 || columns == 0)
	{
		std::cout << "rows or columns cant be 0\n";
		system("pause");
	}
	m_cells = new Cell * [rows];
	for (int i = 0; i < rows; ++i)
	{
		m_cells[i] = new Cell[columns];
	}
	c_rows = rows;
	c_columns = columns;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			m_cells[i][j] = {};
		}
	}
}

void Spreadsheet::setCellAt(int r, int c, Cell cl)
{
	m_cells[r][c] = cl;
}

void Spreadsheet::setCellAt(int r, int c, const std::string& s)
{
	Cell cl;	
	cl.setValue(s);
	m_cells[r][c] = cl;
}

Cell Spreadsheet::getCellAt(int r, int c)
{
	return m_cells[r][c];
}

void Spreadsheet::addRow(int r)
{
	++c_rows;
	Cell** m_cells2 = new Cell * [c_rows];
	for (int i = 0; i < c_rows; ++i)
	{
		m_cells2[i] = new Cell[c_columns];
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c_columns; ++j)
		{
			m_cells2[i][j] = m_cells[i][j];
		}
	}
	for (int i = r + 1; i < c_rows; ++i)
	{
		for (int j = 0; j < c_columns; ++j)
		{
			m_cells2[i][j] = m_cells[i][j];
		}
	}
	for (int i = 0; i < c_rows; ++i)
	{
		delete[]m_cells[i];
	}
	delete[]m_cells;
	m_cells = m_cells2;
	m_cells2 = nullptr;
}

void Spreadsheet::removeRow(int r)
{
	--c_rows;
	Cell** m_cells2 = new Cell * [c_rows];
	for (int i = 0; i < c_rows; ++i)
	{
		m_cells2[i] = new Cell[c_columns];
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c_columns; ++j)
		{
			m_cells2[i][j] = m_cells[i][j];
		}
	}
	for (int i = r; i < c_rows; ++i)
	{
		for (int j = 0; j < c_columns; ++j)
		{
			m_cells2[i][j] = m_cells[i + 1][j];
		}
	}
	for (int i = 0; i < c_rows; ++i)
	{
		delete[]m_cells[i];
	}
	delete[]m_cells;
	m_cells = m_cells2;
	m_cells2 = nullptr;
}

void Spreadsheet::addColumn(int c)
{
	++c_columns;
	Cell** m_cells2 = new Cell * [c_rows];
	for (int i = 0; i < c_rows; ++i)
	{
		m_cells2[i] = new Cell[c_columns];
	}
	for (int i = 0; i < c_rows; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			m_cells2[i][j] = m_cells[i][j];
		}
	}
	for (int i = 0; i < c_rows; ++i)
	{
		for (int j = c + 1; j < c_columns; ++j)
		{
			m_cells[i][j] = m_cells[i][j];
		}
	}
	for (int i = 0; i < c_rows; ++i)
	{
		delete[]m_cells[i];
	}
	delete[]m_cells;
	m_cells = m_cells2;
	m_cells2 = nullptr;
}

void Spreadsheet::removeColumn(int c)
{
	--c_columns;
	Cell** m_cells2 = new Cell * [c_rows];
	for (int i = 0; i < c_rows; ++i)
	{
		m_cells2[i] = new Cell[c_columns];
	}
	for (int i = 0; i < c_rows; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			m_cells2[i][j] = m_cells[i][j];
		}
	}
	for (int i = 0; i < c_rows; ++i)
	{
		for (int j = c; j < c_columns; ++j)
		{
			m_cells2[i][j] = m_cells[i][j + 1];
		}
	}
	for (int i = 0; i < c_rows; ++i)
	{
		delete[]m_cells[i];
	}
	delete[]m_cells;
	m_cells = m_cells2;
	m_cells2 = nullptr;
}

void Spreadsheet::swapRows(int r1, int r2)
{
	for (int i = 0; i < c_columns; ++i)
	{
		swap(&m_cells[r1 - 1][i], &m_cells[r2 - 1][i]);
	}
}

void Spreadsheet::swap(Cell* s1, Cell* s2)
{
	Cell* s3 = s1;
	s1 = s2;
	s2 = s3;
}

void Spreadsheet::swapColumns(int c1, int c2)
{
	for (int i = 0; i < c_rows; ++i)
	{
		swap(&m_cells[i][c1 - 1], &m_cells[i][c2 - 1]);
	}
}

Spreadsheet::~Spreadsheet()
{
	for (int i = 0; i < c_rows; ++i)
	{
		delete[]m_cells[i];
	}
	delete[]m_cells;
}