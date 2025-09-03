#ifndef Grid_HPP
# define Grid_HPP

#include <unordered_set>
#include <unordered_map>
#include <Cell.hpp>
#include <gameOfLife.hpp>

struct CellHash
{
	size_t operator()(const Cell& c) const;
};

using CellSet = std::unordered_set<Cell, CellHash>;

class Grid
{
	public:
		/*Canonical Form*/
		Grid(void);
		Grid(Grid const &src);
		~Grid(void);
		Grid &operator=(Grid const &rhs);

		/*Constructor Overloading*/
		Grid(int width, int height);

		/*Getters Members*/
		int				getWidth() const;
		int				getHeight() const;
		const CellSet	&getGrid() const;

		/*Public Members*/
		void	addCell(int x, int y);
		void	iteration();

	private:
		int		_width;
		int		_height;
		CellSet	_grid;
};

#endif // Grid_HPP