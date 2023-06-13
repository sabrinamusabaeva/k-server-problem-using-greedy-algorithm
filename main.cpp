#include <iostream>
#include <vector>
#include <vector>
#include <math.h>

using namespace std;
struct point {
  int x, y;
};

int dist(point p1, point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void initialize_servers(vector<point>& servers, int k) {
  for (int i = 0; i < k; i++) {
    int x = rand() % 100;
    int y = rand() % 100;
    point p = {x, y};
    servers.push_back(p);
  }
}

int k_server_greedy(int k, vector<point> requests) {
  vector<point> servers;
  initialize_servers(servers, k);
  int total_distance = 0;
  for (int i = k; i < requests.size(); i++) {
    int closest_server = -1;
    int min_distance = INT_MAX;
    for (int j = 0; j < k; j++) {
      int distance = distance(servers[j], requests[i]);
      if (distance < min_distance) {
        min_distance = distance;
        closest_server = j;
      }
    }
    if (closest_server != -1) {
      total_distance += min_distance;
      servers[closest_server] = requests[i];
    }
  }
  return total_distance;
}

int main() {
  int k;
  cin >> k;
  vector<point> requests;
  for (int i = 0; i < k; i++) {
    point p;
    cin >> p.x >> p.y;
    requests.push_back(p);
  }
  int total_distance = k_server_greedy(k, requests);
  cout << total_distance << endl;

  return 0;
}
