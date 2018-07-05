
#import <Foundation/Foundation.h>
#import "CRCloudStorageProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"
#import "CRAuthenticationDelegate.h"
@interface CREgnyte : NSObject <CRCloudStorageProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithDomain:(NSString *)domain clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;

-(instancetype)initWithDomain:(NSString *)domain clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret scopes:(NSMutableArray<NSString *> *)scopes;

-(instancetype)initWithDomain:(NSString *)domain clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

-(instancetype)initWithDomain:(NSString *)domain clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state scopes:(NSMutableArray<NSString *> *)scopes;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;
-(void) setAuthDelegate:(id<CRAuthenticationDelegate>)delegate;
@end
