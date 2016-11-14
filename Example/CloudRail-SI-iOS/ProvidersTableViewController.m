//
//  ProvidersTableViewController.m
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 31/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "ProvidersTableViewController.h"
#import "ProfileViewController.h"

@interface ProvidersTableViewController ()
@property (nonatomic) NSMutableArray * sourceInterfaces;
@property (nonatomic) NSString * selectedInterface;

@end

@implementation ProvidersTableViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  // Uncomment the following line to preserve selection between presentations.
  // self.clearsSelectionOnViewWillAppear = NO;
  
  // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
  // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

-(void)viewDidAppear:(BOOL)animated{
  self.sourceInterfaces = [@[] mutableCopy];
  
  
  if ([self.currentInterface isEqualToString:@"Profile"]) {
    
    [self.sourceInterfaces addObject:@"Facebook"];
    [self.sourceInterfaces addObject:@"GitHub"];
    [self.sourceInterfaces addObject:@"GooglePlus"];
    [self.sourceInterfaces addObject:@"LinkedIn"];
    [self.sourceInterfaces addObject:@"MicrosoftLive"];
    [self.sourceInterfaces addObject:@"Slack"];
    [self.sourceInterfaces addObject:@"Twitter"];
    [self.sourceInterfaces addObject:@"Yahoo"];
    [self.sourceInterfaces addObject:@"Instagram"];
    
    
  } else if([self.currentInterface isEqualToString:@"CloudStorage"]){
    [self.sourceInterfaces addObject:@"Box"];
    [self.sourceInterfaces addObject:@"Dropbox"];
    [self.sourceInterfaces addObject:@"GoogleDrive"];
    [self.sourceInterfaces addObject:@"OneDrive"];
    [self.sourceInterfaces addObject:@"Egnyte"];
    
  } else if([self.currentInterface isEqualToString:@"PointsOfInterest"]){
    [self.sourceInterfaces addObject:@"Foursquare"];
    [self.sourceInterfaces addObject:@"GooglePlaces"];
    [self.sourceInterfaces addObject:@"Yelp"];
  } else if([self.currentInterface isEqualToString:@"Email"]){
    [self.sourceInterfaces addObject:@"MailJet"];
    [self.sourceInterfaces addObject:@"SendGrid"];
  } else if([self.currentInterface isEqualToString:@"Payment"]){
    [self.sourceInterfaces addObject:@"PayPal"];
    [self.sourceInterfaces addObject:@"Stripe"];
  } else if([self.currentInterface isEqualToString:@"SMS"]){
    [self.sourceInterfaces addObject:@"Nexmo"];
    [self.sourceInterfaces addObject:@"Twilio"];
  } else if([self.currentInterface isEqualToString:@"Social"]){
    [self.sourceInterfaces addObject:@"Facebook"];
    [self.sourceInterfaces addObject:@"Twitter"];
  }
  
  self.selectedInterface = @"";
  [self.tableView reloadData];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
  return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
  return [self.sourceInterfaces count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
  UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell2" forIndexPath:indexPath];
  
  cell.textLabel.text = self.sourceInterfaces[indexPath.row];
  
  return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
  
  self.selectedInterface = self.sourceInterfaces[indexPath.row];
  
  if ([self.currentInterface isEqualToString:@"Profile"]) {
    [self performSegueWithIdentifier:@"toService" sender:self];
    
  } else if([self.currentInterface isEqualToString:@"CloudStorage"]){
    [self performSegueWithIdentifier:@"toCloudStorage" sender:self];
    
  } else if([self.currentInterface isEqualToString:@"PointsOfInterest"]){
    [self performSegueWithIdentifier:@"toPoi" sender:self];
    
    
  } else if([self.currentInterface isEqualToString:@"Email"]){
    [self performSegueWithIdentifier:@"toEmail" sender:self];
    
    
  } else if([self.currentInterface isEqualToString:@"Payment"]){
    [self performSegueWithIdentifier:@"toPayment" sender:self];
    
    
  } else if([self.currentInterface isEqualToString:@"SMS"]){
    [self performSegueWithIdentifier:@"toSms" sender:self];
    
    
  }else if([self.currentInterface isEqualToString:@"Social"]){
    [self performSegueWithIdentifier:@"toSocial" sender:self];
    
    
  }
}

#pragma mark - Navigation

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {

  [(ProfileViewController*)segue.destinationViewController setServiceName:self.selectedInterface];
  
}

@end
