// shield.c

#include <armor.h>

inherit EQUIP;

void setup()
{
		//set("atype", "shield");
	if( clonep(this_object()) ) return;

	set("armor_type", TYPE_SHIELD);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}