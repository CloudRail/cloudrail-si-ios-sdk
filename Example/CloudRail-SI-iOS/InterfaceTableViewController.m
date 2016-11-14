//
//  InterfaceTableViewController.m
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 31/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "InterfaceTableViewController.h"
#import "ProvidersTableViewController.h"

@interface InterfaceTableViewController ()
@property (nonatomic) NSMutableArray * sourceInterfaces;
@property (nonatomic) NSString * selectedService;
@end

@implementation InterfaceTableViewController

- (void)viewDidLoad {
  
  [super viewDidLoad];
  
  self.sourceInterfaces = [@[] mutableCopy];
  
  [self.sourceInterfaces addObject:@"CloudStorage"];
  [self.sourceInterfaces addObject:@"Profile"];
  [self.sourceInterfaces addObject:@"PointsOfInterest"];
  [self.sourceInterfaces addObject:@"Email"];
  [self.sourceInterfaces addObject:@"Payment"];
  [self.sourceInterfaces addObject:@"SMS"];
  [self.sourceInterfaces addObject:@"Social"];
  
}


#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
  return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
  return [self.sourceInterfaces count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
  UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
  
  cell.textLabel.text = self.sourceInterfaces[indexPath.row];
  
  return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
  self.selectedService = [self sourceInterfaces][indexPath.row];
  [self performSegueWithIdentifier:@"toProviders" sender:self];
  
}

#pragma mark - Navigation

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {

  [(ProvidersTableViewController*)segue.destinationViewController setCurrentInterface:self.selectedService];
}

@end
