
#import <Foundation/Foundation.h>
#import "CRProfileProtocol.h"
#import "CRSocialProtocol.h"

@interface CRTwitter : NSObject <CRProfileProtocol, CRSocialProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri;

//Specific for CloudStorage Interface
-(instancetype)initWithClientId:(NSString *)clientId clientSecret: (NSString *)clientSecret;

-(void)useAdvancedAuthentication;

@end
