#include <ansi.h>
#include <armor.h>

inherit S_RING;
inherit F_AUTOLOAD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  

void create()
{
	set_name(order[random(13)]+"�ط����"NOR, ({ "magic ring", "ring" }));
	set("long", HIC"����һ����Զ�����������Ľ�ָ���������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("value", 50000);
	set("material", "gem");
	set("armor_prop/armor", 60);
    set("armor_prop/damage", 10); 
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",5);
		set("armor_prop/karey",5);
		set("armor_prop/percao",5);
		set("armor_prop/dexerity",5);
		set("armor_prop/constitution",0);
  
    
	set("armor_type", TYPE_FINGER);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
        set("no_clone",1);
        set("no_pawn",1);
	set("no_beg",1);
	set("no_steal",1);
	setup();
}	

int query_autoload() { return 1; }