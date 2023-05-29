#include <iostream>
#include <cstdio>
#include <cstring>
#include <Eigen/Dense>



Eigen::MatrixXi board(int n,int m){
Eigen::MatrixXi board = Eigen::MatrixXi::Zero(n,m);
return board; 
}

int live_judge(Eigen::MatrixXi board,int n, int m)
{
    int count = 0; 
    for (int i = n-1; i <= n+1; i++){
        for (int k = m-1; k <= m+1; k++){
            if (board(i,k) == 1){
                count++;
            }
        }
    }
    return count;
}

int liveordie(Eigen::MatrixXi board,int n,int m,int count){
    if(board(n,m)==1){
        if(count == 3 || count == 4){
            return 1;
        }
        else{
        return 0;
        }
    }
    else{
        if(count == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int liveordie_test(int board,int n,int m,int count){
    if(board == 1){
        if(count == 3 || count == 4){
            return 1;
        }
        else{
        return 0;
        }
    }
    else{
        if(count == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
}




 Eigen::MatrixXi onegeneration(Eigen::MatrixXi board,int n,int m, int num){
    if (num == 0){
        board(n,m) = 0;
        return board;
    }
    else{
        board(n,m) = 1;
        return board;
    }

}


Eigen::MatrixXi next_result(Eigen::MatrixXi board){
Eigen::MatrixXi nextboard = board;
int r = board.rows();
int c = board.cols();
int count;
int num;
for (int i = 1; i < c-1; i++){
    for (int k = 1; k < r-1; k++){
        count = live_judge(board,i,k);
        num = liveordie(board,i,k,count);
        nextboard = onegeneration(nextboard,i,k,num);
    }
}
return nextboard;
}


Eigen::MatrixXi first_liveplace(Eigen::MatrixXi board,int y, int x){
    int startx = 0;
    int starty = 0;
        while (true)
        {
            std::cout << "開始点のX座標を入力してください(終了: -1) x :";
            std::cin >> startx;
            if(std::cin >> startx){
                if(startx == 0 || startx > x){
                    std::cout << "エリア外です" << std::endl;
                    continue; 
                }
                if(startx == -1){
                    break;
                }
            }
            else{   
                std::cout << "整数入力をお願いします" << std::endl;
                std::cin.clear();
                std::cin.ignore(999, '\n');
                continue;
            }
            std::cout << "開始点のY座標を入力してください(終了: -1) y :";
            std::cin >> starty; 
            if(std::cin >> starty){
                if(starty == 0 || starty > x){
                    std::cout << "エリア外です" << std::endl;
                    continue; 
                }
                if(starty == -1){
                    break;
                }
                
                board(starty,startx) = 1;
            }
            else{
                std::cout << "整数入力をお願いします" << std::endl;
                std::cin.clear();
                std::cin.ignore(999, '\n');
                continue;
                
            }

        }
    return board;
}


int main(){
//create board
Eigen::MatrixXi onboard,trimingboard;
int x,y;
std::cout << "盤面の大きさを決めてください x : ";
std::cin >> x;
std::cout << "盤面の大きさを決めてください y : ";
std::cin >> y;

onboard = board(y+2,x+2);
std::cout <<"0世代" << "\n"; 
trimingboard = onboard.block(1,1,y,x);
std::cout << trimingboard << "\n\n"; 

onboard = first_liveplace(onboard,y,x);

std::cout <<"1世代" << "\n"; 
trimingboard = onboard.block(1,1,y,x);
std::cout << trimingboard << "\n\n"; 
onboard = next_result(onboard);
std::cout <<"2世代" << "\n";
trimingboard = onboard.block(1,1,y,x); 
std::cout << trimingboard  << "\n\n"; 
onboard = next_result(onboard);
std::cout <<"3世代" << "\n"; 
trimingboard = onboard.block(1,1,y,x);
std::cout << trimingboard  << "\n\n"; 

}
