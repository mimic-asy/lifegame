#include <iostream>
#include <cstdio>
#include <cstring>
#include <Eigen/Dense>

Eigen::MatrixXi board(int n, int m)
{
    Eigen::MatrixXi board = Eigen::MatrixXi::Zero(n, m);
    return board;
}

int live_judge(Eigen::MatrixXi board, int n, int m)
{
    int count = 0;
    for (int i = n - 1; i <= n + 1; i++)
    {
        for (int k = m - 1; k <= m + 1; k++)
        {
            if (board(i, k) == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int liveordie(Eigen::MatrixXi board, int n, int m, int count)
{
    if (board(n, m) == 1)
    {
        if (count == 3 || count == 5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (count == 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int liveordie_test(int board, int n, int m, int count)
{
    if (board == 1)
    {
        if (count == 3 || count == 5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (count == 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

Eigen::MatrixXi onegeneration(Eigen::MatrixXi board, int n, int m, int num)
{
    if (num == 0)
    {
        board(n, m) = 0;
        return board;
    }
    else
    {
        board(n, m) = 1;
        return board;
    }
}

Eigen::MatrixXi next_result(Eigen::MatrixXi board)
{
    Eigen::MatrixXi nextboard = board;
    int r = board.rows();
    int c = board.cols();
    int count;
    int num;
    for (int i = 1; i < c - 1; i++)
    {
        for (int k = 1; k < r - 1; k++)
        {
            count = live_judge(board, i, k);
            num = liveordie(board, i, k, count);
            nextboard = onegeneration(nextboard, i, k, num);
        }
    }
    return nextboard;
}

Eigen::MatrixXi first_liveplace(Eigen::MatrixXi board, int y, int x)
{
    int startx = 0;
    int starty = 0;
    while (true)
    {
        std::cout << "開始点のX座標を入力してください(終了: -1) x: ";
        if (!(std::cin >> startx))
        {
            std::cout << "整数入力をお願いします" << std::endl;
            std::cin.clear();
            std::cin.ignore(999, '\n');
            continue;
        }
        if (startx == -1)
        {
            break;
        }
        if (startx < 0 || startx > x || startx == 0)
        {
            std::cout << "エリア外です" << std::endl;
            continue;
        }

        std::cout << "開始点のY座標を入力してください(終了: -1) y: ";
        if (!(std::cin >> starty))
        {
            std::cout << "整数入力をお願いします" << std::endl;
            std::cin.clear();
            std::cin.ignore(999, '\n');
            continue;
        }
        if (starty == -1)
        {
            break;
        }
        if (starty < 0 || starty > y|| starty == 0)
        {
            std::cout << "エリア外です" << std::endl;
            continue;
        }

        board(starty, startx) = 1;
    }
    return board;
}


void cout_generation(Eigen::MatrixXi board,int y, int x){
    Eigen::MatrixXi trimingboard;
    int max_gen;

    for(;;){
        std::cout << "何世代まで進めるか決めてください : "<<std::endl;
        if (!(std::cin >> max_gen))
        {
            std::cout << "整数入力をお願いします" << std::endl;
            std::cin.clear();
            std::cin.ignore(999, '\n');
            continue;
        }
        for(int i = 1 ;i <= max_gen; i++){
            board = next_result(board);
            std::cout << i << "世代\n";
            trimingboard = board.block(1,1,y,x);
            std::cout << trimingboard  << "\n\n";
            }
        break;
        }

    }


Eigen::MatrixXi printnumber(Eigen::MatrixXi board,int y,int x){
for(int n = 0; n < x+1; n++){
    board(0,n) = n;
}
std::cout<< " "<< std::endl;
for(int i = 0; i < y+1; i++){
    board(i,0) = i;
}

return board;
}


int main()
{
    // create board
    Eigen::MatrixXi onboard, trimingboard,only_cout;
    int x, y;
    std::cout << "盤面の大きさを決めてください x : ";
    std::cin >> x;
    std::cout << "盤面の大きさを決めてください y : ";
    std::cin >> y;

    onboard = board(y + 2, x + 2);
    only_cout = printnumber(onboard,y,x);
    trimingboard = only_cout.block(0,0,y+1,x+1);
    std::cout << trimingboard << "\n\n";
    onboard = first_liveplace(onboard, y, x);
    std::cout << "0世代"<< "\n";
    trimingboard = onboard.block(1,1,y,x);
    std::cout << trimingboard  << "\n\n";
    cout_generation(onboard,y,x);

}
