
#import <Foundation/Foundation.h>

#import "CRProfileProtocol.h"




@interface CRGitHub : NSObject <CRProfileProtocol>

-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;
@end
