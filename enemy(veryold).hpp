class Enemy{
	private : 
		int xLoc, yLoc,xMax,yMax;
		int energyPoints;
		float damageOutput;
		char enemyAppearance;
		WINDOW *curwin;
		void simpleMovePattern;
	public :
		int enemyDifficulty;
                Enemy(WINDOW *win,int y, int x, int); 
		void registerHit(int x);
		void initSimpleMovePattern();	
		void hitPlayer(int x);

};

Enemy::Enemy(WINDOW *win,int y, int x, int diffLvl){
	curwin = win;
	yLoc = y;
	xLoc = x;
	getmaxyx(curwin, yMax, xMax);
	enemyDifficulty = diffLvl;
	switch (enemyDifficulty){               
		case 1:
		damageOutput = 0.5;
		enemyAppearance = 'L' ;
		energyPoints = 10;
		break;

		case 2:
		damageOutput = 1.0;
		enemyAppearace = 'M' ;
		energyPoints = 20; 
		break;

		case 3:
		damage Output = 2.0;
		enemyAppearance = 'H' ;
		energyPoints = 35 ;
		break;

	};
};

void Enemy::registerHit(int x){
	energyPoints -= x;  
};

void Enemy::simpleMovePattern(){
	srand(time(NULL));             	
	int enemyDirection = rand()%4+1;
	switch(enemyDirection){
		case 1: 
		mvwaddch(curwin, yLoc, xLoc, ' ');    //UP
		yLoc--;
		if(yLoc < 1)
			yLoc = 1;
		break;

		case 2:
		mvwaddch(curwin, yLoc, xLoc, ' ');   //DOWN
    		yLoc++;
    		if(yLoc > yMax-2)
        		yLoc = yMax-2;
		break;

		case 3:
		mvwaddch(curwin, yLoc, xLoc, ' ');   //LEFT
    		xLoc--;
    		if(xLoc < 1)
        		xLoc = 1;
		break;

		case 4:
		mvwaddch(curwin, yLoc, xLoc, ' ');   //RIGHT
    		xLoc++;
    		if(xLoc > xMax-2)
        		xLoc = xMax-2;
		break;
	};	
};
void Enemy:: initSimpleMovePattern(){
	while (energyPoints > 0 /** && GameOver != true*/ ){      //forse puo servire un boolean globale per spezzare tutti i cicli?
		simpleMovePattern();
	};                                                        //devo capire come gestire l'attesa della mossa del player

};

void Enemy::hitPlayer(int x){
	Player.minusHealth(x);                 //uguale a plusHealth, o lo implementiamo o facciamo un metodo generico changeHealth, cambia poco
};

class MeleeEnemy: public Enemy{
	public:
};

class RangedEnemy: public Enemy{
	public:
};

class SummonerEnemy: public Enemy{
	public: 
};















