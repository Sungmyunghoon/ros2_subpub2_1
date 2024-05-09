#include "psub2_1/sub2_1.hpp" // 헤더 파일 포함
int main(int argc, char * argv[]) // main 함수
{
    rclcpp::init(argc, argv); // ROS 2를 초기화
    auto node = std::make_shared<Sub>(); // 클래스의 객체를 생성
    rclcpp::spin(node); // 노드가 종료될 때까지 계속해서 실행
    rclcpp::shutdown();
    return 0;
}
