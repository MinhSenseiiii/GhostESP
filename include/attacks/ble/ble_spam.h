/**
 * @file ble_spam.h
 * @brief BLE spam attack header
 * 
 * This module handles BLE advertisement spam attacks including:
 * - Apple device spam (AirPods, Beats, AppleTV, etc.)
 * - Microsoft device spam
 * - Samsung device spam
 * - Google Fast Pair spam
 * - Flipper Zero spam
 * - Random spam (mix of all types)
 */

#ifndef BLE_SPAM_H
#define BLE_SPAM_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief BLE spam attack types
 */
typedef enum {
    BLE_SPAM_MICROSOFT,     ///< Microsoft device spam
    BLE_SPAM_APPLE,         ///< Apple device spam (AirPods, Beats, etc.)
    BLE_SPAM_SAMSUNG,       ///< Samsung watch spam
    BLE_SPAM_GOOGLE,        ///< Google Fast Pair spam
    BLE_SPAM_FLIPPERZERO,   ///< Flipper Zero spam
    BLE_SPAM_RANDOM         ///< Random mix of all spam types
} ble_spam_type_t;

/**
 * @brief Start BLE spam attack
 * 
 * @param type Type of BLE spam attack to start
 */
void ble_spam_start(ble_spam_type_t type);

/**
 * @brief Stop BLE spam attack
 */
void ble_spam_stop(void);

/**
 * @brief Check if BLE spam is currently running
 * 
 * @return true if spam is running, false otherwise
 */
bool ble_spam_is_running(void);

/**
 * @brief Set the HID keyboard payload script to execute on device connection
 * 
 * When a device connects to the BLE spam attack advertising as a keyboard,
 * this script will be executed automatically. Script follows BadBLE syntax
 * (e.g., "DELAY 100", "STRING Hello", "WINDOW R", "ENTER", etc.)
 * 
 * @param script Null-terminated script string. If NULL, disables payload execution.
 *               Memory is copied internally, caller retains ownership.
 * @return true if script was set successfully, false otherwise
 */
bool ble_spam_set_payload(const char *script);

/**
 * @brief Enable connection acceptance for the BLE spam attack
 * 
 * When enabled, BLE spam will accept incoming connections and act as a
 * HID keyboard device, executing the configured payload script on connection.
 * Requires a payload script to be set via ble_spam_set_payload().
 * 
 * @param enable true to accept connections, false to revert to advertisement-only
 */
void ble_spam_set_accept_connections(bool enable);

#endif // BLE_SPAM_H
