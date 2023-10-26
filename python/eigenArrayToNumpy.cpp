#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <Eigen/Dense>
#include <iostream>

namespace py = boost::python;
namespace np = boost::python::numpy;

// 将 Eigen::Array 转换为 NumPy 数组
np::ndarray eigenArrayToNumpy(const Eigen::ArrayXd& arr)
{
    np::dtype dtype = np::dtype::get_builtin<double>();
    np::ndarray npArray = np::zeros(py::make_tuple(arr.size()), dtype);
    std::copy(arr.data(), arr.data() + arr.size(), reinterpret_cast<double*>(npArray.get_data()));
    return npArray;
}

// 将 NumPy 数组转换为 Eigen::Array
Eigen::ArrayXd numpyToEigenArray(const np::ndarray& npArray)
{
    if (npArray.get_nd() != 1) {
        throw std::runtime_error("Expected 1-dimensional NumPy array");
    }
    if (npArray.get_dtype() != np::dtype::get_builtin<double>()) {
        throw std::runtime_error("Expected NumPy array of type double");
    }
    int size = npArray.shape(0);
    Eigen::ArrayXd arr(size);
    std::copy(reinterpret_cast<double*>(npArray.get_data()), reinterpret_cast<double*>(npArray.get_data()) + size, arr.data());
    return arr;
}

int main()
{
    // 初始化 Python 解释器
    Py_Initialize();
    np::initialize();

    try {
        // 导入所需的 Python 模块
        boost::python::object main_module = boost::python::import("__main__");
        boost::python::object main_namespace = main_module.attr("__dict__");

        // 测试1：打印 Hello World
        boost::python::exec("print('Hello World!')", main_namespace);

        // 测试2：返回 NumPy 版本信息
        boost::python::exec("import numpy as np\n" "version = np.__version__\n", main_namespace);
        boost::python::object version = main_namespace["version"];

        std::string ver = boost::python::extract<std::string>(version);
        std::cout << "NumPy version = " << ver << std::endl;

        // 测试3：在 Python 中使用 NumPy 处理数组

        // 创建 Eigen::Array
        Eigen::ArrayXd arr(5);
        arr << 1, 2, 3, 4, 5;

        std::cout << arr << std::endl;

        // 将 Eigen::Array 转换为 NumPy 数组
        np::ndarray npArray = eigenArrayToNumpy(arr);

        boost::python::dict globals;
        globals["arr"] = npArray;
        
        boost::python::exec("import numpy as np\n"
                            "squared = np.square(arr)\n", globals, main_namespace);

        // 获取 Python 中的处理结果
        boost::python::object squared = main_namespace["squared"];

        np::ndarray npArray2 = boost::python::extract<np::ndarray>(squared);

        // 将 NumPy 数组转换为 Eigen::Array
        Eigen::ArrayXd result = numpyToEigenArray(boost::python::extract<np::ndarray>(squared));

        // 打印结果
        std::cout << "处理结果: " << result.transpose() << std::endl;
    }
    catch (boost::python::error_already_set const&) {
        PyErr_Print();
    }

    // 清理Python解释器
    Py_Finalize();

    return 0;
}