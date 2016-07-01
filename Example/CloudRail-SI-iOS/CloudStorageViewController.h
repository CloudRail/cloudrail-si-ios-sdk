//
//  CloudStorageViewController.h
//  CloudRail-SI-iOS
//
//  Created by Felipe Cesar on 15/06/16.
//  Copyright © 2016 Felipe Cesar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CloudRailSI/CloudRailSI.h>

@interface CloudStorageViewController : UIViewController

@property (nonatomic) NSString * serviceName;
@property (nonatomic) NSString * clientId;
@property (nonatomic) NSString * clientSecret;
@property (nonatomic) id<CRCloudStorageProtocol> service;

@end
