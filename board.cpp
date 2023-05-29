#include <iostream>
#include <cstdio>
#include <cstring>
#include <Eigen/Dense>



Eigen::MatrixXf board(int n,int m){
Eigen::MatrixXf board = Eigen::MatrixXf::Zero(n,m);
return board; 
}

int live_judge(Eigen::MatrixXf board,int n, int m)
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

int liveordie(Eigen::MatrixXf board,int n,int m,int count){
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




 Eigen::MatrixXf onegeneration(Eigen::MatrixXf board,int n,int m, int num){
    if (num == 0){
        board(n,m) = 0;
        return board;
    }
    else{
        board(n,m) = 1;
        return board;
    }

}


Eigen::MatrixXf next_result(Eigen::MatrixXf board){
Eigen::MatrixXf nextboard = board;
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

/*
int main(){
//create board
Eigen::MatrixXf onboard;
onboard = board(7,7);
std::cout <<"0世代" << "\n"; 
std::cout << onboard << "\n\n"; 
onboard(1,2) = 1; onboard(2,1) = 1; onboard(2,2) = 1;
std::cout <<"1世代" << "\n"; 
std::cout << onboard << "\n\n"; 
onboard = next_result(onboard);
std::cout <<"2世代" << "\n"; 
std::cout << onboard << "\n\n"; 
onboard = next_result(onboard);
std::cout <<"3世代" << "\n"; 
std::cout << onboard << "\n\n"; 

}
*/
