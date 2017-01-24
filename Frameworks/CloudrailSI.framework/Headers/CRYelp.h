
#import <Foundation/Foundation.h>
#import "CRPointsOfInterestProtocol.h"

@interface CRYelp : NSObject <CRPointsOfInterestProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret token:(NSString *)token tokenSecret:(NSString *)tokenSecret;



-(void)useAdvancedAuthentication;

@end
