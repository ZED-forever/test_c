#include "game.h"

void InitBoard(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            board[i][j] = ' ';
        }
    }
}
void PrintBoard(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %c ",board[i][j]);
            if(j < col-1){
                printf("|");
            }
        }
        printf("\n");
        if(i < row-1){
            for(j=0;j<col;j++){
                printf("---");
                if(j < col-1){
                    printf("|");
                }
            }
            printf("\n");
        }
        
                
    }
}

void PlayerMove(char board[ROW][COL],int row,int col){
    int x = 0;
    int y = 0;
    printf("玩家移动！\n");
    while(1){
        printf("请输入你的坐标,在一个%d*%d的棋盘上\n",row,col);
        scanf("%d%d",&x,&y);
        if(x >= 1 && x <= row && y >= 1 && y <= col &&board[x-1][y-1] == ' '){
            board[x-1][y-1] = '*';
            break;
        }
        printf("输入坐标错误，请重新输入\n");
    }
}

void ComputerMove(char board[ROW][COL],int row,int col){
    printf("电脑移动！\n");
    while(1){
        int x = rand() % row;
        int y = rand() % col;
        if(board[x][y] == ' '){
            board[x][y] = '#';
            break;
        }
    }
}

char Fill(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(board[i][j] == ' '){
                return 'C';
            }
        }
    }
    return 'Q';
}

char IsWin(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    char tmp = 0;
    int count = 0;
    char flag = 0;
    for(i=0;i<row;i++){
        tmp = board[i][0];
        count = 1;
        for(j=1;j<col;j++){
            if(board[i][j] != tmp || tmp == ' '){
                break;
            }else{
                count +=1;
            }
        }
        if(count == col){
            return board[i][0];
        }
    }
    for(j=0;j<col;j++){
        tmp = board[0][j];
        count = 1;
        for(i=1;i<row;i++){
            if(board[i][j] != tmp || tmp == ' '){
                break;
            }else{
                count +=1;
            }
        }
        if(count == col){
            return board[0][j];
        }
    }
    tmp = board[0][0];
    count = 1;
    for(i=1;i<row;i++){
        j = i;
        if(board[i][j] != tmp || tmp == ' '){
            break;
        }else{
            count +=1;
        }
    }
    if(count == col){
        return board[i][0];
    }
    flag = Fill(board,row,col);
    return flag;
}