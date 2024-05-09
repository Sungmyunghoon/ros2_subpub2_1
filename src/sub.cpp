#include "psub2_1/sub2_1.hpp" // 헤더파일 포함
void Sub::subscribe_msg(const std_msgs::msg::Int32::SharedPtr msg) const // 멤버 함수 정의
{
    RCLCPP_INFO(this->get_logger(), "Received number: '%d'", msg->data); //정수형 메시지를 sub할 때 호출되는 callback 함수로 사용
}
Sub::Sub() : Node("mysub") // 클래스의 생성자를 정의
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)); // sub에 적용할 QoS 프로파일을 설정
    sub_ = this->create_subscription<std_msgs::msg::Int32>("mytopic", qos_profile, std::bind(&Sub::subscribe_msg, this, _1));
    //정수형 메시지를 sub하는 구독자를 생성
}
