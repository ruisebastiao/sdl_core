#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/VehicleInfo/OnVehicleData.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::VehicleInfo
  version	1.2
  generated at	Fri Dec 14 06:14:25 2012
  source stamp	Fri Dec 14 06:14:23 2012
  author	robok0der
*/

using namespace NsRPC2Communication::VehicleInfo;


OnVehicleData& OnVehicleData::operator =(const OnVehicleData& c)
{
  if(gps)  delete gps;
  gps= c.gps ? new NsAppLinkRPCV2::GPSData(c.gps[0]) : 0;
  if(speed)  delete speed;
  speed= c.speed ? new float(c.speed[0]) : 0;
  if(rpm)  delete rpm;
  rpm= c.rpm ? new unsigned int(c.rpm[0]) : 0;
  if(fuelLevel)  delete fuelLevel;
  fuelLevel= c.fuelLevel ? new float(c.fuelLevel[0]) : 0;
  if(avgFuelEconomy)  delete avgFuelEconomy;
  avgFuelEconomy= c.avgFuelEconomy ? new float(c.avgFuelEconomy[0]) : 0;
  if(batteryVoltage)  delete batteryVoltage;
  batteryVoltage= c.batteryVoltage ? new float(c.batteryVoltage[0]) : 0;
  if(externalTemperature)  delete externalTemperature;
  externalTemperature= c.externalTemperature ? new float(c.externalTemperature[0]) : 0;
  if(vin)  delete vin;
  vin= c.vin ? new std::string(c.vin[0]) : 0;
  if(prndl)  delete prndl;
  prndl= c.prndl ? new NsAppLinkRPCV2::PRNDL(c.prndl[0]) : 0;
  if(tirePressure)  delete tirePressure;
  tirePressure= c.tirePressure ? new NsAppLinkRPCV2::TireStatus(c.tirePressure[0]) : 0;
  if(batteryPackVoltage)  delete batteryPackVoltage;
  batteryPackVoltage= c.batteryPackVoltage ? new float(c.batteryPackVoltage[0]) : 0;
  if(batteryPackCurrent)  delete batteryPackCurrent;
  batteryPackCurrent= c.batteryPackCurrent ? new float(c.batteryPackCurrent[0]) : 0;
  if(batteryPackTemperature)  delete batteryPackTemperature;
  batteryPackTemperature= c.batteryPackTemperature ? new int(c.batteryPackTemperature[0]) : 0;
  if(engineTorque)  delete engineTorque;
  engineTorque= c.engineTorque ? new int(c.engineTorque[0]) : 0;
  if(odometer)  delete odometer;
  odometer= c.odometer ? new unsigned int(c.odometer[0]) : 0;
  if(tripOdometer)  delete tripOdometer;
  tripOdometer= c.tripOdometer ? new unsigned int(c.tripOdometer[0]) : 0;
  if(genericbinary)  delete genericbinary;
  genericbinary= c.genericbinary ? new std::string(c.genericbinary[0]) : 0;
  return *this;
}


OnVehicleData::~OnVehicleData(void)
{
  if(gps)  delete gps;
  if(speed)  delete speed;
  if(rpm)  delete rpm;
  if(fuelLevel)  delete fuelLevel;
  if(avgFuelEconomy)  delete avgFuelEconomy;
  if(batteryVoltage)  delete batteryVoltage;
  if(externalTemperature)  delete externalTemperature;
  if(vin)  delete vin;
  if(prndl)  delete prndl;
  if(tirePressure)  delete tirePressure;
  if(batteryPackVoltage)  delete batteryPackVoltage;
  if(batteryPackCurrent)  delete batteryPackCurrent;
  if(batteryPackTemperature)  delete batteryPackTemperature;
  if(engineTorque)  delete engineTorque;
  if(odometer)  delete odometer;
  if(tripOdometer)  delete tripOdometer;
  if(genericbinary)  delete genericbinary;
}


OnVehicleData::OnVehicleData(void) : 
  RPC2Notification(Marshaller::METHOD_NSRPC2COMMUNICATION_VEHICLEINFO__ONVEHICLEDATA),
  gps(0),
  speed(0),
  rpm(0),
  fuelLevel(0),
  avgFuelEconomy(0),
  batteryVoltage(0),
  externalTemperature(0),
  vin(0),
  prndl(0),
  tirePressure(0),
  batteryPackVoltage(0),
  batteryPackCurrent(0),
  batteryPackTemperature(0),
  engineTorque(0),
  odometer(0),
  tripOdometer(0),
  genericbinary(0)
{
}


OnVehicleData::OnVehicleData(const OnVehicleData& c) : RPC2Notification(Marshaller::METHOD_NSRPC2COMMUNICATION_VEHICLEINFO__ONVEHICLEDATA)
{
  *this=c;
}


const NsAppLinkRPCV2::GPSData* OnVehicleData::get_gps(void)
{
  return gps;
}

bool OnVehicleData::set_gps(const NsAppLinkRPCV2::GPSData& gps_)
{
  if(gps)  delete gps;
  gps=new NsAppLinkRPCV2::GPSData(gps_);
  return true;
}

void OnVehicleData::reset_gps(void)
{
  if(gps)  delete gps;
  gps=0;
}

const float* OnVehicleData::get_speed(void)
{
  return speed;
}

bool OnVehicleData::set_speed(const float& speed_)
{
  if(speed)  delete speed;
  speed=new float(speed_);
  return true;
}

void OnVehicleData::reset_speed(void)
{
  if(speed)  delete speed;
  speed=0;
}

const unsigned int* OnVehicleData::get_rpm(void)
{
  return rpm;
}

bool OnVehicleData::set_rpm(const unsigned int& rpm_)
{
  if(rpm)  delete rpm;
  rpm=new unsigned int(rpm_);
  return true;
}

void OnVehicleData::reset_rpm(void)
{
  if(rpm)  delete rpm;
  rpm=0;
}

const float* OnVehicleData::get_fuelLevel(void)
{
  return fuelLevel;
}

bool OnVehicleData::set_fuelLevel(const float& fuelLevel_)
{
  if(fuelLevel)  delete fuelLevel;
  fuelLevel=new float(fuelLevel_);
  return true;
}

void OnVehicleData::reset_fuelLevel(void)
{
  if(fuelLevel)  delete fuelLevel;
  fuelLevel=0;
}

const float* OnVehicleData::get_avgFuelEconomy(void)
{
  return avgFuelEconomy;
}

bool OnVehicleData::set_avgFuelEconomy(const float& avgFuelEconomy_)
{
  if(avgFuelEconomy)  delete avgFuelEconomy;
  avgFuelEconomy=new float(avgFuelEconomy_);
  return true;
}

void OnVehicleData::reset_avgFuelEconomy(void)
{
  if(avgFuelEconomy)  delete avgFuelEconomy;
  avgFuelEconomy=0;
}

const float* OnVehicleData::get_batteryVoltage(void)
{
  return batteryVoltage;
}

bool OnVehicleData::set_batteryVoltage(const float& batteryVoltage_)
{
  if(batteryVoltage)  delete batteryVoltage;
  batteryVoltage=new float(batteryVoltage_);
  return true;
}

void OnVehicleData::reset_batteryVoltage(void)
{
  if(batteryVoltage)  delete batteryVoltage;
  batteryVoltage=0;
}

const float* OnVehicleData::get_externalTemperature(void)
{
  return externalTemperature;
}

bool OnVehicleData::set_externalTemperature(const float& externalTemperature_)
{
  if(externalTemperature)  delete externalTemperature;
  externalTemperature=new float(externalTemperature_);
  return true;
}

void OnVehicleData::reset_externalTemperature(void)
{
  if(externalTemperature)  delete externalTemperature;
  externalTemperature=0;
}

const std::string* OnVehicleData::get_vin(void)
{
  return vin;
}

bool OnVehicleData::set_vin(const std::string& vin_)
{
  if(vin)  delete vin;
  vin=new std::string(vin_);
  return true;
}

void OnVehicleData::reset_vin(void)
{
  if(vin)  delete vin;
  vin=0;
}

const NsAppLinkRPCV2::PRNDL* OnVehicleData::get_prndl(void)
{
  return prndl;
}

bool OnVehicleData::set_prndl(const NsAppLinkRPCV2::PRNDL& prndl_)
{
  if(prndl)  delete prndl;
  prndl=new NsAppLinkRPCV2::PRNDL(prndl_);
  return true;
}

void OnVehicleData::reset_prndl(void)
{
  if(prndl)  delete prndl;
  prndl=0;
}

const NsAppLinkRPCV2::TireStatus* OnVehicleData::get_tirePressure(void)
{
  return tirePressure;
}

bool OnVehicleData::set_tirePressure(const NsAppLinkRPCV2::TireStatus& tirePressure_)
{
  if(tirePressure)  delete tirePressure;
  tirePressure=new NsAppLinkRPCV2::TireStatus(tirePressure_);
  return true;
}

void OnVehicleData::reset_tirePressure(void)
{
  if(tirePressure)  delete tirePressure;
  tirePressure=0;
}

const float* OnVehicleData::get_batteryPackVoltage(void)
{
  return batteryPackVoltage;
}

bool OnVehicleData::set_batteryPackVoltage(const float& batteryPackVoltage_)
{
  if(batteryPackVoltage)  delete batteryPackVoltage;
  batteryPackVoltage=new float(batteryPackVoltage_);
  return true;
}

void OnVehicleData::reset_batteryPackVoltage(void)
{
  if(batteryPackVoltage)  delete batteryPackVoltage;
  batteryPackVoltage=0;
}

const float* OnVehicleData::get_batteryPackCurrent(void)
{
  return batteryPackCurrent;
}

bool OnVehicleData::set_batteryPackCurrent(const float& batteryPackCurrent_)
{
  if(batteryPackCurrent)  delete batteryPackCurrent;
  batteryPackCurrent=new float(batteryPackCurrent_);
  return true;
}

void OnVehicleData::reset_batteryPackCurrent(void)
{
  if(batteryPackCurrent)  delete batteryPackCurrent;
  batteryPackCurrent=0;
}

const int* OnVehicleData::get_batteryPackTemperature(void)
{
  return batteryPackTemperature;
}

bool OnVehicleData::set_batteryPackTemperature(const int& batteryPackTemperature_)
{
  if(batteryPackTemperature)  delete batteryPackTemperature;
  batteryPackTemperature=new int(batteryPackTemperature_);
  return true;
}

void OnVehicleData::reset_batteryPackTemperature(void)
{
  if(batteryPackTemperature)  delete batteryPackTemperature;
  batteryPackTemperature=0;
}

const int* OnVehicleData::get_engineTorque(void)
{
  return engineTorque;
}

bool OnVehicleData::set_engineTorque(const int& engineTorque_)
{
  if(engineTorque)  delete engineTorque;
  engineTorque=new int(engineTorque_);
  return true;
}

void OnVehicleData::reset_engineTorque(void)
{
  if(engineTorque)  delete engineTorque;
  engineTorque=0;
}

const unsigned int* OnVehicleData::get_odometer(void)
{
  return odometer;
}

bool OnVehicleData::set_odometer(const unsigned int& odometer_)
{
  if(odometer)  delete odometer;
  odometer=new unsigned int(odometer_);
  return true;
}

void OnVehicleData::reset_odometer(void)
{
  if(odometer)  delete odometer;
  odometer=0;
}

const unsigned int* OnVehicleData::get_tripOdometer(void)
{
  return tripOdometer;
}

bool OnVehicleData::set_tripOdometer(const unsigned int& tripOdometer_)
{
  if(tripOdometer)  delete tripOdometer;
  tripOdometer=new unsigned int(tripOdometer_);
  return true;
}

void OnVehicleData::reset_tripOdometer(void)
{
  if(tripOdometer)  delete tripOdometer;
  tripOdometer=0;
}

const std::string* OnVehicleData::get_genericbinary(void)
{
  return genericbinary;
}

bool OnVehicleData::set_genericbinary(const std::string& genericbinary_)
{
  if(genericbinary)  delete genericbinary;
  genericbinary=new std::string(genericbinary_);
  return true;
}

void OnVehicleData::reset_genericbinary(void)
{
  if(genericbinary)  delete genericbinary;
  genericbinary=0;
}

bool OnVehicleData::checkIntegrity(void)
{
  return OnVehicleDataMarshaller::checkIntegrity(*this);
}
