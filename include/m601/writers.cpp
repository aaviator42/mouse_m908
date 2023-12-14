/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include "../rd_mouse.h"

//writer functions (apply changes to mouse)

int mouse_m601::write_profile(){
	
	//prepare data
	uint8_t buffer[6] = {0x05, 0x02, 0x01, 0x00, 0x00, 0x00};

	//modify buffer to include specified profile
	if( _s_profile == profile_1 ){
		buffer[2] = 0x01;
	}else if( _s_profile == profile_2 ){
		buffer[2] = 0x02;
	}
	
	//send data
	for( int i = 0; i < 6; i++ ){
		libusb_control_transfer( _i_handle, 0x21, 0x09, 0x0305, 0x0001, buffer, 6, 1000 );
	}
	
	return 0;
}

int mouse_m601::write_settings(){
	// TODO implement
	return 0;
}

int mouse_m601::write_macro( int macro_number ){
	// TODO implement macros
	(void)macro_number;
	throw std::string( "Macros are currently not supported on the M601." );
	return 1;
}