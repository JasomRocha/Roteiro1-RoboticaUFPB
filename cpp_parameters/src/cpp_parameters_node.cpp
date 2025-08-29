#include <chrono>
#include <functional>
#include <string>
#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

class MinimalParam : public rclcpp::Node
{
public:
  MinimalParam()
  : Node("minimal_param_node")
  {
    // Declara parâmetro com valor padrão "world"
    this->declare_parameter("my_parameter", "world");

    // Cria um timer que chama o callback a cada 1s
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&MinimalParam::timer_callback, this));
  }

private:
  void timer_callback()
  {
    // Obtém o valor do parâmetro
    std::string my_param = this->get_parameter("my_parameter").as_string();

    // Exibe no console
    RCLCPP_INFO(this->get_logger(), "Hello %s!", my_param.c_str());

    // Redefine o parâmetro para "world" após cada iteração (opcional)
    std::vector<rclcpp::Parameter> all_new_parameters{
      rclcpp::Parameter("my_parameter", "world")};
    this->set_parameters(all_new_parameters);
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalParam>());
  rclcpp::shutdown();
  return 0;
}

