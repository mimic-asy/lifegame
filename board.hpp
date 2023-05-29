#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <Eigen/Dense>

Eigen::MatrixXi board(int,int);
int live_judge(Eigen::MatrixXi board,int n, int m);
int liveordie(Eigen::MatrixXi board,int n,int m,int count);
int liveordie_test(int board,int n,int m,int count);
Eigen::MatrixXi onegeneration(Eigen::MatrixXi board,int n,int m, int lvordenum);
Eigen::MatrixXi next_result(Eigen::MatrixXi board);
Eigen::MatrixXi first_liveplace(Eigen::MatrixXi board);