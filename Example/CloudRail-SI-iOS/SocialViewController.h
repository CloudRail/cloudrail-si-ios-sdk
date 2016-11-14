//
//  SocialViewController.h
//  CloudrailSI
//
//  Created by Felipe Cesar on 04/07/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CloudRailSI/CloudRailSI.h>

@interface SocialViewController : UIViewController
@property (nonatomic) NSString * serviceName;

@property (nonatomic) NSString * clientId;
@property (nonatomic) NSString * clientSecret;
@property (nonatomic) id<CRSocialProtocol> service;
@end
