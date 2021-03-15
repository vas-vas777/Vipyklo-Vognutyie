#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
//#include "matplotlibcpp.h"
#include "C:\����\���������\NumCpp-master\include\NumCpp\Linalg.hpp"
#include "C:\����\���������\NumCpp-master\include\NumCpp\NdArray.hpp"
//#include "C:\����\���������\NumCpp-master\include\NumCpp\Functions\min.hpp"
//#include "C:\����\���������\NumCpp-master\include\NumCpp\Functions\max.hpp"
//#include "C:\����\���������\NumCpp-master\include\NumCpp\Functions\amax.hpp"
//#include "C:\����\���������\NumCpp-master\include\NumCpp\Functions\amin.hpp"
#include "C:\����\���������\NumCpp-master\include\NumCpp\Functions.hpp"
//#include "C:\\Users\\�������\\AppData\\Local\\Programs\\Python\\Python37\\Lib\\site-packages\\numpy\\linalg


//namespace plt = matplotlibcpp;
//namespace linal = nc::linalg;
//std::vector<std::vector<double>> matrix_H = { {0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0} }; //������� �
//nc::NdArray<double> matrix_H;
//nc::NdArray<double> optimal_strategy_x = { 0.0 };
//nc::NdArray<double> optimal_strategy_y = { 0.0 };
nc::NdArray<double> function_of_kernel(1, 5);
//std::vector<std::vector<double>> reverse_matrix_C = { {0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0} }; //�������� ������� � ������� �
//std::vector<std::vector<double>> optimal_strategy_x = { { 0.0,0.0,0.0 } }; //����������� ��������� �*
//std::vector<std::vector<double>> optimal_strategy_y = { { 0.0}, {0.0}, {0.0} }; //����������� ��������� �*
//std::vector<double> graph_of_errors;




double e_error = 1.0; //�������� ������
double cost_of_game_v = 0.0; //���� ����

void enter_values_of_kernel_function(int argc, char* argv[]) //���� ������� � �������� �� ����
{
    std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUWXYZ�������������������������������������Ũ��������������������������";
    size_t count_argv = 1;
    if (argc <= 4)
    {
        std::cout << "�� ��� ����� �������" << std::endl;
        exit(1);
    }
    if (argc > 6)
    {
        std::cout << "������� ����� ������. ����������� ������  ������ 5 �����" << std::endl;
    }
    std::string str_argv = "";
    for (size_t index = 1; index < argc; ++index)
    {
        if (index < 6)
        {
            str_argv += std::string(argv[index]);
        }
        else
            break;
    }
    if (str_argv.find_first_of(letters) != std::string::npos)
    {
        std::cout << "������� �����" << std::endl;
        exit(1);
    }
    for (size_t index_row = 0; index_row < 5; ++index_row)
    {
        //for (size_t index_column = 0; index_column < 3; ++index_column
       // {
            if (count_argv <= 5)
            {
                function_of_kernel[index_row] = std::stod(argv[count_argv]);
                
                count_argv++;
            }
            else
                break;
       // }
        std::cout << std::endl;
    }
}



void analitic_method() //������ ������������� �������
{
    if (2 * function_of_kernel[0] < 0 && 2 * function_of_kernel[1]>0)
    {
        ;
    }
    function_of_kernel.print();
    std::cout << "x=-(cy+d)/2a=" << "y*" << function_of_kernel[2] << "+" << function_of_kernel[3] << "/" << 2 * function_of_kernel[0] << std::endl;
    std::cout << "y=-(cx+e)/2b=" << "x*" << function_of_kernel[2] << "+" << function_of_kernel[4] << "/" << 2 * function_of_kernel[1] << std::endl;
    std::cout << "psi(y)=" << "y*" << function_of_kernel[2] << "+" << function_of_kernel[3] << "/" << 2 * function_of_kernel[0] << "," << "y>=" << -(function_of_kernel[3] / function_of_kernel[2]) << std::endl;
    std::cout << "psi(y)=0,y<" << -(function_of_kernel[3] / function_of_kernel[2]) << std::endl;
    std::cout << "fi(x)=" << "x*" << function_of_kernel[2] << "+" << function_of_kernel[4] << "/" << 2 * function_of_kernel[0] << "," << "x<=" << -(function_of_kernel[4] / function_of_kernel[2]) << std::endl;
    std::cout << "fi(x)=0,x>" << -(function_of_kernel[4] / function_of_kernel[2]) << std::endl;
    double x = (-2.0 * function_of_kernel[1] * function_of_kernel[3] + function_of_kernel[2] * function_of_kernel[4]) / (-function_of_kernel[2]*function_of_kernel[2] + 4.0 * function_of_kernel[1] * function_of_kernel[0]);
    if (x < 0.0)
    {
        x = 0.0;
    }
    std::cout << "x=" << x<< std::endl;
    double y = floor((-((function_of_kernel[2] * x + function_of_kernel[4]) / (2 * function_of_kernel[1])))*10)/10;
    std::cout << "y=" << y << std::endl;
    /*double y = -((function_of_kernel[2] * x + function_of_kernel[4]) / (2 * function_of_kernel[1]));
    std::cout << "y=" << y << std::endl;*/
    double H_x_y = function_of_kernel[0] * powf(x, 2) + function_of_kernel[1] * powf(y, 2) + function_of_kernel[2] * x * y + function_of_kernel[3] * x + function_of_kernel[4] * y;
    std::cout << "H(x,y)" << H_x_y << std::endl;
   // x = 0.25; y = 0.75;
    ///std::cout << function_of_kernel[0] * powf(x, 2) + function_of_kernel[1] * powf(y, 2) + function_of_kernel[2] * x * y + function_of_kernel[3] * x + function_of_kernel[4] * y << std::endl;
}

void braun_robin() //�������� ������-���������
{
    //std::fstream result_file("C:\\����\\���������\\Lab1-Braun-Robins\\Lab1-Braun-Robins\\table.csv", std::ios_base::out | std::ios_base::trunc);
    double N = 2.0;
    // result_file.open("table.csv", std::ios::app| std::ios::out);

    std::vector<double> wins_of_A; //������� ������ �
    std::vector<double> loses_of_B;//�������� ������ �
    
    std::vector<double> high_cost_of_game; // ������� �������� ������� ���� ����
    std::vector<double>::iterator iterator_of_high_cost_of_game;
    std::vector<double> low_cost_of_game; // ������� �������� ������ ���� ����
    std::vector<double>::iterator iterator_of_low_cost_of_game;
    double count = 1.0; //���������� ����� 
    int pos_min_element_of_high_cost_of_game = 0; //������� ������������ �������� � ������� ������� �������� ������� ���� ����
    int pos_max_element_of_low_cost_of_game = 0; //������� ������������� �������� � ������� ������� �������� ������� ���� ����
    int pos_max_win_of_A = 0;
    int pos_min_lose_of_B = 0;

    double h = 0.0;
    int count_sedl = 0;
    
    std::vector<double>values_of_h;

    do
    {
        nc::NdArray<double> matrix_H(N+1,N+1);
        nc::NdArray<double> copy_of_matrix_H(N+1,N+1);
        std::vector<int>choose_of_A(N+1);
        std::vector<int>choose_of_B(N+1);
       
        for (int index_row = 0; index_row < N + 1; ++index_row)
        {
                for (int index_col = 0; index_col < N + 1; ++index_col)
                {
                    matrix_H(index_row,index_col) = function_of_kernel[0] * powf(double(index_row) / N, 2) + function_of_kernel[1] * powf(double(index_col) / N, 2) + function_of_kernel[2] * (double(index_row) / N) * (double(index_col) / N) + function_of_kernel[3] * (double(index_row) / N) + function_of_kernel[4] * (double(index_col) / N);
                }
        }
       // matrix_H.print();
        std::cout << "max cols - ";
        std::cout << nc::min(matrix_H.max(nc::Axis::ROW)) << std::endl;
        std::cout << "min rows - ";
        std::cout << nc::max(matrix_H.min(nc::Axis::COL)) << std::endl;

        if (nc::min(matrix_H.max(nc::Axis::ROW)).toStlVector() != nc::max(matrix_H.min(nc::Axis::COL)).toStlVector())
        {
            std::cout << "not_sedl_N=" << N << std::endl;
            wins_of_A = matrix_H(matrix_H.rSlice(), 1).toStlVector();
            loses_of_B = matrix_H(1, matrix_H.rSlice()).toStlVector();
            count = 1;
            std::vector<double>::iterator max_result_of_A;
            max_result_of_A = std::max_element(wins_of_A.begin(), wins_of_A.end());
            pos_max_win_of_A = std::distance(wins_of_A.begin(), max_result_of_A);
           // std::cout << pos_max_win_of_A << std::endl;
            choose_of_A[pos_max_win_of_A] += 1;
            std::vector<double>::iterator min_result_of_B;
            min_result_of_B = std::min_element(loses_of_B.begin(), loses_of_B.end());
            pos_min_lose_of_B = std::distance(loses_of_B.begin(), min_result_of_B);
            choose_of_B[pos_min_lose_of_B] += 1;
           // std::cout << pos_min_lose_of_B << std::endl;
            high_cost_of_game.push_back(wins_of_A.at(pos_max_win_of_A) * 1.0 / count);
            low_cost_of_game.push_back(loses_of_B.at(pos_min_lose_of_B) * 1.0 / count);
            e_error = high_cost_of_game.back() - low_cost_of_game.back();

            do
            {
                count++;
                for (auto index = 0; index < N + 1; ++index)
                {
                    if (pos_max_win_of_A == index)
                    {
                       // std::cout << pos_max_win_of_A << std::endl;
                        std::transform(loses_of_B.begin(), loses_of_B.end(), matrix_H(index, matrix_H.rSlice()).toStlVector().begin(), loses_of_B.begin(), std::plus<double>());
                        //choose_of_A[index] += 1;
                        choose_of_A[index] += 1;
                    }
                    

                    if (pos_min_lose_of_B == index)
                    {
                        std::transform(wins_of_A.begin(), wins_of_A.end(), matrix_H(matrix_H.rSlice(),index).toStlVector().begin(), wins_of_A.begin(), std::plus<double>());
                      //  std::cout << pos_min_lose_of_B << std::endl;
                       choose_of_B[index] += 1;
                    }
                }

                max_result_of_A = std::max_element(wins_of_A.begin(), wins_of_A.end());
                pos_max_win_of_A = std::distance(wins_of_A.begin(), max_result_of_A);

                min_result_of_B = std::min_element(loses_of_B.begin(), loses_of_B.end());
                pos_min_lose_of_B = std::distance(loses_of_B.begin(), min_result_of_B);

                high_cost_of_game.push_back(wins_of_A.at(pos_max_win_of_A) * 1.0 / count);
                //������� �������� �������� ������ ���� ����
                low_cost_of_game.push_back(loses_of_B.at(pos_min_lose_of_B) * 1.0 / count);
                //����� ������������ �������� ����� �������� ������� ���� ����
                iterator_of_high_cost_of_game = std::min_element(high_cost_of_game.begin(), high_cost_of_game.end());
                pos_min_element_of_high_cost_of_game = std::distance(high_cost_of_game.begin(), iterator_of_high_cost_of_game);
                //����� ������������� �������� ����� �������� ������� ���� ����
                iterator_of_low_cost_of_game = std::max_element(low_cost_of_game.begin(), low_cost_of_game.end());
                pos_max_element_of_low_cost_of_game = std::distance(low_cost_of_game.begin(), iterator_of_low_cost_of_game);
                
                //���������� �������� ������
                e_error = high_cost_of_game.at(pos_min_element_of_high_cost_of_game) - low_cost_of_game.at(pos_max_element_of_low_cost_of_game);

                         

            } while (e_error>0.1);
                        
           /* for (auto i : choose_of_A)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            for (auto i : choose_of_B)
            {
                std::cout << i << " ";
            }*/
            std::cout << std::endl;
                for (auto i = 0; i < N + 1; i++)
                {
                    for (auto j = 0; j < N + 1; j++)
                    {
                       // std::cout << matrix_H(i, j) << " " << choose_of_A[i] / count << " " << choose_of_B[j] / count << std::endl;
                        h += matrix_H(i, j) * (choose_of_A[i] / count) * (choose_of_B[j] / count);
                    }
                }
                std::cout << "h=" << h << std::endl;
            
            for (auto i = 0; i < N + 1; ++i)
            {
                for (auto j = 0; j < N + 1; ++j)
                {
                    copy_of_matrix_H(i, j) = nc::abs(h- matrix_H(i, j));
                }
            }
          //  matrix_H.print();
           // copy_of_matrix_H.print();
            nc::NdArray<double>::iterator min_copy_of_H;
            min_copy_of_H = std::min_element(copy_of_matrix_H.begin(), copy_of_matrix_H.end());
           // std::cout << *min_copy_of_H << std::endl;
            for (auto i = 0; i < N + 1; ++i)
            {
                for (auto j = 0; j < N + 1; ++j)
                {
                    if (copy_of_matrix_H(i, j) == *min_copy_of_H)
                    {
                        std::cout << "x=" << i << " y=" << j << " " << matrix_H(i, j) <<" "<<*min_copy_of_H<< std::endl;
                        values_of_h.push_back(matrix_H(i, j));
                        break;
                    }
                   
                }
               
            }
                
                N++;
                choose_of_A.clear();
                choose_of_B.clear();
                matrix_H.zeros();
                copy_of_matrix_H.zeros();
                wins_of_A.clear();
                loses_of_B.clear();
                high_cost_of_game.clear();
                low_cost_of_game.clear();
                e_error = 0;
                count = 0;
                h = 0;
            
        }
        else
        {
        std::cout << "sedl_N=" << N << std::endl;
        count_sedl++;
            for (int i = 0; i < (N + 1); ++i)
            {
                for (int j = 0; j < N + 1; j++)
                    if (matrix_H(i, j) == *(nc::min(matrix_H.max(nc::Axis::ROW)).toStlVector().data()))
                    {
                       
                        std::cout << "x=" << double(i) / N << " y=" << double(j) / N << "h=" << matrix_H(i, j) << std::endl;
                        values_of_h.push_back(matrix_H(i, j));
                        break;
                    }
            }
            N++;
            count = 0;
          
            e_error = 0;
            //h = 0;
        }
       
       // values_of_h[0] = h;
       // std::cout << std::abs(values_of_h[0] - values_of_h[1]) << std::endl;
        /*if ((std::abs(values_of_h[0] - values_of_h[1]) < 1.05) && N>2)
        {
            break;
        }
        else*/
        
           // values_of_h[1] = values_of_h[0];
          
           // N++;
           
        
        
        
    } while (N<15);
    for (auto i : values_of_h)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

   
}

void print_analitic_solve() //������ �������������� �������
{
    //std::cout << "x*=(";
    //for (size_t index_column = 0; index_column < 3; ++index_column)
    //{
    //    std::cout << optimal_strategy_x[0][index_column] << " ";  //������ x*
    //}
    //std::cout << ")";
    //std::cout << std::endl;
    //std::cout << "y*=(";
    //for (size_t index_row = 0; index_row < 3; ++index_row)
    //{
    //    std::cout << optimal_strategy_y[index_row][0] << " "; //������ y*
    //}
    //std::cout << ")";
    //std::cout << std::endl;
    //std::cout << "v=" << cost_of_game_v << std::endl;
    /*nc::NdArray<double> matrix = { {1.0,2.0,3.0},{2.0,2.0,6.0},{1.0,54.0,7.0} };
    matrix = nc::linalg::inv(matrix);
    matrix.print();*/

    //plt::plot(graph_of_errors);//���������� �������
    //plt::xlabel("Counts");
    //plt::ylabel("e-error");
    //plt::show();

}