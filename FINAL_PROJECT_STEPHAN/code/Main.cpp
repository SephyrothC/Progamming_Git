#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

// Define a Player with attributes name, agility, strength, luck, and alive
// status
struct Player {
  std::string name;
  int agility;
  int strength;
  int luck;
  bool alive;
};

// Define an abstract Game class with a pure virtual play() method and a
// getName() method
class Game {
public:
  virtual std::string getName() = 0; // Returns the name of the game
  virtual void
  play(std::vector<Player> &players,
       std::vector<std::string> &deadPlayers) = 0; // Plays the game
};

// Define a RedLightGreenLight game that inherits from the Game class
class RedLightGreenLight : public Game {
public:
  // Returns the name of the game
  std::string getName() override { return "RedLightGreenLight"; }

  // Play the RedLightGreenLight game
  void play(std::vector<Player> &players,
            std::vector<std::string> &deadPlayers) override {
    // Generate a random game score between 1 and 50
    int gameScore = rand() % 50 + 1;

    // Iterate over all players
    for (Player &player : players) {
      // Only consider players who are still alive
      if (player.alive) {
        // Calculate the player's score as the sum of a random number, their
        // luck, and their agility
        int playerScore = rand() % 101 + player.luck + player.agility;

        // If the player's score is less than the game score, the player dies
        if (playerScore < gameScore) {
          player.alive = false;
          deadPlayers.push_back(player.name);
        }
      }
    }
  }
};

// Define a RockPaperScissors game that inherits from the Game class
class RockPaperScissors : public Game {
public:
  // Returns the name of the game
  std::string getName() override { return "RockPaperScissors"; }

  // Play the RockPaperScissors game
  void play(std::vector<Player> &players,
            std::vector<std::string> &deadPlayers) override {
    // Create a list of alive players
    std::vector<Player *> alivePlayers;
    for (Player &player : players) {
      if (player.alive) {
        alivePlayers.push_back(&player);
      }
    }

    // Continue the game as long as there are at least 2 players
    while (alivePlayers.size() >= 2) {
      // Select two players for the game
      int index1 = rand() % alivePlayers.size();
      Player *player1 = alivePlayers[index1];
      alivePlayers.erase(alivePlayers.begin() + index1);

      int index2 = rand() % alivePlayers.size();
      Player *player2 = alivePlayers[index2];
      alivePlayers.erase(alivePlayers.begin() + index2);

      // Each player makes a move (rock, paper, or scissors)
      int roll1 = rand() % 3;
      int roll2 = rand() % 3;

      // Determine the winner based on the rules of Rock Paper Scissors
      if ((roll1 == 0 && roll2 == 2) || (roll1 == 1 && roll2 == 0) ||
          (roll1 == 2 && roll2 == 1)) {
        // Player 1 wins, so player 2 is marked as dead
        player2->alive = false;
        deadPlayers.push_back(player2->name);
      } else if ((roll2 == 0 && roll1 == 2) || (roll2 == 1 && roll1 == 0) ||
                 (roll2 == 2 && roll1 == 1)) {
        // Player 2 wins, so player 1 is marked as dead
        player1->alive = false;
        deadPlayers.push_back(player1->name);
      } else {
        // In case of a tie, the player with the higher luck wins
        if (player1->luck > player2->luck) {
          player2->alive = false;
          deadPlayers.push_back(player2->name);
        } else if (player2->luck > player1->luck) {
          player1->alive = false;
          deadPlayers.push_back(player1->name);
        } else {
          // If both players have the same luck, one is chosen randomly to be
          // the loser
          if (rand() % 2 == 0) {
            player2->alive = false;
            deadPlayers.push_back(player2->name);
          } else {
            player1->alive = false;
            deadPlayers.push_back(player1->name);
          }
        }
      }
    }
  }
};

// Define a TugOfWar game that inherits from the Game class
class TugOfWar : public Game {
public:
  // Returns the name of the game
  std::string getName() override { return "TugOfWar"; }

  // Play the TugOfWar game
  void play(std::vector<Player> &players,
            std::vector<std::string> &deadPlayers) override {
    // Create a list of alive players
    std::vector<Player *> alivePlayers;
    for (Player &player : players) {
      if (player.alive) {
        alivePlayers.push_back(&player);
      }
    }

    // Continue the game as long as there are at least 2 players
    while (alivePlayers.size() >= 2) {
      // Determine the team size (maximum of 10)
      int teamSize = std::min(10, static_cast<int>(alivePlayers.size() / 2));
      std::vector<Player *> team1, team2;

      // Create two teams
      for (int i = 0; i < teamSize; i++) {
        // Select a player for team 1
        int index = rand() % alivePlayers.size();
        team1.push_back(alivePlayers[index]);
        alivePlayers.erase(alivePlayers.begin() + index);

        // Select a player for team 2
        index = rand() % alivePlayers.size();
        team2.push_back(alivePlayers[index]);
        alivePlayers.erase(alivePlayers.begin() + index);
      }

      // Calculate the total strength and luck of each team
      int strength1 = 0, strength2 = 0;
      int luck1 = 0, luck2 = 0;
      for (Player *player : team1) {
        strength1 += player->strength;
        luck1 += player->luck;
      }
      for (Player *player : team2) {
        strength2 += player->strength;
        luck2 += player->luck;
      }

      // Determine the losing team
      std::vector<Player *> *losingTeam = nullptr;
      if (strength1 > strength2) {
        losingTeam = &team2;
      } else if (strength1 < strength2) {
        losingTeam = &team1;
      } else if (luck1 > luck2) {
        losingTeam = &team2;
      } else if (luck1 < luck2) {
        losingTeam = &team1;
      } else {
        losingTeam = (rand() % 2 == 0) ? &team1 : &team2;
      }

      // Mark all players in the losing team as dead
      for (Player *player : *losingTeam) {
        player->alive = false;
        deadPlayers.push_back(player->name);
      }
    }
  }
};

// Main function
int main() {
  // Seed the random number generator
  srand(time(0));

  // Create 456 players
  std::vector<Player> players;
  for (int i = 1; i <= 456; i++) {
    players.push_back({"Player #" + std::to_string(i), rand() % 10 + 1,
                       rand() % 10 + 1, rand() % 10 + 1, true});
  }

  // Create a list of games
  std::vector<std::unique_ptr<Game>> games;
  games.push_back(std::make_unique<RedLightGreenLight>());
  games.push_back(std::make_unique<TugOfWar>());
  games.push_back(std::make_unique<RockPaperScissors>());

  // Main game loop
  int turn = 1;
  while (true) {
    // Play a game
    std::vector<std::string> deadPlayers;
    Game *game = games[rand() % games.size()].get();
    game->play(players, deadPlayers);

    // Count the number of alive players
    int aliveCount = 0;
    for (const Player &player : players) {
      if (player.alive) {
        aliveCount++;
      }
    }

    // Print the game results
    std::cout << "[Turn #" << turn << "]\n";
    std::cout << "[Game] " << game->getName() << "\n";
    std::cout << "[Alive] nb : " << aliveCount << "\n";
    std::cout << "[Dead] nb : " << deadPlayers.size() << "\n";

    std::cout << "Player Dead this turn :\n";
    for (const std::string &name : deadPlayers) {
      std::cout << name << ", ";
    }
    std::cout << "\n\n";

    // End the game if there is only one player left
    if (aliveCount <= 1) {
      break;
    }

    turn++;
  }

  // Print the winner
  for (const Player &player : players) {
    if (player.alive) {
      std::cout << "[Victory] " << player.name << "\n";
      break;
    }
  }

  return 0;
}
