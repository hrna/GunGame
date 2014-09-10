
class GameEngine {
private:
	int random_hit;
	bool rollOn;
	int damage;
	int rTurn;
public:
	int doDamage(int accuracy);
	int battle(int playeraccu, int cpuaccu);
};