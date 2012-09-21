#!/bin/bash
# usage: $ ./generate-remote-confs.sh

smartmeter_conf_file="./SmartMeter.conf"
smartmeter_remote_conf_file="./SmartMeter-Remote.conf"
meterfilesystem_conf_file="./MeterFileSystem.conf"
meterfilesystem_remote_conf_file="./MeterFileSystem-Remote.conf"
home_data_path="\/devel\/verif\/data\/smartmeter-trunk\/data"
meter_address="tty2:\/\/\/dev\/ttyS0:0:5"

sed \
	-e 's/\/home\/data/'"$home_data_path"'/' \
	-e 's/SysLogAppender/ConsoleAppender/' \
	-e 's/environment-path = "\/dev";/environment-path = ".\/remote-setup";/' \
	-e 's/environment-default = "\/etc\/default-flash-env";/environment-default = ".\/remote-setup\/default-flash-env";/' \
	-e 's/boot-info-path = "\/proc\/gridnet\/boot";/boot-info-path = ".\/remote-setup";/' \
	-e 's/ssid-path = "\/etc\/gridnet-release";/ssid-path = ".\/remote-setup\/gridnet-release";/' \
	-e 's/partition-path = "\/dev";/partition-path = ".\/remote-setup";/' \
	-e 's/boot-files-path = "\/home\/conf\/boot";/boot-files-path = "'"$home_data_path"'";/' \
	-e 's/wan-provisioned-file = "\/home\/conf\/active\/wimax\/supplicant.conf";/wan-provisioned-file = ".\/filesystem\/SmartMeter\/active\/wimax\/supplicant.conf";/' \
	-e 's/security-provisioned-file = "\/home\/conf\/security-provisioned";/security-provisioned-file = "'"$home_data_path"'\/security-provisioned";/' \
	-e 's/wimax-message-server-ip-addr = "localhost";/wimax-message-server-ip-addr = "'"$meter_ip_address"'";/' \
	-e 's/wimax-folder = "\/home\/conf\/active\/wimax";/wimax-folder = ".\/filesystem\/common\/active\/wimax";/' \
	-e 's/tables-conf-file = "\/home\/conf\/active\/tables.conf";/tables-conf-file = ".\/filesystem\/SmartMeter\/active\/tables.conf";/' \
	-e 's/abort-udchpc-missing = "true";/abort-udchpc-missing = "false";/' \
	-e 's/slave-device = "device:\/\/\/dev\/amrSlave";/slave-device = "test:\/\/\/tmp\/amrSlave";/' \
	-e 's/path = "\/home\/conf\/active\/wimax\/radio.conf";/path = ".\/filesystem\/common\/active\/wimax\/radio.conf";/' \
	-e 's/path = "\/home\/app\/active\/default-tables.conf";/path = ".\/filesystem\/SmartMeter\/active\/default-tables.conf";/' \
	-e 's/tz-filename = "\/etc\/TZ";/tz-filename = "'"$home_data_path"'\/TZ";/' \
	-e 's/meter-password-filename = "\/home\/conf\/meter.password";/meter-password-filename = "'"$home_data_path"'\/meter.password";/' \
	-e 's/meter-password-dirname = "\/home\/conf";/meter-password-dirname = "'"$home_data_path"'";/' \
	-e 's/meter-prov-usage-marker-filename = "\/home\/conf\/meter-provision-usage-report-sent";/meter-prov-usage-marker-filename = "'"$home_data_path"'\/meter-provision-usage-report-sent";/' \
	-e 's/amr-trouble-device = "\/dev\/amrtbl";/amr-trouble-device = "'"$home_data_path"'\/amrtbl";/' \
	-e 's/bootcount-path = "\/proc\/driver\/bootcount";/bootcount-path = "'"$home_data_path"'\/bootcount";/' \
	-e 's/\/mnt\/alt//' \
	-e 's/meter-key-filename = "\/home\/conf\/meter.key";/meter-key-filename = "'"$home_data_path"'\/meter\.key";/' \
	-e 's/state-file =  "\/home\/conf\/clockstate";/state-file = "'"$home_data_path"'\/clockstate";/' \
	-e 's/is-meter-provisioned-filename = "\/home\/conf\/meter-provisioning-info";/is-meter-provisioned-filename = "'"$home_data_path"'\/meter-provisioning-info";/' \
	-e 's/simulator-only = "false";/simulator-only = "true";/' \
	-e 's/disable-meter-event-monitor = "false";/disable-meter-event-monitor = "true";/' \
	-e 's/net-dev = "eth1";/net-dev = "eth0";/' \
	$smartmeter_conf_file > $smartmeter_remote_conf_file

sed \
	-e 's/meter-address = "tty2:\/\/\/dev\/ttymxc0:0:5";/meter-address = "'"$meter_address"'";/' \
	-e 's/meter-password-file = "\/home\/conf\/meter.password";/meter-password-file = "'"$home_data_path"'\/meter.password";/' \
	-e 's/log-configuration = "\/home\/app\/logger.meterfs.properties";/log-configuration-file = "logger.meterfs.properties";/' \
	$meterfilesystem_conf_file > $meterfilesystem_remote_conf_file
