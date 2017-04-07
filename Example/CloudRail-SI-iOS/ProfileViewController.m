//
//  ProfileViewController.m
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 31/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "ProfileViewController.h"

@interface ProfileViewController ()
@property (weak, nonatomic) IBOutlet UILabel *interfaceLabel;
@property (weak, nonatomic) IBOutlet UILabel *fullNameLabel;
@property (weak, nonatomic) IBOutlet UILabel *emailLabel;
@property (weak, nonatomic) IBOutlet UILabel *genderLabel;
@property (weak, nonatomic) IBOutlet UILabel *descriptionLabel;
@property (weak, nonatomic) IBOutlet UILabel *dateOfBirthLabel;
@property (weak, nonatomic) IBOutlet UILabel *localeLabel;
@property (weak, nonatomic) IBOutlet UIImageView *profilePictureImageView;
@end

@implementation ProfileViewController

- (void)viewDidLoad {
    [super viewDidLoad];

  
  NSDictionary * authDic = @{
                   @"facebookKey" : @"636472443170383",
                   @"facebookSecret" : @"572d1e670d481820e6de7525cfec757f",
                   
                   @"githubKey" : @"d3977ffa6fa0bf080e5d",
                   @"githubSecret" : @"681e1ef13e1f9b3d7f2c98934eff98e2568f94ec",
                   
                   @"googleplusKey" : @"871545970580-rsfohjd4g7ge0j3bmue6vc3t1t4if22c.apps.googleusercontent.com",
                   @"googleplusSecret" : @"MpVwm1MK2lgKQCP2T6BjVn8c",
                   
                   @"linkedinKey" : @"776pu73rvy0uv3",
                   @"linkedinSecret" : @"bzeERnuNFxSn90NG",
                   
                   @"microsoftliveKey" : @"000000004018F12F",
                   @"microsoftliveSecret" : @"lGQPubehDO6eklir1GQmIuCPFfzwihMo",
                   
                   @"slackKey" : @"47078298801.47063373940",
                   @"slackSecret" : @"14a84b9e8e0c4903f7ef92f414a84a2f",
                   
                   @"yahooKey" : @"dj0yJmk9VjdBS1N4eTI4aXhTJmQ9WVdrOU9GVlhRa1ZUTldjbWNHbzlNQS0tJnM9Y29uc3VtZXJzZWNyZXQmeD0wMA--",
                   @"yahooSecret" : @"cee21168758635abee1f190cdffd26d0e79b2a5a",
                   
                   @"twitterKey" : @"z0vkP9FQkcWdo5W1NZWI0mp9I",
                   @"twitterSecret" : @"D2S3B89XtlAc7mGxEwyYYZXqPCj8n2SY0nNTbXmGWYSSpvsIrF",
                   
                   @"instagramKey" : @"189b04674a354daaa3f861d6d8e90d17",
                   @"instagramSecret" : @"36e344b94b8e4082a5b5a569e4c4a2b8",
                   
                   };
  
  
  NSString * key = [[self.serviceName lowercaseString] stringByAppendingString:@"Key"];
  NSString * secret = [[self.serviceName lowercaseString] stringByAppendingString:@"Secret"];

  self.serviceName = [@"CR" stringByAppendingString:self.serviceName];
  Class cl = NSClassFromString(self.serviceName);
  
  
  self.service = [[cl alloc] initWithClientId:authDic[key] clientSecret:authDic[secret] redirectUri:@"https://www.cloudrailauth.com/auth" state:@"CR123"];
  
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)actionButton:(id)sender {
  [self userInfos];
  
}

-(void) userInfos{
  
  NSMutableArray * dictionary = [NSMutableArray array];
  
  NSString * pictureUrl = [self.service pictureURL];
  [dictionary addObject:pictureUrl];
  NSString * identifier = [self.service identifier];
  [dictionary addObject:identifier];
  NSString * name = [self.service fullName];
  [dictionary addObject:name];
  NSString * gender = [self.service gender];
  [dictionary addObject:gender];
  NSString * description = [self.service profileDescription];
  [dictionary addObject:description];
  NSString * locale = [self.service locale];
  [dictionary addObject:locale];
  id birth = [self.service dateOfBirth];
  [dictionary addObject:birth];
  
  NSString * email = [self.service email];
  [dictionary addObject:email];

  
  if ([pictureUrl isKindOfClass:[NSString class]]) [self.profilePictureImageView setImage:[UIImage imageWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:pictureUrl]]]];
  
  if ([identifier isKindOfClass:[NSString class]]) self.interfaceLabel.text = identifier;
  else if ([identifier isKindOfClass:[NSNull class]]) self.interfaceLabel.text = @"null";
  
  
  if ([name isKindOfClass:[NSString class]]) self.fullNameLabel.text = name;
  else if ([name isKindOfClass:[NSNull class]]) self.fullNameLabel.text = @"null";
  
  if ([gender isKindOfClass:[NSString class]]) self.genderLabel.text = gender;
  else if ([gender isKindOfClass:[NSNull class]]) self.genderLabel.text = @"null";
  
  if ([description isKindOfClass:[NSString class]]) self.descriptionLabel.text = description;
  else if ([description isKindOfClass:[NSNull class]]) self.descriptionLabel.text = @"null";
  
  if ([locale isKindOfClass:[NSString class]]) self.localeLabel.text = locale;
  else if ([locale isKindOfClass:[NSNull class]]) self.localeLabel.text = @"null";
  
  if ([birth isKindOfClass:[CRDateOfBirth class]]) self.dateOfBirthLabel.text = [(CRDateOfBirth*)birth description];
  else if ([birth isKindOfClass:[NSNull class]]) self.dateOfBirthLabel.text = @"null";
  
  
  if ([email isKindOfClass:[NSString class]]) self.emailLabel.text = email;
  else if ([email isKindOfClass:[NSNull class]]) self.emailLabel.text = @"null";

  NSLog(@"%@" ,dictionary);

}

@end
