#ifndef _PUB_HPP_ // 중복 포함을 방지하기 위해
#define _PUB_HPP_ 
#include "rclcpp/rclcpp.hpp" // Ros2의 C++라이브러리를 사용하기 위한 헤더 파일을 포함합니다.
#include "std_msgs/msg/int32.hpp" // std_msgs 패키지의 int 메시지 타입을 사용하기 위한 헤더 파일을 사용합니다.
#include <memory> // make_shared 함수를 사용하기 위한 헤더파일
#include <chrono> // 시간과 관련된 기능을 사용하기 위한 헤더파일
using namespace std::chrono_literals;
class Pub : public rclcpp::Node // Pub클레스 선언
{
private:
    rclcpp::TimerBase::SharedPtr timer_; // 타이머를 나타내는 스마트 포인터
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_; // 정수형 메시지를 발행하기 위한 스마트 포인터
    size_t count_; // 발행된 메시지의 수를 저장하는 변수입니다.
    void publish_msg(); // 메시지를 발행하는 함수입니다.
public:
    Pub(); // 생성자
};
#endif //_PUB_HPP_ 헤더 파일 종료
