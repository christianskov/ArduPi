/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing WeatherStation
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "WeatherStation.h"

/*****************************************************************************
 * Implementation for type : WeatherStation
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void WeatherStation_SensorsDisplayImpl_OnExit(int state, struct WeatherStation_Instance *_instance);
void WeatherStation_send_RemoteControlOut_changeDisplay(struct WeatherStation_Instance *_instance);
void WeatherStation_send_timer_timer_start(struct WeatherStation_Instance *_instance, int delay);
void WeatherStation_send_timer_timer_cancel(struct WeatherStation_Instance *_instance);
void WeatherStation_send_db_db_init(struct WeatherStation_Instance *_instance);
void WeatherStation_send_db_push_int(struct WeatherStation_Instance *_instance, char * node, char * sensor, int value);
void WeatherStation_send_db_db_upload(struct WeatherStation_Instance *_instance, char * node, char * sensor);
void WeatherStation_send_sensapp_registerSensor(struct WeatherStation_Instance *_instance, char * node, char * sensor);
void WeatherStation_send_sensapp_pushData(struct WeatherStation_Instance *_instance, char * node, char * sensor, int value, char * unit);
void WeatherStation_send_sensapp_pushRawData(struct WeatherStation_Instance *_instance, char * data);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void WeatherStation_SensorsDisplayImpl_OnEntry(int state, struct WeatherStation_Instance *_instance) {
switch(state) {
case WEATHERSTATION_SENSORSDISPLAYIMPL_STATE:
_instance->WeatherStation_SensorsDisplayImpl_State = WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE;
WeatherStation_SensorsDisplayImpl_OnEntry(_instance->WeatherStation_SensorsDisplayImpl_State, _instance);
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE:
{
fprintf(stdout, ("Waiting...\n"));

}
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_INITDB_STATE:
{
fprintf(stdout, ("Starting DB...\n"));

WeatherStation_send_db_db_init(_instance);
WeatherStation_send_sensapp_registerSensor(_instance, "weather", "temp");
WeatherStation_send_sensapp_registerSensor(_instance, "weather", "light");
}
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE:
{
WeatherStation_send_timer_timer_start(_instance, _instance->WeatherStation_delay_var);
}
break;
default: break;
}
}

// On Exit Actions:
void WeatherStation_SensorsDisplayImpl_OnExit(int state, struct WeatherStation_Instance *_instance) {
switch(state) {
case WEATHERSTATION_SENSORSDISPLAYIMPL_STATE:
WeatherStation_SensorsDisplayImpl_OnExit(_instance->WeatherStation_SensorsDisplayImpl_State, _instance);
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE:
{
fprintf(stdout, ("Processing...\n"));

}
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_INITDB_STATE:
{
fprintf(stdout, ("done!\n"));

}
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void WeatherStation_handle_RemoteControlIn_temperature(struct WeatherStation_Instance *_instance, uint16_t temp) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE) {
if (1) {
{
fprintf(stdout, ("Temperature is: "));

printf("%u", temp);
fprintf(stdout, ("\n"));

WeatherStation_send_db_push_int(_instance, "weather", "temp", temp);
_instance->WeatherStation_i_var = _instance->WeatherStation_i_var + 1;
if(_instance->WeatherStation_i_var > _instance->WeatherStation_counter_var) {
WeatherStation_send_db_db_upload(_instance, "weather", "temp");
_instance->WeatherStation_i_var = 0;
}
}
}
}
}
void WeatherStation_handle_RemoteControlIn_light(struct WeatherStation_Instance *_instance, uint16_t light) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE) {
if (1) {
{
fprintf(stdout, ("Light is: "));

printf("%u", light);
fprintf(stdout, ("\n"));

WeatherStation_send_db_push_int(_instance, "weather", "light", light);
_instance->WeatherStation_j_var = _instance->WeatherStation_j_var + 1;
if(_instance->WeatherStation_j_var > _instance->WeatherStation_counter_var) {
WeatherStation_send_db_db_upload(_instance, "weather", "light");
_instance->WeatherStation_j_var = 0;
}
}
}
}
}
void WeatherStation_handle_timer_timer_timeout(struct WeatherStation_Instance *_instance) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE) {
if (1) {
WeatherStation_SensorsDisplayImpl_OnExit(WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE, _instance);
_instance->WeatherStation_SensorsDisplayImpl_State = WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE;
{
fprintf(stdout, ("Changing Display on Arduino\n"));

WeatherStation_send_RemoteControlOut_changeDisplay(_instance);
}
WeatherStation_SensorsDisplayImpl_OnEntry(WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE, _instance);
}
}
}
void WeatherStation_handle_Start_start(struct WeatherStation_Instance *_instance) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE) {
if (1) {
WeatherStation_SensorsDisplayImpl_OnExit(WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE, _instance);
_instance->WeatherStation_SensorsDisplayImpl_State = WEATHERSTATION_SENSORSDISPLAYIMPL_INITDB_STATE;
WeatherStation_SensorsDisplayImpl_OnEntry(WEATHERSTATION_SENSORSDISPLAYIMPL_INITDB_STATE, _instance);
}
}
}
void WeatherStation_handle_db_db_init_done(struct WeatherStation_Instance *_instance) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_INITDB_STATE) {
if (1) {
WeatherStation_SensorsDisplayImpl_OnExit(WEATHERSTATION_SENSORSDISPLAYIMPL_INITDB_STATE, _instance);
_instance->WeatherStation_SensorsDisplayImpl_State = WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE;
WeatherStation_SensorsDisplayImpl_OnEntry(WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE, _instance);
}
}
}

// Observers for outgoing messages:
void (*WeatherStation_send_RemoteControlOut_changeDisplay_listener)(struct WeatherStation_Instance*)= 0x0;
void register_WeatherStation_send_RemoteControlOut_changeDisplay_listener(void (*_listener)(struct WeatherStation_Instance*)){
WeatherStation_send_RemoteControlOut_changeDisplay_listener = _listener;
}
void WeatherStation_send_RemoteControlOut_changeDisplay(struct WeatherStation_Instance *_instance){
if (WeatherStation_send_RemoteControlOut_changeDisplay_listener != 0x0) WeatherStation_send_RemoteControlOut_changeDisplay_listener(_instance);
}
void (*WeatherStation_send_timer_timer_start_listener)(struct WeatherStation_Instance*, int)= 0x0;
void register_WeatherStation_send_timer_timer_start_listener(void (*_listener)(struct WeatherStation_Instance*, int)){
WeatherStation_send_timer_timer_start_listener = _listener;
}
void WeatherStation_send_timer_timer_start(struct WeatherStation_Instance *_instance, int delay){
if (WeatherStation_send_timer_timer_start_listener != 0x0) WeatherStation_send_timer_timer_start_listener(_instance, delay);
}
void (*WeatherStation_send_timer_timer_cancel_listener)(struct WeatherStation_Instance*)= 0x0;
void register_WeatherStation_send_timer_timer_cancel_listener(void (*_listener)(struct WeatherStation_Instance*)){
WeatherStation_send_timer_timer_cancel_listener = _listener;
}
void WeatherStation_send_timer_timer_cancel(struct WeatherStation_Instance *_instance){
if (WeatherStation_send_timer_timer_cancel_listener != 0x0) WeatherStation_send_timer_timer_cancel_listener(_instance);
}
void (*WeatherStation_send_db_db_init_listener)(struct WeatherStation_Instance*)= 0x0;
void register_WeatherStation_send_db_db_init_listener(void (*_listener)(struct WeatherStation_Instance*)){
WeatherStation_send_db_db_init_listener = _listener;
}
void WeatherStation_send_db_db_init(struct WeatherStation_Instance *_instance){
if (WeatherStation_send_db_db_init_listener != 0x0) WeatherStation_send_db_db_init_listener(_instance);
}
void (*WeatherStation_send_db_push_int_listener)(struct WeatherStation_Instance*, char *, char *, int)= 0x0;
void register_WeatherStation_send_db_push_int_listener(void (*_listener)(struct WeatherStation_Instance*, char *, char *, int)){
WeatherStation_send_db_push_int_listener = _listener;
}
void WeatherStation_send_db_push_int(struct WeatherStation_Instance *_instance, char * node, char * sensor, int value){
if (WeatherStation_send_db_push_int_listener != 0x0) WeatherStation_send_db_push_int_listener(_instance, node, sensor, value);
}
void (*WeatherStation_send_db_db_upload_listener)(struct WeatherStation_Instance*, char *, char *)= 0x0;
void register_WeatherStation_send_db_db_upload_listener(void (*_listener)(struct WeatherStation_Instance*, char *, char *)){
WeatherStation_send_db_db_upload_listener = _listener;
}
void WeatherStation_send_db_db_upload(struct WeatherStation_Instance *_instance, char * node, char * sensor){
if (WeatherStation_send_db_db_upload_listener != 0x0) WeatherStation_send_db_db_upload_listener(_instance, node, sensor);
}
void (*WeatherStation_send_sensapp_registerSensor_listener)(struct WeatherStation_Instance*, char *, char *)= 0x0;
void register_WeatherStation_send_sensapp_registerSensor_listener(void (*_listener)(struct WeatherStation_Instance*, char *, char *)){
WeatherStation_send_sensapp_registerSensor_listener = _listener;
}
void WeatherStation_send_sensapp_registerSensor(struct WeatherStation_Instance *_instance, char * node, char * sensor){
if (WeatherStation_send_sensapp_registerSensor_listener != 0x0) WeatherStation_send_sensapp_registerSensor_listener(_instance, node, sensor);
}
void (*WeatherStation_send_sensapp_pushData_listener)(struct WeatherStation_Instance*, char *, char *, int, char *)= 0x0;
void register_WeatherStation_send_sensapp_pushData_listener(void (*_listener)(struct WeatherStation_Instance*, char *, char *, int, char *)){
WeatherStation_send_sensapp_pushData_listener = _listener;
}
void WeatherStation_send_sensapp_pushData(struct WeatherStation_Instance *_instance, char * node, char * sensor, int value, char * unit){
if (WeatherStation_send_sensapp_pushData_listener != 0x0) WeatherStation_send_sensapp_pushData_listener(_instance, node, sensor, value, unit);
}
void (*WeatherStation_send_sensapp_pushRawData_listener)(struct WeatherStation_Instance*, char *)= 0x0;
void register_WeatherStation_send_sensapp_pushRawData_listener(void (*_listener)(struct WeatherStation_Instance*, char *)){
WeatherStation_send_sensapp_pushRawData_listener = _listener;
}
void WeatherStation_send_sensapp_pushRawData(struct WeatherStation_Instance *_instance, char * data){
if (WeatherStation_send_sensapp_pushRawData_listener != 0x0) WeatherStation_send_sensapp_pushRawData_listener(_instance, data);
}

