//
//  CRVideoMetaData.h
//  CloudrailSI
//
//  Created by Mujtaba Alam on 24.08.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRVideoMetaData : CRSandboxObject

@property (strong, nonatomic) NSString * videoId;
@property (strong, nonatomic) NSString * videoTitle;
@property (strong, nonatomic) NSString * videoDescription;
@property (strong, nonatomic) NSNumber * publishedAt;
@property (strong, nonatomic) NSString * channelId;
@property (strong, nonatomic) NSNumber * duration;
@property (strong, nonatomic) NSString * thumbnailUrl;
@property (strong, nonatomic) NSString * embedHtml;
@property (strong, nonatomic) NSNumber * viewCount;
@property (strong, nonatomic) NSNumber * likeCount;
@property (strong, nonatomic) NSNumber * dislikeCount;


- (void)initWithVideoId:(NSString *)videoId
             videoTitle:(NSString *)videoTitle
       videoDescription:(NSString *)videoDescription
            publishedAt:(NSNumber *)publishedAt
              channelId:(NSString *)channelId
               duration:(NSNumber *)duration
           thumbnailUrl:(NSString *)thumbnailUrl
              embedHtml:(NSString *)embedHtml
              viewCount:(NSNumber *)viewCount
              likeCount:(NSNumber *)likeCount
           dislikeCount:(NSNumber *)dislikeCount;


@end
