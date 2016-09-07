
#import <Foundation/Foundation.h>
#import "CRPointsOfInterestProtocol.h"

@interface CRFoursquare : NSObject <CRPointsOfInterestProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret;



@end
