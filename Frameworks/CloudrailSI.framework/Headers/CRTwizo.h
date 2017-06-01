
#import <Foundation/Foundation.h>
#import "CRSMSProtocol.h"

@interface CRTwizo : NSObject <CRSMSProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithKey:(NSString *)key;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
