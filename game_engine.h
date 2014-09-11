
class GameEngine {
private:
	int random_hit;
	int damage;
	int rTurn;
	bool rollOn;
	int whoWin;
	int winner;
public:
	int doDamage(int accuracy);
	int battle(int playeraccu, int cpuaccu);
	int placeBets();
	int checkBets();
};