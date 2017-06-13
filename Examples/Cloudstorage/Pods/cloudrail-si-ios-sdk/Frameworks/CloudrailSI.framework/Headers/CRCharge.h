//
//  Charge.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.

#import "CRSandboxObject.h"
#import "CRCreditCard.h"

@interface CRCharge : CRSandboxObject

@property (nonatomic) NSString  * identifier;
@property (nonatomic) NSNumber * amount;
@property (nonatomic) NSString * currency;
@property (nonatomic) CRCreditCard * source;
@property (nonatomic) NSNumber * created;

@property (nonatomic) NSString * status;

@property (nonatomic) NSNumber * refunded;

- (void) initWithAmount:(NSNumber *) amount
               created:(NSNumber *) created
              currency:(NSString *) currency
            identifier:(NSString *) identifier
              refunded:(NSNumber*)refunded
                source:(CRCreditCard*) source
                status:(NSString *) status;
@end
