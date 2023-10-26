#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <iostream>

namespace py = boost::python;
namespace np = boost::python::numpy;

int main()
{
    Py_Initialize();
    np::initialize();

    py::object main_module = py::import("__main__");
    py::object main_namespace = main_module.attr("__dict__");

    py::exec("print('Hello World!')", main_namespace);

    // /home/rudy/workspace/FusionPosition/Asensing_LiDAR_Driver/src/ag_driver/driver/decoder/A2/example.py
    py::exec_file("example.py", main_namespace, main_namespace);
    py::object add_func = main_namespace["add"];
    // py::object result = func(1, 2);

    // py::object module = py::import("example");
    // py::object add_func = module.attr("add");
    int result = py::extract<int>(add_func(2, 3));
    std::cout << "The result is: " << result << std::endl;

    return 0;
}