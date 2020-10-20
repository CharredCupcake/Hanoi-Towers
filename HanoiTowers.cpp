#include "HanoiTowers.hpp"

HanoiTowers::HanoiTowers(const size_t discSize)
{
	init(discSize);
}

void HanoiTowers::printMoves()
{
	size_t i = 0;
	solve(m_discCount, CtoI::A, CtoI::C, CtoI::B);
	reverceMoves();
	while (!m_moves.empty())
	{
		i++;
		std::cout << "Move " << i << " : " << m_moves.top().disc << " "
				  << char('A' - 1 + m_moves.top().from) << " ---> " << char('A' - 1 + m_moves.top().to) << "\n";
		m_moves.pop();
	}

}

void HanoiTowers::init(const size_t discCount)
{
	m_discCount = discCount;
	m_poleA.m_id = CtoI::A;
	m_poleB.m_id = CtoI::B;
	m_poleC.m_id = CtoI::C;

	for (size_t i = discCount; i > 0; i--)
	{
		m_poleA.m_data.push(i);
	}
}

void HanoiTowers::move(Pole& sending, Pole& receiving)
{
	receiving.m_data.push(sending.m_data.top());
	sending.m_data.pop();
	Move TempMove;
	TempMove.from = sending.m_id;
	TempMove.disc = receiving.m_data.top();
	TempMove.to = receiving.m_id;
	m_moves.push(TempMove);
}

void HanoiTowers::solve(size_t n , CtoI from, CtoI to, CtoI free)
{
	if (n == 1)
	{
		move(getPole(from), getPole(to));
		return;
	}
	solve(n - 1, from, free, to);
	move(getPole(from), getPole(to));
	solve(n - 1, free, to, from);
}

Pole& HanoiTowers::getPole(CtoI id)
{
	if (m_poleA.m_id == id)return m_poleA;
	if (m_poleB.m_id == id)return m_poleB;
	if (m_poleC.m_id == id)return m_poleC;
}

void HanoiTowers::reverceMoves()
{
	std::stack<Move> newMoves;
	while (!m_moves.empty())
	{
		newMoves.push(m_moves.top());
		m_moves.pop();
	}
	m_moves = newMoves;
}
