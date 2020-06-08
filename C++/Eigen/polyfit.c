#include <Eigen/Core>
#include <Eigen/QR>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
using namespace Eigen;

Eigen::VectorXd polyfit(Eigen::VectorXd xvals, Eigen::VectorXd yvals,
                        int order) {
  assert(xvals.size() == yvals.size());
  assert(order >= 1 && order <= xvals.size() - 1);
  Eigen::MatrixXd A(xvals.size(), order + 1);

  for (int i = 0; i < xvals.size(); i++)
    A(i, 0) = 1.0;

  for (int j = 0; j < xvals.size(); j++) {
    for (int i = 0; i < order; i++)
      A(j, i + 1) = A(j, i) * xvals(j);
  }

  auto Q = A.householderQr(); // 对矩阵A进行QR分解
  auto result = Q.solve(yvals);
  return result;
}

double polyeval(Eigen::VectorXd coeffs, double x) {
  double result = 0.0;
  for (int i = 0; i < coeffs.size(); i++) {
    result += coeffs[i] * pow(x, i);
  }
  return result;
}

int main() {
  VectorXd x_veh(8);
  VectorXd y_veh(8);
  x_veh << 1, 2, 3, 4, 5, 6, 7, 8;
  y_veh << 2, 1, 4, 3, 6, 5, 8, 7;
  auto coeffs = polyfit(x_veh, y_veh, 3);
  double cte = polyeval(coeffs, 0.0);
  // double epsi = atan(coeffs[1]);
  // cout << "output coeffs size is :" << coeffs.size() << endl;
  cout << "output fit polynomial is : " << endl << coeffs << endl;
  cout << "output cte is : " << cte << endl;
  // cout << "output epsi is : " << epsi << endl;

  // vector<double> next_sx(8);
  // vector<double> next_sy(8);
  // double D = 5;
  // for (int i = 0; i < 8; ++i)
  // {

  // 	const double dx = D * i;
  // 	const double dy = coeffs[3] * dx * dx * dx + coeffs[2] * dx * dx +
  // coeffs[1] * dx + coeffs[0];

  // 	next_xs[i] = dx;
  // 	next_ys[i] = dy;
  // }
  return 0;
}
