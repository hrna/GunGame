
class Players {
private:
	int humanHealth = 100;
	int cpuHealth = 100;
public:
	void reduceHealth(int damage, int player);
	int getHealth(int player);
};

