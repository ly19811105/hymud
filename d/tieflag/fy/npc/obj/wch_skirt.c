 // cloth.c
// 
#include <armor.h> 
inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name(HIY"��" + HIR "��"NOR + "����ȹ", ({ "miniskirt" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����˿��ɵĽ���ȹ\n");
                set("material", "cloth");
                set("value", 5000);
                set("armor_prop/armor", 33);
        }
        setup();
} 