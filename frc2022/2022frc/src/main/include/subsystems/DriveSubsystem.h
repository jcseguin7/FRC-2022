/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "ctre/Phoenix.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void Stop();
  void DriveJoystick(std::shared_ptr<Joystick> stick);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  std::shared_ptr<WPI_TalonSRX> driveTalon1 ;
  std::shared_ptr<WPI_TalonSRX> driveTalon2 ;
  std::shared_ptr<WPI_TalonSRX> driveTalon3 ;
  std::shared_ptr<WPI_TalonSRX> driveTalon4 ;

  std::shared_ptr<frc::DifferentialDrive> differentialDrive ;

  std::shared_ptr<frc::MotorControllerGroup> motorControllerLeft{driveTalon1, driveTalon2} ;
  std::shared_ptr<frc::MotorControllerGroup> motorControllerRight{driveTalon3, driveTalon4} ;
};
