
#import <Foundation/Foundation.h>
#import "CRProfileProtocol.h"
#import "CRSocialProtocol.h"

@interface CRFacebook : NSObject <CRProfileProtocol, CRSocialProtocol>

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;



@end
