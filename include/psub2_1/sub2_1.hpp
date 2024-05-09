#ifndef _SUB_HPP_ //중복 방지
#define _SUB_HPP_ 
#include "rclcpp/rclcpp.hpp" //Ros2의 C++라이브러리를 사용하기 위한 헤더 파일을 포함합니다.
#include "std_msgs/msg/int32.hpp" // std_msgs 패키지의 int형 메시지 타입을 사용하기 위한 헤더 파일을 사용합니다.
#include <functional> // 함수 객체를 만들고 바인딩하기 위한 헤더 파일
#include <memory> // make_shared 함수를 사용하기 위한 헤더파일
using std::placeholders::_1;
class Sub : public rclcpp::Node // Sub클레스 선언
{
private:
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_; // 정수형 메시지를 구하기 위한 스마트 포인터
    void subscribe_msg(const std_msgs::msg::Int32::SharedPtr msg) const; //정수형 메시지를 구독할 때 호출되는 콜백 함수
public:
    Sub(); // 생성자
};
#endif //_SUB_HPP_ 헤더 파일 종료
