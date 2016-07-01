//
//  Subscription.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"
#import "CRCreditCard.h"

@interface CRSubscription : CRSandboxObject

@property (nonatomic) NSString * identifier;
@property (nonatomic) NSNumber * created;
@property (nonatomic) NSString * name;
@property (nonatomic) NSString * subscriptionDescription;
@property (nonatomic) NSString * subscriptionPlanID;
@property (nonatomic) NSNumber * lastCharge;
@property (nonatomic) NSNumber * nextCharge;
@property (nonatomic) CRCreditCard * creditCard;

@property (nonatomic) NSString * state;

@end
