//
//  ProfileProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 30/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AuthenticatingProtocol.h"
#import "DateOfBirth.h"
#import "PersistableProtocol.h"

@protocol ProfileProtocol <AuthenticatingProtocol,PersistableProtocol>

-(void) initializeServiceCode;
-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;


-(NSString *) identifier;
-(NSString *) fullName;
-(NSString *) email;
-(NSString *) gender;
-(NSString *) description;
-(DateOfBirth *) dateOfBirth;
-(NSString *) locale;
-(NSString *) pictureURL;

@end
