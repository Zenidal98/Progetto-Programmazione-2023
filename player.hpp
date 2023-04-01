// dove mettere gameover?

class Player{
    private:
        int xLoc, yLoc, xMax, yMax;
        int health;
        int score;
        char character;
        WINDOW *curwin;
        // distanza di attacco
        int distance;
        // potenza di attacco
        int power;
        // soldi
        int coins;
    public:
        Player(WINDOW *win, int x, int y, char c, int h, int s, int d, int p);
        // colpo subito
        void registerHit();
        void plusScore(int points);
        void plusHealth(int hp);
        void minusHealth(int hp);
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();
        void display();
        // aumenta distanza di attacco 
        void distanceUp(int plusD);
        // aumenta potenza di attacco
        void powerUp(int plusP);
        // nemico colpito
        void hitEnemy();
        // gestione soldi
        void plusMoney(int plusM);
        void minusMoney(int minusM);
};