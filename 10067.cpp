#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct status {
	int a, b, c, d;
};

status start, end;
status forbidden;

vector<status> v;
map<int,bool> visited;

bool is_forbidden(const status& s) {
	for (int i = 0, sz = v.size(); i < sz; i++) {
		if (s.a == v[i].a && s.b == v[i].b && s.c == v[i].c && s.d == v[i].d)
			return true;
	}
	return false;
}

bool is_visited(const status& s) {
	return visited.find(s.a * 1000 + s.b * 100 + s.c * 10 + s.d) == visited.end() ? false : true;
}

status make_move(status s, int move) {
	status tmp = s;

	switch(move) {
		case 0:
			tmp.a = (tmp.a + 1) % 10;
			break;
		case 1:
			tmp.a = (tmp.a + 9) % 10;
			break;
		case 2:
			tmp.b = (tmp.b + 1) % 10;
			break;
		case 3:
			tmp.b = (tmp.b + 9) % 10;
			break;
		case 4:
			tmp.c = (tmp.c + 1) % 10;
			break;
		case 5:
			tmp.c = (tmp.c + 9) % 10;
			break;
		case 6:
			tmp.d = (tmp.d + 1) % 10;
			break;
		case 7:
			tmp.d = (tmp.d + 9) % 10;
			break;
	}

	return tmp;
}

int solve() {
	status s;
	pair<status, int> tmp;
	queue< pair<status, int> > q;

	if (is_forbidden(start))
		return -1;
	
	q.push(make_pair(start, 0));

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		if (tmp.first.a == end.a && tmp.first.b == end.b && tmp.first.c == end.c && tmp.first.d == end.d) {
			return tmp.second;
		}

		for (int i = 0; i < 8; i++) {
			s = make_move(tmp.first, i);
			if (!is_forbidden(s) && !is_visited(s)) {
				visited[s.a*1000 + s.b*100 + s.c*10 + s.d] = true;
				q.push(make_pair(s, tmp.second + 1));
			}
		}
	}

	return -1;
}

int main(void) {
	int cases, n;

	cin >> cases;

	while (cases--) {
		cin >> start.a >> start.b >> start.c >> start.d;
		cin >> end.a >> end.b >> end.c >> end.d;
		cin >> n;

		v.clear();
		visited.clear();

		while (n--) {
			cin >> forbidden.a >> forbidden.b >> forbidden.c >> forbidden.d;
			v.push_back(forbidden);
		}

		cout << solve() << endl;
	}

	return 0;
}
