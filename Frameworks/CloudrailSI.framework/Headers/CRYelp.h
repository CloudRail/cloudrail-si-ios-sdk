
#import <Foundation/Foundation.h>
#import "CRPointsOfInterestProtocol.h"

@interface CRYelp : NSObject <CRPointsOfInterestProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithClientID:(NSString *)clientID clientSecret:(NSString *)clientSecret;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
