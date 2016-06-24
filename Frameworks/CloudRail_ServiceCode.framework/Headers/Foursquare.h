
#import <Foundation/Foundation.h>

#import "PointsOfInterestProtocol.h"




@interface Foursquare : NSObject <PointsOfInterestProtocol>

-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;

@end
