 // cloth.c
// 
#include <armor.h> 
inherit BOOTS;
#include <ansi.h>
void create()
{
    set_name(HIC"����ѥ"NOR, ({ "cloudboots" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "�����ⲽ��ѥ�������ָ�ƽ�����Ƶļ���\n");
                set("material", "cloth");
                set("value", 1000);
                set("armor_prop/dodge", 10 );
        }
        
} 