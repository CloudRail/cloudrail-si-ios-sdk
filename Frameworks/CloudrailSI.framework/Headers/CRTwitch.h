
#import <Foundation/Foundation.h>
#import "CRVideoProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

@interface CRTwitch : NSObject <CRVideoProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
