#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <Eigen/Dense>

Eigen::MatrixXf board(int,int);
int live_judge(Eigen::MatrixXf board,int n, int m);
int liveordie(Eigen::MatrixXf board,int n,int m,int count);
int liveordie_test(int board,int n,int m,int count);
Eigen::MatrixXf onegeneration(Eigen::MatrixXf board,int n,int m, int lvordenum);
Eigen::MatrixXf next_result(Eigen::MatrixXf board);