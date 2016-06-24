
#import <Foundation/Foundation.h>

#import "PointsOfInterestProtocol.h"




@interface GooglePlaces : NSObject <PointsOfInterestProtocol>

-(instancetype)initWithApiKey:(NSString *)apiKey;
@end
