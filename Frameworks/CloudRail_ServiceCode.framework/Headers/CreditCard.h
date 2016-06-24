//
//  CreditCard.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SandboxObject.h"
#import "Address.h"

@interface CreditCard : SandboxObject

//CostumerData
@property (nonatomic) NSString * firstName;
@property (nonatomic) NSString * lastName;
@property (nonatomic) Address * address;
@property (nonatomic) NSString * number;

// Card validation code
@property (nonatomic) NSString * cvc;

// Values between 1 and 12
@property (nonatomic) NSNumber * expire_month;

// Four digit expiration data
@property (nonatomic) NSNumber * expire_year;

// Can have the following values: visa, mastercard, discover, amex
@property (nonatomic) NSString * type;

@end
