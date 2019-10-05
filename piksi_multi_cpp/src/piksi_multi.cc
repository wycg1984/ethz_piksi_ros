#include "piksi_multi_cpp/piksi_multi.h"

#include <libsbp/sbp.h>

namespace piksi_multi_cpp {

PiksiMulti::PiksiMulti(const ros::NodeHandle &nh,
                       const ros::NodeHandle &nh_private)
    : nh_(nh), nh_private_(nh_private) {
  getROSParameters();
  advertiseTopics();
}

void PiksiMulti::getROSParameters() {
  nh_private_.getParam("interface", params_.interface);
  nh_private_.getParam("port", params_.port);
}

void PiksiMulti::advertiseTopics() {}

bool PiksiMulti::connect() {
  // Select interface.
  auto interface =
      kStrToInterface.find(params_.interface) != kStrToInterface.end()
          ? kStrToInterface.find(params_.interface)->second
          : Interface::kInvalid;

  // Connect to interface.
  switch (interface) {
  case Interface::kUSB:
    return connectUSB();
  case Interface::kSerial:
    return connectSerial();
  case Interface::kTCP:
    return connectTCP();
  default:
    ROS_ERROR("No valid interface ('usb', 'serial', 'tcp') specified.");
    return false;
  }
}
bool PiksiMulti::disconnect() { return false; }
bool PiksiMulti::read() { return false; }

bool PiksiMulti::connectUSB() { return false; }

bool PiksiMulti::connectSerial() {
  ROS_ERROR("Serial interface not implemented.");
  return false;
}

bool PiksiMulti::connectTCP() {
  ROS_ERROR("TCP interface not implemented.");
  return false;
}

} // namespace piksi_multi_cpp
