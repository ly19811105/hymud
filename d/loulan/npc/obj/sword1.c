 // sword.c : an example weapon
#include <weapon.h>
#include <ansi.h> 
inherit SWORD; 
void create()
{
    set_name(HIG"���Ž�"NOR, ({ "duanmen sword","sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "��������,��Ѫ���顣\n");
        set("value", 1000);
                set("material", "steel");
        }
    init_sword(70); 
// These properties are optional, if you don't set them, it will use the
// default values. 
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");  
}  