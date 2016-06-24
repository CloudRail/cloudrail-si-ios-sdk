//
//  POI.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SandboxObject.h"
#import "Location.h"

@interface POI : SandboxObject

@property (nonatomic) NSString * name;
@property (nonatomic) NSString * imageURL;
@property (nonatomic) NSString * phone;
@property (nonatomic) NSMutableArray<NSString *> * categories;
@property (nonatomic) Location * location;

@end
