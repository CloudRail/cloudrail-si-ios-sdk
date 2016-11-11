
#import <Foundation/Foundation.h>
#import "CRPointsOfInterestProtocol.h"

@interface CRGooglePlaces : NSObject <CRPointsOfInterestProtocol>
@property (weak, nonatomic) id target;

- (instancetype)initWithApiKey:(NSString *)apiKey;



@end
