//
//  PoiViewController.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 22/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CloudRailSI/CloudRailSI.h>

@interface PoiViewController : UIViewController

@property (nonatomic) NSString * serviceName;

@property (nonatomic) NSString * clientId;
@property (nonatomic) NSString * clientSecret;
@property (nonatomic) id<CRPointsOfInterestProtocol> service;

@end
