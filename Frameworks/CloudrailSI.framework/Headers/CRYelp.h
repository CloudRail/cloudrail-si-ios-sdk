
#import <Foundation/Foundation.h>

#import "CRPointsOfInterestProtocol.h"




@interface CRYelp : NSObject <CRPointsOfInterestProtocol>

-(instancetype)initWithConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret token:(NSString *)token tokenSecret:(NSString *)tokenSecret;
@end
