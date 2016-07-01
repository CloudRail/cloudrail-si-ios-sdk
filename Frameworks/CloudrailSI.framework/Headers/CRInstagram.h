
#import <Foundation/Foundation.h>

#import "CRProfileProtocol.h"




@interface CRInstagram : NSObject <CRProfileProtocol>

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;
@end
