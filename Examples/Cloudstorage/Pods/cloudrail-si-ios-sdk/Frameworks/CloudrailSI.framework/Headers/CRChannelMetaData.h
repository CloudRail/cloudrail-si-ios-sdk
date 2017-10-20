//
//  CRChannelMetaData.h
//  CloudrailSI
//
//  Created by Mujtaba Alam on 24.08.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRChannelMetaData : CRSandboxObject

@property (strong, nonatomic) NSString * channelId;
@property (strong, nonatomic) NSString * name;

@property (strong, nonatomic) NSNumber * followers;
@property (strong, nonatomic) NSString * url;

@property (strong, nonatomic) NSString * logoUrl;
@property (strong, nonatomic) NSString * bannerUrl;


- (void)initWithChannelId:(NSString *)channelId
             name:(NSString *)name
            followers:(NSNumber *)followers
              url:(NSString *)url
               logoUrl:(NSString *)logoUrl
           bannerUrl:(NSString *)bannerUrl;


@end
