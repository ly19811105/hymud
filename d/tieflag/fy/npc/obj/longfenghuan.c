 // hammer.c
#include <weapon.h> 
inherit HAMMER; 
void create()
{
        set_name("����˫��", ({ "longfeng" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������˫�����Ϲٵĳ�������\n");
                set("value", 3000);
                set("material", "iron");
                set("wield_msg", "$N˫��һ�֣��ó�һ˫$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        } 
        ::init_hammer(305);
}       