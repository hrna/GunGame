
class GameEngine {
private:
	int random_hit;
	int damage;
	int rTurn;
	bool rollOn;
public:
	int doDamage(int accuracy);
	int battle(int playeraccu, int cpuaccu);
};