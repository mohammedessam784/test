

#ifndef INC_GPS_H_
#define INC_GPS_H_


#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>




typedef struct {
    char time[11];      // HHMMSS.ss
    char status;        // A = valid, V = invalid
    double latitude;    // Degrees
    char lat_dir;       // N/S
    double longitude;   // Degrees
    char lon_dir;       // E/W
    double speed;       // Knots
    char date[7];       // DDMMYY
} GNRMC_Data;

void GPS_Initialization();
void GPS_Read_Data(GNRMC_Data *data);
void GPS_parseGNRMC(char *sentence, GNRMC_Data *data);
/*
void GPS_sendGPSData(UART_HandleTypeDef *huart, GNRMC_Data *data);
void sendUART(UART_HandleTypeDef *huart, const char *message) ;
*/
double convertToDegrees(char *rawValue);
double my_atof(const char *str);



#endif /* INC_GPS_H_ */
