# KVPstorage
Simple key-value pair storage in C


Improvements:
- malloc failure during lst_new_setting will cause program to exit and that might not be desired
- cmd_get could return multipe entries (multiple entries are currently ignored)
- cmd_delete could delete multipe entries (multiple entries are currently ignored)