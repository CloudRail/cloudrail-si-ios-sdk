//
//  Velocity.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 28/04/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SandboxObject.h"

@interface Velocity : SandboxObject

@property (nonatomic) NSNumber * metersPerSec;
- (instancetype)initWithMetersPerSec:(NSNumber*) number;

@end
