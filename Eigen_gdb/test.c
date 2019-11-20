#include <iostream>
#include <Eigen/Dense>
// using namespace Eigen;
int main()
{
    Eigen::MatrixXd m(3,3);
    m << 1,2,3,
         4,5,6,
         7,8,9;
    std::cout << "Here is the matrix m:\n" << m << std::endl;
    std::cout << "Here is the sum of m:" << m.sum() << std::endl;
    std::cout << "Here is the min of m:" << m.minCoeff() << std::endl;
    std::cout << "Here is the trace of m:" << m.trace() << std::endl;
    std::cout << "rows is : " << m.rows() << "\n" << "cols is : " << m.cols() << std::endl;
    Eigen::MatrixXd m_t = m.transpose();
    std::cout << "Here is the matrix transpose of m:\n" << m_t << std::endl;
    Eigen::MatrixXd m_i = m.inverse();
    std::cout << "Here is the matrix inverse of m:\n" << m_i << std::endl;
    Eigen::MatrixXd m_b = m.block(1,1,2,2);
    std::cout << "Here is the matrix block of m:\n" << m_b << std::endl;
    Eigen::Matrix4d m_identity = Eigen::Matrix4d::Identity() ;
    std::cout << "Here is the identity matrix :\n" << m_identity << std::endl;
    Eigen::MatrixXd m_random = Eigen::MatrixXd::Random(5,4) ;
    std::cout << "Here is the random matrix :\n" << m_random << std::endl;
    Eigen::MatrixXd m_zero = Eigen::MatrixXd::Zero(2,4) ;
    std::cout << "Here is the zero matrix :\n" << m_zero << std::endl;

}