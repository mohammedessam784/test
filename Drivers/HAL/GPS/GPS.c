#include "HAL/GPS/GPS.h"

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


void GPS_Initialization()
{
	 
}




 char buffer[120];
void GPS_Read_Data(GNRMC_Data *data)
{
	    
}

void GPS_parseGNRMC( char *sentence, GNRMC_Data *data) {
    char temp[120];
	  int field = 0;
	char *token =0;
    strcpy(temp, sentence);

    token = strtok(temp, ",");
    
    if (strcmp(token, "$GNRMC") != 0) {
            return;
        }

    while (token != NULL) {
        switch (field) {
            case 1: strncpy(data->time, token, 10); data->time[10] = '\0'; break;
            case 2: data->status = token[0];
            if (token[0]=='V') {return;}
		    break;
            case 3: data->latitude = convertToDegrees(token); break;
            case 4: data->lat_dir = token[0]; break;
            case 5: data->longitude = convertToDegrees(token); break;
            case 6: data->lon_dir = token[0]; break;
            case 7: data->speed = my_atof(token); break;
            case 8: strncpy(data->date, token, 6); data->date[6] = '\0'; return;
        }
        token = strtok(NULL, ",");
        field++;
    }
}




/*
void GPS_sendGPSData(UART_HandleTypeDef *huart, GNRMC_Data *data) {
    char buffer[128];
    HAL_Delay(100);
    sprintf(buffer, "Time: %s\r\n", data->time);
    sendUART(huart, buffer);
    HAL_Delay(100);
    sprintf(buffer, "Status: %c\r\n", data->status);
    sendUART(huart, buffer);
    HAL_Delay(100);
    sprintf(buffer, "Latitude: %.6f %c\r\n", data->latitude, data->lat_dir);
    sendUART(huart, buffer);
    HAL_Delay(100);
    sprintf(buffer, "Longitude: %.6f %c\r\n", data->longitude, data->lon_dir);
    sendUART(huart, buffer);
    HAL_Delay(100);
    sprintf(buffer, "Speed: %.2f Knots\r\n", data->speed);
    sendUART(huart, buffer);
    HAL_Delay(100);
    sprintf(buffer, "Date: %s\r\n", data->date);
    sendUART(huart, buffer);
    HAL_Delay(100);
}


void sendUART(UART_HandleTypeDef *huart, const char *message) {

   
}

*/


double convertToDegrees(char *rawValue) {
    double val = my_atof(rawValue);
    int deg = (int)(val / 100);
    double min = val - (deg * 100);
    return deg + (min / 60.0);
}

double my_atof(const char *str) {
    double result = 0.0;
    double fraction = 1.0;
    int sign = 1;

    
   // while (isdigit(*str)) 
			{
        result = result * 10.0 + (*str - '0');
        str++;
    }

    
    if (*str == '.') {
        str++;
        //while (isdigit(*str)) 
					{
            fraction /= 10.0;
            result += (*str - '0') * fraction;
            str++;
        }
    }

    return result * sign;
}


