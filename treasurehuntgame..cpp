#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <cmath>    // For abs()
#include <vector>   // For storing obstacles and traps

using namespace std;

struct Position {
    int x, y;
};

class TreasureHunt {
private:
    int gridSize;
    Position player, treasure;
    vector<Position> obstacles;
    vector<Position> traps;
    int moves;
    int lives;

public:
    TreasureHunt(int size) : gridSize(size), moves(0), lives(3) {
        srand(time(0));
        player = {0, 0};
        treasure = getRandomPosition();
        while (treasure.x == player.x && treasure.y == player.y) {
            treasure = getRandomPosition();
        }
        generateObstacles();
        generateTraps();
    }

    Position getRandomPosition() {
        return {rand() % gridSize, rand() % gridSize};
    }

    bool isObstacle(Position pos) {
        for (auto& ob : obstacles) {
            if (ob.x == pos.x && ob.y == pos.y) return true;
        }
        return false;
    }

    bool isTrap(Position pos) {
        for (auto& trap : traps) {
            if (trap.x == pos.x && trap.y == pos.y) return true;
        }
        return false;
    }

    void generateObstacles() {
        int numObstacles = gridSize / 2;
        for (int i = 0; i < numObstacles; i++) {
            Position ob = getRandomPosition();
            if (ob.x != player.x || ob.y != player.y || ob.x != treasure.x || ob.y != treasure.y) {
                obstacles.push_back(ob);
            }
        }
    }

    void generateTraps() {
        int numTraps = gridSize / 3;
        for (int i = 0; i < numTraps; i++) {
            Position trap = getRandomPosition();
            if (!isObstacle(trap) && trap.x != player.x && trap.y != player.y) {
                traps.push_back(trap);
            }
        }
    }

    string getDirectionHint() {
        if (player.y < treasure.y) return "Move South (S)!";
        if (player.y > treasure.y) return "Move North (W)!";
        if (player.x < treasure.x) return "Move East (D)!";
        if (player.x > treasure.x) return "Move West (A)!";
        return "You are at the treasure!";
    }

    int getDistance() {
        return abs(player.x - treasure.x) + abs(player.y - treasure.y);
    }

    void resetGame() {
        gridSize += 2; // Increase grid size for next level
        moves = 0;
        lives = 3;
        player = {0, 0};
        treasure = getRandomPosition();
        obstacles.clear();
        traps.clear();
        generateObstacles();
        generateTraps();
        playGame();
    }

    void playGame() {
        cout << "🏆 Welcome to Treasure Hunt! Find the treasure and avoid traps! 🏆\n";

        while (true) {
            cout << "\n💡 Hint: " << getDirectionHint() << "\n";
            cout << "📍 You are " << getDistance() << " steps away.\n";
            cout << "❤️ Lives left: " << lives << " | 🔄 Moves: " << moves << "\n";

            cout << "Enter move (W/A/S/D): ";
            char move;
            cin >> move;

            Position newPlayer = player;
            if (move == 'W' || move == 'w') newPlayer.y--;
            else if (move == 'S' || move == 's') newPlayer.y++;
            else if (move == 'A' || move == 'a') newPlayer.x--;
            else if (move == 'D' || move == 'd') newPlayer.x++;
            else {
                cout << "❌ Invalid move! Use W, A, S, or D.\n";
                continue;
            }

            // Boundary check
            newPlayer.x = max(0, min(gridSize - 1, newPlayer.x));
            newPlayer.y = max(0, min(gridSize - 1, newPlayer.y));

            // Obstacle check
            if (isObstacle(newPlayer)) {
                cout << "🚧 Oops! There's an obstacle here! Try a different direction.\n";
                continue;
            }

            // Trap check
            if (isTrap(newPlayer)) {
                cout << "💥 You stepped on a trap! Lost 1 life! 💔\n";
                lives--;
                if (lives == 0) {
                    cout << "💀 Game Over! You ran out of lives. 💀\n";
                    return;
                }
            }

            // Wrong direction check
            int oldDistance = getDistance();
            player = newPlayer;
            int newDistance = getDistance();

            if (newDistance > oldDistance) {
                cout << "⚠️ You moved away from the treasure! Lost 1 life! 💔\n";
                lives--;
                if (lives == 0) {
                    cout << "💀 Game Over! You ran out of lives. 💀\n";
                    return;
                }
            }

            moves++;

            // Win Condition
            if (player.x == treasure.x && player.y == treasure.y) {
                cout << "\n🎉 Congratulations! You found the treasure in " << moves << " moves! 🎉\n";
                cout << "🚀 Moving to the next level...\n";
                resetGame();
                return;
            }
        }
    }
};

int main() {
    TreasureHunt game(5);  // Start with a 5x5 grid
    game.playGame();
    return 0;
}
