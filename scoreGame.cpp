#include <iostream>


int rePosY(int uMove){
    if(uMove == 20)
        return 0;
    else if(uMove == -1)
        return 19;
    else    
        return uMove;
}

int rePosX(int uMove){
    if(uMove == 10)
        return 0;
    else if(uMove == -1)
        return 9;
    else    
        return uMove;
}
int main(){
    std::string user;
    int start = 0;
    int endY = 19;
    int scorePoseY = rand() % (endY - start + 1) + start;
    int endX = 9;
    int scorePoseX = rand() % (endX - start + 1) + start;

    int score = 0;
    int uMoveY = 10, uMoveX = 5;
    while(true){
        for (int x = 0; x < 10; x++){
            for(int y = 0; y < 20; y++){
                if(y == uMoveY && x==uMoveX){
                    std::cout << "0";
                    continue;
                }
                if(y == scorePoseY && x==scorePoseX){
                    std::cout << "#";
                    continue;
                }
                    
                std::cout << "-";
            }
            std::cout <<std::endl;
        }       
        std::cout << uMoveX<< " - x; " << uMoveY << " - y; " << score << " - score;" << std::endl;
        std::cout << "Enter your move:";
        std::cin >> user;
        if(user == "w" || user == "W"){
            uMoveX--;
            uMoveX = rePosX(uMoveX);
        }
        else if(user == "s" || user == "S"){
            uMoveX++;
            uMoveX = rePosX(uMoveX);
        }
        else if(user == "D" || user == "d"){
            uMoveY++;
            uMoveY = rePosY(uMoveY);
        }
        else if(user == "A" || user == "a"){
            uMoveY--;
            uMoveY = rePosY(uMoveY);
        }
        if(uMoveY == scorePoseY && uMoveX ==scorePoseX){
            scorePoseX = rand() % (endX - start + 1) + start;
            scorePoseY = rand() % (endY - start + 1) + start;
            score+=10;
        }
    }
}