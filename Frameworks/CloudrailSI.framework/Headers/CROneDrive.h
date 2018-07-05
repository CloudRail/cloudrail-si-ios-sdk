
#import <Foundation/Foundation.h>
#import "CRCloudStorageProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"
#import "CRAuthenticationDelegate.h"
@interface CROneDrive : NSObject <CRCloudStorageProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;

-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret scopes:(NSMutableArray<NSString *> *)scopes;

-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state scopes:(NSMutableArray<NSString *> *)scopes;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;
-(void) setAuthDelegate:(id<CRAuthenticationDelegate>)delegate;
@end
