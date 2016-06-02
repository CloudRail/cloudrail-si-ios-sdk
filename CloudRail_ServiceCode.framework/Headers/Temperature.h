//
//  Temperature.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 28/04/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SandboxObject.h"

@interface Temperature : SandboxObject

@property (nonatomic) NSNumber * kelvin;




- (instancetype)initWithKelvin:(NSNumber*) kelvin;
-(NSNumber *) fahrenheit;
-(void) setFahrenheit:(NSNumber*) fahrenheit;
-(NSNumber*) celcius;
-(void) setCelcius:(NSNumber*) number;
-(BOOL) isValid;
@end
