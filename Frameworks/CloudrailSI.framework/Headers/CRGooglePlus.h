
#import <Foundation/Foundation.h>

#import "CRProfileProtocol.h"




@interface CRGooglePlus : NSObject <CRProfileProtocol>

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;
@end
