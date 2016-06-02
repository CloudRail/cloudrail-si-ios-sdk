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
    
  } else if([self.currentInterface isEqualToString:@"CloudStorage"]){
    [self.sourceInterfaces addObject:@"Box"];
    [self.sourceInterfaces addObject:@"Dropbox"];
    [self.sourceInterfaces addObject:@"GoogleDrive"];
    [self.sourceInterfaces addObject:@"OneDrive"];
  }
  
  self.selectedInterface = @"";
  
  
  [self.tableView reloadData];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
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
  [self performSegueWithIdentifier:@"toService" sender:self];
}


#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {

  [(ProfileViewController*)segue.destinationViewController setServiceName:self.selectedInterface];

}


@end
