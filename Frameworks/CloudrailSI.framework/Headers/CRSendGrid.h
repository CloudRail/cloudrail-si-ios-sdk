
#import <Foundation/Foundation.h>
#import "CREmailProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"
#import "CRAuthenticationDelegate.h"
@interface CRSendGrid : NSObject <CREmailProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithApiKey:(NSString *)apiKey;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;
-(void) setAuthDelegate:(id<CRAuthenticationDelegate>)delegate;
@end
