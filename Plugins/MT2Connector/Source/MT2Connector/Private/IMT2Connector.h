// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "MT2ConnectorPrivatePCH.h"
#include "ModuleManager.h"


/**
 * The public interface to this module
 */
class IMT2Connector : public IModuleInterface
{

public:

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static IMT2Connector& Get();
	void StartupModule();
	void ShutdownModule();
	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static bool IsAvailable();
};

