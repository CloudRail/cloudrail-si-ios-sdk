//
//  CRMessageItem.h
//  CloudrailSI
//
//  Created by Mujtaba Alam on 03.11.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"
#import "CRMessageButton.h"

@interface CRMessageItem : CRSandboxObject

/// Title of the message item
@property (nonatomic) NSString * title;

/// SubTitle (description) of the message item
@property (nonatomic) NSString * subTitle;

/// MediaUrl - URL of the image to be displayed
@property (nonatomic) NSString * mediaUrl;

/*
 * Contains a list of Message Buttons and their actions
 */
@property (nonatomic) NSMutableArray<CRMessageButton *> * buttons;

@end
