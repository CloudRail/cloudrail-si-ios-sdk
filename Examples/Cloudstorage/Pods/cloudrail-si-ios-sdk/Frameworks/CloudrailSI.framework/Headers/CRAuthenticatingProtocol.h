
//  AuthenticatingProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 30/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  common interface for services that allow logging in and out actions.
 */
@protocol CRAuthenticatingProtocol <NSObject>

/**
 * (Optional) Explicitly triggers user authentication.
 * Allows better control over the authentication process.
 * Optional because all methods that require prior authentication will trigger it automatically,
 * unless this method has been called before.
 */
- (void)login;

/**
 * (Optional) Revokes the current authentication.
 */
- (void)logout;

@end
