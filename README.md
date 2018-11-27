# B-T-Loadout-and-Spawn-System
Dont know why Cause there are some Codes like this
Hope you have Fun


For Installation go to you Init.c and search the 
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
/*
		player.RemoveAllItems();

		EntityAI item = player.GetInventory().CreateInInventory(topsArray.GetRandomElement());
		EntityAI item2 = player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		EntityAI item3 = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
*/
		EntityAI itemEnt;
		ItemBase itemBs;
		
		itemEnt = player.GetInventory().CreateInInventory("Rag");
		itemBs = ItemBase.Cast(itemEnt);
		itemBs.SetQuantity(4);
		SetRandomHealth(itemEnt);

		itemEnt = player.GetInventory().CreateInInventory("RoadFlare");
		itemBs = ItemBase.Cast(itemEnt);
	}
};

and replace it with ALL out Of the Loadout+Spawn.c

then Config everything and badaboom there you are
