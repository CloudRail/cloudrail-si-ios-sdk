//
//  DateOfBirth.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 27/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"
@interface CRDateOfBirth : CRSandboxObject

@property (nonatomic) NSNumber * year;
@property (nonatomic) NSNumber * month;
@property (nonatomic) NSNumber * day;


/**
 *  Generated a NSDate from the properties: year, month, day
 *
 * @return NSDate the date object
 */
- (NSDate *) date;
@end
