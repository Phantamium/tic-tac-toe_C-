#include <iostream>
#include <algorithm>


void drawboard(char *spaces);
void playermove(char *spaces, char player);
void computermove(char *spaces, char computer);
int minimax(char *spaces, char computer, char player, bool isMaximizing, int depth);
bool checkwinner(char *spaces, char player, char computer);
bool checkwinner_silent(char *spaces, char symbol);
bool checktie(char *spaces);

int main(){
    char spaces[9] = {' ', ' ',' ',' ',' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawboard(spaces);

    while (running){
        playermove(spaces, player);
        drawboard(spaces);
        if(checkwinner(spaces, player, computer)){
            running = false;
            break;
        }
        if(checktie(spaces)){
            std::cout << "It's a TIE !!" << "\n";
            running = false;
            break;
        }
        computermove(spaces, computer);
        drawboard(spaces);  
        if(checkwinner(spaces, player, computer)){
            running = false;
            break;
        }
        if(checktie(spaces)){
            std::cout << "It's a TIE !!" << "\n";
            running = false;
            break;
        }
    }
}

void drawboard(char *spaces){
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << "\n";
    // std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "\n";
}
void playermove(char *spaces, char player){
    int number;
    while(true){
        std::cout << "Enter a position (1-9): ";
        std::cin >> number;
        if(number >= 1 && number <= 9){
            if(spaces[number-1] == ' '){
                spaces[number-1] = player;
                break;
            } else {
                std::cout << "That spot is already taken!\n";
            }
        } else {
            std::cout << "Invalid position! Enter 1-9.\n";
        }
    }
}

int minimax(char *spaces, char computer, char player, bool isMaximizing,int depth) {
    if (depth == 0){
        return 0;
    }
    if (checkwinner_silent(spaces, player)) {
        return -1; // Computer loses
    }
    if (checkwinner_silent(spaces, computer)) {
        return 1; // Computer wins
    }
    if (checktie(spaces)) {
        return 0; // Tie
    }
    if (isMaximizing) {
        int bestScore = -9999;
        for (int i = 0; i<9; i++) {
            if (spaces[i] == ' ') {
                spaces[i] = computer; //pretends to place the peice
                bestScore = std::max(bestScore, minimax(spaces, computer, player, false, depth - 1));
                spaces[i] = ' ';
            }
        }
        return bestScore;
    }
    else{
        int bestScore = 9999;
        for (int i = 0; i<9; i++) {
            if (spaces[i] == ' ') {
                spaces[i] = player;
                bestScore = std::min(bestScore, minimax(spaces, computer, player, true, depth - 1));
                spaces[i] = ' ';
            }
        }
        return bestScore;
    }
}
void computermove(char *spaces, char computer){
    // int number;
    // srand(time(0));

    // while(true){
    //     number = rand() % 9;
    //     if(spaces[number] == ' '){
    //         spaces[number] = computer;
    //         break;
    //     }
    // }

    int bestScore = -9999;
    int bestMove = -1;
    char player = 'X';

    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            spaces[i] = computer;
            int score = minimax(spaces, computer, player, false, 6);
            spaces[i] = ' ';
        
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    spaces[bestMove] = computer;    
}

bool checkwinner(char *spaces, char player, char computer){

    //rows
    if((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE HAHAHA\n";
        return true;
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE HAHAHA\n";
        return true;
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE HAHAHA\n";
        return true;
    }
    
    //diagonals
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8])){
        if(spaces[0] == player) {
            std::cout << "YOU WIN!\n";
        } else {
            std::cout << "YOU LOSE HAHAHA\n";
        }
        return true;
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6])){
        if(spaces[2] == player) {
            std::cout << "YOU WIN!\n";
        } else {
            std::cout << "YOU LOSE HAHAHA\n";
        }
        return true;
    }
    
    //columns
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE HAHAHA\n";
        return true;
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE HAHAHA\n";
        return true;
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE HAHAHA\n";
        return true;
    }
    return false;
}

bool checkwinner_silent(char *spaces, char symbol) {
    return ((spaces[0]==symbol && spaces[1]==symbol && spaces[2]==symbol) ||
            (spaces[3]==symbol && spaces[4]==symbol && spaces[5]==symbol) ||
            (spaces[6]==symbol && spaces[7]==symbol && spaces[8]==symbol) ||
            (spaces[0]==symbol && spaces[3]==symbol && spaces[6]==symbol) ||
            (spaces[1]==symbol && spaces[4]==symbol && spaces[7]==symbol) ||
            (spaces[2]==symbol && spaces[5]==symbol && spaces[8]==symbol) ||
            (spaces[0]==symbol && spaces[4]==symbol && spaces[8]==symbol) ||
            (spaces[2]==symbol && spaces[4]==symbol && spaces[6]==symbol));
}

bool checktie(char *spaces){
    for(int i=0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    return true;
}

