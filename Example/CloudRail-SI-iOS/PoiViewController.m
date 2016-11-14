//
//  PoiViewController.m
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 22/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "PoiViewController.h"

@implementation PoiViewController

-(void)viewDidLoad{
  
  
  if ([self.serviceName isEqualToString:@"Yelp"]) {
    self.service = [[CRYelp alloc] initWithConsumerKey:@"6aiXfOwD3wcHh1VJnDdDow" consumerSecret:@"Hr_wv-72pm7CJ6rcNMxKdiKkNlE" token:@"Kc4hsHaW1NsL2CYwWuBBZa32AXcTqr3l"  tokenSecret:@"9P8T6eYYllj1qyrdCLhgERNHloU"];
  } else if([self.serviceName isEqualToString:@"GooglePlaces"]){
    self.service = [[CRGooglePlaces alloc] initWithApiKey:@"AIzaSyCMSQyKrvt-Wlauh0k5zP8J7ONcnL6IQT8"];
    
  } else if ([self.serviceName isEqualToString:@"Foursquare"]){
    self.service = [[CRFoursquare alloc] initWithClientId:@"2HVTEYZ3LKKRPNRUFVOGTVIF0WLL0XMUJPZQS0QEB1MAB12P" clientSecret:@"PYFJIRODDMQL5N1WTZPBTTR5EMC2W2RJVIX0H5KAQBI43SXM"];
  }
}

- (IBAction)firstTest:(id)sender {
  //FIX the generator!!
  //MAnnheim : 49.483927, 8.473272
  NSMutableArray<CRPOI*> * poi =  [self.service nearbyPoisWithLatitude:@49.483927 longitude:@8.473272 radius:@300 searchTerm:nil categories:nil];
  NSLog(@"%@", poi);
}
@end
