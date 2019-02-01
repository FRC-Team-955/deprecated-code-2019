2019 robot code for Destination: Deep Space

instructions for Spark-run motors (Neo's):
Spark *mySpark; //initialize
mySpark = new Spark(0); //declare in RobotInit(); 0 or whatever number PWM port is being used
mySpark->SetRaw(speed); //write speed in TeleopPeriodic()...

speed values:
1000       =full reverse
1001-1459  =variable speed reverse
1460-1540  =halt
1541-2000  =variable speed forward
2000       =full forward
