//
//  POI.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"
#import "CRLocation.h"

@interface CRPOI : CRSandboxObject

@property (nonatomic) NSString * name;
@property (nonatomic) NSString * imageURL;
@property (nonatomic) NSString * phone;
@property (nonatomic) NSMutableArray<NSString *> * categories;
@property (nonatomic) CRLocation * location;

@end
