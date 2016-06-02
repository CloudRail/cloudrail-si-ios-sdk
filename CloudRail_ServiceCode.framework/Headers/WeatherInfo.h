//
//  WeatherInfo.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 28/04/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SandboxObject.h"
#import "Location.h"
#import "Temperature.h"
#import "Pressure.h"
#import "Velocity.h"

@interface WeatherContition : NSObject

@property (nonatomic) NSNumber * code;
@property (nonatomic) NSString * label;
@property (nonatomic) NSString * description;

@end


@interface WeatherInfo : SandboxObject


@property (nonatomic) Location * location;

@property (nonatomic) NSString * cityName;
@property (nonatomic) NSString * cityId;
@property (nonatomic) NSDate * startDate;
@property (nonatomic) NSDate * endDate;

@property (nonatomic) BOOL * isForecast;
@property (nonatomic) NSNumber * forecastAccuracy;

@property (nonatomic) Temperature * temperature;
@property (nonatomic) Pressure * pressure;
@property (nonatomic) NSNumber * humidity;

@property (nonatomic) Velocity * windSpeed;

@property (nonatomic) NSNumber * windDirection;

@property (nonatomic) Velocity * gustSpeed;
@property (nonatomic) NSNumber * gustDirection;

@property (nonatomic) NSNumber * cloudiness;

@property (nonatomic) NSNumber * rain;
@property (nonatomic) NSNumber * rainProbability;

@property (nonatomic) NSNumber * co2;
@property (nonatomic) NSNumber * noise;


// min- and max- values between the given time range

@property (nonatomic) Temperature * minTemperature;
@property (nonatomic) Temperature * maxTemperature;
@property (nonatomic) Pressure * minPressure;
@property (nonatomic) Pressure * maxPressure;
@property (nonatomic) NSNumber * minHumidity;
@property (nonatomic) NSNumber * maxHumidity;
@property (nonatomic) Velocity * minWindSpeed;
@property (nonatomic) Velocity * maxWindSpeed;
@property (nonatomic) NSNumber * minCo2;
@property (nonatomic) NSNumber * maxCo2;
@property (nonatomic) NSNumber * minNoise;
@property (nonatomic) NSNumber * maxNoise;

@property (nonatomic) Velocity * maxGustSpeed;

@property (nonatomic) NSNumber * sumRain;


@property (nonatomic) NSMutableArray<WeatherContition*> * weatherConditions;
@property (nonatomic) NSString * languageCode;



@end













