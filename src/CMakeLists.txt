set(FIRMWARE_NAME loguino)
set(loguino_RECURSE True)
set(SD_RECURSE True)

#set(${FIRMWARE_NAME}_BOARD ethernet)
set(${FIRMWARE_NAME}_BOARD mega2560)
set(${FIRMWARE_NAME}_SRCS loguino.cpp)
SET(${FIRMWARE_NAME}_PORT "/dev/tty.usbserial" CACHE STRING "Serial port to upload firmware to")

generate_arduino_firmware(loguino)
OPTION( ENABLE_HS1101_POLLER "Enable polling of HS1101 Relative Humidity Sensor" ON)
IF (ENABLE_HS1101_POLLER)
	SET(HS1101_PIN "2" CACHE STRING "Pin the sense pin of the HS1101 is connected to")
ENDIF(ENABLE_HS1101_POLLER)

OPTION( ENABLE_BMP085_POLLER "Enable polling of BMP085 Barometric Pressure Sensor" ON)
OPTION( ENABLE_TMP102_POLLER "Enable polling of TMP102 Temperature Sensors" ON)
IF (ENABLE_TMP102_POLLER)
	SET(TMP102_I2C_ADDRESS "72" CACHE STRING "Address of I2C device")
ENDIF(ENABLE_TMP102_POLLER)

OPTION( ENABLE_GPS_POLLER "Enable poling of NMEA compatible GPS devices" ON)
IF (ENABLE_GPS_POLLER)
	SET(GPS_SERIAL_DEV "Serial2" CACHE STRING "Serial device for GPS device" )
	SET(GPS_SERIAL_DEV_SPEED "4800" CACHE STRING "Speed of GPS device" )
ENDIF(ENABLE_GPS_POLLER)

OPTION( ENABLE_DUMMY_POLLER "Enable polling of the dummy poller" ON)
OPTION( ENABLE_DIGITAL_POLLER "Enable polling of digital pins" ON)
IF (ENABLE_DIGITAL_POLLER)
	SET(DIGITAL_PINS "31,32,33,34,35,36" CACHE STRING  "Digital pins to poll")
	SET(INVERT_DIGITAL_PINS "32,33" CACHE STRING  "Digital pins to invert")
ENDIF(ENABLE_DIGITAL_POLLER)

OPTION( ENABLE_ANALOG_POLLER "Enable polling of analog pins" ON)
IF (ENABLE_ANALOG_POLLER)
	SET (ANALOG_PINS "2,3,4" CACHE STRING  "Comma Seperated List of analog pins to use")
ENDIF(ENABLE_ANALOG_POLLER)






OPTION( ENABLE_ITG3200_POLLER "Enable polling of itg3200 gyrometers" ON)
IF (ENABLE_ITG3200_POLLER)
	SET (ITG3200_ADDRESS "0x69" CACHE STRING "I2C Address of the ITG3200 Gyro" )
ENDIF (ENABLE_ITG3200_POLLER)


OPTION( ENABLE_LIS331_POLLER "Enable polling of LIS331 accelerometers" ON)
IF (ENABLE_LIS331_POLLER)
	SET( LIS_BUS_ADDRESS "25" CACHE STRING "I2C Address of the LIS331 Accelerometer" )
ENDIF (ENABLE_LIS331_POLLER)

OPTION( ENABLE_MS_POLLER "Enable polling of MegaSquirt ECU" ON)
IF (ENABLE_MS_POLLER)
	SET(MYVAR "Test" CACHE STRING "This is my variable")
	SET(MS_WAIT_TIME "100" CACHE STRING "Time number of polls to skip after a megasquirt timout" )
	SET(MS_STATUS_PIN "9" CACHE STRING "Pin to take high when megasquirt is online" )
ENDIF(ENABLE_MS_POLLER)

OPTION( ENABLE_SERIAL_OUTPUT "Enable logging to a serial device" ON)
if (ENABLE_SERIAL_OUTPUT)
	SET(SO_SERIAL_PORT "Serial" CACHE STRING "Serial port to write serial output to" )	
	SET(SO_SERIAL_PORT_SPEED "115200" CACHE STRING "Serial port speed")
endif(ENABLE_SERIAL_OUTPUT)

	
OPTION( ENABLE_SD_OUTPUT "Enable logging to an SD card" ON)
IF (ENABLE_SD_OUTPUT)
	SET (SD_ACTIVE_PIN "9" CACHE STRING "Pin to make high when SD card is active")
ENDIF(ENABLE_SD_OUTPUT)

OPTION (ENABLE_ETHERNET_LOGGER "Enable the Ethernet Server" ON)
IF (ENABLE_ETHERNET_LOGGER)
	SET ( ETHERNET_MAC_ADDRESS  "0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED" CACHE STRING "MAC Address in HEX Seperated by commas")
	SET ( ETHERNET_IP_ADDRESS  "192,168,10,23" CACHE STRING "IP Address seperated by commas")
	SET ( ETHERNET_DNS_ADDRESS  "8,8,8,8" CACHE STRING "DNS server IP address seperated by commas")
	SET ( ETHERNET_GW_ADDRESS  "192,168,10,1" CACHE STRING "Default Gateway IP seperated by commas")
	SET ( ETHERNET_NETMASK  "255,255,255,0" CACHE STRING "Netmask seperated by commas")

ENDIF (ENABLE_ETHERNET_LOGGER)
CONFIGURE_FILE( ${CMAKE_SOURCE_DIR}/src/libraries/config/config.in  ${CMAKE_SOURCE_DIR}/src/libraries/config/config.h)


