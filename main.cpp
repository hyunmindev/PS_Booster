#include <iostream>
#include <vector>


using namespace std;

struct Position {
  int x;
  int y;
};

int position_number;
vector<Position> position_vec;
vector<vector<int>> position_graph;

void makePositionGraph() {
  for (int i = 0; i < position_number; i++) {
    for (int j = 0; j < position_number; j++) {
      int x_distance = abs(position_vec[i].x - position_vec[j].x);
      int y_distance = abs(position_vec[i].y - position_vec[j].y);
      position_graph[i][j] = min(x_distance, y_distance);
      position_graph[j][i] = min(x_distance, y_distance);
    }
  }
}

void caclculateDistance() {
  for (int k = 0; k < position_number; k++) {
    for (int i = 0; i < position_number; i++) {
      for (int j = 0; j < position_number; j++) {
        position_graph[i][j] = min(position_graph[i][j], position_graph[i][k] + position_graph[k][j]);
      }
    }
  }
}

int main() {
  int question_number;
  cin >> position_number >> question_number;

  position_vec.resize(position_number); // resize global variable
  position_graph.resize(position_number, vector<int>(position_number));
  vector<bool> result_vec(question_number); // initialize result vector

  for (int i = 0; i < position_number; i++) {
    cin >> position_vec[i].x >> position_vec[i].y;
  }

  makePositionGraph();
  caclculateDistance();

  for (int i = 0; i < question_number; i++) {
    int start, arrival, health;
    cin >> start >> arrival >> health;
    result_vec[i] = position_graph[start - 1][arrival - 1] <= health;
  }

  for (bool result : result_vec) {
    result ? cout << "YES" << endl : cout << "NO" << endl;
  }

  return 0;
}