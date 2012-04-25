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
 * along with Loguino.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * $Rev$:   
 * $Author$: 
 * $Date$:  
 
 */
#include <logger.h>
#include <message.h>

int num_messages=0;
void log_message(){
    extern Message m;
    
	num_messages++;
  	if (num_messages>500){
  	  	flush_output();
  	  	num_messages=0;
  	}
    
#ifdef ENABLE_SERIAL_OUTPUT
	SerialLogger::log();
#endif
    
#ifdef ENABLE_SD_OUTPUT
    SDOut();
#endif
#ifdef ENABLE_ETHERNET_LOGGER
	EthernetLogger::log_message();
#endif
}

void loggerBegin(){
#ifdef ENABLE_SERIAL_OUTPUT
	SerialLogger::begin();
#endif
#ifdef ENABLE_SD_OUTPUT
    SDOutBegin();
#endif

#ifdef ENABLE_ETHERNET_LOGGER
	EthernetLogger::begin();
#endif
}

void flush_output(){
#ifdef ENABLE_SERIAL_OUTPUT
	SerialLogger::flush();
#endif
#ifdef ENABLE_SD_OUTPUT
    SDOutFlush();
    
#endif
#ifdef ENABLE_ETHERNET_LOGGER
	EthernetLogger::flush();
#endif
    

}
