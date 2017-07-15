#ifndef _RUNGEKUTA45_H
#define _RUNGEKUTA45_H
#include <Eigen/core>
using namespace Eigen;

typedef VectorXd&(*STATEMODEL)(double& t, VectorXd& y0, VectorXd& dy, const VectorXd& otherPara);

class RungeKuta45
{
public:
	RungeKuta45() :fun_(nullptr), h_(0.0) {};

	RungeKuta45(STATEMODEL fun, double h) :fun_(fun), h_(h) {};

	//VectorXd& integrate(STATEMODEL fun, double& t, VectorXd& y0, VectorXd& dy);
	VectorXd& integrate(double& t, VectorXd& y0, VectorXd& dy, const VectorXd& otherPara);

private:
	STATEMODEL fun_;
	double h_;
};

#endif // !_RUNGEKUTA45_H
