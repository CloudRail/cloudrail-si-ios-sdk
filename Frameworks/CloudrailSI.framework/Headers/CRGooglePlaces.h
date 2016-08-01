
#import <Foundation/Foundation.h>
#import "CRPointsOfInterestProtocol.h"

@interface CRGooglePlaces : NSObject <CRPointsOfInterestProtocol>

-(instancetype)initWithApiKey:(NSString *)apiKey;



@end
