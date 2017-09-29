
#import <Foundation/Foundation.h>
#import "CRMessagingProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

@interface CRLine : NSObject <CRMessagingProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithBotToken:(NSString *)botToken;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
