#include <gtest/gtest.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <Eigen/Core>
#include "board.hpp"

TEST(live_judgeTest,input1){
    Eigen::MatrixXi board3x3_0 = Eigen::MatrixXi::Zero(3,3);
    EXPECT_EQ(live_judge(board3x3_0, 1, 1),0);
    Eigen::MatrixXi board3x3_1 = Eigen::MatrixXi::Zero(3,3);
    board3x3_1(0,1)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),1);
    board3x3_1(0,2)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),2);
    board3x3_1(0,0)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),3);
    board3x3_1(1,0)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),4);
    board3x3_1(1,1)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),5);
    board3x3_1(1,2)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),6);
    board3x3_1(2,0)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),7);
    board3x3_1(2,1)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),8);
    board3x3_1(2,2)= 1;
    EXPECT_EQ(live_judge(board3x3_1, 1, 1),9);
}


TEST(liveordieTest,Input1){
    EXPECT_EQ(liveordie_test(0,1,1,0),0);
    EXPECT_EQ(liveordie_test(0,1,1,1),0);
    EXPECT_EQ(liveordie_test(0,1,1,2),0);
    EXPECT_EQ(liveordie_test(0,1,1,3),1);
    EXPECT_EQ(liveordie_test(0,1,1,4),0);
    EXPECT_EQ(liveordie_test(0,1,1,5),0);
    EXPECT_EQ(liveordie_test(0,1,1,6),0);
    EXPECT_EQ(liveordie_test(0,1,1,7),0);
    EXPECT_EQ(liveordie_test(0,1,1,8),0);
}


TEST(liveordieTest,Input2){
    EXPECT_EQ(liveordie_test(1,1,1,0),0);
    EXPECT_EQ(liveordie_test(1,1,1,1),0);
    EXPECT_EQ(liveordie_test(1,1,1,2),0);
    EXPECT_EQ(liveordie_test(1,1,1,3),1);
    EXPECT_EQ(liveordie_test(1,1,1,4),1);
    EXPECT_EQ(liveordie_test(1,1,1,5),0);
    EXPECT_EQ(liveordie_test(1,1,1,6),0);
}

TEST(onegeneration,Input1){
    Eigen::MatrixXi board = Eigen::MatrixXi::Zero(7,7);
    EXPECT_EQ(onegeneration(board,1,1,0),board);
    board(1,1) =1 ;
    EXPECT_EQ(onegeneration(board,1,1,1),board);
}

TEST(next_result,Input1){
    Eigen::MatrixXi board = Eigen::MatrixXi::Zero(7,7);
    Eigen::MatrixXi nextboard;
    board(1,2) = 1; board(2,1) = 1; board(2,2) = 1;
    nextboard = next_result(board);
    board(1,1) = 1;
    EXPECT_EQ(nextboard,board);
}
TEST(next_result,Input2){
    Eigen::MatrixXi board = Eigen::MatrixXi::Zero(7,7);
    Eigen::MatrixXi nextboard;
    board(1,1) =1; board(1,3) =1;
    board(2,3) =1; 
    board(3,1) =1; board(3,2) =1; board(3,3) =1;
    nextboard = next_result(board);
    Eigen::MatrixXi board2 = Eigen::MatrixXi::Zero(7,7);
    board2(1,2) = 1; 
    board2(2,1) = 1; board2(2,3) = 1; board2(2,4) = 1; 
    board2(3,2) = 1; board2(3,3) = 1; 
    board2(4,2) = 1; 
    EXPECT_EQ(nextboard, board2);
}

TEST(next_result,Input3){
    Eigen::MatrixXi board = Eigen::MatrixXi::Zero(7,7);
    Eigen::MatrixXi nextboard;
    board(1,2) = 1; board(1,4) = 1;
    board(2,1) = 1; board(2,3) = 1; 
    board(3,2) = 1; board(3,4) = 1; 
    board(4,1) = 1; board(4,3) = 1; 
    nextboard = next_result(board);
    Eigen::MatrixXi board2 = Eigen::MatrixXi::Zero(7,7);
    board2(1,2) = 1; board2(1,3) = 1; 
    board2(2,1) = 1; board2(2,4) = 1; 
    board2(3,1) = 1; board2(3,4) = 1; 
    board2(4,2) = 1; board2(4,3) = 1;

    EXPECT_EQ(nextboard, board2);
}

TEST(next_result,Input4){
    Eigen::MatrixXi board(7,7);
    Eigen::MatrixXi nextboard(7,7);
    board <<  0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,0 ,1 ,0 ,1 ,0 ,0,
              0 ,1 ,0 ,1 ,0 ,1 ,0,
              0 ,1 ,0 ,0 ,0 ,1 ,0,
              0 ,1 ,0 ,0 ,0 ,1 ,0,
              0 ,0 ,1 ,1 ,1 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0;
    
    nextboard = next_result(board);
    Eigen::MatrixXi board2(7,7);
    board2 << 0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,0 ,1 ,1 ,1 ,0 ,0,
              0 ,1 ,0 ,1 ,0 ,1 ,0,
              0 ,1 ,0 ,0 ,0 ,1 ,0,
              0 ,1 ,0 ,1 ,0 ,1 ,0,
              0 ,0 ,1 ,1 ,1 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0;

    EXPECT_EQ(nextboard, board2);
}

TEST(next_result,Input5){
    Eigen::MatrixXi board(7,7);
    Eigen::MatrixXi nextboard(7,7);
    board <<  0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,0 ,1 ,1 ,0 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,1 ,0 ,0 ,1 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,1 ,0 ,0 ,1 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0;
    
    nextboard = next_result(board);
    Eigen::MatrixXi board2(7,7);
    board2 << 0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,0 ,1 ,1 ,0 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0,
              0 ,0 ,0 ,0 ,0 ,0 ,0;

    EXPECT_EQ(nextboard, board2);
}
