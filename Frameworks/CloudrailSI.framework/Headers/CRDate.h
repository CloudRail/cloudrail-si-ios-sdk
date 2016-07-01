//
//  Date.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 5/10/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRSandboxObject.h"

@interface CRDate : CRSandboxObject

@property (nonatomic, readonly) NSDate * internalDate;// normal Objc Date ( seconds based)
@end
