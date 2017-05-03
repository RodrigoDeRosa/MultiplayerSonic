#include <vector>
#include "Player.hpp"

using namespace std;

class Model{
	vector<Player*>* players;
	public:
		Model();
		void addPlayer(string playerName);
		Player* getPlayer(string name);
		void updatePlayerPosition(string playerName, float velX, float velY);
		void setPlayerPosition(string playerName, float x, float y);
		void setPlayerVelocities(string playerName, float velX, float velY);
		vector<float> getPlayerVelocities(string playerName);
		vector<float> getPlayerPosition(string playerName);
};
