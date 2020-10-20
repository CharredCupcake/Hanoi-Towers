#pragma once
#include <iostream>
#include <stack>

//char to int
enum CtoI
{
	A = 1,
	B,
	C
};

struct Pole
{
	CtoI m_id;
	std::stack<size_t> m_data;
};

struct Move
{
	CtoI from;
	size_t disc;
	CtoI to;
};

class HanoiTowers
{
public:
	HanoiTowers(const size_t discSize);
	void printMoves();
protected:
	size_t m_discCount;
	Pole m_poleA, m_poleB, m_poleC;
	std::stack<Move> m_moves;

private:
	void init(const size_t discCount);
	void move(Pole& sending, Pole& receiving);
	void solve(size_t n, CtoI from, CtoI to, CtoI hanging);
	Pole& getPole(CtoI id);
	void reverseMoves();
};

