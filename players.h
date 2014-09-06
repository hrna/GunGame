
class Players {
private:
	int humanHealth;
	int cpuHealth;
public:
	void reduceHealth(int damage, int player);
	int getHealth(int player);
	int setHealth(int hp);
};

