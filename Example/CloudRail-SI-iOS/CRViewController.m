//
//  CRViewController.m
//  CloudRail-SI-iOS
//
//  Created by Felipe Cesar on 05/24/2016.
//  Copyright (c) 2016 Felipe Cesar. All rights reserved.
//

#import "CRViewController.h"
//#import "CloudRail.h"
#import <CloudRail_ServiceCode/CloudRail_ServiceCode.h>
@interface CRViewController ()

@property (nonatomic) Dropbox* dropbox;
@end

@implementation CRViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
  self.dropbox = [[Dropbox alloc] initWithClientId:@"IDENTIFIER" clientSecret:@"SECRET"];
	// Do any additional setup after loading the view, typically from a nib.
}

-(void)viewDidAppear:(BOOL)animated{

  NSInputStream * object = [self.dropbox downloadWithFilePath:@"/mudkip.jpg"];
  
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
