	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		//////////////////////////////////////////////////////////////////
		// 		The B&T (Bob&T1gr3x) Loadout and Spawner System			//
		//															 	//
		//			Inspired by Rexxenexx (OpenDayz Forum)			 	//
		//					30 Plus Loadouts 						 	//
		//																//
		//  At first i need to say it is probably not the best way to  	//
		//do it but it works , i think someone else could do it better.	//
		//////////////////////////////////////////////////////////////////
		
		/** Settings **/
		
		bool CustomLoadout 			= true;						// If you change this to false you are very stupid or you are an Admin :D / it is for Custom Loadouts & the Admin Loadouts
		
		bool CustomClothes			= true;						// Really ? //These are the Presets From Rexxenexx so Huge Shout Outs to Him but i dont included all of these Presets
		
		bool SpawnWithWeapon 		= true;						// If you want to spawn with a Weapon
		bool WeaponsPP 				= true;						// Main switch for the Pistols and Primary / if it is false you cant get Pistols or Primary Weapons execpt WeaponsAndMeele is on
		
		bool OnlyPistol 			= true;						// Use it if you want to spawn with only Pistol DISABLE Everything else For Weapons except SpawnWithWeapon;WeaponPP you can enable the Chance
		bool OnlyPrimary 			= false;					// Use it if you want to spawn with only Primary DISABLE Everything else For Weapons except SpawnWithWeapon and WeaponPP
		bool OnlyMeele 				= false;					// Use it if you want to spawn with only Meele DISABLE Everything else For Weapons except SpawnWithWeapon
		bool PistolAndPrimary		= false;					// If you want to spawn with Pistol and a Primary
		bool WeaponAndMeele 		= false;					// Only if OnlyWeapon and OnlyMeele =false / it could bug around
		bool WeapPAttachments		= false;					// Attachments For the Weapons, Suppressor and a Sight
		bool ChanceForPistol 		= true;						// For a Chance to spawn with Pistol so it is not sure if you spawn wit a Pistol
		bool ChanceForPrimary 		= false;					// For a Chance to spawn with Primary so it is not sure if you spawn wit a Primary

		int  maxPistol				= 9;						// Chance for Pistol / 9 = 10% 	[higher numbers = lower chance / lower numbers = higher chance]
		int  maxPrimary				= 9;						// Chance for Pistol / 9 = 10% 	[higher numbers = lower chance / lower numbers = higher chance]
		
		bool SpawnWithLights		= false;						// Spawn with something to light up the night
		
		bool spawnwithfood 			= true;						// Do you really need an explanation
		
		bool SpawnWithMeds 			= false; 					// is an Explanation needed ?
		
		bool SpawnBackPack			= true;						// Spawn with Backpack
		bool RndBackpack 			= true;						// Spawn with Backpack by a certain Chance /Only With SpawnBackPack=true
		int  maxBackpack			= 9;						// Chance for Backpack / 9 = 10% [higher numbers = lower chance / lower numbers = higher chance]	
		
		//Admin Settings
		bool AdminSettings			= false;					// Main Switch for Admin Settings
		
		bool AdminSpawnLoadout		= false;					// Admin Spawn with Fixed Loadouts / Weapons will be on Hotkey 1 but it will spawn at you bag 
																// i tried it the same way as the Primary Weapons but they got lost 
		string Admin1 = "76561198039799329";					//Steam ID 64 Tigr3x
		string Admin2 = "";										//Steam ID 64
		string Admin3 = "";										//Steam Id 64
		// Add Admins for exp.:    								78787878787878
																/** Steam ID 64 **/
		
		//Spawns	probably not the best way to do it but it kinda works
		
		bool Spawner				= false;					// Main Switch For Spawns		
		
		//Admin
		bool AdminSpawnLocation 	= false;					// Admin Spwan Location
		vector AdminLocation = "2328 133 3708";					// Write in the Coordinates for a Fixed Spawn Point exp. "7240 0 3030" ( https://dayz.ginfo.gg/ )
		//vector AdminLocation2 = "7240 30 3030";				// For Different Spwan Locations Check the Admin Spawn Section
		//vector AdminLocation3 = "7240 30 3030";				// For Different Spwan Locations
		
		//Player
		bool PlayerCustomSpawn		= false;					// If you want Coustom Spawns for Players
		bool PlayerFixedSpawn		= false;					// Set true for a Fixed Spawn Point / Only With Player Custom Spawn
		bool PlayerRandomSpawns		= false;					// If you wabt to create own Spawnpoints / insert Coordinates in Locations
		int  maxSpawnPoints			= 2 ;						// If you want more Spawn Points set this to your Desired amount ( 1 = 2 Spawn Points / 19 = 20 Spawnpoints
		vector PlayerLocation 		= "7240 30 3030";			// Write in the Coordinates for a Fixed Spawn Point exp. "7240 0 3030" ( https://dayz.ginfo.gg/ ) 
																// Height MUST also wrote in Activate Debug if you can and spawn there then relog and you can see the Height Coords

												
		//Spawn Locations
		vector Location1 	= "7240 28 3030";						// Write in Coordinates for Custom Spawn Locations
		vector Location2 	= "5371 333 9881";
		vector Location3 	= "2328 133 3708";						// you will Spawn normally and the get teleported to one of these Locations
		vector Location4 	= "5371 333 9881";
		vector Location5 	= "5371 333 9881";
		vector Location6 	= "5371 333 9881";
		vector Location7 	= "5371 333 9881";
		vector Location8 	= "5371 333 9881";
		vector Location9 	= "5371 333 9881";
		vector Location10 	= "5371 333 9881";
		vector Location11 	= "5371 333 9881";
		vector Location12 	= "5371 333 9881";
		vector Location13 	= "5371 333 9881";
		vector Location14 	= "5371 333 9881";
		vector Location15 	= "5371 333 9881";
		vector Location16 	= "5371 333 9881";
		vector Location17 	= "5371 333 9881";
		vector Location18 	= "5371 333 9881";
		vector Location19 	= "5371 333 9881";
		vector Location20 	= "5371 333 9881";
	/**	vector Location21 	= "5371 333 9881";  **/				// look at Spawn section if you want to add more Spawns
		
		ItemBase itemBs;
		ItemBase itemCount;
		ItemBase itemAtt;
		EntityAI itemEnt;
		EntityAI itemEntAmmo;
		EntityAI itemEntFood;
		EntityAI itemEntWeapon;
		EntityAI itemEntBackpack;
		EntityAI suppressor;
		EntityAI Buttstock;
		EntityAI Handguard;
		EntityAI Sight;
		EntityAI SightBatt;
		EntityAI magazin;
		EntityAI itemEntFlash;
		EntityAI itemEntMeeleWeapon;
		
			//Loadouts
		if(CustomLoadout == true )
		{	
			if (CustomClothes == true) 
			{
				player.RemoveAllItems();
				int clothes = Math.RandomIntInclusive(0,28);
				switch (clothes.ToString()) 
				{
					case "0": 
					itemEnt = player.GetInventory().CreateInInventory("TTSKOPants");
					itemEnt = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
					itemEnt = player.GetInventory().CreateInInventory("MilitaryBeret_CDF");
					itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
					break;
					
					case "1": 
					itemEnt = player.GetInventory().CreateInInventory("FirefightersPants_Beige");
					itemEnt = player.GetInventory().CreateInInventory("FirefighterJacket_Beige");
					itemEnt = player.GetInventory().CreateInInventory("FirefightersHelmet_Yellow");
					itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
					break;

					case "2": 
					itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Autumn");
					itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Autumn");
					itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
					break;

					case "3": 
					itemEnt = player.GetInventory().CreateInInventory("HunterPants_Spring");
					itemEnt = player.GetInventory().CreateInInventory("HuntingJacket_Spring");
					itemEnt = player.GetInventory().CreateInInventory("HikingBoots_Brown");
					break;

					case "4": 
					itemEnt = player.GetInventory().CreateInInventory("HunterPants_Summer");
					itemEnt = player.GetInventory().CreateInInventory("HuntingJacket_Summer");
					itemEnt = player.GetInventory().CreateInInventory("HikingBoots_Brown");
					break;

					case "5": 
					itemEnt = player.GetInventory().CreateInInventory("USMCPants_Woodland");
					itemEnt = player.GetInventory().CreateInInventory("USMCJacket_Woodland");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige")
					break;

					case "6": 
					itemEnt = player.GetInventory().CreateInInventory("USMCPants_Desert");
					itemEnt = player.GetInventory().CreateInInventory("USMCJacket_Desert");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
					break;
					
					case "7": 
					itemEnt = player.GetInventory().CreateInInventory("NBCPantsGray");
					itemEnt = player.GetInventory().CreateInInventory("NBCJacketGray");
					itemEnt = player.GetInventory().CreateInInventory("NBCBootsGray");
					itemEnt = player.GetInventory().CreateInInventory("NBCGlovesGray");
					itemEnt = player.GetInventory().CreateInInventory("GasMask");
					break;

					case "8": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
					itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Black");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					break;

					case "9": 
					itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Flat");
					itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Flat");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("MilitaryBeret_Red");
					break;

					case "10": 
					itemEnt = player.GetInventory().CreateInInventory("PolicePants");
					itemEnt = player.GetInventory().CreateInInventory("PoliceJacket");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("OfficerHat");
					break;

					case "11": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
					itemEnt = player.GetInventory().CreateInInventory("RidersJacket_Black");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Black");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Black");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Black");
					itemEnt = player.GetInventory().CreateInInventory("TankerHelmet");
					break;

					case "12": 
					itemEnt = player.GetInventory().CreateInInventory("TTSKOPants");
					itemEnt = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
					itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Beige");
					itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
					itemEnt = player.GetInventory().CreateInInventory("BoonieHat_Tan");
					break;

					case "13": 
					itemEnt = player.GetInventory().CreateInInventory("TTSKOPants");
					itemEnt = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
					itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
					break;

					case "14": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Beige");
					itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Tan");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
					itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Beige");
					itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
					itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGoggles");	
					break;

					case "15": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Olive");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
					itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
					break;

					case "16": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
					itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Black");
					itemEnt = player.GetInventory().CreateInInventory("UKAssVest_Black");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Black");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Blackskull");
					itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Black");
					break;

					case "17": 
					itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Summer");
					itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Summer");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
					itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
					itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
					break;

					case "18": 
					itemEnt = player.GetInventory().CreateInInventory("USMCPants_Woodland");
					itemEnt = player.GetInventory().CreateInInventory("USMCJacket_Woodland");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
					itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
					itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGoggles");	
					break;

					case "19": 
					itemEnt = player.GetInventory().CreateInInventory("GhillieSuit_Woodland");
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
					itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Green");
					itemEnt = player.GetInventory().CreateInInventory("GhillieHood_Woodland");
					break;

					case "20": 
					itemEnt = player.GetInventory().CreateInInventory("GhillieSuit_Mossy");
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
					itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Green");
					itemEnt = player.GetInventory().CreateInInventory("GhillieHood_Mossy");
					break;

					case "21": 
					itemEnt = player.GetInventory().CreateInInventory("GhillieSuit_Tan");
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Beige");
					itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Tan");
					itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Beige");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Beige");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Beige");
					itemEnt = player.GetInventory().CreateInInventory("GhillieHood_Tan");
					break;

					case "22": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
					itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Black");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Black");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Black");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Black");
					itemEnt = player.GetInventory().CreateInInventory("GorkaHelmetComplete_Black");
					break;

					case "23": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
					itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Olive");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Green");
					itemEnt = player.GetInventory().CreateInInventory("GorkaHelmetComplete_Green");
					break;

					case "24": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
					itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Black");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Black");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Black");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Black");
					itemEnt = player.GetInventory().CreateInInventory("DarkMotoHelmet_Black");
					break;

					case "25": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Olive");
					itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
					itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Green");
					itemEnt = player.GetInventory().CreateInInventory("DarkMotoHelmet_Green");
					break;

					case "26": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
					itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Tan");
					itemEnt = player.GetInventory().CreateInInventory("UKAssVest_Olive");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Black");
					itemEnt = player.GetInventory().CreateInInventory("BaseballCap_Black");
					break;

					case "27": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Beige");
					itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Tan");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
					itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
					itemEnt = player.GetInventory().CreateInInventory("BoonieHat_Tan");
					break;

					case "28": 
					itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
					itemEnt = player.GetInventory().CreateInInventory("ManSuit_Black");
					itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
					itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Black");
					itemEnt = player.GetInventory().CreateInInventory("BoonieHat_Black");
					break;
				};
			}else if(CustomClothes == false){
				//Vanilla
					itemEnt = player.GetInventory().CreateInInventory( "bandagedressing" );
					itemBs = ItemBase.Cast(itemEnt);							
					itemBs.SetQuantity(3);
			};
			//Weapons
			if (SpawnWithWeapon == true)
			{
				if (WeaponsPP == true || WeaponAndMeele == true )
				{
					if (OnlyPistol == true || PistolAndPrimary == true )
					{
						bool PistolChance = false;
						int chancePistol = Math.RandomIntInclusive(0,maxPistol);
						if(chancePistol == 0 && ChanceForPistol == true )
						{
								PistolChance = true;
								int weapons = Math.RandomIntInclusive(0,3);
									
								switch(weapons.ToString())
								{
									case "0":
									itemEntWeapon = player.GetInventory().CreateInInventory("FNX45");
									itemEnt = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
									itemEnt = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
									magazin = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
									
									player.SetQuickBarEntityShortcut(itemEntWeapon,2 ,true);
									player.SetQuickBarEntityShortcut(magazin,3 ,true);
									if ( WeapPAttachments ==true )
									{
										suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
										suppressor = ItemBase.Cast(itemEntWeapon);
									};
									break;

									case "1":
									itemEntWeapon = player.GetInventory().CreateInInventory("CZ75");
									itemEnt = player.GetInventory().CreateInInventory("Mag_CZ75_15Rnd");
									itemEnt = player.GetInventory().CreateInInventory("Mag_CZ75_15Rnd");
									magazin = player.GetInventory().CreateInInventory("Mag_CZ75_15Rnd");
									
									player.SetQuickBarEntityShortcut(itemEntWeapon,2 ,true);
									player.SetQuickBarEntityShortcut(magazin,3 ,true);
									if ( WeapPAttachments ==true )
									{
										suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
										suppressor = ItemBase.Cast(itemEntWeapon);
									};
									break;

									case "2":					
									itemEntWeapon = player.GetInventory().CreateInInventory("makarovij70");
									itemEnt = player.GetInventory().CreateInInventory("mag_ij70_8rnd");
									itemEnt = player.GetInventory().CreateInInventory("mag_ij70_8rnd");
									magazin = player.GetInventory().CreateInInventory("mag_ij70_8rnd");
									
									player.SetQuickBarEntityShortcut(itemEntWeapon,2 ,true);
									player.SetQuickBarEntityShortcut(magazin,3 ,true);
									if ( WeapPAttachments ==true )
									{
										suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
										suppressor = ItemBase.Cast(itemEntWeapon);
									};
									break;
									
									case "3":
									itemEntWeapon = player.GetInventory().CreateInInventory("CZ61");
									itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
									itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
									magazin = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
									
									player.SetQuickBarEntityShortcut(itemEntWeapon,2 ,true);
									player.SetQuickBarEntityShortcut(magazin,3 ,true);
									if ( WeapPAttachments ==true )
									{
										suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
										suppressor = ItemBase.Cast(itemEntWeapon);
									};
									break;
								};
						}else if(ChanceForPistol == false){
						
							int weapons2 = Math.RandomIntInclusive(0,3);
								
							switch(weapons2.ToString())
							{
								
								case "0":
								itemEntWeapon = player.GetInventory().CreateInInventory("FNX45");
								itemEnt = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,2 ,true);
								player.SetQuickBarEntityShortcut(magazin,3 ,true);
								if ( WeapPAttachments ==true )
									{
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									};
								break;

								case "1":
								itemEntWeapon = player.GetInventory().CreateInInventory("CZ75");
								itemEnt = player.GetInventory().CreateInInventory("Mag_CZ75_15Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_CZ75_15Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_CZ75_15Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,2 ,true);
								player.SetQuickBarEntityShortcut(magazin,3 ,true);
								if ( WeapPAttachments ==true )
									{
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									};
								break;

								case "2":					
								itemEntWeapon = player.GetInventory().CreateInInventory("makarovij70");
								itemEnt = player.GetInventory().CreateInInventory("mag_ij70_8rnd");
								itemEnt = player.GetInventory().CreateInInventory("mag_ij70_8rnd");
								magazin = player.GetInventory().CreateInInventory("mag_ij70_8rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,2 ,true);
								player.SetQuickBarEntityShortcut(magazin,3 ,true);
								if ( WeapPAttachments ==true )
									{
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									};
								break;
								
								case "3":
								itemEntWeapon = player.GetInventory().CreateInInventory("CZ61");
								itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,2 ,true);
								player.SetQuickBarEntityShortcut(magazin,3 ,true);
								if ( WeapPAttachments ==true )
									{
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("AK_Suppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									};
								break;
							};
						}
					};
					if (OnlyPrimary == true || PistolAndPrimary == true )
					{
						bool PrimaryChance = false;
						int chancePrimary = Math.RandomIntInclusive(0,maxPrimary);
						if(chancePrimary == 0 && ChanceForPrimary == true )
						{
							PrimaryChance = true;
							int weapons3 = Math.RandomIntInclusive(0,7);
									
							switch(weapons3.ToString())
							{
								case "0":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("AKM");
								itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								Buttstock = itemEntWeapon.GetInventory().CreateAttachment("AK_Woodbttstck");
								Buttstock = ItemBase.Cast(itemEntWeapon);
								Handguard = itemEntWeapon.GetInventory().CreateAttachment("AK_WoodHndgrd");
								Handguard = ItemBase.Cast(itemEntWeapon);
								if (WeapPAttachments == true ){
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("AK_Suppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									Sight = itemEntWeapon.GetInventory().CreateAttachment("KobraOptic");
									Sight = ItemBase.Cast(itemEntWeapon);
									SightBatt = Sight.GetInventory().CreateAttachment("Battery9V");
									SightBatt = ItemBase.Cast(Sight);
								};
								break;

								case "1":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("M4A1");
								itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								Buttstock = itemEntWeapon.GetInventory().CreateAttachment("M4_MPBttstck");
								Buttstock = ItemBase.Cast(itemEntWeapon);
								Handguard = itemEntWeapon.GetInventory().CreateAttachment("M4_RISHndgrd");
								Handguard = ItemBase.Cast(itemEntWeapon);
								if (WeapPAttachments == true ){
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("M4_Suppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									Sight = itemEntWeapon.GetInventory().CreateAttachment("M68Optic");
									Sight = ItemBase.Cast(itemEntWeapon);
									SightBatt = Sight.GetInventory().CreateAttachment("Battery9V");
									SightBatt = ItemBase.Cast(Sight);
								};
								break;

								case "2":					
								itemEntWeapon = player.GetHumanInventory().CreateInHands("MP5K");
								itemEnt = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								Buttstock = itemEntWeapon.GetInventory().CreateAttachment("MP5k_StockBttstck");
								Buttstock = ItemBase.Cast(itemEntWeapon);
								Handguard = itemEntWeapon.GetInventory().CreateAttachment("MP5_PlasticHndgrd");
								Handguard = ItemBase.Cast(itemEntWeapon);
								if (WeapPAttachments == true ){
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									Sight = itemEntWeapon.GetInventory().CreateAttachment("M68Optic");
									Sight = ItemBase.Cast(itemEntWeapon);
									SightBatt = Sight.GetInventory().CreateAttachment("Battery9V");
									SightBatt = ItemBase.Cast(Sight);
								};
								break;
								
								case "3":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("Mosin9130");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
								magazin = player.GetInventory().CreateInInventory("Ammo_762x54");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								if (WeapPAttachments == true ){
									Sight = itemEntWeapon.GetInventory().CreateAttachment("PUScopeOptic");
									Sight = ItemBase.Cast(itemEntWeapon);
								};
								break;
								
								case "4":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("SVD");
								itemEnt = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								if (WeapPAttachments == true ){
									Sight = itemEntWeapon.GetInventory().CreateAttachment("PSO11Optic");
									Sight = ItemBase.Cast(itemEntWeapon);
								};
								break;
								
								case "5":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("UMP45");
								itemEnt = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								if (WeapPAttachments == true ){
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									Sight = itemEntWeapon.GetInventory().CreateAttachment("M68Optic");
									Sight = ItemBase.Cast(itemEntWeapon);
									SightBatt = Sight.GetInventory().CreateAttachment("Battery9V");
									SightBatt = ItemBase.Cast(Sight);
								};
								break;
								
								case "6":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("SawedoffMosin9130");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
								magazin = player.GetInventory().CreateInInventory("Ammo_762x54");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								break;
								
								case "7":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("Mp133Shotgun");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_12gaSlug_10Rnd");
								
								magazin = player.GetInventory().CreateInInventory("Ammo_12gaSlug");
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								break;
							};
						}else if(ChanceForPrimary == false){
							int weapons4 = Math.RandomIntInclusive(0,7);
								
							switch(weapons4.ToString())
							{
								case "0":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("AKM");
								itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								Buttstock = itemEntWeapon.GetInventory().CreateAttachment("AK_Woodbttstck");
								Buttstock = ItemBase.Cast(itemEntWeapon);
								Handguard = itemEntWeapon.GetInventory().CreateAttachment("AK_WoodHndgrd");
								Handguard = ItemBase.Cast(itemEntWeapon);
								if (WeapPAttachments == true ){
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("AK_Suppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									Sight = itemEntWeapon.GetInventory().CreateAttachment("KobraOptic");
									Sight = ItemBase.Cast(itemEntWeapon);
									SightBatt = Sight.GetInventory().CreateAttachment("Battery9V");
									SightBatt = ItemBase.Cast(Sight);
								};
								break;

								case "1":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("M4A1");
								itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								Buttstock = itemEntWeapon.GetInventory().CreateAttachment("M4_MPBttstck");
								Buttstock = ItemBase.Cast(itemEntWeapon);
								Handguard = itemEntWeapon.GetInventory().CreateAttachment("M4_RISHndgrd");
								Handguard = ItemBase.Cast(itemEntWeapon);
								if (WeapPAttachments == true ){
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("M4_Suppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									Sight = itemEntWeapon.GetInventory().CreateAttachment("M68Optic");
									Sight = ItemBase.Cast(itemEntWeapon);
									SightBatt = Sight.GetInventory().CreateAttachment("Battery9V");
									SightBatt = ItemBase.Cast(Sight);
								};
								break;

								case "2":					
								itemEntWeapon = player.GetHumanInventory().CreateInHands("MP5K");
								itemEnt = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								Buttstock = itemEntWeapon.GetInventory().CreateAttachment("MP5k_StockBttstck");
								Buttstock = ItemBase.Cast(itemEntWeapon);
								Handguard = itemEntWeapon.GetInventory().CreateAttachment("MP5_PlasticHndgrd");
								Handguard = ItemBase.Cast(itemEntWeapon);
								if (WeapPAttachments == true ){
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									Sight = itemEntWeapon.GetInventory().CreateAttachment("M68Optic");
									Sight = ItemBase.Cast(itemEntWeapon);
									SightBatt = Sight.GetInventory().CreateAttachment("Battery9V");
									SightBatt = ItemBase.Cast(Sight);
								};
								break;
								
								case "3":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("Mosin9130");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
								magazin = player.GetInventory().CreateInInventory("Ammo_762x54");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								if (WeapPAttachments == true ){
									Sight = itemEntWeapon.GetInventory().CreateAttachment("PUScopeOptic");
									Sight = ItemBase.Cast(itemEntWeapon);
								};
								break;
								
								case "4":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("SVD");
								itemEnt = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								if (WeapPAttachments == true ){
									Sight = itemEntWeapon.GetInventory().CreateAttachment("PSO11Optic");
									Sight = ItemBase.Cast(itemEntWeapon);
								};
								break;
								
								case "5":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("UMP45");
								itemEnt = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
								itemEnt = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
								magazin = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								
								if (WeapPAttachments == true ){
									suppressor = itemEntWeapon.GetInventory().CreateAttachment("PistolSuppressor");
									suppressor = ItemBase.Cast(itemEntWeapon);
									Sight = itemEntWeapon.GetInventory().CreateAttachment("M68Optic");
									Sight = ItemBase.Cast(itemEntWeapon);
									SightBatt = Sight.GetInventory().CreateAttachment("Battery9V");
									SightBatt = ItemBase.Cast(Sight);
								};
								break;
								
								case "6":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("SawedoffMosin9130");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
								magazin = player.GetInventory().CreateInInventory("Ammo_762x54");
								
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								break;
								
								case "7":
								itemEntWeapon = player.GetHumanInventory().CreateInHands("Mp133Shotgun");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");
								itemEnt = player.GetInventory().CreateInInventory("AmmoBox_12gaSlug_10Rnd");
								
								magazin = player.GetInventory().CreateInInventory("Ammo_12gaSlug");
								player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
								player.SetQuickBarEntityShortcut(magazin,1 ,true);
								break;
							};
						}
					};
				};
				//Meele
				if(OnlyMeele == true || WeaponAndMeele == true )
				{
					int MeeleWeapon = Math.RandomIntInclusive(0,20);
					switch(MeeleWeapon.ToString())
						{
							case "0":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("WoodAxe");
							break;
							
							case "1":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("CombatKnife");
							break;
							
							case "2":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("BaseballBat");
							break;
							
							case "3":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("Crowbar");
							break;
							
							case "4":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("FieldShovel");
							break;
							
							case "5":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("FirefighterAxe");
							break;
							
							case "6":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("Hatchet");
							break;
							
							case "7":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("HuntingKnife");
							break;
							
							case "8":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("KitchenKnife");
							break;
							
							case "9":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("LugWrench");
							break;
							
							case "10":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("Machete");
							break;
							
							case "11":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("NailedBaseballBat");
							break;
							
							case "12":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("Pickaxe");
							break;
							
							case "13":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("Pipe");
							break;
							
							case "14":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("Pitchfork");
							break;
							
							case "15":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("PoliceBaton");
							break;
							
							case "16":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("Shovel");
							break;
							
							case "17":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("Wrench");
							break;
							
							case "18":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("SledgeHammer");
							break;
							
							case "19":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("SteakKnife");
							break;
							
							case "20":
							itemEntMeeleWeapon = player.GetInventory().CreateInInventory("FarmingHoe");
							break;
						};
				}
			};
			//Light
			if(SpawnWithLights == true)
			{
				//light
				int light = Math.RandomIntInclusive(0,8);
				switch(light.ToString())
				{
					case "0":
					itemEnt = player.GetInventory().CreateInInventory( "Flashlight" );
					itemEntFlash = itemEnt.GetInventory().CreateAttachment("Battery9V");
					itemEntFlash = ItemBase.Cast(itemEnt);
					break;
					
					case "1":
					itemEnt = player.GetInventory().CreateInInventory( "Chemlight_Blue" );
					break;
					
					case "2":
					itemEnt = player.GetInventory().CreateInInventory( "Chemlight_Green" );
					break;
					
					case "3":
					itemEnt = player.GetInventory().CreateInInventory( "Chemlight_Red" );
					break;
					
					case "4":
					itemEnt = player.GetInventory().CreateInInventory( "Chemlight_White" );
					break;
					
					case "5":
					itemEnt = player.GetInventory().CreateInInventory( "Chemlight_Yellow" );
					break;
					
					case "6":
					itemEnt = player.GetInventory().CreateInInventory( "PortableGasLamp" );
					itemEntFlash = itemEnt.GetInventory().CreateAttachment("LargeGasCanister");
					itemEntFlash = ItemBase.Cast(itemEnt);
					break;
					
					case "7":
					itemEnt = player.GetInventory().CreateInInventory( "Torch" );
					itemEnt = player.GetInventory().CreateInInventory( "Matchbox" );
					break;
					
					case "8":
					itemEnt = player.GetInventory().CreateInInventory( "Roadflare" );
					break;
				};
			};
			// Food
			if(spawnwithfood == true)
			{
				int Drinkfood = Math.RandomIntInclusive(0,6);
				int Eatfood = Math.RandomIntInclusive(0,15);
				switch(Eatfood.ToString())
				{
					case "0":
						itemEntFood = player.GetInventory().CreateInInventory("SpaghettiCan");
					break;

					case "1":
						itemEntFood = player.GetInventory().CreateInInventory("TunaCan");
					break;

					case "2":
						itemEntFood = player.GetInventory().CreateInInventory("Rice");
					break;
					
					case "3":
						itemEntFood = player.GetInventory().CreateInInventory("SpaghettiCan");
					break;
					
					case "4":
						itemEntFood = player.GetInventory().CreateInInventory("SardinesCan");
					break;
					
					case "5":
						itemEntFood = player.GetInventory().CreateInInventory("BakedBeansCan");
					break;
					
					case "6":
						itemEntFood = player.GetInventory().CreateInInventory("TacticalBaconCan");
					break;
					
					case "7":
						itemEntFood = player.GetInventory().CreateInInventory("PeachesCan");
					break;
					
					case "8":
							itemEntFood = player.GetInventory().CreateInInventory("Apple");
							itemEntFood = player.GetInventory().CreateInInventory("Apple");
					break;
					
					case "8":
							itemEntFood = player.GetInventory().CreateInInventory("Kiwi");
							itemEntFood = player.GetInventory().CreateInInventory("Kiwi");
					break;
					
					case "9":
							itemEntFood = player.GetInventory().CreateInInventory("Pear");
							itemEntFood = player.GetInventory().CreateInInventory("Pear");
					break;
					
					case "10":
							itemEntFood = player.GetInventory().CreateInInventory("Plum");
							itemEntFood = player.GetInventory().CreateInInventory("Plum");
					break;
					
					case "11":
							itemEntFood = player.GetInventory().CreateInInventory("Potato");
							itemEntFood = player.GetInventory().CreateInInventory("Potato");
					break;
					
					case "12":
							itemEntFood = player.GetInventory().CreateInInventory("PowderedMilk");
							itemEntFood = player.GetInventory().CreateInInventory("PowderedMilk");
					break;
					
					case "13":
							itemEntFood = player.GetInventory().CreateInInventory("Tomato");
							itemEntFood = player.GetInventory().CreateInInventory("Tomato");
					break;
					
					case "14":
							itemEntFood = player.GetInventory().CreateInInventory("Zucchini");
					break;
					
					case "15":
						itemEntFood = player.GetInventory().CreateInInventory("Pumpkin");
					break;
					
				};
				
				switch(Drinkfood.ToString())
				{
					case "0":
							itemEntFood = player.GetInventory().CreateInInventory("SodaCan_Cola");
							itemEntFood = player.GetInventory().CreateInInventory("SodaCan_Cola");
					break;

					case "1":
							itemEntFood = player.GetInventory().CreateInInventory("SodaCan_Kvass");
							itemEntFood = player.GetInventory().CreateInInventory("SodaCan_Kvass");
					break;

					case "3":
							itemEntFood = player.GetInventory().CreateInInventory("SodaCan_Pipsi");
							itemEntFood = player.GetInventory().CreateInInventory("SodaCan_Pipsi");
					break;
					
					case "4":
							itemEntFood = player.GetInventory().CreateInInventory("SodaCan_Spite");
							itemEntFood = player.GetInventory().CreateInInventory("SodaCan_Spite");
					break;
					
					case "5":
						itemEntFood = player.GetInventory().CreateInInventory("Canteen");
					break;
					
					case "6":
						itemEntFood = player.GetInventory().CreateInInventory("WaterBottle");
					break;
				};
			};
			// Spawn with Meds
			if (SpawnWithMeds == true )
			{
				int Medic = Math.RandomIntInclusive(0,8);
				switch(Medic.ToString())
				{
					case "0":
							itemEntFood = player.GetInventory().CreateInInventory("bandagedressing");
							itemEntFood = player.GetInventory().CreateInInventory("Epinephrine");
					break;
					case "1":
							itemEntFood = player.GetInventory().CreateInInventory("bandagedressing");
							itemEntFood = player.GetInventory().CreateInInventory("Morphine");
					break;
					case "2":
							itemEntFood = player.GetInventory().CreateInInventory("Epinephrine");
							itemEntFood = player.GetInventory().CreateInInventory("Morphine");
					break;
					case "3":
							itemEntFood = player.GetInventory().CreateInInventory("bandagedressing");
							itemEntFood = player.GetInventory().CreateInInventory("bandagedressing");
					break;
					case "4":
							itemEntFood = player.GetInventory().CreateInInventory("TetracyclineAntibiotics");
							itemEntFood = player.GetInventory().CreateInInventory("SalineBagIV");
					break;
					case "5":
							itemEntFood = player.GetInventory().CreateInInventory("Morphine");
							itemEntFood = player.GetInventory().CreateInInventory("SalineBagIV");
					break;
					case "6":
							itemEntFood = player.GetInventory().CreateInInventory("Epinephrine");
							itemEntFood = player.GetInventory().CreateInInventory("SalineBagIV");
					break;
					case "7":
							itemEntFood = player.GetInventory().CreateInInventory("bandagedressing");
							itemEntFood = player.GetInventory().CreateInInventory("SalineBagIV");
					break;
					case "8":
							itemEntFood = player.GetInventory().CreateInInventory("SalineBagIV");
							itemEntFood = player.GetInventory().CreateInInventory("SalineBagIV");
					break;
				};
			};
			//Backpack
			if(SpawnBackPack == true)
			{
				//Random Backpack
				bool backpackChance = false;
				int chanceBackpack = Math.RandomIntInclusive(0,maxBackpack);
				
				if ( RndBackpack == false) 
				{
					int backpack = Math.RandomIntInclusive(0,29);
					switch(backpack.ToString())
					{
						case "0":
						itemEntBackpack = player.GetInventory().CreateInInventory("CourierBag");
						break;

						case "1":
						itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Black");
						break;

						case "2":
						itemEntBackpack = player.GetInventory().CreateInInventory("HuntingBag");
						break;
						
						case "3":
						itemEntBackpack = player.GetInventory().CreateInInventory("AssaultBag_Black");
						break;
						
						case "4":
						itemEntBackpack = player.GetInventory().CreateInInventory("AssaultBag_Green");
						break;
						
						case "5":
						itemEntBackpack = player.GetInventory().CreateInInventory("AssaultBag_Ttsko");
						break;
						
						case "6":
						itemEntBackpack = player.GetInventory().CreateInInventory("ChildBag_Blue");
						break;
						
						case "7":
						itemEntBackpack = player.GetInventory().CreateInInventory("ChildBag_Green");
						break;
						
						case "8":
						itemEntBackpack = player.GetInventory().CreateInInventory("ChildBag_Red");
						break;
						
						case "9":
						itemEntBackpack = player.GetInventory().CreateInInventory("CoyoteBag_Brown");
						break;
						
						case "10":
						itemEntBackpack = player.GetInventory().CreateInInventory("CoyoteBag_Green");
						break;
						
						case "11":
						itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Blue");
						break;
						
						case "12":
						itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Green");
						break;
						
						case "13":
						itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Orange");
						break;
						
						case "14":
						itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Red");
						break;
						
						case "15":
						itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Yellow");
						break;
						
						case "16":
						itemEntBackpack = player.GetInventory().CreateInInventory("ImprovisedBag");
						break;
						
						case "17":
						itemEntBackpack = player.GetInventory().CreateInInventory("LeatherBelt_Beige");
						break;
						
						case "18":
						itemEntBackpack = player.GetInventory().CreateInInventory("LeatherSack_Beige");
						break;
						
						case "19":
						itemEntBackpack = player.GetInventory().CreateInInventory("MountainBag_Blue");
						break;
						
						case "20":
						itemEntBackpack = player.GetInventory().CreateInInventory("MountainBag_Green");
						break;
						
						case "21":
						itemEntBackpack = player.GetInventory().CreateInInventory("MountainBag_Orange");
						break;
						
						case "22":
						itemEntBackpack = player.GetInventory().CreateInInventory("MountainBag_Red");
						break;
						
						case "23":
						itemEntBackpack = player.GetInventory().CreateInInventory("SmershBag");
						break;
						
						case "24":
						itemEntBackpack = player.GetInventory().CreateInInventory("TaloonBag_Blue");
						break;
						
						case "25":
						itemEntBackpack = player.GetInventory().CreateInInventory("TaloonBag_Green");
						break;
						
						case "26":
						itemEntBackpack = player.GetInventory().CreateInInventory("TaloonBag_Orange");
						break;
						
						case "27":
						itemEntBackpack = player.GetInventory().CreateInInventory("TaloonBag_Violet");
						break;
						
						case "28":
						itemEntBackpack = player.GetInventory().CreateInInventory("TortillaBag");
						break;
						
						case "29":
						itemEntBackpack = player.GetInventory().CreateInInventory("ChestHolster");
						break;
					};
					
				}else{
					if(chanceBackpack == 0 /*|| chanceBackpack == 1*/ )
					{
						backpackChance = true;
						
						if(backpackChance == true)
						{
							int backpack2 = Math.RandomIntInclusive(0,29);
							switch(backpack2.ToString())
							{
								case "0":
								itemEntBackpack = player.GetInventory().CreateInInventory("CourierBag");
								break;

								case "1":
								itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Black");
								break;

								case "2":
								itemEntBackpack = player.GetInventory().CreateInInventory("HuntingBag");
								break;
								
								case "3":
								itemEntBackpack = player.GetInventory().CreateInInventory("AssaultBag_Black");
								break;
								
								case "4":
								itemEntBackpack = player.GetInventory().CreateInInventory("AssaultBag_Green");
								break;
								
								case "5":
								itemEntBackpack = player.GetInventory().CreateInInventory("AssaultBag_Ttsko");
								break;
								
								case "6":
								itemEntBackpack = player.GetInventory().CreateInInventory("ChildBag_Blue");
								break;
								
								case "7":
								itemEntBackpack = player.GetInventory().CreateInInventory("ChildBag_Green");
								break;
								
								case "8":
								itemEntBackpack = player.GetInventory().CreateInInventory("ChildBag_Red");
								break;
								
								case "9":
								itemEntBackpack = player.GetInventory().CreateInInventory("CoyoteBag_Brown");
								break;
								
								case "10":
								itemEntBackpack = player.GetInventory().CreateInInventory("CoyoteBag_Green");
								break;
								
								case "11":
								itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Blue");
								break;
								
								case "12":
								itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Green");
								break;
								
								case "13":
								itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Orange");
								break;
								
								case "14":
								itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Red");
								break;
								
								case "15":
								itemEntBackpack = player.GetInventory().CreateInInventory("DryBag_Yellow");
								break;
								
								case "16":
								itemEntBackpack = player.GetInventory().CreateInInventory("ImprovisedBag");
								break;
								
								case "17":
								itemEntBackpack = player.GetInventory().CreateInInventory("LeatherBelt_Beige");
								break;
								
								case "18":
								itemEntBackpack = player.GetInventory().CreateInInventory("LeatherSack_Beige");
								break;
								
								case "19":
								itemEntBackpack = player.GetInventory().CreateInInventory("MountainBag_Blue");
								break;
								
								case "20":
								itemEntBackpack = player.GetInventory().CreateInInventory("MountainBag_Green");
								break;
								
								case "21":
								itemEntBackpack = player.GetInventory().CreateInInventory("MountainBag_Orange");
								break;
								
								case "22":
								itemEntBackpack = player.GetInventory().CreateInInventory("MountainBag_Red");
								break;
								
								case "23":
								itemEntBackpack = player.GetInventory().CreateInInventory("SmershBag");
								break;
								
								case "24":
								itemEntBackpack = player.GetInventory().CreateInInventory("TaloonBag_Blue");
								break;
								
								case "25":
								itemEntBackpack = player.GetInventory().CreateInInventory("TaloonBag_Green");
								break;
								
								case "26":
								itemEntBackpack = player.GetInventory().CreateInInventory("TaloonBag_Orange");
								break;
								
								case "27":
								itemEntBackpack = player.GetInventory().CreateInInventory("TaloonBag_Violet");
								break;
								
								case "28":
								itemEntBackpack = player.GetInventory().CreateInInventory("TortillaBag");
								break;
								
								case "29":
								itemEntBackpack = player.GetInventory().CreateInInventory("ChestHolster");
								break;
							};
							
						}
					}
				}
			}
		};
		//ADMINLOADOUTS
		if((player.GetIdentity().GetPlainId() == Admin1) && AdminSpawnLoadout == true)
			{
				player.RemoveAllItems();
				
				//Spawn Weapon and put it on Hotkey 1 
				itemEntWeapon = player.GetHumanInventory().CreateInHands("CZ61");
				
				//Clothes
				itemEnt = player.GetInventory().CreateInInventory("NBCPantsGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCJacketGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCBootsGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCGlovesGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCHoodGray");
				itemEnt = player.GetInventory().CreateInInventory("GP5GasMask");
				
				//Items
				itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				
				//Magazin + Put Weapon and Magazine on Hotkeys 
				magazin = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				
				player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
				player.SetQuickBarEntityShortcut(magazin,1 ,true);
				
				//Create and Attach Suppressor
				suppressor = itemEntWeapon.GetInventory().CreateAttachment("AK_Suppressor");
				suppressor = ItemBase.Cast(itemEntWeapon);;
				
			}else if((player.GetIdentity().GetPlainId() == Admin2) && AdminSpawnLoadout == true)
			{
			player.RemoveAllItems();
				
				//Spawn Weapon
				itemEntWeapon = player.GetHumanInventory().CreateInHands("CZ61");
				
				//Clothes
				itemEnt = player.GetInventory().CreateInInventory("NBCPantsGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCJacketGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCBootsGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCGlovesGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCHoodGray");
				itemEnt = player.GetInventory().CreateInInventory("GP5GasMask");
				
				//Items
				itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				
				//Magazin + Put Weapon and Magazine on Hotkeys 
				magazin = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				
				player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
				player.SetQuickBarEntityShortcut(magazin,1 ,true);
				
				//Create and Attach Suppressor
				suppressor = itemEntWeapon.GetInventory().CreateAttachment("AK_Suppressor");
				suppressor = ItemBase.Cast(itemEntWeapon);;
			
			}else if((player.GetIdentity().GetPlainId() == Admin3) && AdminSpawnLoadout == true)
			{
				player.RemoveAllItems();
				
				//Spawn Weapon in Hands
				itemEntWeapon = player.GetHumanInventory().CreateInHands("CZ61");
				
				//Clothes
				itemEnt = player.GetInventory().CreateInInventory("NBCPantsGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCJacketGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCBootsGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCGlovesGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCHoodGray");
				itemEnt = player.GetInventory().CreateInInventory("GP5GasMask");
				
				//Items
				itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				
				//Magazin + Put Weapon and Magazine on Hotkeys 
				magazin = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
				
				player.SetQuickBarEntityShortcut(itemEntWeapon,0 ,true);
				player.SetQuickBarEntityShortcut(magazin,1 ,true);
				
				//Create and Attach Suppressor
				suppressor = itemEntWeapon.GetInventory().CreateAttachment("AK_Suppressor");
				suppressor = ItemBase.Cast(itemEntWeapon);;
			};
		// SPAWNS
		if(Spawner == true)
		{
			if (PlayerCustomSpawn == true)
			{
				if(PlayerRandomSpawns == true)
				{
				int Spawns = Math.RandomIntInclusive(0,maxSpawnPoints);
					switch(Spawns.ToString())
					{
						case "0":
						player.SetPosition(Location1)
						break;
						case "1":
						player.SetPosition(Location2)
						break;
						case "2":
						player.SetPosition(Location3)
						break;
						case "3":
						player.SetPosition(Location4)
						break;
						case "4":
						player.SetPosition(Location5)
						break;
						case "5":
						player.SetPosition(Location6)
						break;
						case "6":
						player.SetPosition(Location7)
						break;
						case "7":
						player.SetPosition(Location8)
						break;
						case "8":
						player.SetPosition(Location9)
						break;
						case "9":
						player.SetPosition(Location10)
						break;
						case "10":
						player.SetPosition(Location11)
						break;
						case "11":
						player.SetPosition(Location12)
						break;
						case "12":
						player.SetPosition(Location13)
						break;
						case "13":
						player.SetPosition(Location14)
						break;
						case "14":
						player.SetPosition(Location15)
						break;
						case "15":
						player.SetPosition(Location16)
						break;
						case "16":
						player.SetPosition(Location17)
						break;
						case "17":
						player.SetPosition(Location18)
						break;
						case "18":
						player.SetPosition(Location19)
						break;
						case "19":
						player.SetPosition(Location20)
						break;
						/**
						case "20":												//if you want to add more Spawns
						player.SetPosition(Location21)
						break;
						**/
					};
				};
				if (PlayerFixedSpawn == true )
				{
					player.SetPosition(PlayerLocation);
				}
			};
			if (AdminSpawnLocation == true && (player.GetIdentity().GetPlainId() == Admin1)){
						player.SetPosition(AdminLocation);
				} else if (AdminSpawnLocation == true && (player.GetIdentity().GetPlainId() == Admin2)){
					player.SetPosition(AdminLocation);			// <-- This Line
					//player.SetPosition(AdminLocation2);													// you need to Exclude or delete the first Line
				}else if (AdminSpawnLocation == true && (player.GetIdentity().GetPlainId() == Admin3)){
					player.SetPosition(AdminLocation);			// <-- This Line
					//player.SetPosition(AdminLocation3);													// you need to Exclude or delete the first Line
				}
		}
	}
};
