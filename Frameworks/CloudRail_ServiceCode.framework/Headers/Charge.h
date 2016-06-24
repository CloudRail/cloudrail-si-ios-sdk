//
//  Charge.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.

#import "SandboxObject.h"
#import "CreditCard.h"

@interface Charge : SandboxObject

@property (nonatomic) NSString  * identifier;
@property (nonatomic) NSNumber * amount;
@property (nonatomic) NSString * currency;
@property (nonatomic) CreditCard * source;
@property (nonatomic) NSNumber * created;

@property (nonatomic) NSString * status;

@property (nonatomic) NSNumber * refunded;
@end
