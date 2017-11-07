//
//  CRMessageButton.h
//  CloudrailSI
//
//  Created by Mujtaba Alam on 03.11.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRMessageButton : CRSandboxObject

/// Text - Button text
@property (nonatomic) NSString * text;

/*
 * Type - Button type can be uri or postback
 * This define the action to be taken
 * For the type uri - use the url field
 * For the type postback - use the payload field
 */
@property (nonatomic) NSString * type;

/// Url - This is type uri request which is handled externally
@property (nonatomic) NSString * url;

/// Payload - This is type postback request which is handled internally
@property (nonatomic) NSString * payload;

@end
