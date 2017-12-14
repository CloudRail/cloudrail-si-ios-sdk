
#import <Foundation/Foundation.h>
#import "CRMessagingProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

@interface CRSlackBot : NSObject <CRMessagingProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithBotToken:(NSString *)botToken;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
