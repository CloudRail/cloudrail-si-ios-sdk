//
//  SocialProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRPersistableProtocol.h"
#import "CRAuthenticatingProtocol.h"

/**
 * Interface for interaction with social networks
 */
@protocol CRSocialProtocol <NSObject,CRPersistableProtocol,CRAuthenticatingProtocol>

/**
 * Creates a new post/update to the currently logged in user's wall/stream/etc.
 * @param content The post's content
 */
- (void) postUpdateWithContent:(nonnull NSString *) content;

/**
 * Creates a new post/update to the currently logged in user's wall/stream/etc posting an
 * image and a message.
 * Throws an exception if the message is too long for the service instance.
 *
 * @param message The message that shall be posted together with the image.
 * @param image Stream containing the image content.
 */
- (void) postImageWithMessage:(nonnull NSString *) message
                        image:(nonnull NSInputStream *) image;

/**
 * Creates a new post/update to the currently logged in user's wall/stream/etc posting a
 * video and a message.
 * Throws an exception if the message is too long for the service instance.
 *
 * @param message The message that shall be posted together with the video.
 * @param video Stream containing the video content.
 * @param size The size of the video in bytes.
 * @param mimeType The mime type of the video, for instance video/mp4.
 */
- (void) postVideoWithMessage:(nonnull NSString *) message
                        video:(nonnull NSInputStream *) video
                         size:(long) size
                     mimeType:(nonnull NSString *) mimeType;

/**
 * Retrieves a list of connection/friend/etc. IDs.
 * The IDs are compatible with those returned by Profile.getIdentifier().
 * @return A (possibly empty) list of IDs
 */
- (nonnull NSArray<NSString *>*) connections;


@end
