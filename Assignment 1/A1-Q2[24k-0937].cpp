#include <iostream>
using namespace std;

class Ball {
    int x, y;
public:
    Ball() : x(0), y(0) {}  // Ball starts at (0,0)
    
    void move(int dx, int dy) {  // Move ball by dx, dy
        x += dx;
        y += dy;
    }

    int getX() { return x; }
    int getY() { return y; }
    pair<int, int> getCoordinates() { return {x, y}; }
};

class Robot {
    string name;
    int hits;
public:
    Robot(string n) : name(n), hits(0) {}

    void hitBall(Ball &ball, const string &direction) {
        int dx = 0, dy = 0;
        if (direction == "left") dx = -1;
        else if (direction == "right") dx = 1;
        else if (direction == "up") dy = 1;
        else if (direction == "down") dy = -1;

        ball.move(dx, dy);  // Corrected ball movement
        hits++;
        cout << name << " hits the ball to (" << ball.getX() << "," << ball.getY() << ")\n";
    }

    int getHits() { return hits; }
};

class Goal {
    const int goalx, goaly;
public:
    Goal() : goalx(3), goaly(3) {}

    bool isGoalReached(int x, int y) {
        return x == goalx && y == goaly;
    }
};

class Team {
    string name;
    Robot robot;
public:
    Team(string n, string robotName) : name(n), robot(robotName) {}

    Robot& getRobot() { return robot; }
    string getName() { return name; }
};

class Game {
    Team team1, team2;
    Ball ball;
    Goal goal;
public:
    Game() : team1("Team 1", "Robot 1"), team2("Team 2", "Robot 2") {}

    void play(Team &team) {
        cout << "\n" << team.getName() << "'s Turn\n";
        Robot &robot = team.getRobot();
        ball=Ball();
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            string direction;
            cout << " Enter direction (left/right/up/down): ";
            cin >> direction;
            robot.hitBall(ball, direction);
        }
        cout << "\n Team " << team.getName() << " reached goal in " << robot.getHits() << " hits!\n";
    }

    void declareWinner() {
        int hits1 = team1.getRobot().getHits();
        int hits2 = team2.getRobot().getHits();

        if (hits1 < hits2) cout << "\n Team 1 Wins!";
        else if (hits1 > hits2) cout << "\nTeam 2 Wins!";
        else cout << "\nIt's a Draw!";
    }

    void startGame() {
        cout << "\n Game Started!\n";
        play(team1);
        play(team2);
        declareWinner();
    }
};

int main() {
    Game game;
    game.startGame();
    return 0;
}
