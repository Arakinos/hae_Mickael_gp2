#pragma once
#include "Lib.hpp"
#include <algorithm>
#include <unordered_map>

using namespace std;
namespace std
{

	template<>
	struct hash<Vector2f>
	{
		std::size_t operator()(const Vector2f& k) const
		{
			return (unsigned int)((int)k.x << 16) | ((unsigned int)k.y);
		}
	};
}

class Dijkstra
{
public:
	bool	computed = false;
	std::vector<Vector2f> G;
	Vector2f start;
	std::unordered_map<Vector2f, double> distance;
	std::unordered_map<Vector2f, Vector2f> pred;
	


	void Init(const vector<Vector2f> & _Graph, const Vector2f & S)
	{
		G = _Graph;
		start = S;
		for (const Vector2f& vec: _Graph)
		{
			distance[vec] = 99999999;
		}
		distance[S] = 0;
		int i = 0;
	}
	Vector2f FindMin(std::vector<Vector2f>& queue)
	{
		int mini = 9999999;
		Vector2f sommet = Vector2f(-1, -1);
		for (const Vector2f& vec : queue)
		{
			if (distance[vec] < mini)
			{
				mini = distance[vec];
				sommet = vec;
			}
		}
		int i = 0;
		return sommet;
	}
	int FindMin2(std::vector<Vector2f>& queue)
	{
		int mini = 9999999;
		int pos = -1;
		int possave = 0;
		Vector2f sommet = Vector2f(-1, -1);
		for (const Vector2f& vec : queue)
		{
			pos++;
			if (distance[vec] < mini)
			{
				mini = distance[vec];
				sommet = vec;
				possave = pos;
			}
		}
		int i = 0;
		return possave;
	}
	double weigth(Vector2f a, Vector2f b)
	{
		Vector2f dif = b - a;
		double difd = sqrt((dif.x*dif.x)+  (dif.y * dif.y));
		return difd;
	}
	void maj_distances(Vector2f S1, Vector2f S2)
	{
		if (distance[S2] > distance[S1] + weigth(S1, S2))
		{
			distance[S2] = distance[S1] + weigth(S1, S2);
			pred[S2] = S1;
		}
		int i = 0;
	}
	void Dijkstrak(const vector<Vector2f> & _Graph, Vector2f Sdeb)
	{
		Init(_Graph, Sdeb);
		vector<Vector2f> Q = _Graph;
		start = Sdeb;
		while (Q.size() != 0)
		{
			Vector2f s1 = FindMin(Q);
			int sai = FindMin2(Q);
			Q.erase(Q.begin()+sai);
			for (const Vector2f & s : Q)
			{
				if ((s.x == s1.x + 1 && s.y == s1.y) || (s.x == s1.x - 1 && s.y == s1.y) || (s.x == s1.x&& s.y == s1.y + 1) || (s.x == s1.x && s.y == s1.y - 1))
				{
					maj_distances(s1, s);
				}
			}
		}
		computed = true;
	}
	bool FindPath(std::vector<Vector2f>& result, const Vector2f sFin)
	{
		result.clear();
		Vector2f cur = sFin;
		while (cur != start) {
			result.push_back(cur);
			Vector2f prev = cur;
			cur = pred[cur];
			if (prev == cur)
				return false;
		}
		if (result.size() == 0) {
			return false;
		}
		else {
			result.push_back(start);
			std::reverse(result.begin(), result.end());
			return true;
		}
	}
};

