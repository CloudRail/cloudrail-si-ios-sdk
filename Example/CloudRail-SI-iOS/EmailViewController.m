//
//  EmailViewController.m
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 23/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "EmailViewController.h"

@implementation EmailViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  NSDictionary * authDic = @{
                             @"mailjetKey" : @"c33840d7698d32862e5f2d837e1ae9dd",
                             @"mailjetSecret" : @"4f58b437a4b6964a2ccafc5f133a6a84",
                             
                             @"sendgridKey" : @"bobauer",
                             @"sendgridSecret" : @"cloudrail123",
                           
                             };
  
  NSString * key = [[self.serviceName lowercaseString] stringByAppendingString:@"Key"];
  NSString * secret = [[self.serviceName lowercaseString] stringByAppendingString:@"Secret"];
  
  if ([self.serviceName isEqualToString:@"MailJet"]) {
    self.service = [[CRMailJet alloc] initWithClientId:authDic[key] clientSecret:authDic[secret]];
  } else if([self.serviceName isEqualToString:@"SendGrid"]){

    [NSException raise:@"get new apikey" format:@""];
  }
}

- (IBAction)sendEmail:(id)sender {
  
//  [self.service sendEmail:@"felipe.cesar+mailjet@cloudrail.com" fromName:@"Bob Bauer" toAddresses:[@[@"fel.cesar@gmail.com",@"fel.cesar@hotmail.com"] mutableCopy] subject:@"Mailjet Felipe" textBody:@"The Mailjet is working!!! This email was sent using it! \n\r" htmlBody:@"" ccAddresses:[@[]mutableCopy] bccAddresses:[@[@"felipe@cloudrail.com"] mutableCopy]];
  
  [self.service sendEmailFromAddress:@"felipe.cesar+mailjet@cloudrail.com" fromName:@"Bob Bauer" toAddresses:[@[@"fel.cesar@gmail.com"] mutableCopy] subject:@"Felipe" textBody:@"Sendgrid is working!!! This email was sent using it! \n\r" htmlBody:@"" ccAddresses:[@[]mutableCopy] bccAddresses:[@[] mutableCopy]];

}

@end
