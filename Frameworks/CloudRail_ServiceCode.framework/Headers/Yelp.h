
#import <Foundation/Foundation.h>

#import "PointsOfInterestProtocol.h"




@interface Yelp : NSObject <PointsOfInterestProtocol>

-(instancetype)initWithConsumerKey:(NSString *)consumerKey consumerSecret: (NSString *)consumerSecret token: (NSString *)token tokenSecret: (NSString *)tokenSecret;
@end
