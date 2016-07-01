//
//  ProfileViewController.m
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 31/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "ProfileViewController.h"

@interface ProfileViewController ()
@end

@implementation ProfileViewController

- (void)viewDidLoad {
    [super viewDidLoad];

  // CHANGE THE VALUES OF THE DICTIONARY TO THE ON FOUND ON YOUR APPLICATION
  NSDictionary * authDic = @{
                   @"facebookKey" : @"IDENTIFIER",
                   @"facebookSecret" : @"SECRET",
                   
                   @"githubKey" : @"IDENTIFIER",
                   @"githubSecret" : @"SECRET",
                   
                   @"googleplusKey" : @"IDENTIFIER",
                   @"googleplusSecret" : @"SECRET",
                   
                   @"linkedinKey" : @"IDENTIFIER",
                   @"linkedinSecret" : @"SECRET",
                   
                   @"microsoftliveKey" : @"IDENTIFIER",
                   @"microsoftliveSecret" : @"SECRET",
                   
                   @"slackKey" : @"IDENTIFIER",
                   @"slackSecret" : @"SECRET",
                   
                   @"yahooKey" : @"IDENTIFIER",
                   @"yahooSecret" : @"SECRET",
                   
                   @"twitterKey" : @"IDENTIFIER",
                   @"twitterSecret" : @"SECRET",
                   
                   };
  
  
  NSString * key = [[self.serviceName lowercaseString] stringByAppendingString:@"Key"];
  NSString * secret = [[self.serviceName lowercaseString] stringByAppendingString:@"Secret"];

  
  self.serviceName = [@"CR" stringByAppendingString:self.serviceName];
  Class cl = NSClassFromString(self.serviceName);
  self.service = [(id<CRProfileProtocol>)[cl alloc] initWithClientId:authDic[key] clientSecret:authDic[secret] redirectUri:@"https://www.cloudrailauth.com/auth" state:@"CR123"];
  
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)actionButton:(id)sender {
  [self testAllAtOnce];
  
}

-(void) testAllAtOnce{
  
  NSMutableArray * dictionary = [NSMutableArray array];
  
  NSString * ronaldo = [self.service pictureURL];
  [dictionary addObject:ronaldo];
  NSString * identifier = [self.service identifier];
  [dictionary addObject:identifier];
  NSString * name = [self.service fullName];
  [dictionary addObject:name];
  NSString * gender = [self.service gender];
  [dictionary addObject:gender];
  NSString * description = [self.service description];
  [dictionary addObject:description];
  NSString * locale = [self.service locale];
  [dictionary addObject:locale];
  id birth = [self.service dateOfBirth];
  [dictionary addObject:birth];

  NSLog(@"%@" ,dictionary);

}



@end
