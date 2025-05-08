#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "GameManager.h"

GameManager::GameManager(int size) {
    this->size = size;

    for (int i = 0; i < size; i++) {
        matrix.push_back(std::vector<bool>());

        for (int j = 0; j < size; j++) {
            matrix[i].push_back(std::rand() % 3 > 0 ? true : false);
        }
    }
}

int GameManager::getBorderCellCount(int x, int y) {
    int count = 0;

    if (x > 0 && y > 0 &&               matrix[x - 1][y - 1] == 1) count++;
    if (y > 0 &&                        matrix[x][y - 1] == 1) count++;
    if (x < size - 1 && y > 0 &&        matrix[x + 1][y - 1] == 1) count++;
    if (x > 0 &&                        matrix[x - 1][y] == 1) count++;
    if (x < size - 1 &&                 matrix[x + 1][y] == 1) count++;
    if (x > 0 && y < size - 1 &&        matrix[x - 1][y + 1] == 1) count++;
    if (y < size - 1 &&                 matrix[x][y + 1] == 1) count++;
    if (x < size - 1 && y < size - 1 && matrix[x + 1][y + 1] == 1) count++;

    return count;
}

void GameManager::update() {
    std::vector<std::vector<bool>> newField = matrix;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = getBorderCellCount(i, j);

            if (matrix[i][j] && neighbors < 2) newField[i][j] = false;
            else if (matrix[i][j] && neighbors > 3) newField[i][j] = false;
            else if (!matrix[i][j] && neighbors == 3) newField[i][j] = true;
        }
    }

    matrix = newField;
}

void GameManager::render() {
    std::cout << "\x1B[2J\x1B[H";

    for (int i = 0; i < size; i++) {
        std::string row;

        for (int j = 0; j < size; j++) {
            row += (matrix[i][j] == true ? "X" : " ");
        }

        std::cout << row << std::endl;
    }
}