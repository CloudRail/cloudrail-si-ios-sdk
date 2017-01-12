
#import <Foundation/Foundation.h>
#import "CRProfileProtocol.h"

@interface CRGitHub : NSObject <CRProfileProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

//Specific for CloudStorage Interface
-(instancetype)initWithClientId:(NSString *)clientId clientSecret: (NSString *)clientSecret;

@end
