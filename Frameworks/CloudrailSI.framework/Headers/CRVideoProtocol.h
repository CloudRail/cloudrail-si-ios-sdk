//
//  CRVideoProtocol.h
//  CloudrailSI
//
//  Created by Mujtaba Alam on 24.08.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import "CRVideoMetaData.h"
#import "CRChannelMetaData.h"
#import "CRAuthenticatingProtocol.h"
#import "CRPersistableProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

/**
 * A common interface for cloud storage services, abstracts to the level of paths consistently for all services.
 */
@protocol CRVideoProtocol <CRAuthenticatingProtocol, CRPersistableProtocol, CRAdvancedRequestSupporterProtocol>


/**
 * Upload video
 * @param title The name of the video
 * @param description The description of the video
 * @param stream The InputStream (video data) is going to be uploaded
 * @param size The size of the InputStream
 * @param channelId The Channel ID (optional)
 * @param mimeType The video mime type (e.g. video/) (required)
 * @return CRVideoMetaData metadata of the video after successfully uploaded
 */
- (CRVideoMetaData *_Nullable)uploadVideoWithTitle:(nonnull NSString *) title
                                description:(NSString *_Nullable) description
                                   stream:(nonnull NSInputStream *) stream
                                     size:(long) size
                                channelId:(NSString *_Nullable) channelId
                                 mimeType:(nonnull NSString *) mimeType;

/**
 * Retrives metadata of videos from search query
 *
 * @param query A query string to be used in the search for the file in the service.
 * @param offset The first video to return metadata for.
 * @param limit The maximum amount of videos that should be returned.
 * @return NSMutableArray<CRVideoMetaData *> An array containing the metadata of the videos matching the query.
 */

- (NSMutableArray<CRVideoMetaData *> * _Nullable)searchVideosWithQuery:(nonnull NSString *) query
                                                                 offset:(long) offset
                                                                  limit:(long) limit;

/**
 * Get video by video ID
 * @param videoId The video Id that you want to get
 * @return CRVideoMetaData metadata of the video
 */
- (CRVideoMetaData *_Nullable)videoWithId:(nonnull NSString *) videoId;


/**
 * Get channel metaData by channel ID
 * @param channelId The channel that you want to get metaData of
 * @return CRChannelMetaData metadata of the video
 */
- (CRChannelMetaData *_Nullable)channelWithId:(nonnull NSString *) channelId;


/**
 * Get channel metaData for own user
 * @return Users Own Channel metaData (CRChannelMetaData)
 */
- (CRChannelMetaData *_Nullable)channel;


/**
 * Retrives metadata of videos from channel
 *
 * @param channelId The channel ID whos video metaData you want to retrieve
 * @param offset The first video to return metadata for.
 * @param limit The maximum amount of videos that should be returned.
 * @return NSMutableArray<CRVideoMetaData *> An array containing the metadata of the videos matching the channelId.
 */

- (NSMutableArray<CRVideoMetaData *> * _Nullable)listVideosForChannel:(nonnull NSString *) channelId
                                                             offset:(long) offset
                                                              limit:(long) limit;

@end





