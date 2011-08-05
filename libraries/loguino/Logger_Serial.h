/* Copyright 2011 David Irvine
 * 
 * This file is part of Loguino
 *
 * Loguino is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Loguino is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Loguino.  If not, see "http://www.gnu.org/licenses/".
 * 
 * $Rev$:   
 * $Author$: 
 * $Date$:  

*/



#ifndef LOGGER_SERIAL_H
#define LOGGER_SERIAL_H

#include "LoguinoConfig.h"
#include "Message.h"
#include <WProgram.h>

#ifdef ENABLE_SERIAL_LOGGER
	#ifndef SO_SERIAL_PORT
		#error SO_SERIAL_PORT must be defined as a valid arduino Serial device
	#endif
	#ifndef SO_SERIAL_PORT_SPEED
		#error SO_SERIAL_PORT_SPEED must be defined as the speed to log to the serial port
	#endif


class SerialLogger
{
	static bool active;
    public:
        static bool begin();
        static bool log(Message &msg);
        static bool flush();
};
#endif

#endif
