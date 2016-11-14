//
//  SMSViewController.m
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 23/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SMSViewController.h"

@implementation SMSViewController


- (void)viewDidLoad {
  [super viewDidLoad];
  
  
  NSDictionary * authDic = @{
                             @"twilioKey" : @"AC761c011ece38c545f5aca9af11ff4689",
                             @"twilioSecret" : @"a935b428d203810ff4aff44dddf84711",
                             
                             @"nexmoKey" : @"9bc82b93",
                             @"nexmoSecret" : @"32bec7e1d44c85a8",
                             
                             };
  
  
  NSString * key = [[self.serviceName lowercaseString] stringByAppendingString:@"Key"];
  NSString * secret = [[self.serviceName lowercaseString] stringByAppendingString:@"Secret"];
  
//  Class cl = NSClassFromString(self.serviceName);
  
  if ([self.serviceName isEqualToString:@"Twilio"]) {
    self.service = [[CRTwilio alloc] initWithAccountSid:authDic[key] authToken:authDic[secret]];
  } else if([self.serviceName isEqualToString:@"Nexmo"]){
    self.service = [[CRNexmo alloc] initWithClientId:authDic[key] clientSecret:authDic[secret]];
    
  }
  // Do any additional setup after loading the view.
}


- (IBAction)sendSMS:(id)sender {
  
//  [self.service sendSmsFromName:@"Felipe" toNumber:@"+4915732767994" content:@"Cloudrail is awesome!"];
  
  //twillio must be with special phone number
  [self.service sendSmsFromName:@"MG28341899112cfdccb11911bdb36f901f" toNumber:@"+4915732767994" content:@"Cloudrail is awesome!"];
}

@end
