#include "game.h"
#include "game.c"//这是vscode的特殊写法

void menu(){
    printf("*******************\n");
    printf("***1.play  0.exit**\n");
    printf("*******************\n");
}
void game(){
    char board[ROW][COL] = {0};
    char ret = {0};
    //初始化
    InitBoard(board,ROW,COL);
    //打印出来空盘
    PrintBoard(board,ROW,COL);
    while(1){
        //玩家下棋
        PlayerMove(board,ROW,COL); 
        PrintBoard(board,ROW,COL);
        ret= IsWin(board,ROW,COL);
        if(ret != 'C'){
            break;
        }
        //电脑下棋
        ComputerMove(board,ROW,COL);
        PrintBoard(board,ROW,COL);
        ret = IsWin(board,ROW,COL);
        if(ret != 'C'){
            break;
        }
    }
    if(ret == '*'){
        printf("恭喜你获胜！\n");
    }else if(ret == '#'){
        printf("你输了！\n");
    }else{
        printf("和棋！\n");
    }

}

int main(){
    int input =1;
    srand((unsigned int)time(NULL));
    while(input){
        menu();
        printf("游戏开始！\n");
        printf("选择开始游戏>\n");
        scanf("%d",&input);
        switch (input){
        case 1:
            game();
            break;
        case 0:
            printf("游戏结束!\n");
            break;
        default:
            printf("输入错误!,请重新选择\n");
            break;
        }
    }
    return 0;
}