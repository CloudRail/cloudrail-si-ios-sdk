//
//  SocialViewController.m
//  CloudrailSI
//
//  Created by Felipe Cesar on 04/07/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SocialViewController.h"

@implementation SocialViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  
  NSDictionary * authDic = @{
                             @"facebookKey" : @"636472443170383",
                             @"facebookSecret" : @"572d1e670d481820e6de7525cfec757f",
                             
                             @"googleplusKey" : @"871545970580-rsfohjd4g7ge0j3bmue6vc3t1t4if22c.apps.googleusercontent.com",
                             @"googleplusSecret" : @"MpVwm1MK2lgKQCP2T6BjVn8c",
                             
                             @"twitterKey" : @"z0vkP9FQkcWdo5W1NZWI0mp9I",
                             @"twitterSecret" : @"D2S3B89XtlAc7mGxEwyYYZXqPCj8n2SY0nNTbXmGWYSSpvsIrF"
                             };
  
  
  NSString * key = [[self.serviceName lowercaseString] stringByAppendingString:@"Key"];
  NSString * secret = [[self.serviceName lowercaseString] stringByAppendingString:@"Secret"];
  
  self.serviceName = [@"CR" stringByAppendingString:self.serviceName];

  
  if ([self.serviceName isEqualToString:@"CRFacebook"]) {
    self.service = [[CRFacebook alloc] initWithClientId:authDic[key] clientSecret:authDic[secret] redirectUri:@"https://www.cloudrailauth.com/auth" state:@"STATE"];
    
  } else if ([self.serviceName isEqualToString:@"CRTwitter"]){
    self.service = [[CRTwitter alloc] initWithClientId:authDic[key] clientSecret:authDic[secret] redirectUri:@"https://www.cloudrailauth.com/auth"];
  }
  
}

- (IBAction)postButton:(id)sender {

  [self.service postUpdateWithContent:@"Post using CloudRail SDK."];

}

- (IBAction)connectionsButton:(id)sender {
  
  id list = [self.service connections];
  
  NSLog(@"LIST of connections: %@",  list);
}

@end
