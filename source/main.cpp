#include <cmath>
#include <cstring>
#include <iostream>

using std::cout, std::endl;

#define DIRECTION_COUNT     (4)
#define NO_WAY              (-1)
#define NOT_FOUND           DIRECTION_COUNT
#define IDEAL_PARAM_COUNT   (3)
#define MATRIX              argv[1]
#define KEY                 argv[2]
#define MINIMUM_MATRIX_SIZE (2)

const struct coord {
  int col{};
  int row{};
} k_directions[DIRECTION_COUNT]{
    {0, -1},  // up
    {-1, 0},  // right
    {0, 1},   // down
    {1, 0}    // left
};

int **map;

int scan_next(coord pos, size_t size, size_t step) {
  for (int curent_direction{}; curent_direction < DIRECTION_COUNT;
       curent_direction++) {
    if (pos.col + k_directions[curent_direction].col >=
            static_cast<int>(size) or
        pos.col + k_directions[curent_direction].col < 0 or
        pos.row + k_directions[curent_direction].row >=
            static_cast<int>(size) or
        pos.row + k_directions[curent_direction].row < 0)
      continue;
    if (map[pos.col + k_directions[curent_direction].col]
           [pos.row + k_directions[curent_direction].row] ==
        static_cast<int>(step))
      return curent_direction;
  }
  return NOT_FOUND;
}

bool check_is_matrix(const std::string chars) {
  if (chars.length() < (MINIMUM_MATRIX_SIZE * MINIMUM_MATRIX_SIZE))
    return false;
  return (std::sqrt(chars.length()) == std::trunc(std::sqrt(chars.length())));
}

int main(int argc, char **argv) {
  if (argc < IDEAL_PARAM_COUNT) {
    cout << "Not enough parameters" << endl;
    return EXIT_FAILURE;
  }

  if (argc > IDEAL_PARAM_COUNT) {
    cout << "I ignore unnecessary parameters" << endl;
  }

  if (!check_is_matrix(MATRIX)) {
    cout << "An incorrect matrix is specified" << endl;
    return EXIT_FAILURE;
  }

  const size_t k_matrix_size{static_cast<size_t>(sqrt(strlen(MATRIX)))};
  map = new int *[k_matrix_size];
  size_t matrix_elem{};
  for (size_t matrix_col{}; matrix_col < k_matrix_size; matrix_col++) {
    map[matrix_col] = new int[k_matrix_size];
    for (size_t matix_row{}; matix_row < k_matrix_size; matix_row++) {
      map[matrix_col][matix_row] = -1;
      for (size_t key_elem{}; key_elem < strlen(KEY); key_elem++) {
        if (MATRIX[matrix_elem] == KEY[key_elem])
          map[matrix_col][matix_row] = static_cast<int>(key_elem);
      }
      matrix_elem++;
    }
  }

  int step{};

  {
    coord *way;

    way = new coord[strlen(KEY)];

    way[step] = {0, 0};

    do {
      // find first step
      if (step == 0) {
        while (map[way[0].col][way[0].row] != 0) {
          way[0].col++;
          if (way[0].col >= static_cast<int>(k_matrix_size)) {
            way[0].col = 0;
            way[0].row++;
          }
          if (way[0].row >= static_cast<int>(k_matrix_size)) {
            cout << "WRONG WAY";
            return -EXIT_FAILURE;
          }
        }
        step = 1;
      }
      // next step
      else {
        auto next_direction =
            scan_next(way[step - 1], k_matrix_size, static_cast<size_t>(step));
        if (next_direction == NOT_FOUND) {
          map[way[step - 1].col][way[step - 1].row] = NO_WAY;
          step--;
        } else {
          way[step].col = way[step - 1].col + k_directions[next_direction].col;
          way[step].row = way[step - 1].row + k_directions[next_direction].row;
          step++;
        }
      }
    } while (step != static_cast<int>(strlen(KEY)) or step == NO_WAY);

    if (step != NO_WAY) {
      for (int steps{0}; steps < step - 1; steps++) {
        cout << "[" << way[steps].col << "," << way[steps].row << "]->";
      }

      cout << "[" << way[step - 1].col << "," << way[step - 1].row << "]"
           << endl;
    } else
      cout << "NOT FOUND";
  }
  return EXIT_SUCCESS;
}