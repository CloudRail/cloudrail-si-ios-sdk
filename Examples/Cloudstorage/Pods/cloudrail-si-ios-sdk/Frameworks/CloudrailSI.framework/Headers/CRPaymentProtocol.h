//
//  PaymentProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRCharge.h"
#import "CRRefund.h"
#import "CRSubscription.h"
#import "CRSubscriptionPlan.h"

/**
 * A simple interface for managing payment tasks.
 */
@protocol CRPaymentProtocol <NSObject>


/**
 * Charges a credit card and returns a charge resource.
 *
 * @param amount A positive integer in the smallest currency unit (e.g. cents)
 *      representing how much to charge the credit card.
 * @param currency A three-letter ISO code for currency.
 * @param source The credit card to be charged.
 * @return A charge resource representing the newly created payment.
 */
- (nonnull CRCharge *)createChargeWithAmount:(nonnull NSNumber *)amount
                                   currency:(nonnull NSString *)currency
                                     source:(nonnull CRCreditCard *)source;
/**
 * Returns information about an existing charge. Mostly used to get an update
 * on the status of the charge.
 *
 * @param identifier The ID of the charge.
 * @return A charge resource for the provided ID.
 */
- (nonnull CRCharge *)chargeWithIdentifier:(nonnull NSString *)identifier;

/**
 * Receive a list of charges within a specified timeframe.
 *
 * @param from Timestamp representing the start date for the list.
 * @param to Timestamp representing the end date for the list.
 * @param creditCard Optionally the credit card information so it can be listed all the charges of this specific credit card.
 * @return List of charge resources.
 */
- (nonnull NSMutableArray<CRCharge *> *)listChargesFrom:(nonnull NSNumber *)from
                                                    to:(nonnull NSNumber *)to
                                            creditCard:(nonnull CRCreditCard *)creditCard;
/**
 * Refund a previously made charge.
 *
 * @param identifier The ID of the charge to be refunded.
 * @return A refund resource.
 */
- (nonnull CRRefund *)refundChargeWithIdentifier:(nonnull NSString *)identifier;

/**
 * Refund a specified amount from a previously made charge.
 *
 * @param identifier The ID of the charge to be refunded.
 * @param amount The amount that shall be refunded.
 * @return A refund resource.
 */
- (nonnull CRRefund *)partiallyRefundChargeWithIdentifier:(nonnull NSString *)identifier
                                                  amount:(nonnull NSNumber *)amount;
/**
 * Returns information about an existing refund. Mostly used to get an update
 * on the status of the refund.
 *
 * @param identifier The ID of the refund.
 * @return A refund resource for the provided ID.
 */
- (nonnull NSMutableArray<CRRefund *> *)refundsForChargeWithIdentifier:(nonnull NSString *)identifier;

/**
 * Returns information about the refunds for a specific charge.
 *
 * @param identifier The ID of the charge.
 * @return A refund resource for the provided charge.
 */
- (nonnull CRRefund *)refundWithIdentifier:(nonnull NSString *)identifier;

/**
 * Creates a subscription plan which is required to use subscription based payments.
 * The result of this method can be used together with 'createSubscription' in
 * order to subscribe someone to your subscription plan.
 *
 * @param name The name for the subscription plan.
 * @param amount The amount that is charged on a regular basis. A positive integer
 *      in the smallest currency unit (e.g. cents).
 * @param currency A three-letter ISO code for currency.
 * @param description A description for this subscription plan.
 * @param interval Specifies the billing frequency together with interval_count.
 *      Allowed values are:day, week, month or year.
 * @param interval_count Specifies the billing frequency together with interval.
 *      For example:interval_count = 2 and interval = "week" -> Billed every
 *      two weeks.
 * @return Returns the newly created subscription plan resource.
 */
- (nonnull CRSubscriptionPlan *)createSubscriptionPlanWithName:(nonnull NSString *)name
                                                       amount:(nonnull NSNumber *)amount
                                                     currency:(nonnull NSString *)currency
                                                  description:(nonnull NSString *)description
                                                     interval:(nonnull NSString *)interval
                                                intervalCount:(nonnull NSNumber *)interval_count;


/**
 * Returns a list of all existing subscription plans.
 *
 * @return List of subscription plans.
 */
- (nonnull NSMutableArray<CRSubscriptionPlan *> *)listSubscriptionPlans;

/**
 * Subscribes a new customer to an existing subscription plan.
 *
 * @param planID The ID of the subscription plan.
 * @param name A name for the subscription.
 * @param description A description for the subscription.
 * @param source The customer that shall be subscribed.
 * @return The newly created subscription resource.
 */
- (nonnull CRSubscription *)createSubscriptionWithPlanID:(nonnull NSString *)planID
                                                   name:(nonnull NSString *)name
                                            description:(nonnull NSString *)description
                                                 source:(nonnull CRCreditCard *)source;

/**
 * Cancel an active subscription.
 *
 * @param identifier ID of the subscription that should be canceled.
 */
- (void)cancelSubscriptionWithIdentifier:(nonnull NSString *)identifier;


@end
