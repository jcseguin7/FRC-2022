/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"
#include "ctre/Phoenix.h"


DriveSubsystem::DriveSubsystem() {
    driveTalon1.reset(new WPI_TalonSRX(1)) ;
    driveTalon2.reset(new WPI_TalonSRX(2)) ;
    driveTalon3.reset(new WPI_TalonSRX(3)) ;
    driveTalon4.reset(new WPI_TalonSRX(4)) ;

    motorControllerLeft.reset(new frc::MotorControllerGroup(*driveTalon1, *driveTalon2)) ;
    motorControllerRight.reset(new frc::MotorControllerGroup(*driveTalon3, *driveTalon4)) ;

    differentialDrive.reset(new frc::DifferentialDrive(*motorControllerLeft, *motorControllerRight)) ;
}

// This method will be called once per scheduler run
void DriveSubsystem::Periodic() {}

void DriveSubsystem::Stop() {
    differentialDrive -> ArcadeDrive(0.0, 0.0) ;
}

void DriveSubsystem::DriveJoystick(std::shared_ptr<Joystick> stick) {
    differentialDrive -> ArcadeDrive(stick->GetY(), stick->GetX())
}


