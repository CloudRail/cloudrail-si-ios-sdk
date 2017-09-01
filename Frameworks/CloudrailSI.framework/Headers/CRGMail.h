
#import <Foundation/Foundation.h>
#import "CREmailProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

@interface CRGMail : NSObject <CREmailProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithClientID:(NSString *)clientID clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
