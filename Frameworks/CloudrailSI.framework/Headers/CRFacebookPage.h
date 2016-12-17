
#import <Foundation/Foundation.h>
#import "CRSocialProtocol.h"
#import "CRAuthenticatingProtocol.h"

@interface CRFacebookPage : NSObject <CRSocialProtocol,CRAuthenticatingProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithPageName:(NSString *)pageName clientID:(NSString *)clientID clientSecret:(NSString *)clientSecret;



@end
