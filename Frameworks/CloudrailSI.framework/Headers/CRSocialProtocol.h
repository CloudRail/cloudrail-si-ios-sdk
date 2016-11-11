//
//  SocialProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRPersistableProtocol.h"

/**
 * Interface for interaction with social networks
 */
@protocol CRSocialProtocol <NSObject,CRPersistableProtocol>

/**
 * Creates a new post/update to the currently logged in user's wall/stream/etc.
 * @param content The post's content
 */
- (void) postUpdateWithContent:(nonnull NSString *) content;

/**
 * Retrieves a list of connection/friend/etc. IDs.
 * The IDs are compatible with those returned by Profile.getIdentifier().
 * @return A (possibly empty) list of IDs
 */
- (nonnull NSArray<NSString *>*) connections;


@end
