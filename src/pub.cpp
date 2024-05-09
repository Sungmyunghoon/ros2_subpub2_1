#include "psub2_1/pub2_1.hpp" // 헤더파일 포함

Pub::Pub() : Node("mypub"), count_(0) // 클래스의 생성자를 정의
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)); // Publish에 적용할 QoS 프로파일을 설정
    pub_ = this->create_publisher<std_msgs::msg::Int32>("mytopic", qos_profile); // int형 메시지를 발행하는 발행자를 생성
    timer_ = this->create_wall_timer(50ms, std::bind(&Pub::publish_msg, this)); // 타이머를 생성
}
void Pub::publish_msg() // 멤버 함수 정의
{
    static int count = 0; // 변수 선언
    auto msg = std_msgs::msg::Int32(); // Int형 정수 메시지 선언
    msg.data = count++; // 값이 증가되는 것을 메시지에 포함
    RCLCPP_INFO(this->get_logger(), "Published message: '%d'", msg.data); // 메시지 전송
    pub_->publish(msg); // 메시지 발행
}
