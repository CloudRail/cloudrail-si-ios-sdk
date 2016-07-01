
#import <Foundation/Foundation.h>

#import "CRPointsOfInterestProtocol.h"




@interface CRFoursquare : NSObject <CRPointsOfInterestProtocol>

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret;
@end
