//
//  PaymentViewController.m
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 23/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "PaymentViewController.h"

@implementation PaymentViewController
- (void)viewDidLoad {
  [super viewDidLoad];
  
  NSDictionary * authDic = @{
                             @"paypalKey" : @"AVeum9__j-L3R4d5kCxB6WBHwU6_D2t572vIcsXt5NVJGCfckrFaZUiAQSU9iX2RzS9I6YN8PhWFUzJ7",
                             @"paypalSecret" : @"EACwCe3Rmq7NgSWu0HNOXvxsC_q-SW4NRDUkOsE0vPRCVYZxE2V7bUqJA32j7Da_sW_XJXJOUgtUO2nf",
                             
                             @"stripeKey" : @"sk_test_44hDJ8L9grqg5RJ8WCS5rUUV",
                             };
  
  
  NSString * key = [[self.serviceName lowercaseString] stringByAppendingString:@"Key"];
  NSString * secret = [[self.serviceName lowercaseString] stringByAppendingString:@"Secret"];
  
  
  if ([self.serviceName isEqualToString:@"PayPal"]) {
    self.service = [[CRPayPal alloc] initWithUseSandbox:YES clientId:authDic[key] clientSecret:authDic[secret]];
  } else if([self.serviceName isEqualToString:@"Stripe"]){
    self.service = [[CRStripe alloc]initWithSecretKey:authDic[key]];
    
  }
  

  
}
- (IBAction)listSubscriptionPlans:(id)sender {//OK
  
//  if([self.serviceName isEqualToString:@"Stripe"]){
//    self.service = [[Stripe alloc]initWithSecretKey:authDic[key]];
    NSMutableArray<CRSubscriptionPlan*> * plans = [self.service listSubscriptionPlans];
  
  
  NSLog(@"Plans - %@", plans);
  
}
- (IBAction)cancelSubscription:(id)sender {//OK!!!
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    [self.service cancelSubscriptionWithIdentifier:@"sub_8h0XCMFVcgIule"];
    return;
  }
  
  [self.service cancelSubscriptionWithIdentifier:@"I-X1YC5M5RVVGM"];
}
- (IBAction)createSubscription:(id)sender {//OK
  
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    CRCreditCard * master = [[CRCreditCard alloc] init];
    master.number= @"4242424242424242";
    master.expire_month = @12;
    master.expire_year = @2017;
    master.cvc = @"123";
    master.firstName = @"Bob";
    master.lastName = @"Bauer";
    master.type = @"visa";
    master.address = [[CRAddress alloc] init];
    master.address.country = @"US";
    master.address.city = @"Nova York";
    master.address.state = @"CA";
    master.address.line1 = @"csb 08 lote 3 e 4";
    master.address.line2 = @"aqui e lefal";
    master.address.postalCode = @"68163";
    
    NSLog(@"MASTER - %@", master);
    CRSubscription * subscribed=  [self.service createSubscriptionWithPlanID:@"Felipe Awesome" name:@"Bob Client" description:@"Bob subscribed" source:master];
    NSLog(@"Subscription - %@", subscribed);
    return;
  }
  
  CRCreditCard * master = [self paypalCard1];
  CRSubscription * subscribed=  [self.service createSubscriptionWithPlanID:@"P-83J31140HE0634304QGWFOUA" name:@"Bob Client" description:@"Bob subscribed" source:master];
  
  NSLog(@"Subscription - %@", subscribed);
  
}
- (IBAction)partiallyRefound:(id)sender {//OK
  
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    CRRefund* refund = [self.service partiallyRefundChargeWithIdentifier:@"ch_18PdLMF5KQWFtvy8X571vBlx" amount:@100];
    NSLog(@"Refund - %@", refund);
    return;
  }
  
  
  CRRefund* refund = [self.service partiallyRefundChargeWithIdentifier:@"PAY-54B164195A4923009K5VDLII" amount:@400];
  NSLog(@"Refund - %@", refund);
}


- (IBAction)createCharge:(id)sender {//OK
  
  
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    
    CRCreditCard * master = [[CRCreditCard alloc] init];
    master.number= @"4242424242424242";
    master.expire_month = @12;
    master.expire_year = @2017;
    master.cvc = @"123";
    master.firstName = @"Bob";
    master.lastName = @"Bauer";
    master.type = @"visa";
    master.address = [[CRAddress alloc] init];
    master.address.country = @"US";
    master.address.city = @"Nova York";
    master.address.state = @"CA";
    master.address.line1 = @"csb 08 lote 3 e 4";
    master.address.line2 = @"aqui e lefal";
    master.address.postalCode = @"68163";
    
    CRCharge * charge = [self.service createChargeWithAmount:@500 currency:@"USD" source:master];
    NSLog(@"Charge - %@", charge);
    return;
  }
  
  CRCharge * charge = [self.service createChargeWithAmount:@500 currency:@"USD" source:[self paypalCard1]];
  NSLog(@"Charge - %@", charge);

}

- (IBAction)listCharges:(id)sender {  //OK
  
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    
    CRCreditCard * master = [[CRCreditCard alloc] init];
    master.number= @"4242424242424242";
    master.expire_month = @12;
    master.expire_year = @2017;
    master.cvc = @"123";
    master.firstName = @"Bob";
    master.lastName = @"Bauer";
    master.type = @"visa";
    master.address = [[CRAddress alloc] init];
    master.address.country = @"US";
    master.address.city = @"Nova York";
    master.address.state = @"CA";
    master.address.line1 = @"csb 08 lote 3 e 4";
    master.address.line2 = @"aqui e lefal";
    master.address.postalCode = @"68163";
    NSMutableArray<CRCharge*> * charges = [self.service listChargesFrom:@1466553600 to:@1466719200 creditCard:master];
    NSLog(@"Charges - %@", charges);
    return;
  }
  
  
//  MILISECONDS!!!!!
  NSMutableArray<CRCharge*> * charges = [self.service listChargesFrom:@1466553600000 to:@1466861880000 creditCard:[self paypalCard1]];
  NSLog(@"Charges - %@", charges);

  
}
- (IBAction)createSubscriptionPlan:(id)sender {//OK
  
  
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    CRSubscriptionPlan * subPlan = [self.service createSubscriptionPlanWithName:@"Felipe Awesome3" amount:@2000 currency:@"USD" description:@"Avengers bill" interval:@"day" intervalCount:@7];
    
    NSLog(@"Sub plan %@", subPlan);
    return;
  }
  
   CRSubscriptionPlan * subPlan = [self.service createSubscriptionPlanWithName:@"Felipe Awesome2" amount:@2000 currency:@"USD" description:@"Avengers bill" interval:@"day" intervalCount:@7];
  NSLog(@"Sub plan %@", subPlan);

  
}
- (IBAction)refoundsForCharge:(id)sender {//OK
  
  
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    
    NSMutableArray<CRRefund*> * refund = [self.service refundsForChargeWithIdentifier:@"ch_18Pcl5F5KQWFtvy8LhOxBzMo"];
    
    NSLog(@"rfounds - %@", refund);
    return;
  }
  
  NSMutableArray<CRRefund*> * refund = [self.service refundsForChargeWithIdentifier:@"PAY-8DX81751SL278112JK5WRGAQ"];
  
  NSLog(@"rfounds - %@", refund);
  
}

- (IBAction)getCharge:(id)sender {//OK
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    CRCharge* charge = [self.service chargeWithIdentifier:@"ch_18PcW7F5KQWFtvy8ffNbOeSs"];
    NSLog(@"charge - %@",charge);
    return;
  }
  
  
  CRCharge* charge = [self.service chargeWithIdentifier:@"PAY-8DX81751SL278112JK5WRGAQ"];
  NSLog(@"charge - %@",charge);
  return;
}
- (IBAction)getRefound:(id)sender {//OK
  
  
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    CRRefund * refund = [self.service refundWithIdentifier:@"re_18Pd0zF5KQWFtvy8woazzTiY"];
    NSLog(@"Refund - %@", refund);
    return;
  }
  CRRefund * refund = [self.service refundWithIdentifier:@"36C47073MA8530026"];
  NSLog(@"Refund - %@", refund);
}

- (IBAction)refundCharges:(id)sender {//OK
  
  if ([self.serviceName isEqualToString:@"Stripe"]) {
    CRRefund * refund = [self.service refundChargeWithIdentifier:@"ch_18Pcl5F5KQWFtvy8LhOxBzMo"];
    NSLog(@"Refund - %@", refund);
    return;
  }
  
  
  
  CRRefund * refund= [self.service refundChargeWithIdentifier:@"PAY-8DX81751SL278112JK5WRGAQ"];
  NSLog(@"Refund - %@", refund);

  
  
}


-(CRCreditCard *) paypalCard1{
  CRCreditCard * master = [[CRCreditCard alloc] init];
  master.number= @"4032033787054753";
  master.expire_month = @06;
  master.expire_year = @2021;
  //  master.cvc = @"123";
  master.firstName = @"Patrick";
  master.lastName = @"Stoklasa";
  master.type = @"visa";
  master.address = [[CRAddress alloc] init];
  master.address.country = @"DE";
  master.address.city = @"Nova York";
  master.address.state = @"CA";
  master.address.line1 = @"csb 08 lote 3 e 4";
  master.address.line2 = @"aqui e lefal";
  master.address.postalCode = @"68163";
  
  return master;
//  NSLog(@"MASTER - %@", master);
}

-(CRCreditCard *) paypalCard2{
  CRCreditCard * master = [[CRCreditCard alloc] init];
  master.number= @"4032032553030369";
  master.expire_month = @06;
  master.expire_year = @2021;
  //  master.cvc = @"123";
  master.firstName = @"Patrick";
  master.lastName = @"Stoklasa";
  master.type = @"visa";
  master.address = [[CRAddress alloc] init];
  master.address.country = @"DE";
  master.address.city = @"Nova York";
  master.address.state = @"CA";
  master.address.line1 = @"csb 08 lote 3 e 4";
  master.address.line2 = @"aqui e lefal";
  master.address.postalCode = @"68163";
  
  return master;
  //  NSLog(@"MASTER - %@", master);
}

@end
