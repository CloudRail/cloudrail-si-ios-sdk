//
//  CRAppDelegate.m
//  CloudRail-SI-iOS
//
//  Created by Felipe Cesar on 05/24/2016.
//  Copyright (c) 2016 Felipe Cesar. All rights reserved.
//

#import "CRAppDelegate.h"
#import <CloudRailSI/CloudRailSI.h>

#define kCLOUDRAIL_KEY @""

@implementation CRAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
  [CRCloudRail setAppKey:kCLOUDRAIL_KEY];
    return YES;
}

// Used for AdvancedAuthentication
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url {
  [[NSNotificationCenter defaultCenter] postNotificationName:@"kCloseSafariViewControllerNotification" object:url];
  return YES;
}


@end
