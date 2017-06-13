//
//  Refund.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRRefund : CRSandboxObject

@property (nonatomic) NSString * identifier;
@property (nonatomic) NSNumber * amount;
@property (nonatomic) NSNumber * created;
@property (nonatomic) NSString * currency;
@property (nonatomic) NSString * chargeID;
@property (nonatomic) NSString * state;

- (void)initWithAmount:(NSNumber *) amount
             chargeId:(NSString *) chargeID
              created:(NSNumber *) created
           identifier:(NSString *) identifier
                state:(NSString *) state
             currency:(NSString *) currency;
@end
