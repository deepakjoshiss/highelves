@set current_dir=%~dp0
@echo %current_dir%  
@robocopy %~dp0art\compiledtextures %~dp0art\textures /E /MOVE /NFL /NDL /NJH /NJS /nc /ns /np
@%~dp0assetcachebuilder.exe
@rename %~dp0art\textures compiledtextures
@pause