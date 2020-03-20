
//   "Aspen SIM800" is a comprehensive SIM800 library for simplified and in-depth chip access.
//   Copyright (C) 2016  Mattias Aabmets (https://github.com/aspenforest)
//
//   This API library is free software: you can redistribute it and/or modify
//   it under the terms of the GNU Affero General Public License as published
//   by the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   This API library is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
//   See the GNU Affero General Public License for more details.
//
//   You should have received a copy of the GNU Affero General Public License
//   along with this API library.  If not, see <http://www.gnu.org/licenses/>.


#include <SIM800.h>


// ============================================================
void SIM800::BT_Host_Dev_Info(CmdType type, char* str) {
    char _str[strlen(str)+1];
	strcpy(_str, str);
	outBuilder(type, _str, P("BTHOST"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Guest_Devs_Paired_Info(CmdType type) {
    outBuilder(type, "", P("BTSTATUS"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Power(CmdType type, char* str) {
    outBuilder(type, str, P("BTPOWER"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Pair_Guest(CmdType type, char* str) {
    outBuilder(type, str, P("BTPAIR"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_UnPair_Guest(CmdType type, char* str) {
    outBuilder(type, str, P("BTUNPAIR"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Scan(CmdType type, char* str) {
    outBuilder(type, str, P("BTSCAN"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Connect_Paired_Dev(CmdType type, char* str) {
    outBuilder(type, str, P("BTCONNECT"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Disconnect_Paired_Dev(CmdType type, char* str) {
    outBuilder(type, str, P("BTDISCONN"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Accept_Connect_Request(CmdType type, char* str) {
    outBuilder(type, str, P("BTACPT"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Get_data_SPP_Based(CmdType type, char* str) {
    outBuilder(type, str, P("BTSPPGET"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Send_data_SPP_Based_length_Packet(char* str) {
    outBuilder(SET, str, P("BTSPPSEND"));
    print(ioBuffer);
}

// ============================================================
//void SIM800::BT_Send_data_SPP_Based() {
//    outBuilder(EXE, "", P("BTSPPSEND"));
//    print(ioBuffer);
//}

// ============================================================
void SIM800::BT_Send_data_SPP_Based(const char* data, bool inFlash){
	
	if(inFlash){
		char _data[strlen_P(data)+1];
		strcpy_P(_data, data);
		outBuilder(EXE, "", P("BTSPPSEND"));
		Send_SPP_data_Helper(_data);
	}
	else{
		char _data[strlen(data)+1];
		strcpy(_data, data);
		outBuilder(EXE, "", P("BTSPPSEND"));
		Send_SPP_data_Helper(_data);
	}
}

// ============================================================
void SIM800::BT_Get_RSSI_dBm_Connected_Dev(CmdType type, char* str) {
    outBuilder(type, str, P("BTRSSI"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Set_visibility(CmdType type, char* str) {
    outBuilder(type, str, P("BTVIS"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Set_SPP_config(CmdType type, char* str) {
    outBuilder(type, str, P("BTSPPCFG"));
    print(ioBuffer);
}

// ============================================================
void SIM800::BT_Set_Pairing_Mode(CmdType type, char* str) {
    outBuilder(type, str, P("BTPAIRCFG"));
    print(ioBuffer);
}


//=============================================================
void SIM800::Send_SPP_data_Helper(char* data) {
    strcat_P(ioBuffer, P("\r"));
    write(ioBuffer);
    delay(50);
    outBuilder(EXE, data, "", false);
    strcat_P(ioBuffer, P("\x1A"));
    overrideTimeout(100);
    print(ioBuffer);
}
