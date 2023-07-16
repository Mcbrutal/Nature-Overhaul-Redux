class USMC_Mission
{
	//	The name of the mission
	private	string					m_MissionName		=	"A supply vehicle has been attacked!";
	//	Mission starts in X seconds
	private	int						m_StartTime			=	1980;
	//	Classname zombie (model) = Number of zombies to spawn, classes can be repeated
	private	ref	TStringArray		m_ZombieClassname	=	{ "ZmbM_Convoy_Summer", "DZNC_GREEN_SoldierNormal", "DZNC_GREEN_usSoldier_normal_Desert","ZmbM_Convoy_Summer", "DZNC_GREEN_usSoldier_normal_Woodland", "DZNC_GREEN_PatrolNormal_Autumn","ZmbM_Convoy_Summer", "DZNC_GREEN_PatrolNormal_Flat", "DZNC_GREEN_PatrolNormal_PautRev", "DZNC_GREEN_PatrolNormal_Summer", "ZmbM_Convoy_Summer", "DZNC_GREEN_SoldierNormal", "DZNC_GREEN_usSoldier_normal_Desert","ZmbM_Convoy_Summer", "DZNC_GREEN_usSoldier_normal_Woodland", "DZNC_GREEN_PatrolNormal_Autumn","ZmbM_Convoy_Summer", "DZNC_GREEN_PatrolNormal_Flat", "DZNC_GREEN_PatrolNormal_PautRev", "DZNC_GREEN_PatrolNormal_Summer" };
	//	What the zombies are wearing( backpacks, etc. )
	private	ref	TStringArray		m_Inventorys		=	{ "MilitaryBeret_CDF", "PlateCarrierVest_Green", "SmershBag" };
	//	Coordinates of the mission( several comma-separated-random )
    private ref TVectorArray		m_Positions 		= 	{ "3633.92 196.351 12836", "4592.34 0 10202.81" };
    private ref TVectorArray 		m_CarPositions 		= 	{ "3623.92 196.351 12826", "4585.34 0 10215.81" };
	//	Names for coordinates( must be the same as in m_positions )
	private	ref	TStringArray		m_LocationsName		=	{ "Petrovka", "NWAF" };
	//	Classname of the Reward Chest
	private		string				m_ChestClassname	=	"OPG_AirDrop";
	//	Max loot spawn: 0 = all loot will spawn, X amount = random items from m_ChestLoot will spawn.
	private	int						m_AmountLoot		=	15;
	//	Loot in the chest
	private	ref	TStringArray		m_ChestLoot			=	{ "Winchester70", "CZ550", "TF_M1A_Black", "TF_M1A_OD", "Mp133Shotgun", "TF_AKS74U", "Colt1911", "Engraved1911", "Glock19", "FNX45", "Mosin9130_Black", "CC_Thompson", "CC_Mac10", "TF_AKMN", "TF_M4A1_CQBR", "TF_SCAR_L_Black", "TF_SCAR_L_CQC_Black", "TF_AK101", "TF_AK102", "TF_AK103", "TF_AK104", "TF_AK105", "TF_AK105_Bullpup", "TF_M4A1", "TF_M16A4", "Aug", "AugShort", "FAMAS", "M67Grenade", "M67Grenade", "FlashGrenade", "FlashGrenade", "AmmoBox_9x19_25rnd", "AmmoBox_9x19_25rnd", "AmmoBox_45ACP_25rnd", "AmmoBox_45ACP_25rnd", "AmmoBox_00buck_10rnd", "AmmoBox_00buck_10rnd", "AmmoBox_308Win_20Rnd", "AmmoBox_308Win_20Rnd", "AmmoBox_545x39_20Rnd", "AmmoBox_545x39_20Rnd", "AmmoBox_556x45_20Rnd", "AmmoBox_556x45_20Rnd", "AmmoBox_762x39_20Rnd", "AmmoBox_762x39_20Rnd", "AmmoBox_762x54_20Rnd", "AmmoBox_762x54_20Rnd", "Mag_Glock_15Rnd", "Mag_Glock_15Rnd", "Mag_1911_7Rnd", "Mag_1911_7Rnd", "Mag_FNX45_15Rnd", "Mag_FNX45_15Rnd", "Mag_CZ550_10rnd", "Mag_CZ550_10rnd", "Mag_AKM_Drum75Rnd", "Mag_AKM_Drum75Rnd", "TF_Mag_M14_20Rnd", "TF_Mag_M14_20Rnd", "TF_Mag_AK74_60Rnd", "TF_Mag_AK74_60Rnd", "Mag_STANAG_60Rnd", "Mag_STANAG_60Rnd", "TF_Mag_AK101_Plastic30Rnd", "TF_Mag_AK101_Plastic30Rnd",  "CC_Thompson_Mag", "CC_Thompson_Mag", "CC_Mac10_Mag", "CC_Mac10_Mag", "Mag_Aug_30Rnd", "Mag_Aug_30Rnd", "AK_PlasticHndgrd", "AK_WoodHndgrd", "AK_PlasticBttstck_Black", "AK_WoodBttstck", "TF_Atlas_Bipod", "TF_AK_Tactica_Tula10000Receiver", "TF_SCAR_StndBttstck_Black", "TF_M4CraneBttstck", "TF_M16_Bttstck", "TF_SCAR_MREXHndgrd_Black", "TF_AKS74U_ZenitB11PlasticHndgrd_RIS", "TF_M16_KACHndgrd_RIS", "TF_M4_DD12Hndgrd_RIS_FDE", "TF_ElcanSpecterDROptic_Black", "TF_ElcanSpecterDR_6xOptic_Black", "TF_EOTechXPSOpticDown_Black", "TF_HAMROptic_Black", "TF_OKP7Optic", "TF_M4_ColtA2Optic", "M4_CarryHandleOptic", "ACOGOptic", "ACOGOptic_6x", "PUScopeOptic", "KobraOptic", "HuntingOptic", "PSO1Optic", "Universallight", "Battery9V", "Battery9V", "Battery9V", "Battery9V" };
	//	Instead of smoke, you can also register a vehicle.
	private		string			m_SmokeReward			=	"SmokePTC";
	private		string			m_CarReward				=	"OffroadHatchback";
	private		int				m_Seconds				=	0;
	private		bool			m_Start					=	false;
	private		bool			m_End					=	false;
	private	ref	array<EntityAI>	m_Zombies				=	new array<EntityAI>;
	private		vector			m_Position				=	"0 0 0";
	private		vector			m_CarPosition			=	"0 0 0";
	private		string			m_LocationName			=	"";

	void MissionCreate()
	{
		int			v_R			=	0;
		EntityAI	v_EntityAI;
		int			v_C			=	0;
		int			v_Z;
		
		if ( m_Start )
		{
			return;
		}
		Print( "[USMC] Mission created" );
		m_Start			=	true;
		v_R				= 	Math.RandomInt( 0, m_Positions.Count() );
		m_Position		=	m_Positions[v_R];
		m_CarPosition	=	m_CarPositions[v_R];
		m_Position[1]	=	GetGame().SurfaceY( m_Position[0], m_Position[2] );
		m_CarPosition[1]=	GetGame().SurfaceY( m_CarPosition[0], m_CarPosition[2] );
		m_LocationName	=	m_LocationsName[v_R];
		for ( v_Z = 0; v_Z < m_ZombieClassname.Count(); v_Z++ )
		{
			v_EntityAI	=	EntityAI.Cast( GetGame().CreateObject( m_ZombieClassname[v_Z], m_Position, false, true, true ) );
			//Print in script file the zombies created
			Print( string.Format( "[USMC] Created zombie: %1", m_ZombieClassname[v_Z] ) );
			if ( !v_EntityAI )
			{
				//Print in script file if zombies are not created
				Print( string.Format( "[USMC] Failed to create zombies: %1", m_ZombieClassname[v_Z] ) );
				continue;
			}
			for ( v_C = 0; v_C < m_Inventorys.Count(); v_C++ )
			{
				v_EntityAI.GetInventory().CreateInInventory( m_Inventorys[v_C] );
			}
			m_Zombies.Insert( v_EntityAI );
		}
		//Print in script file location of the mission
		Print( string.Format( "[USMC] Location: %1, mission started: %2", m_LocationName, m_MissionName ) );
		USMC_StaticFunctions.SendPacket( NULL, USM_INT_MOD, USM_INT_MISSION_MESSAGE, string.Format( "At location: %1, mission started: %2", m_LocationName, m_MissionName ), NULL, true );
		USMC_StaticFunctions.SendMessage( NULL, string.Format( "At location: %1, mission started: %2", m_LocationName, m_MissionName ), true );
	}
	
	void CreateLootBox()
	{
		EntityAI	v_EntityAI;
		string 		item;
		
		Print( string.Format( "[USMC] Chest spawned at: %1", m_Position ) );
		v_EntityAI	=	EntityAI.Cast( GetGame().CreateObject( m_ChestClassname, m_Position ) );
		// If there is any loot to be spawned?
		if (m_ChestLoot.Count() > 0) {
			// If we are spawning ALL items 
			if (m_AmountLoot == 0) {
				// Log info 
				Print( string.Format( "[USMC] Config amount 0 spawning all loot" ) );
				for (int v_I = 0; v_I < m_ChestLoot.Count(); v_I++ )
				{
					item = m_ChestLoot[v_I];
					v_EntityAI.GetInventory().CreateInInventory( item );
					Print( string.Format( "[USMC] Loot in chest: %1", item ) );
				}
			}
			else
			{
				// Log info
				Print( string.Format( "[USMC] Config amount set, spawning loot amount: %1", m_AmountLoot ) );
				// For each item to be spawned 
				for (int i2 = 1; i2 <= m_AmountLoot; i2++)
				{
					// Spawn random item at point 
					item = m_ChestLoot.GetRandomElement();
					// Spawn Item 
					v_EntityAI.GetInventory().CreateInInventory( item );
					Print( string.Format( "[USMC] Loot in chest: %1", item ) );
				}
			}
		}
		else
		{
			Print( string.Format( "[USMC] Error, NO spawning of loot" ) );
		}
		if ( m_CarReward == "" )
		{
			return;
		}
		if ( m_SmokeReward == "")
		{
			return;
		}
		m_Position[0]	=	m_Position[0] + 0;
		m_Position[1]	=	GetGame().SurfaceY( m_Position[0], m_Position[2] );
		v_EntityAI		=	EntityAI.Cast( GetGame().CreateObject( m_SmokeReward, m_Position, false ) );
		v_EntityAI		=	EntityAI.Cast( GetGame().CreateObject( m_CarReward, m_CarPosition, false ) );
		v_EntityAI.OnDebugSpawn();
	}
	
	void CheckMission()
	{
		int	v_I;

		for ( v_I = 0; v_I < m_Zombies.Count(); v_I++ )
		{
			if ( !m_Zombies[v_I] )
			{
				//Print( "[USMC] The zombies are absent" );
				continue;
			}
			if ( m_Zombies[v_I].IsAlive() )
			{
				//Print( string.Format( "[USMC] The zombies are alive: %1", m_Zombies[v_I] ) ); 
				return;
			}
		}
		Print( "[USMC] Mission completed" );
		m_End	=	true;
		m_Start =	false;
		m_Seconds = 0;
		CreateLootBox();
	}
	void Update()
	{
		if ( m_End )
		{
			return;
		}
		if ( !m_Start )
		{
			m_Seconds++;
			if ( m_Seconds == m_StartTime )
			{
				MissionCreate();
				m_Start	=	true;
			}
			return;
		}
		CheckMission();
	}
}
