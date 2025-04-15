#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>

class Scene {
    public:
        Scene(int n, int m) : row(n), col(m) {
            grid = (char**)malloc(sizeof(char*)*(row+1));
            for (int i = 0; i <= row; i++) {
                grid[i] = (char*)malloc(sizeof(char)*(col+1));
                for(int j = 0; j <= col; j++)
                    grid[i][j] = '.';
            }
        }
        ~Scene() {
            for (int i = 0; i <= row; i++)
                free(grid[i]);
            free(grid);
        }

        void update(int p);                         // Update the game state to reflect the situation at P seconds.
        void addBlock(int x, int y, char **block);  // Add a block to the scene at position (X, Y).
        bool checkRow(int r) const;                 // Check whether the row needs to be eliminated.
        void eliminate(int r);                      // Eliminate the row.
        void print() const;                         // Print the game screen.
    private:
        int row;
        int col;
        int gameTimer = 1;
        char **grid;
};

#endif

// You might start with the following codes:


#include "function.h"

void Scene::dfs(int x, int y, vector<vector<char>>&v) {

}

void Scene::update(int p) {
    while (gameTimer != p) {
        
        vector<vector<int>> vis(row, vector<char>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!vis[i][j]) {
                    vector<vector<char>> omg(row, vector<char>(col, '.'));
                    dfs(i, j, omg);
                    bool moveable = true;
                    for (int i = 0; i < row; i++) {
                        for (int j = 0; j < col; j++) {
                            if (!(omg[i][j] == '*' && i+1 < row && omg[i+1][j] == '.' && grid[i+1][j] == '.')) moveable = false;
                        }
                    }
                    if (moveable) {
                        for (int i = row-1-1; i >= 0; i--) {
                            for (int j = 0; j < col; j++) {
                                if (omg[i][j] == '*') grid[i+1][j] = '*';
                            }
                        }
                    }
                }
            }
        }

        gameTimer++;
    }
}

void Scene::addBlock(int x, int y, char **block) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[x+i][y+j] = block[x+i][y+j];
        }
    }
}

bool Scene::checkRow(int r) const {
    for (int i = 0; i < col; i++) if (grid[r][col] == '.') return false;
    return true;
}

void Scene::eliminate(int r) {
    for (int i = 0; i < col; i++) grid[r][i] = '.';
}

void Scene::print() const {
    // ...
}