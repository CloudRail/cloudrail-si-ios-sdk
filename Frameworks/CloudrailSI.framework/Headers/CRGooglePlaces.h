
#import <Foundation/Foundation.h>
#import "CRPointsOfInterestProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

@interface CRGooglePlaces : NSObject <CRPointsOfInterestProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithApiKey:(NSString *)apiKey;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
