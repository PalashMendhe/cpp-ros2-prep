class MinimalPublisher : public rclcpp::Node {
public:
    MinimalPublisher() : Node("minimal_publisher") { // create a node named "minimal_publisher"
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10); // create a publisher that publishes a mesage of string type to the topic named "topic" with a queue size of 10
        timer_ = this->create_wall_timer( // cretae a timer that callbacks the timer function every 500ms
            500ms,
            std::bind(&MinimalPublisher::timer_callback, this)); // bind the timer callback function to the timer
    }
private:
    void timer_callback() {
        auto message = std_msgs::msg::String(); //create a message og string type
        message.data = "Hello ROS2"; // set the data
        publisher_->publish(message); // publish the message to the topic
    }
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_; //create a publisher object thta creates a publisher that publishes a message of string type
    rclcpp::TimerBase::SharedPtr timer_; // create a timer object that creates a timer that callbacks the timer function every 500ms
};