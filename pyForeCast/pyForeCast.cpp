#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/chrono.h>
#include <pybind11/operators.h>
#include <optional>


//#include "CoreForeCast/"
using namespace pybind11::literals;
namespace py = pybind11;

void init_diffs(py::module_ &);
void init_exp(py::module_ &);
void init_ew(py::module_ &);
void init_ga(py::module_ &);
void init_roll(py::module_ &);
void init_sc(py::module_ &);
void init_seas(py::module_ &);

namespace arima {
	void init(py::module_ &);
}

namespace ets {
	void init(py::module_ &);
}
namespace theta {
	void init(py::module_ &);
}

PYBIND11_MODULE(pyForeCast, m) {
	// optional module docstring
	m.doc() = "pyForeCast.Amalgamation of StatsForeCast, CoreForecast and SkilList in one place";


	//CoreForeCast
	init_diffs(m);
	init_exp(m);
	init_ew(m);
	init_ga(m);
	init_roll(m);
	init_sc(m);
	init_seas(m);
	// StatsForecast
	arima::init(m);
	ets::init(m);
	theta::init(m);
}
