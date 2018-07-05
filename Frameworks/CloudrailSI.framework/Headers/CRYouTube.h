
#import <Foundation/Foundation.h>
#import "CRVideoProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"
#import "CRAuthenticationDelegate.h"
@interface CRYouTube : NSObject <CRVideoProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithApiKey:(NSString *)apiKey;

-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state scopes:(NSMutableArray<NSString *> *)scopes;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;
-(void) setAuthDelegate:(id<CRAuthenticationDelegate>)delegate;
@end
