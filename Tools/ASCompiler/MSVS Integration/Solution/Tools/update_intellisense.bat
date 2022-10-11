@echo off
echo Processing dll files...
IntellisenseCreator.exe ../../../../../Server/scripts/intellisense.h ../../../as.dll ../../../fo.dll > update_intellisense.log
IntellisenseCreator.exe ../../../../../Server/scripts/intellisense_client.h ../../../as.dll ../../../fo_client.dll >> update_intellisense.log
IntellisenseCreator.exe ../../../../../Server/scripts/intellisense_mapper.h ../../../as.dll ../../../fo_mapper.dll >> update_intellisense.log
echo Finished.
pause