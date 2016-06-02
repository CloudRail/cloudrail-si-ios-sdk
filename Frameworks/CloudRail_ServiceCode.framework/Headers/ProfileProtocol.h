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

/**
 * @return A unique identifier for the authenticated user. All services provide this value. Useful for "Login with ...". Prefixed with the lowercased service name and a minus.
 */
-(NSString *) identifier;

/**
 * @return The user's full name or null if not present
 */
-(NSString *) fullName;

/**
 * @return The user's email address or null if not present
 */
-(NSString *) email;

/**
 * @return The user's gender, normalized to be one of "female", "male", "other" or null if not present
 */
-(NSString *) gender;

/**
 * @return The description the user has given themselves or null if not present
 */
-(NSString *) description;

/**
 * @return The date of birth in a special format, see {@link com.cloudrail.si.types.DateOfBirth DateOfBirth}
 */
-(DateOfBirth *) dateOfBirth;

/**
 * @return The locale/language setting of the user, e.g. "en", "de" or null if not present
 */
-(NSString *) locale;

/**
 * @return The URL of the user's profile picture or null if not present
 */
-(NSString *) pictureURL;

@end
