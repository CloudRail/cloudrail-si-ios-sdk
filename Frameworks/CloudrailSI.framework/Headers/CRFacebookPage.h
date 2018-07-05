
#import <Foundation/Foundation.h>
#import "CRSocialProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"
#import "CRAuthenticationDelegate.h"
@interface CRFacebookPage : NSObject <CRSocialProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithPageName:(NSString *)pageName clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;

-(instancetype)initWithPageName:(NSString *)pageName clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret scopes:(NSMutableArray<NSString *> *)scopes;

-(instancetype)initWithPageName:(NSString *)pageName clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

-(instancetype)initWithPageName:(NSString *)pageName clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state scopes:(NSMutableArray<NSString *> *)scopes;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;
-(void) setAuthDelegate:(id<CRAuthenticationDelegate>)delegate;
@end
