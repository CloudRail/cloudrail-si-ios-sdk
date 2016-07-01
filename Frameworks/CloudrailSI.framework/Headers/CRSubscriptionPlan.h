//
//  SubscriptionPlan.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRCreditCard.h"

@interface CRSubscriptionPlan : CRSandboxObject

@property (nonatomic) NSString * identifier;
@property (nonatomic) NSString * name;
@property (nonatomic) NSString * subscriptionDescription;
@property (nonatomic) NSNumber * created;
@property (nonatomic) NSNumber * amount;
@property (nonatomic) NSString * currency;
@property (nonatomic) NSString * interval;
@property (nonatomic) NSNumber * interval_count;
@end
