//
//  CRAuthenticationDelegate.h
//  CloudrailSI
//
//  Created by Felipe César Silveira de Assis on 18/06/18.
//  Copyright © 2018 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CRAuthenticationDelegate <NSObject>

@optional
-(void) authDidStart:(NSDictionary<NSString*,NSString*> *) service;
-(void) authDidFinish:(NSDictionary<NSString*,NSString*> *) service;
-(void) authDidCancel:(NSDictionary<NSString*,NSString*> *) service;

@end
