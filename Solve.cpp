#include "Header.h"

nc::NdArray<double> function_of_kernel(1, 5);
std::vector<double>values_of_h;
double differ_of_h = 0.0;
double e_error = 1.0; //величина ошибки
double cost_of_game_v = 0.0; //цена игры

void enter_values_of_kernel_function(int argc, char* argv[]) //ввод матрицы и проверка на ввод
{
    std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUWXYZабвгдеёжзийклмнопрстуфзцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    size_t count_argv = 1;
    if (argc <= 4)
    {
        std::cout << "Не все числа введены" << std::endl;
        exit(1);
    }
    if (argc > 6)
    {
        std::cout << "Слишком много данных. Учитываются только  первые 5 чисел" << std::endl;
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
        std::cout << "Введена буква" << std::endl;
        exit(1);
    }
    for (size_t index_row = 0; index_row < 5; ++index_row)
    {

        if (count_argv <= 5)
        {
            function_of_kernel[index_row] = std::stod(argv[count_argv]);

            count_argv++;
        }
        else
            break;

        std::cout << std::endl;
    }
}



void analitic_method() //расчёт аналитическим методои
{
    if (2 * function_of_kernel[0] < 0 && 2 * function_of_kernel[1]>0)
    {
        ;
    }
    function_of_kernel.print();
   // std::cout << "x=-(cy+d)/2a=" << "y*" << function_of_kernel[2] << "+(" << function_of_kernel[3] << "/" << 2 * function_of_kernel[0] << ")" << std::endl;
  //  std::cout << "y=-(cx+e)/2b=" << "x*" << function_of_kernel[2] << "+(" << function_of_kernel[4] << "/" << 2 * function_of_kernel[1] << ")" << std::endl;
  //  std::cout << std::endl;
  //  std::cout << "psi(y)=" << "y*" << function_of_kernel[2] << "+(" << function_of_kernel[3] << "/" << 2 * function_of_kernel[0] << ")," << "y>=" << -(function_of_kernel[3] / function_of_kernel[2]) << std::endl;
  //  std::cout << "psi(y)=0,y<" << -(function_of_kernel[3] / function_of_kernel[2]) << std::endl;
  //  std::cout << std::endl;
  //  std::cout << "fi(x)=" << "x*" << function_of_kernel[2] << "+(" << function_of_kernel[4] << "/" << 2 * function_of_kernel[0] << ")," << "x<=" << -(function_of_kernel[4] / function_of_kernel[2]) << std::endl;
 //   std::cout << "fi(x)=0,x>" << -(function_of_kernel[4] / function_of_kernel[2]) << std::endl;
 //   std::cout << std::endl;
    std::cout << "Вывод оптимальных стратегий" << std::endl;
    double x = (-2.0 * function_of_kernel[1] * function_of_kernel[3] + function_of_kernel[2] * function_of_kernel[4]) / (-function_of_kernel[2] * function_of_kernel[2] + 4.0 * function_of_kernel[1] * function_of_kernel[0]);
    if (x < 0.0)
    {
        x = 0.0;
    }
    std::cout << "x=" << x << std::endl;
    double y = floor((-((function_of_kernel[2] * x + function_of_kernel[4]) / (2 * function_of_kernel[1]))) * 10) / 10;
    std::cout << "y=" << y << std::endl;
    double H_x_y = function_of_kernel[0] * powf(x, 2) + function_of_kernel[1] * powf(y, 2) + function_of_kernel[2] * x * y + function_of_kernel[3] * x + function_of_kernel[4] * y;
    std::cout << "Значение функции выигрыша" << std::endl;
    std::cout << "H(x,y)=" << H_x_y << std::endl;
    values_of_h.push_back(H_x_y);

}

void braun_robin() //алгоритм Брауна-Робинсона
{
    //std::fstream result_file("C:\\МГТУ\\ТеорияИгр\\Lab1-Braun-Robins\\Lab1-Braun-Robins\\table.csv", std::ios_base::out | std::ios_base::trunc);
    double N = 2.0;
    // result_file.open("table.csv", std::ios::app| std::ios::out);

    std::vector<double> wins_of_A; //выиграш игрока А
    std::vector<double> loses_of_B;//проигрыш игрока В

    std::vector<double> high_cost_of_game; // среднии значения верхней цены игры
    std::vector<double>::iterator iterator_of_high_cost_of_game;
    std::vector<double> low_cost_of_game; // среднии значения нижней цены игры
    std::vector<double>::iterator iterator_of_low_cost_of_game;
    double count = 1.0; //количество шагов 
    int pos_min_element_of_high_cost_of_game = 0; //позиция минимального элемента в массиве средних значений верхней цены игры
    int pos_max_element_of_low_cost_of_game = 0; //позиция максимального элемента в массиве средних значений верхней цены игры
    int pos_max_win_of_A = 0;
    int pos_min_lose_of_B = 0;

    double h = 0.0;
    double x = 0.0; //численное решение стратегии 1-го игрока
    double y = 0.0; //численное решение стратегии 2-го игрока
  //  int count_sedl = 0;


    do
    {
        nc::NdArray<double> matrix_H(N + 1, N + 1);
        nc::NdArray<double> copy_of_matrix_H(N + 1, N + 1);
        std::vector<int>choose_of_A(N + 1);
        std::vector<int>choose_of_B(N + 1);

        for (int index_row = 0; index_row < N + 1; ++index_row)
        {
            for (int index_col = 0; index_col < N + 1; ++index_col)
            {
                matrix_H(index_row, index_col) = floor((function_of_kernel[0] * powf(double(index_row) / N, 2) + function_of_kernel[1] * powf(double(index_col) / N, 2) + function_of_kernel[2] * (double(index_row) / N) * (double(index_col) / N) + function_of_kernel[3] * (double(index_row) / N) + function_of_kernel[4] * (double(index_col) / N)) * 1000) / 1000;
            }
        }

       // std::cout << matrix_H.min(nc::Axis::ROW) << " " << matrix_H.max(nc::Axis::COL) << std::endl;
       // std::cout << nc::max(matrix_H.min(nc::Axis::ROW)) << " - " << nc::min(matrix_H.max(nc::Axis::COL)) << std::endl;

        if (nc::min(matrix_H.max(nc::Axis::ROW)).toStlVector() != nc::max(matrix_H.min(nc::Axis::COL)).toStlVector()) //COL-строка, ROW-столбец
        {
           
            std::cout << "N=" << N << std::endl;
            for (auto i = 0; i < N + 1; ++i)
            {
                for (auto j = 0; j < N + 1; ++j)
                {
                    std::cout << std::fixed << std::setprecision(3) << matrix_H(i, j) << "\t";
                }
                std::cout << std::endl;
            }
            std::cout << "Седловой точки нет, решение методом Брауна - Робинсон" << std::endl;

            wins_of_A = matrix_H(matrix_H.rSlice(), 1).toStlVector();
            loses_of_B = matrix_H(1, matrix_H.rSlice()).toStlVector();
            count = 1;
            std::vector<double>::iterator max_result_of_A;
            max_result_of_A = std::max_element(wins_of_A.begin(), wins_of_A.end());
            pos_max_win_of_A = std::distance(wins_of_A.begin(), max_result_of_A);

            choose_of_A[pos_max_win_of_A] += 1;
            std::vector<double>::iterator min_result_of_B;
            min_result_of_B = std::min_element(loses_of_B.begin(), loses_of_B.end());
            pos_min_lose_of_B = std::distance(loses_of_B.begin(), min_result_of_B);
            choose_of_B[pos_min_lose_of_B] += 1;

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
                        std::transform(loses_of_B.begin(), loses_of_B.end(), matrix_H(index, matrix_H.rSlice()).toStlVector().begin(), loses_of_B.begin(), std::plus<double>());
                        choose_of_A[index] += 1;
                    }


                    if (pos_min_lose_of_B == index)
                    {
                        std::transform(wins_of_A.begin(), wins_of_A.end(), matrix_H(matrix_H.rSlice(), index).toStlVector().begin(), wins_of_A.begin(), std::plus<double>());
                        choose_of_B[index] += 1;
                    }
                }

                max_result_of_A = std::max_element(wins_of_A.begin(), wins_of_A.end());
                pos_max_win_of_A = std::distance(wins_of_A.begin(), max_result_of_A);

                min_result_of_B = std::min_element(loses_of_B.begin(), loses_of_B.end());
                pos_min_lose_of_B = std::distance(loses_of_B.begin(), min_result_of_B);

                high_cost_of_game.push_back(wins_of_A.at(pos_max_win_of_A) * 1.0 / count);
                //подсчёт среднего значения нижней цены игры
                low_cost_of_game.push_back(loses_of_B.at(pos_min_lose_of_B) * 1.0 / count);
                //поиск минимального элемента среди значений верхней цены игры
                iterator_of_high_cost_of_game = std::min_element(high_cost_of_game.begin(), high_cost_of_game.end());
                pos_min_element_of_high_cost_of_game = std::distance(high_cost_of_game.begin(), iterator_of_high_cost_of_game);
                //поиск максимального элемента среди значений верхней цены игры
                iterator_of_low_cost_of_game = std::max_element(low_cost_of_game.begin(), low_cost_of_game.end());
                pos_max_element_of_low_cost_of_game = std::distance(low_cost_of_game.begin(), iterator_of_low_cost_of_game);

                //вычисление величины ошибки
                e_error = high_cost_of_game.at(pos_min_element_of_high_cost_of_game) - low_cost_of_game.at(pos_max_element_of_low_cost_of_game);



            } while (e_error > 0.1);

            std::cout << std::endl;
            for (auto i = 0; i < N + 1; i++)
            {
                for (auto j = 0; j < N + 1; j++)
                {
                    h += matrix_H(i, j) * (choose_of_A[i] / count) * (choose_of_B[j] / count);
                }
            }
            std::cout << "h=" << h << " ";

            for (auto i = 0; i < N + 1; ++i)
            {
                for (auto j = 0; j < N + 1; ++j)
                {
                    copy_of_matrix_H(i, j) = nc::abs(h - matrix_H(i, j));
                }
            }

            nc::NdArray<double>::iterator min_copy_of_H;
            min_copy_of_H = std::min_element(copy_of_matrix_H.begin(), copy_of_matrix_H.end());
            size_t flag = 0;
            for (auto i = 0; i < N + 1; ++i)
            {
                for (auto j = 0; j < N + 1; ++j)
                {
                    if (copy_of_matrix_H(i, j) == *min_copy_of_H)
                    {
                        x = double(i) / N;
                        y = double(j) / N;
                        std::cout << "x=" << x << " y=" << y << std::endl;
                       
                        values_of_h.push_back(matrix_H(i, j));
                       
                        flag = 1;
                        break;
                    }

                }
                if (flag == 1)
                {
                    flag = 0;
                    break;
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
            std::cout << std::setprecision(0) << "N=" << N << std::endl;
            for (auto i = 0; i < N + 1; ++i)
            {
                for (auto j = 0; j < N + 1; ++j)
                {
                    std::cout << std::fixed << std::setprecision(3) << matrix_H(i, j) << "\t";
                }
                std::cout << std::endl;
            }
            std::cout << "Есть седловая точка" << std::endl;
            std::cout << "Максимум по столбцам - ";
            std::cout << nc::min(matrix_H.max(nc::Axis::ROW)) << std::endl;
            std::cout << "Минимум по рядам - ";
            std::cout << nc::max(matrix_H.min(nc::Axis::COL)) << std::endl;
            //count_sedl++;
            size_t flag = 0;
            for (int i = 0; i < N + 1; ++i)
            {
                for (int j = 0; j < N + 1; j++)
                {
                   
                    if (matrix_H(i, j) == *(nc::min(matrix_H.max(nc::Axis::ROW)).toStlVector().data()))
                    {
                       // std::cout << "i1=" << i << " j1=" << j << std::endl;
                        std::cout << "x=" << double(i) / N << " y=" << double(j) / N << " H=" << matrix_H(i, j) << std::endl;
                        x = double(i) / N;
                        y = double(j) / N;
                        values_of_h.push_back(matrix_H(i, j));
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    flag = 0;
                    break;
                }
            }
            N++;
            count = 0;

            e_error = 0;

        }

        if (values_of_h.size() == 1)
            differ_of_h = 0.0;
        else
            differ_of_h = std::abs(values_of_h.back() - values_of_h.at(values_of_h.size() - 2));
      /*   for (auto i : values_of_h)
         {
             std::cout << i << " ";
         }
         std::cout << std::endl;*/

    } while (differ_of_h > 0.001 || N < 11);
    std::wcout << "Таким образом, численно найдено решение задачи" << std::endl;
    std::cout << "x=" << x << ", y=" << y << " H=" << values_of_h.back() << std::endl;
}
