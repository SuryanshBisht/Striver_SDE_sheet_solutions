// https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
int val[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int findMinimumCoins(int amount) 
{
    int coins = 0, i = 8;
    while(amount){
        if(amount >= val[i]){
            coins += amount / val[i];
            amount %= val[i];
        }
        i--;
    }
    return coins;
}
