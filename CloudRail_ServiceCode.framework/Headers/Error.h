//
//  Error.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 5/10/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SandboxObject.h"

@interface Error : SandboxObject

@property (nonatomic) NSString * message;
@property (nonatomic) NSString * type;

@end
