//
//  ProfileProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 30/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRAuthenticatingProtocol.h"
#import "CRDateOfBirth.h"
#import "CRPersistableProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"
/**
 * An interface that provides access to a diverse range of services that provide user data. They all have in common, that they allow you to get a unique identifier for a logged in user, so it can be used for "Login with ..." scenarios. All the other information might be present or not, depending on the service and how much information the user has filled out with the respective service. To avoid unnecessary requests, information is cached up to one minute.
 */
@protocol CRProfileProtocol <CRAuthenticatingProtocol,CRPersistableProtocol,CRAdvancedRequestSupporterProtocol>


/**
 * @return A unique identifier for the authenticated user. All services provide this value. Useful for "Login with ...". Prefixed with the lowercased service name and a minus.
 */
- (nonnull NSString *)identifier;

/**
 * @return The user's full name or null if not present
 */
- (nullable NSString *)fullName;

/**
 * @return The user's email address or null if not present
 */
- (nullable NSString *)email;

/**
 * @return The user's gender, normalized to be one of "female", "male", "other" or null if not present
 */
- (nullable NSString *)gender;

/**
 * @return The description the user has given themselves or null if not present
 */
- (nullable NSString *)profileDescription;

/**
 * @return The date of birth in a special format, see {@link com.cloudrail.si.types.DateOfBirth DateOfBirth}
 */
- (nullable CRDateOfBirth *)dateOfBirth;

/**
 * @return The locale/language setting of the user, e.g. "en", "de" or null if not present
 */
- (nullable NSString *)locale;

/**
 * @return The URL of the user's profile picture or null if not present
 */
- (nonnull NSString *)pictureURL;

@end
