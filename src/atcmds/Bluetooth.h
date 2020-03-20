
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

/*
████████████████████████████████████████████████████████████████████████
████   ATcmd                                Manpage    API Method   ████   Count: 16 commands
████████████████████████████████████████████████████████████████████████
*/
public:
    /* AT+BTHOST?  ,AT+BTHOST=<name>         10 */ void BT_Host_Dev_Info         			(CmdType, char* = "");
    /* AT+BTSTATUS?          		  		 10 */ void BT_Guest_Devs_Paired_Info			(CmdType);
    /* AT+BTPOWER=<n>           	  		 11 */ void BT_Power                   			(CmdType, char* = "");
    /* AT+BTPAIR=1,<confirm>    	  		 12 */ void BT_Pair_Guest     	     	 		(CmdType, char* = "");
    /* AT+BTUNPAIR=<device ID>  	  		 13 */ void BT_UnPair_Guest   	    			(CmdType, char* = "");
    /* AT+BTSCAN=<switch>[,<Timer>]   		 13 */ void BT_Scan 		         			(CmdType, char* = "");
    /* AT+BTCONNECT=<deviceID>,<profile ID>	 14	*/ void BT_Connect_Paired_Dev    	 		(CmdType, char* = "");
    /* AT+BTDISCONN=<device ID>              14 */ void BT_Disconnect_Paired_Dev 			(CmdType, char* = "");
    /* AT+BTACPT=<confirm>                   15 */ void BT_Accept_Connect_Request	 		(CmdType, char* = "");
    /* AT+BTSPPGET=<command>[,<reqLength>]
	                        [,<showWithHex>] 17 */ void BT_Get_data_SPP_Based    	 		(CmdType, char* = "");
    /* AT+BTSPPSEND=<length>                 19 */ void BT_Send_data_SPP_Based_length_Packet(char*);              /* response '>' then send data[length(consist the null)] */
	/* AT+BTSPPSEND                          19 */ void BT_Send_data_SPP_Based   	        (const char*, bool = true);              /* response '>' then append Ctrl Z to send */
    /* AT+BTRSSI=<device ID>                 21 */ void BT_Get_RSSI_dBm_Connected_Dev		(CmdType, char* = "");
    /* AT+BTVIS=<visibility>                 28 */ void BT_Set_visibility        	 		(CmdType, char* = "");
    /* AT+BTSPPCFG=<btSppCfg>,<mode> eg:TT,1 29 */ void BT_Set_SPP_config        	 		(CmdType, char* = "");
	/* AT+BTPAIRCFG=1[,<pin_code>]           30 */ void BT_Set_Pairing_Mode      	 		(CmdType, char* = "");

private:
    void Send_SPP_data_Helper(char*);