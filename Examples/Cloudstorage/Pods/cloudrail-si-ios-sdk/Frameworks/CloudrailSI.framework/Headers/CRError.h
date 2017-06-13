//
//  Error.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 5/10/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

#define kCR_ERROR_TYPE_KEY  @"CRErrorTypeKey"
#define kCR_ERROR_MESSAGE_KEY @"CRErrorMessageKey"
@interface CRError : CRSandboxObject

@property (nonatomic) NSString * message;
@property (nonatomic) NSString * type;

@end
