//
//  EmailViewController.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 23/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CloudRailSI/CloudRailSI.h>

@interface EmailViewController : UIViewController
@property (nonatomic) NSString * serviceName;

@property (nonatomic) NSString * clientId;
@property (nonatomic) NSString * clientSecret;
@property (nonatomic) id<CREmailProtocol> service;

@end
