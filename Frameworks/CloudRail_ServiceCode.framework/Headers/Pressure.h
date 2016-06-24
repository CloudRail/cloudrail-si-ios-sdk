//
//  Pressure.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 28/04/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SandboxObject.h"

@interface Pressure : SandboxObject

@property (nonatomic) NSNumber * Pascal;

-(void) setBar:(NSNumber*) bar;
-(void) setPsi:(NSNumber*) psi;

@end
