//
//  Date.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 5/10/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SandboxObject.h"

@interface Date : SandboxObject

@property (nonatomic) NSDate * internalDate;// normal Objc Date ( seconds based)
@property (nonatomic) NSNumber * timeInternal;// long time interval in Miliseconds
@property (nonatomic) NSNumber * time;

@end
