
#import <Foundation/Foundation.h>
#import "CRPointsOfInterestProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

@interface CRYelp : NSObject <CRPointsOfInterestProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret token:(NSString *)token tokenSecret:(NSString *)tokenSecret;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
