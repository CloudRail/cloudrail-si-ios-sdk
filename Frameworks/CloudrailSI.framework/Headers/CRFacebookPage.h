
#import <Foundation/Foundation.h>
#import "CRSocialProtocol.h"

@interface CRFacebookPage : NSObject <CRSocialProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithPageName:(NSString *)pageName clientID:(NSString *)clientID clientSecret:(NSString *)clientSecret;



@end
